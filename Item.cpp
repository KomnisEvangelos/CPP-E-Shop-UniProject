#include "Item.h"
#include "Customer.h"
#include "Order.h"
#include <iostream>
using namespace std;

Item::Item() {
	itemNo=0;
	strcpy(itemDesc, " ");
	itemPrice=0;
}
Item::Item(int itemNo1, char itemDesc1[], float itemPrice1) {
	itemNo = itemNo1;
	strcpy(itemDesc, itemDesc1);
	itemPrice = itemPrice1;
}
void Item::readData() {
	cout << "Give item number:";
	cin >> itemNo;
	cout << "Give item desc:";
	cin >> itemDesc;
	getchar();
	cout << "Give item price:";
	cin >> itemPrice;
}
void Item::setData(int itemNo1, char itemDesc1[], float itemPrice1) {
	itemNo = itemNo1;
	strcpy(itemDesc, itemDesc1);
	itemPrice = itemPrice1;
}
void Item::printData() {
	cout << itemNo << "," << " " << itemDesc << "    " << "," << itemPrice << endl;
}
int Item::getItemNo() {
	return itemNo;
}
char* Item::getItemDesc() {
	return itemDesc;
}
float Item::getItemPrice() {
	return itemPrice;
}