#include "Player.h"                                    //Done
#include"Cell.h"
#include "GameObject.h"

Player::Player(Cell * pCell, int playerNum) : stepCount(0), wallet(100), playerNum(playerNum)
{
	this->pCell = pCell;
	this->turnCount = 0;

	// Make all the needed initialization or validations
}

// ====== Setters and Getters ======

void Player::SetCell(Cell * cell)
{
	pCell = cell;
}

Cell* Player::GetCell() const
{
	return pCell;
}

void Player::SetWallet(int wallet)
{

	this->wallet = (wallet>=0&& wallet<=100)? wallet:100; //M
	// Make any needed validations
}

int Player::GetWallet() const
{
	return wallet;
}

int Player::GetTurnCount() const
{
	return turnCount;
}

void Player::setTurnCount(int count)
{
	turnCount = (count>=0&&count<4)?count:0;
}

// ====== Drawing Functions ======

void Player::Draw(Output* pOut) const
{
	color playerColor = UI.PlayerColors[playerNum];

	pOut->DrawPlayer(GetCell()->GetCellPosition(), playerNum, playerColor); //M
	///TODO: use the appropriate output function to draw the player with "playerColor"

}

void Player::ClearDrawing(Output* pOut) const
{
	color cellColor = pCell->HasCard() ? UI.CellColor_HasCard : UI.CellColor_NoCard;
	
	
	///TODO: use the appropriate output function to draw the player with "cellColor" (to clear it)
	pOut->DrawPlayer(GetCell()->GetCellPosition(), playerNum, cellColor);//M
}

// ====== Game Functions ======

void Player::Move(Grid * pGrid, int diceNumber)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==
	//M
	this->turnCount ++;
	if (turnCount == 3)
	{
		this->wallet += 10 * diceNumber;
		this->turnCount = 0;
		return;
	}
	this->justRolledDiceNum = diceNumber;
	this->GetCell()->GetCellPosition().AddCellNum(diceNumber);
	pGrid->UpdatePlayerCell(this, GetCell()->GetCellPosition());
	if (pCell->HasLadder())
		pCell->GetGameObject()->Apply(pGrid, this);
	else if(pCell->HasSnake())
		int c;//pCell->GetGameObject()->Apply(pGrid, this);
	else if (pCell->HasCard())
		int c;//pCell->GetGameObject()->Apply(pGrid, this);
	if (this->stepCount == 99)
		pGrid->SetEndGame(true);
	// 1- Increment the turnCount because calling Move() means that the player has rolled the dice once
	
	// 2- Check the turnCount to know if the wallet recharge turn comes (recharge wallet instead of move)
	//    If yes, recharge wallet and reset the turnCount and return from the function (do NOT move)
	
	// 3- Set the justRolledDiceNum with the passed diceNumber

	// 4- Get the player current cell position, say "pos", and add to it the diceNumber (update the position)
	//    Using the appropriate function of CellPosition class to update "pos"

	// 5- Use pGrid->UpdatePlayerCell() func to Update player's cell POINTER (pCell) with the cell in the passed position, "pos" (the updated one)
	//    the importance of this function is that it Updates the pCell pointer of the player and Draws it in the new position

	// 6- Apply() the game object of the reached cell (if any)

	// 7- Check if the player reached the end cell of the whole game, and if yes, Set end game with true: pGrid->SetEndGame(true)

}

void Player::AppendPlayerInfo(string & playersInfo) const
{
	playersInfo += "P" + to_string(playerNum) + "(" ;
	playersInfo += to_string(wallet) + ", ";
	playersInfo += to_string(turnCount) + ")";
}