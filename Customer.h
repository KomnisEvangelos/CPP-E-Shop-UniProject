#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer
{
private:
	int custNo;
	char custName[21]; 
	char custEmail[21]; 
public:
	Customer();
	Customer(int custNo1, char custName1[], char custEmail1[]);
	void readData();
	void setData(int custNo1, char custName1[], char custEmail1[]);
	void printData();
	int getCustNo();
	char* getCustName();
	char* getCustEmail();
};

#endif