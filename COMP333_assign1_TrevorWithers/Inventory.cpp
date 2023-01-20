#include "Inventory.h"

//Trevor Withers
//Implementation file for Inventor.h header file for the Inventory Class

using namespace std;

Inventory::Inventory(string fileName, int maxNum)
{
	if (maxNum > 25)
	{
		maxProducts = SIZE;
	}
	else
	{
		maxProducts = maxNum;
	}
	ifstream fin(fileName);
	if (!fin.is_open())
	{
		cout << "File error... Program will now close..." << endl;
		system("pause");
		exit(-1);
	}
	for (noProducts = 0; noProducts < maxProducts; noProducts++)
	{
		fin >> products[noProducts].productCode;
		if (fin.eof())
		{
			break;
		}
		fin.ignore(80, '\n');
		getline(fin, products[noProducts].description);
		fin >> products[noProducts].price;
	}
}

void Inventory::writeInventory(ostream& out/*output*/) const
{
	out << setprecision(2) << fixed;
	out << left
		<< setw(20) << "Product Code"
		<< setw(20) << "Description"
		<< right
		<< setw(10) << "Price"
		<< endl;
	for (int ctr = 0; ctr < noProducts; ctr++)
	{
		out << left
			<< setw(20) << products[ctr].productCode
			<< setw(20) << products[ctr].description
			<< right
			<< setw(10) << products[ctr].price
			<< endl;
	}
}

void Inventory::increasePrice(int code, double ammount)
{
	int ctr = 0;
	for (ctr = 0; ctr < maxProducts; ctr++)
	{
		if (products[ctr].productCode == code)
		{
			if (products[ctr].price + ammount < 1000)
			{
				products[ctr].price += ammount;
			}
			else
			{
				products[ctr].price = 1000.00;
				cout << "The product called " << products[ctr].description << " was set to 1000." << endl;
			}
			break;
		}
	}
	if (ctr == maxProducts)
	{
		cout << "Error. Product not fount. Please recheck entry." << endl;
	}
}

void Inventory::showProduct(int code) const
{
	for (int ctr = 0; ctr < maxProducts; ctr++)
	{
		if (products[ctr].productCode == code)
		{
			cout << "The product is " << products[ctr].description << " and it costs $" << products[ctr].price << endl;
			break;
		}
	}
}

int Inventory::seachProduct(int code) const
{
	int index;
	for (index = 0; index < maxProducts; index++)
	{
		if (products[index].productCode == code)
		{
			break;
		}
	}
	return index;
}