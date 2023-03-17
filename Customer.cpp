#include "Item.h"
#include "Customer.h"
#include "Order.h"
#include <cstring>
#include <iostream>
using namespace std;

Customer::Customer() {
	custNo=0;
	strcpy(custName, " ");
	strcpy(custEmail, " ");
}
Customer::Customer(int custNo1, char custName1[], char custEmail1[]) {
	custNo = custNo1;
	strcpy(custName, custName1);
	strcpy(custEmail, custEmail1);
}
void Customer::readData() {

	cout << "Give customer number:  ";
	cin >> custNo;
	getchar();
	cout << "Give customer name:  ";
	cin.getline(custName, 21);
	cout << "Give customer email:  ";
	cin >> custEmail;
	getchar();
}
void Customer::setData(int custNo1, char custName1[], char custEmail1[]) {
	custNo = custNo1;
	strcpy(custName, custName1);
	strcpy(custEmail, custEmail1);
}
void Customer::printData() {

	cout << "Customer number:" << custNo << endl;
	cout << "Customer name:" << custName << endl;
	cout << "Customer email:" << custEmail << endl;
}
int Customer::getCustNo() {

	return custNo;
}
char* Customer::getCustName() {
	return custName;
}
char* Customer::getCustEmail() {
	return custEmail;
}