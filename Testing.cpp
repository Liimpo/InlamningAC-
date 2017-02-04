#include "TimberRegister.h"
#include <iostream>
#include <iomanip>
#include <crtdbg.h>

void printMenu();
void addTimberToStorage(TimberRegister &t2);
void printStorageInfo(TimberRegister t2);
void printTotalPrice(TimberRegister t2);
void removeTimberFromStorage(TimberRegister &t2);
void setInfo(TimberRegister &t2);
void saveTimbers(TimberRegister t2);
void loadTimbers(TimberRegister &t2);

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
  printMenu();
  TimberRegister t1("Lager");
  TimberRegister t2("Test");
  t2.addTimber("55x55", 33, 55);
  t2.addTimber("33x44", 22, 66);
  /*t1.addTimber("24x200", 240, 10.5);
  t1.addTimber("33x100", 100, 25.33);
  t1.addTimber("44x55", 55, 33);
  t1.addTimber("22x55", 55, 33);
  t1.addTimber("77x55", 55, 33);
  */
  loadTimbers(t1);
 // foo(t1);
  //addTimberToStorage(t1);
  printTotalPrice(t1);
  //removeTimberFromStorage(t1);
  cin.get();
  t2 = t1;
  printStorageInfo(t2);
 /* int nrOf = t2.getNrOfTimbers();
  cout << t2.getNrOfTimbers() << endl;
  string *test = new string[nrOf];
  setInfo(t2);
  t2.copyToArray(test);
  for (int i = 0; i < nrOf; i++)
  {
    cout << test[i] << endl;
  }
  cout << t2.displayTotalPrice() << endl;
  cin.get();
  delete [] test;*/
  saveTimbers(t2);
  return 0;
}

void printMenu()
{
	system("cls");
	cout << "====================================\n=            Welcome!              =\n=      To Timberhandler V1.0       =\n";
	cout << "=   Made by Linus Malmfelt @BTH    =\n====================================\n";
	cout << "1. Add a timber" << endl;
	cout << "2. View all your timbers" << endl;
	cout << "3. View a low count of timbers in your storage" << endl;
	cout << "4. View the total cost of all your timber" << endl;
	cout << "5. Remove a timber" << endl;
	cout << "6. Change status of a certain timber" << endl;
	cout << "7. Save to file" << endl;
	cout << "8. Load from file" << endl;
}
void addTimberToStorage(TimberRegister &t2)
{
	string tempDim = "";
	int tempMeters = 0;
	double tempPrice = 0;
	system("cls");
	cout << "Please specify your dimension (widthxlength): ";
	getline(cin, tempDim);
	cout << "Now enter how many meters you got available: ";
	cin >> tempMeters;
	cout << "Now specify the price of one meter: ";
	cin >> tempPrice;
	cin.ignore();

	//Lägger till ett virke utifrån användarens info.
	if (t2.addTimber(tempDim, tempMeters, tempPrice))
	{
		cout << "You successfully added a new timber to your storage!" << endl;
	}
	else
	{
		cout << "You cant enter a timber that's already in your storage!" << endl;
	}

	system("pause");
}
void printStorageInfo(TimberRegister t2)
{
	int nrOf = t2.getNrOfTimbers();
	string *tempArr = new string[nrOf];
	system("cls");

	t2.copyToArray(tempArr);
	for (int i = 0; i < nrOf; i++)
	{
		cout << tempArr[i] << endl;
	}

	system("pause");
	delete[] tempArr;
}
void printTotalPrice(TimberRegister t2)
{
	system("cls");
	cout << "YOUR STORAGE IS WORTH: " << endl;
	cout << t2.displayTotalPrice() << endl;
}
void removeTimberFromStorage(TimberRegister &t2)
{
	string tempDim = "";
	system("cls");
	cout << "Please enter the dimension of a timber you would like to remove: ";
	getline(cin, tempDim);
	if (t2.removeTimber(tempDim))
	{
		cout << "You successfully removed your timber!!" << endl;
	}
	else
	{
		cout << "You cannot remove a timber that does not exist!!" << endl;
	}

	system("pause");
}
void setInfo(TimberRegister &t2)
{
	string tempDim = "";
	int tempMet = 0;
	double tempPrice = 0;

	system("cls");

	cout << "Enter the dimension of the timber you want to access: ";
	getline(cin, tempDim);

	if (t2.existsTimber(tempDim))
	{
		cout << "Enter your new meters: " << endl;
		cin >> tempMet;

		cout << "Enter your new price: " << endl;
		cin >> tempPrice;

		t2.setTimberInfo(tempDim, tempMet, tempPrice);
		cin.ignore();
	}
	else
	{
		cout << "That timber was not found in your storage.." << endl;
	}
}
void saveTimbers(TimberRegister t2)
{
	string tmpName = "";
	system("cls");

	cout << "Enter a filename, followed by .txt: ";
	getline(cin, tmpName);

	t2.saveToFile(tmpName);
	cout << "Your file is now saved to: " << tmpName << endl;

	system("pause");
}
void loadTimbers(TimberRegister &t2)
{
	string tmpName = "";
	system("cls");

	cout << "Enter the filename you want to load.";
	getline(cin, tmpName);

	t2.readFromFile(tmpName);
	cout << "You read from the file: " << tmpName << endl;

	system("pause");
}
