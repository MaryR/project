#include "Customer.h" //needed for customer class
#include <iostream>
#include <cstdlib>
using namespace std;

//constructor accepts arguments for building
Customer::Customer()
{
	id = 0;
	firstName = "";
	lastName = "";
	password = 0;
	payment = 0;
	address = "";
	zip = 0;
}
//the other constructor
Customer::Customer(int id, string firstName, string lastName, int password, double payment, string address, float zip){
	this -> id = id;
	this -> firstName = firstName;
	this -> lastName = lastName;
	this -> password = password;
	this -> payment = payment;
	this -> address = address;
	this -> zip = zip;
}
//set customer information
void Customer::setId(int id){
this -> id = id;}

void Customer::setFirstName(string firstName){
this -> firstName = firstName;}

void Customer::setLastName(string lastName){
this -> lastName = lastName;}

void Customer::setPassword(int password){
this -> password = password;}

void Customer::setPayment(double payment){
this -> payment = payment;}

void Customer::setAddress(string address){
this -> address = address;}

void Customer::setZip(float zip){
this -> zip = zip;}

//friend operator that sets array
ostream& operator<< (ostream& strm, const Customer& cus){
	strm << cus.id << " "
		<< cus.firstName << " "
		<< cus.lastName << " "
		<< cus.password << " "
		<< cus.payment << " "
		<< cus.address << " "
		<< cus.zip << " ";
		
return strm;	}

//friend that lets you input into the array
istream& operator>> (istream& strm, Customer& cus)
{
	strm >>cus.id
		>>cus.firstName
		>>cus.lastName
		>>cus.password
		>>cus.payment
		>>cus.address
		>>cus.zip;
return strm;
}
//returns booleans of the returned values
bool Customer::operator==(const Customer& cus){
		return (id = cus.id &&
				firstName == cus.firstName &&
				lastName == cus.lastName &&
				password == cus.password &&
				payment == cus.payment &&
				address == cus.address &&
				zip == cus.zip);
}