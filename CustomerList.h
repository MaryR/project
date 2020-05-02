#ifndef CUSTOMERLIST_H
#define CUSTOMERLIST_H

#include <string>
#include "Customer.h"

using namespace std;

const int MAX_NUMBER_CUSTOMERS = 100; //maximum number of customers we can store

class CustomerList	//declaring customer list class
{
	private:
	Customer Lists[MAX_NUMBER_CUSTOMERS]; //database array for customer information
	int numberCustomers; //total customers in database
	
	public:
	CustomerList(); //constructor
	bool addCustomer(const Customer& cus); //for adding customers to database
	bool deleteCustomer(const Customer& cus); //for deletion
		int findLocation(int id); //finds customer by first name
		int findLocation2(int password);
		int totalNumberCustomers(); //how many customers are entered
		Customer searchCustomer(int index); //searches customers
}; 
#endif