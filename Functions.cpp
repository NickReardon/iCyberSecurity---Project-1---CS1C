#include "Customer.h"

void insertCustomer(Customer*& head)
{
	Customer* temp = new Customer;

	cout << "ID: ";
	cin >> temp->id;
	cin.ignore();

	cout << "Name: ";
	getline(cin, temp->name);

	temp->next = head;
	head = temp;
}

void deleteCustomer(Customer*& head)
{
	Customer* lead = head;
	Customer* follow = head;
	int idNum;

	cout << "Enter the ID of the record to be delete: ";
	cin >> idNum;

	while (lead->id != idNum && lead->next != nullptr)
	{
		follow = lead;
		lead = lead->next;
	}

	if (lead == head && lead->id == idNum)
	{
		head = head->next;
		delete lead;
	}
	else if (lead->next == nullptr)
	{
		if (lead->id == idNum)
		{
			follow->next = lead->next;
			delete lead;
		}
		else
		{
			cout << idNum << " is not in the list.\n\n";
		}
	}
	else
	{
		follow->next = lead->next;
		delete lead;
	}
}

void displayCustomer(Customer*& head)
{
	Customer* temp = head;

	while (temp != NULL)
	{
		cout << "ID: " << temp->id << endl
			<< "Name: " << temp->name << endl << endl;
		temp = temp->next;
	}
}