#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

using namespace std;

class Customer{
	private:
		int id; //stores customer id
		string firstName; //stores customer's first name
		string lastName; //stores last name
		int password; //password
		double payment; //stores credit/debit card no.
		string address; //stores address
		float zip; 	   //stores zip code
	public:
		Customer(); //constructor
		
		Customer(int, string, string, int, double, string, float);
		
		void setId(int);
		void setFirstName(string); //sets the info
		void setLastName(string);
		void setPassword(int);
		void setPayment(double);
		void setAddress(string);
		void setZip(float);
		
		int getId() const //returns id
		{return id;}
		
		string getFirstName() const//returns first name
		{return firstName;}
		
		string getLastName() const//returns last name
		{return lastName;}
		
		int getPassword() const
		{return password;}
		
		double getPayment() const
		{return payment;}
		
		string getAddress() const{
		return address;}
		
		float getZip () const{
			return zip;}
			
		bool operator==(const Customer&);	//boolean to check if customer already exists
		
		friend ostream& operator<< (ostream&, const Customer&);	//writes into customer database
		friend istream& operator>> (istream&, Customer&); //takes information to friend
}; 
#endif	
