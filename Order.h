#ifndef ORDER_H
#define ORDER_H

class Order : public Customer, public Item 
{
private:
	int orderNo; 
	char orderDate[11]; 
	float totalAmount;
public:
	Order();
	Order(int orderNo1, char orderDate1[], float totalAmount1,
	int custNo1, char custName1[], char custEmail1[],
	int itemNo1, char itemDesc1[], float itemPrice1);
	void readData(); 
	void setData(int orderNo1, char orderDate1[], float totalAmount1,
	int custNo1, char custName1[], char custEmail1[],
	int itemNo1, char itemDesc1[], float itemPrice1);
	void printData();
	int getOrderNo();
	char* getOrderDate();
	float getTotalAmount();
	void buyItem(float price, int qty);
	int shippingCost();
}; 
#endif