#include "Item.h"
#include "Customer.h"
#include "Order.h"
#include <cstring>
#include <iostream>
using namespace std;

Order::Order() {
	orderNo = 0;
	strcpy(orderDate, "dd/mm/yy");
	totalAmount = 0;
}

Order::Order(int orderNo1, char orderDate1[], float totalAmount1, int custNo1, char custName1[], char custEmail1[], int itemNo1, char itemDesc1[], float itemPrice1) {
	orderNo = orderNo1;
	strcpy(orderDate, orderDate1);
	totalAmount = totalAmount1;
	Customer::Customer(custNo1, custName1, custEmail1);
	Item::Item(itemNo1, itemDesc1, itemPrice1);
}
void Order::readData() {
	Customer::readData();
	cout << "Give order number:  ";
	cin >> orderNo;
	getchar();
	cout << "Give order date:  ";
	cin >> orderDate;
	getchar();
}
void Order::setData(int orderNo1, char orderDate1[], float totalAmount1, int custNo1, char custName1[], char custEmail1[], int itemNo1, char itemDesc1[], float itemPrice1) {
	orderNo = orderNo1;
	strcpy(orderDate, orderDate1);
	totalAmount = totalAmount1;
	Customer::Customer(custNo1, custName1, custEmail1);
	Item::Item(itemNo1, itemDesc1, itemPrice1);
}
void Order::printData() {
	cout << "Order number:" << orderNo << endl;
	cout << "Order date:" << orderDate << endl;
	cout << "Total Amount:" << totalAmount << endl;
	Customer::printData();
	Item::printData();
}
int Order::getOrderNo() {
	return orderNo;
}
char* Order::getOrderDate() {
	return orderDate;
}
float Order::getTotalAmount() {
	return totalAmount;
}
void Order::buyItem(float price, int qty) {
	totalAmount = totalAmount + (price * qty);
}
int Order::shippingCost() {
	if (totalAmount > 200)
		return 0;
	return 20;
}