
#include "stdafx.h"
#include <iostream>
#include <string>
#include "SupportTickets.h"

using namespace std;

class Ticket
{
	static int generatedID;
	int uniqueID, numberOfUsersImpacted;
	string ticketStatus, callersName, categoryOfIssue, descriptionOfIssue, issueType, ticketPriority;
	
public:
	Ticket();
	int getID();
	void CaptureTicket(), ShowTicket(), CloseTicket();
	string calculateTicketPriority(int users);
};


int main()
{
	int newTicket = 0;
	char userInput;
	Ticket Tickets[100];

	
	do {
		Tickets[newTicket].CaptureTicket();
		newTicket++;
		cout << "Open a new ticket? (Y)es or (N)o" << endl;
		cin >> userInput;
		cin.ignore();
	} while (userInput == 'Y' || userInput == 'y');

	for (int i = 0; i < newTicket; i++)
	{
		Tickets[i].ShowTicket();
	}

	Tickets[0].CloseTicket();
	cin >> userInput;
	return 0;
}

void Ticket::CaptureTicket()
{
	cout << "Please input the caller's name: " << endl;
	getline(cin, callersName);
	cout << "Please input type of issue (only input either: (S)erver, (A)pplication or A(C)cess): " << endl;
	getline(cin, categoryOfIssue);

	if (categoryOfIssue == "S" || categoryOfIssue == "s")
	{
		issueType = "Server";

	}
	else if (categoryOfIssue == "A" || categoryOfIssue == "a")
	{
		issueType = "Application";

	}
	else if (categoryOfIssue == "C" || categoryOfIssue == "c")
	{
		issueType = "Access";

	}
	else { cout << "Did not input valid character" << endl; }

	cout << "Please input the description of issue: " << endl;
	getline(cin, descriptionOfIssue);
	cout << "Please input the number of users impacted by the issue" << endl;
	cin >> numberOfUsersImpacted;

	ticketPriority = calculateTicketPriority(numberOfUsersImpacted);

	cout << "Your issue ID is: " << uniqueID << endl;
	cin.clear();
	cin.ignore();
	cout << "**********************************" << endl;
}

int Ticket::generatedID = 1000;

Ticket::Ticket()
{
	uniqueID = generatedID++;
	ticketStatus = "OPEN";
}

int Ticket::getID()
{
	return uniqueID;
}



string Ticket::calculateTicketPriority(int users) {
	string ticketPriority;
	if (users < 10)
	{
		ticketPriority = "Low";
	}
	else if (users >= 10 && users < 50)
	{
		ticketPriority = "Med";
	}
	else if (users >= 50)
	{
		ticketPriority = "High";
	}
	return ticketPriority;
}


void Ticket::ShowTicket()
{
	cout << "*****************************\n";
	cout << "Ticket Listing: " << endl;
	cout << "*****************************\n\n";
	cout << "Ticket ID: " << uniqueID << endl;
	cout << "Type: " << issueType << endl;
	cout << "Status: " << ticketStatus << endl;
	cout << "Description: " << descriptionOfIssue << endl;
	cout << "User: " << callersName << endl;
	cout << "Users Impacted: " << numberOfUsersImpacted << endl;
	cout << "Priroity: " << ticketPriority << endl;
	cout << "*****************************\n\n";
}

void Ticket::CloseTicket()
{
	ticketStatus = "Closed!";
	cout << "Ticket number " << uniqueID << " is " << ticketStatus << endl;
}

