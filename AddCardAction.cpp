#include "AddCardAction.h"

#include "Input.h"
#include "Output.h"
#include "CardOne.h"

AddCardAction::AddCardAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddCardAction::~AddCardAction()
{
}

void AddCardAction::ReadActionParameters()					//>>SHAHEEN
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	// 2- Read the "cardNumber" parameter and set its data member
	cardNumber = pIn->GetInteger(pOut);								// not sure>>SHAHEEN
	// 3- Read the "cardPosition" parameter (its cell position) and set its data member
	cardPosition = pIn->GetCellClicked();
	// 4- Make the needed validations on the read parameters
	if (!(cardNumber >= 1 && cardNumber <= 12))
		pGrid->PrintErrorMessage("Wrong card number, please try again...");
	if (cardPosition.GetCellNum() == 1 || cardPosition.GetCellNum() == 99)
	{
		int x, y;
		pGrid->PrintErrorMessage("Wrong card position, you can't put a card at cell number 1 or 99");
		pIn->GetPointClicked(x, y);					// wait for a click
		ReadActionParameters();
	}
	// 5- Clear status bar
	pOut->ClearStatusBar();
}

void AddCardAction::Execute()					//>>SHAHEEN
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- The first line of any Action Execution is to read its parameter first
	ReadActionParameters();
	// 2- Switch case on cardNumber data member and create the appropriate card object type
	Card * pCard = NULL; // will point to the card object type				//>>SHAHEEN not complete wait for ibraam
	switch (cardNumber)
	{
	case 1:
		pCard = new CardOne(cardPosition);
		break;

		// A- Add the remaining cases
	case 2:
		pCard = new CardOne(cardPosition);
		break;
	case 3:
		pCard = new CardOne(cardPosition);
		break;
	case 4:
		pCard = new CardOne(cardPosition);
		break;
	case 5:
		pCard = new CardOne(cardPosition);
		break;
	case 6:
		pCard = new CardOne(cardPosition);
		break;
	case 7:
		pCard = new CardOne(cardPosition);
		break;
	case 8:
		pCard = new CardOne(cardPosition);
		break;
	case 9:
		pCard = new CardOne(cardPosition);
		break;
	case 10:
		pCard = new CardOne(cardPosition);
		break;
	case 11:
		pCard = new CardOne(cardPosition);
		break;
	case 12:
		pCard = new CardOne(cardPosition);
		break;
	}

	// 3- if pCard is correctly set in the switch case (i.e. if pCard is pointing to an object -- NOT NULL)
	if (pCard)
	{
		// A- We get a pointer to the Grid from the ApplicationManager
		Grid* pGrid = pManager->GetGrid();
		// B- Make the "pCard" reads its card parameters: ReadCardParameters(), It is virtual and depends on the card type
		pCard->ReadCardParameters(pGrid);
		// C- Add the card object to the GameObject of its Cell:
		bool added = pGrid->AddObjectToCell(pCard);

		// D- if the GameObject cannot be added in the Cell, Print the appropriate error message on statusbar
		if (!added)
		{
			// Print an appropriate message
			pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
		}

	}

	// Here, the card is created and added to the GameObject of its Cell, so we finished executing the AddCardAction

}
