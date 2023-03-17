#include "Item.h"
#include "Customer.h"
#include "Order.h"
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>
using namespace std;

void itemsToFile();
int fileToArr(ifstream& fin, Item p[]);
int itemMenu(Item p[], int n);
int searchItem(Item p[], int n, int searchCode);

#define N 5


int main() {

Item itemArr[N];
Order cust;
int itemCounter, searchCode=-1, positionCheck=-1,quantity=0;
ifstream infile("ITEMS20009.TXT");
ofstream outfile("ORDERS20009.TXT");

itemsToFile(); //create items.txt
itemCounter = fileToArr(infile, itemArr);//file to item arr
cust.readData(); // read customer and order data
itemMenu(itemArr, itemCounter);// show availabes items
//put first data on order.txt
outfile << "Customer No    : " << cust.getCustNo() << endl;
outfile << "Customer Name  : " << cust.getCustName() << endl;
outfile << "Customer Email : " << cust.getCustEmail() << endl;
outfile << "Order No       : " << cust.getOrderNo() << endl;
outfile << "Order Date     : " << cust.getOrderDate() << endl;
outfile << endl;
outfile << "ItemNumber  ItemDesc    Quantity   Price   TotalPrice" << endl;
outfile << "----------  ----------- ---------  ------  ----------" << endl;
cout << endl;

//buy procces
while (searchCode != 0){ // while customer wants to buy
	
	do
	{
		cout << "Give item number (0 for stop): ";
		cin >> searchCode;
		if (searchCode == 0) {
			break; // breaks the while loop
		}
		positionCheck = searchItem(itemArr, itemCounter, searchCode);//item code check
		if (positionCheck == -1)
			cout << "Wrong item number! Try again..." << endl;
		else {
			cout << "Give quantity: ";
			cin >> quantity;
			cust.buyItem(itemArr[positionCheck].getItemPrice(), quantity);//calculate total amount
			//put selected item data on order.txt
			outfile << "   " << itemArr[positionCheck].getItemNo() << "        " 
				    << itemArr[positionCheck].getItemDesc() << "         " << quantity 
				    << "       " << itemArr[positionCheck].getItemPrice() << "   " 
				    << itemArr[positionCheck].getItemPrice() * quantity << endl;
			cout << "Complete." << endl;
		}

	} while (positionCheck != -1);
	

} 
//put last data on order.txt
outfile << endl << endl;
outfile << "                                Subtotal:      " << cust.getTotalAmount() << endl;
outfile << "                                Shipping Cost: " << cust.shippingCost() << endl;
outfile << "                                Total Amount:  " << cust.shippingCost() + cust.getTotalAmount() << endl;
outfile.close();

cout << "Your receipt is ready...";
this_thread::sleep_for(chrono::milliseconds(5000));//wait
system("start ORDERS20009.TXT");//opens order.txt

return 0;
}

//functions
int fileToArr(ifstream& fin, Item p[]) {
	char value[20], itemDesc[10];
	int itemNo = 0, c=1,ci=0;
	double itemPrice = 0.0;
		while (fin >> value)
		{

			if (c == 1) {
				itemNo = stoi(value);
				c++;
			}
			else if (c == 2)
			{
				strcpy(itemDesc, value);
				c++;
			}
			else if (c == 3)
			{
				itemPrice = stod(value);
				p[ci].setData(itemNo, itemDesc, itemPrice);
				ci++;
				c = 1;
			}
			
		}
		
fin.close();

	return ci;
}

int itemMenu(Item p[], int n) {
	cout << endl << endl;
	cout << "Avaliable products:" << endl;
	cout << "********************" << endl;
	for (int i = 0; i < n; i++)
	{
		p[i].printData();
		cout << endl;
	}
	return 0;
}

int searchItem(Item p[], int n, int searchCode) {
	
	for (int i = 0; i < n; i++)
	{
		if (p[i].getItemNo() == searchCode) {
			return i;
		}
	}
	return -1;
}
void itemsToFile() {

		ofstream file("ITEMS20009.TXT");
		file << "100   Item1      101.99\n";
		file << "200   Item2      217.99\n";
		file << "300   Item3       49.99\n";
		file << "400   Item4       19.99\n";
		file << "500   Item5       79.49\n";
		file.close();
}
