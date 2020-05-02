#include "CustomerList.h"	//including the .h filebuf
#include <iostream>

using namespace std;
//constructor
CustomerList::CustomerList(){
numberCustomers = 0;}
bool CustomerList::addCustomer(const Customer& cus){	//checks for out of bounds
	if(numberCustomers >= MAX_NUMBER_CUSTOMERS){
			return false;
	}else{
		for(int i=0; i<numberCustomers; ++i){
				if(Lists[i]==cus)
		return false;}
	Lists[numberCustomers]=cus;
	++numberCustomers;
	return true;}
}
bool CustomerList::deleteCustomer(const Customer& cus){	//checks if customer exists and deletes.
	if(numberCustomers ==0)
			return false;
	else{
		for(int i=0; i<numberCustomers; ++i){
			if(Lists[i]==cus){
				Lists[i]=Lists[numberCustomers-1];
					--numberCustomers;
					return true;}
		}
	return false;
	}
}
//for finding customer index by way of entered name
int CustomerList::findLocation(int id){
	
	for(int i=0; i<numberCustomers; ++i)
		if(Lists[i].getId()==id)
			return i;
		return -1;	//returns -1 if the name doesn't exist in the database
}
//for finding customer index by way of password
int CustomerList::findLocation2(int password){
	
	for(int i=0; i<numberCustomers; ++i)
		if(Lists[i].getPassword()==password)
			return i;
		return -1;	//returns -1 if the password doesn't exist in the database
}
int CustomerList::totalNumberCustomers(){	//gives total customer number
	return numberCustomers; }
	
Customer CustomerList::searchCustomer(int index){	//gives index of entered employee information
	return Lists[index];
}