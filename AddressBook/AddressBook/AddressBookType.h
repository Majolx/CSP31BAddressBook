/**
 * AddressBookType.h
 * [Insert Description of File]
 *
 * Written by:  Mathew Larribas
 * Date:        11/13/2013
 ******************************************************************************/
#include <iostream>
#include <fstream>
#include "orderedlinkedlist.h"
#include "ExtPersonType.h"

using namespace std;


class AddressBookType : public orderedLinkedList<ExtPersonType>
{
public:
    void print();
    void printNameInTheMonth(int);
    int search(string);
    void printInfoOf(string);
    void printNamesWithStatus(string);
    void printAt(int);
    void printNamesBetweenLastNames(string, string);
    void saveData(ofstream&);
	bool lexicalCompare(string, string);
	int listSize();
	void AddressBookType::deletePerson(const string firstName, const string lastName);
	
	nodeType<ExtPersonType>* firstNode();

    AddressBookType();
};

// ========================================================================== //
// Constructor - Default
AddressBookType::AddressBookType()
{   
	// Intentionally left blank
}

// ========================================================================== //
// Print - Default
void AddressBookType::print()
{
	nodeType<ExtPersonType> *currentNode;

	if (!(currentNode = firstNode()))
	{
		return;
	}

    while (currentNode != NULL)
    {
       currentNode->info.printInfo();
	   cout << endl;
	   currentNode = currentNode->link;
    }
}

// --------------------------------------------------------------
// Print - Name In The Month
void AddressBookType::printNameInTheMonth(int month)
{
	nodeType<ExtPersonType> *currentNode;

	if (!(currentNode = firstNode()))
	{
		return;
	}

	while (currentNode != NULL)
	{
		if (currentNode->info.getDate().getMonth() == month)
			currentNode->info.print();

		currentNode = currentNode->link;
	}
}

// --------------------------------------------------------------
// Print - Info Of
void AddressBookType::printInfoOf(string lastName)
{
	nodeType<ExtPersonType> *currentNode;

	if (!(currentNode = firstNode()))
	{
		return;
	}

    int index = search(lastName);

	
    if (index != -1)
    {
		for (int i = 0; i < index; i++)
			currentNode = currentNode->link;

        currentNode->info.printInfo();
    }
	else
	{
		cout << "Person not found!" << endl << endl;
	}
}

// --------------------------------------------------------------
// Print - Names with Status
void AddressBookType::printNamesWithStatus(string status)
{
	nodeType<ExtPersonType> *currentNode = first;

	while (currentNode != NULL)
	{
		if (currentNode->info.getStatus() == status)
			currentNode->info.print();
	}
}

// --------------------------------------------------------------
// Print - Print At
void AddressBookType::printAt(int index)
{
	nodeType<ExtPersonType> *currentNode;

	if (!(currentNode = firstNode()))
	{
		return;
	}

	// Progress the node to the correct index
	for (int i = 0; i < index; i++)
	{
		currentNode = currentNode->link;

		// Check to see if the index is out of bounds
		if (currentNode == NULL)
		{
			cout << "Index out of bounds!" << endl << endl;
			return;
		}
	}

	// Print the information of the node
    currentNode->info.printInfo();

}

nodeType<ExtPersonType>* AddressBookType::firstNode()
{
	if (first != NULL)
		return first;
	else
	{
		cout << "No list is present!" << endl << endl;
		return NULL;
	}
}

// --------------------------------------------------------------
// Print - Print Names Between Last Names
void AddressBookType::printNamesBetweenLastNames(string s1, string s2)
{
	nodeType<ExtPersonType> *currentNode;

	if (!(currentNode = firstNode()))
	{
		return;
	}

	while (currentNode != NULL)
	{
		string lastName = currentNode->info.getLastName();
		if (lexicalCompare(lastName, s1) && lexicalCompare(s2, lastName))
			currentNode->info.print();
	}
}

bool AddressBookType::lexicalCompare(string s1, string s2)
{
	if (s1 == s2) return true;

	int i = 0;
	for (;;)
	{
		if (NULL == s1[i]) return false;
		if (NULL == s2[i]) return true;

		char a, b;
		a = tolower(s1[i]);
		b = tolower(s2[i]);

		if (a < b) return false;
		if (b < a) return true;

		i++;
	}
}


// ========================================================================== //
// Search
int AddressBookType::search(string lastName)
{
    int index = 0;
	nodeType<ExtPersonType> *currentNode;

	if (!(currentNode = firstNode()))
	{
		return -1;
	}

	while (currentNode != NULL)
	{
		if (currentNode->info.getLastName() == lastName)
			return index;
		index++;
	}

    return -1;
}

// ========================================================================== //
// Save Data
void AddressBookType::saveData(ofstream& outFile)
{
	nodeType<ExtPersonType> *currentNode;
	currentNode = firstNode();

	while (currentNode != NULL)
	{
		DateType d = currentNode->info.getDate();
		AddressType a = currentNode->info.getAddress();
		string aMembers[4];
		a.getAddress(aMembers[0], aMembers[1], aMembers[2], aMembers[3]);

		outFile << currentNode->info.getFirstName() << " " << currentNode->info.getLastName() << endl;
		outFile << d.getMonth() << " " << d.getDay() << " " << d.getYear() << endl;
		outFile << aMembers[0] << endl;
		outFile << aMembers[1] << endl;
		outFile << aMembers[2] << endl;
		outFile << aMembers[3] << endl;
		outFile << currentNode->info.getPhoneNumber() << endl;
		outFile << currentNode->info.getStatus();

		currentNode = currentNode->link;
	}
	/*for (int i = 0; i < this->length; i++)
	{
		DateType d = list[i].getDate();
		AddressType a = list[i].getAddress();
		string aMembers[4];
		a.getAddress(aMembers[0], aMembers[1], aMembers[2], aMembers[3]);

		outFile << list[i].getFirstName() << " " << list[i].getLastName() << endl;
		outFile << d.getMonth() << " " << d.getDay() << " " << d.getYear() << endl;
		outFile << aMembers[0] << endl;
		outFile << aMembers[1] << endl;
		outFile << aMembers[2] << endl;
		outFile << aMembers[3] << endl;
		outFile << list[i].getPhoneNumber() << endl;
		outFile << list[i].getStatus();
		if (i + 1 != this->length)
			outFile << endl;
	}*/
}

int AddressBookType::listSize()
{
	return this->listSize();
}

//==========================================================================================//
//DeletingPerson
void AddressBookType::deletePerson(const string firstName, const string lastName)
{
	ExtPersonType personInList;
	nodeType<ExtPersonType> *currentNode;
	currentNode = firstNode();

	while (currentNode != NULL)
	{
		if (currentNode->info.getFirstName() == firstName && currentNode->info.getLastName() == lastName)
		{
			personInList = currentNode->info;
			this->deleteNode(personInList);
		}
	}
}