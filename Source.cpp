#include "Customer.h"

void insertCustomer(Customer*& head);
void deleteCustomer(Customer*& head);
void displayCustomer(Customer*& head);

int main()
{
	char answer = 'Y';
	Customer* head = nullptr;

	while (toupper(answer) == 'Y')
	{
		insertCustomer(head);

		cout << "Enter another Customer(Y or N)? ";
		cin >> answer;
		system("cls");
	}

	cout << "Here is the list of Customers:\n";
	displayCustomer(head);

	cout << "Delete a Customer (Y or N) ";
	cin >> answer;

	if (toupper(answer) == 'Y')
	{
		deleteCustomer(head);
		system("cls");

		cout << "Here is the list after deleting:\n";
		displayCustomer(head);
	}

	system("pause");
	return 0;
}