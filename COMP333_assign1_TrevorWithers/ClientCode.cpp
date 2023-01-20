#include "Inventory.h"

//Trevor Withers
//Client code for invetory tracking program

void showNoProducts(const Inventory& myInventory)
{
	cout << "The total number of products is " << myInventory.getNoProducts() << "." << endl;
}

int main()
{
	cout << "Inventory object examples from Inventory.data file:" << endl << endl;
	Inventory company("Inventory.data", 15);
	cout << "\nNumber of products = "
		<< company.getNoProducts() << endl;
	cout << "printing all products in Inventory.data to the screen:\n\n";
	company.writeInventory(cout);
	cout << "\nLooking up product # 54312:\n";
	company.showProduct(54312);		//should be in Inventory.data, if not add it
	cout << "\nIncrease price by $1.22 for product # 54312\n\n";
	company.increasePrice(54312, 1.22);
	cout << "Looking up new price for product # 54312:\n";
	company.showProduct(54312);		//should be incremented
	cout << "\nLooking up product # 60000:\n";
	company.showProduct(60000);		//incremented over $1000
	cout << "\n\nIncrease price by $1000 for product # 88888:\n";
	company.increasePrice(60000, 1000.);
	cout << "Looking up new price for product # 60000\n\n";
	company.showProduct(60000);		//incremented over $1000
	cout << "Number of products = " << company.getNoProducts() << endl;
	cout << "\nprinting all products in Inventory.data screen:\n\n";
	company.writeInventory(cout);


	cout << "\n\n\nEmpty object examples from default.data file" << endl << endl;
	Inventory myshop("default.data");			//empty file
	cout << "Number of products = " << myshop.getNoProducts() << endl << endl;
	cout << "Increase price by $1.22 for product # 24000\n\n";//not in file
	myshop.increasePrice(3483, 1.22);
	ofstream fout("output.file");
	if (!fout.is_open())
	{
		cout << "error opening file " << endl;
		system("pause");
		exit(1);
	}
	fout << fixed << setprecision(2);
	myshop.writeInventory(fout);




	cout << "\n\nFull file (products.data file) examples" << endl << endl;
	Inventory fullLoad("product.data");  //file has more than 25 records
	fullLoad.increasePrice(854, 2.00);
	fullLoad.writeInventory(cout);
	cout << "Number of products  = " << fullLoad.getNoProducts()
		<< endl << endl;
	cout << "\nLooking up product # 666:\n";
	fullLoad.showProduct(666);  //pass one that doesn't exist

	//add the code to call your showNoProducts() function here

	showNoProducts(fullLoad);
	system("type output.file");
	system("pause");

	/*
		Sample Output
		Inventory object examples from Inventory.data file:


		Number of products = 6
		printing all products in Inventory.data to the screen:

		Product Code        Description              Price
		3483                Calendar                 10.00
		2310                Computer Desk           200.00
		3333                Pen                     300.00
		9898                Mouse                     2.59
		54312               Chair                     5.99
		60000               Keyboard                  8.99

		Looking up product # 54312:
		The product is Chair and it costs $5.99

		Increase price by $1.22 for product # 54312

		Looking up new price for product # 54312:
		The product is Chair and it costs $7.21

		Looking up product # 60000:
		The product is Keyboard and it costs $8.99


		Increase price by $1000 for product # 88888:
		The product called Keyboard was set to 1000.
		Looking up new price for product # 60000

		The product is Keyboard and it costs $1000.00
		Number of products = 6

		printing all products in Inventory.data screen:

		Product Code        Description              Price
		3483                Calendar                 10.00
		2310                Computer Desk           200.00
		3333                Pen                     300.00
		9898                Mouse                     2.59
		54312               Chair                     7.21
		60000               Keyboard               1000.00



		Empty object examples from default.data file

		Number of products = 0

		Increase price by $1.22 for product # 24000

		Error. Product not fount. Please recheck entry.


		Full file (products.data file) examples

		Error. Product not fount. Please recheck entry.
		Product Code        Description              Price
		3483                Calendar                 10.00
		2310                Computer Desk           200.00
		3333                Pen                     300.00
		9898                Mouse                     2.59
		54312               Chair                     5.99
		60000               Keyboard                  8.99
		3484                Calendar1                10.00
		2311                Computer Des2           200.00
		3332                Pen2                    300.00
		9892                Mouse2                    2.59
		54313               Chair2                    5.99
		60002               Keyboard2                 8.99
		3484                Calendar3                10.00
		2313                Computer Desk3          200.00
		3334                Pen3                    300.00
		9893                Mouse3                    2.59
		54313               Chair3                    5.99
		60003               Keyboard3                 8.99
		3485                Calendar4                10.00
		2314                Computer Desk4          200.00
		3334                Pen4                    300.00
		9894                Mouse4                    2.59
		54312               Chair4                    5.99
		60004               Keyboard4                 8.99
		3486                Calendar5                10.00
		Number of products  = 25


		Looking up product # 666:
		The total number of products is 25.
		Product Code        Description              Price
		Press any key to continue . . .
	*/
}