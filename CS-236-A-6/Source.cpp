#include <iostream>
#include <string>


#include "Heap.h"

using namespace std;

int main()
{
	Heap H;
	int choice, inKey, input;

	cout << "\nEnter the positive integers to put in heap, enter -9 to stop. : ";

	while (cin >> input && input != -9)
	{
		H.add(input);
	}
	

	cout << "\nThe Heap is: " << endl;
	H.display();
	cout << endl;

	do {
		cout << endl;
		cout << "1. Display the Max-heap" << endl;
		cout << "2. Add an Item" << endl;
		cout << "3. Remove the Largest Item" << endl;
		cout << "4. Exit" << endl << endl;
		cout << "Enter choice: ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
			case 1:
				H.display();
				break;
			case 2:
				cout << "Add item : ";
				cin >> input;
				H.add(input);
				break;
			case 3:
				H.removeMax();
				break;
			case 4:

				break;
			default:
				cout << "Enter a valid choice ( 1 - 4)" << endl;
		}

	} while (choice != 4);

	system("PAUSE");
	return 0;
}