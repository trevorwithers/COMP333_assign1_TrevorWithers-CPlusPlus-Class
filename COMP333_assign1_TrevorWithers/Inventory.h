#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

//Trevor Withers
//Creating an abstract data type Inventory for a class called Inventory

const int SIZE = 25;

struct ProductRec
{
	int productCode;
	string description;
	double price;
};

class Inventory
{
public:
	void showProduct(int/*productCode*/) const;
	int getNoProducts() const { return noProducts; }
	void increasePrice(int/*productCode*/, double/*Amount to increase*/);
	void writeInventory(ostream& /*output*/) const;
	Inventory(string/*fileName*/, int = SIZE/*maxProducts*/);

private:
	int seachProduct(int/*productCode*/) const;
	ProductRec products[SIZE];
	int noProducts;
	int maxProducts;
};