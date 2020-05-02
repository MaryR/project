//this is the software engineering 240 code for the final project of group 4

#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include "Customer.h"
#include "CustomerList.h"

using namespace std;

//function prototypes
void addNewCustomers(CustomerList& CustomerDatabase, int& COUNT, Customer& s);
void signUp(CustomerList& CustomerDatabase, int& COUNT, Customer& s);
void deleteCustomer(CustomerList& CustomerDatabase, Customer& s, int& COUNT);
void displayCustomers(CustomerList& CustomerDatabase, CustomerList& searchCustomer, Customer& s, int COUNT);
void menu (CustomerList& CustomerDatabase, int& COUNT, Customer& s, CustomerList& searchCustomer);
bool logIn(CustomerList& CustomerDatabase);
int getOrder();
int toppings();

//global constants
int empPassword = 0000;

//****************************************************
//This function is the menu for the employee database*
//****************************************************

void mainMenu (CustomerList& CustomerDatabase, int& COUNT, Customer& s, CustomerList& searchCustomer)
{
	//variable declaration
	int y;
	int attempt;
	bool login;
	int price;
	
	do {	//do while loop for looping the switch statment
	
	cout << setw(30) << "--Luigi's pizza--" << endl;
	cout << setw(29) << "Main menu" << endl;
	
	cout <<"1.  Choose a pizza." << endl;
	cout <<"2.  Order a pizza." <<endl;
	cout <<"3.  Log in." << endl;
	cout <<"4.  Sign up" << endl;
	cout <<"5.  Employee access-customer database." << endl;
	cout <<"6.  Exit system."<<endl;
	
	
	cout << endl;	//for formatting space
	cout << endl;
	cout << "Enter your option" << endl;
	cin >> y;	//choice of option to use in the switch statment
	//space between text for readability
	cout << endl;
	cout << endl;
	
	
	//switch statement for picking which menu feature to use
	switch(y){
		case 1 :
			// choose pizza from pizza list
			toppings();

			break;	//breaks loop
		case 2 :
			//make an order
			price = getOrder();
			cout<<"The total for your order is "<< price <<endl;
			break;
		case 3 :
			//log in
			login = logIn(CustomerDatabase);
			if(login = true) {
					cout<<"You have successfully logged in"<<endl;
			}else{
				cout<<"your information is invalid, please sign up."<<endl; }
			break;
		case 4 :
			//sign up
			signUp(CustomerDatabase, COUNT, s);
			cout<<"you have successfully signed up! "<<endl;
			cout<<endl;
			cout<<endl;
			
			
			break;
		case 5 :
			//employee access to customer database modification
			cout<<"this is where employees can alter information stored in the customer database for administration "<<endl;
			cout<<endl;
			cout<<"enter INTEGER password to continue: "<<endl;
			cin>>attempt;
				if(attempt == empPassword){
			
					menu(CustomerDatabase, COUNT, s, searchCustomer);
				}else{
				break;}
			break;
		case 6 :
			//leave the system
			
				cout << "Thank you for using Luigi's pizza. " << endl;
				cout <<endl;
				cout <<endl;
	
			break;
		default :
			cout << "Invalid selection, try again." << endl;
	}
	
	}	while (y != 6); //breaks menu if 5 is selected.
}

//****************************************************
//This function is the menu for the employee database*
//****************************************************

void menu (CustomerList& CustomerDatabase, int& COUNT, Customer& s, CustomerList& searchCustomer)
{
	//variable declaration
	int y;
	
	do {	//do while loop for looping the switch statment
	
	cout << setw(30) << "--Luigi's pizza--" << endl;
	cout << setw(29) << "Employee database" << endl;
	
	cout <<"1.  Add new customers to database." << endl;
	cout <<"2.  Delete customers from the database." << endl;
	cout <<"3.  Display customer data to the screen." << endl;
	cout <<"4.  Quit the system." << endl;
	
	cout << endl;	//for formatting space
	cout << endl;
	cout << "Enter your option" << endl;
	cin >> y;	//choice of option to use in the switch statment
	//space between text for readability
	cout << endl;
	cout << endl;
	
	
	//switch statement for picking which menu feature to use
	switch(y){
		case 1 :
			//Add new Customers to the database
			
			addNewCustomers(CustomerDatabase, COUNT, s);
			

			break;	//breaks loop
		case 2 :
			//Delete customers from the database
			
			deleteCustomer(CustomerDatabase, s, COUNT);
			
			break;
		case 3 :
			//Display Customer data to the screen
			
			displayCustomers(CustomerDatabase, searchCustomer, s, COUNT);
	
			break;
		case 4 :
			//leave the system
			
				cout << "Thank you for using Luigi's pizza. " << endl;
	
			break;
		default :
			cout << "Invalid selection, try again." << endl;
	}
	
	}	while (y != 4); //breaks menu if 5 is selected.
}
// * * * * * * * * * * * * * * *
//T H I S  I S  T H E  M A I N *
// * * * * * * * * * * * * * * *
int main ()
{	
	int x, L;	//variable declarations
	int COUNT = 0; // count for temporary number of Customers added or deleted in main program.
	CustomerList CustomerDatabase;	//access to Customer database
	CustomerList searchCustomer;	//access to search Customer
	CustomerList searchCustomer2; //access to second search customer
	Customer s ;	//stores Customer info temporarily.
	int id;
	string firstname;	//temp first name holder
	string lastname;
	int password;
	double payment;
	string address;
	float zip;
	
	//calls the menu
			mainMenu (CustomerDatabase, COUNT, s, searchCustomer);
		
	
	
	
	cout << endl;	//formatting for readability
	cout << endl;

	
		
return 0;
}

//***************
//add customers *
//***************

void addNewCustomers(CustomerList& CustomerDatabase, int& COUNT, Customer& s){
	
	//variable declarations
	char answ;	//asks if want to continue
	bool flag;	//flag for testing if Customer have already been added.
	
	cout<< "Enter Customers by way of ID, first name, last name, password, payment, address, and zip code do not add spaces in the address" << endl;
	cout << "for example, 12333rdstreetnorth "<<endl;
		for (int i=-1; i< COUNT; ++i){ //for loop for adding to an array
			//get one Customer
			cin >> s;
				flag = CustomerDatabase.addCustomer(s);	//this flag tests if entered Customer information is the same as Customer information already stored
					if(flag == false){
								cout<<"This Customer already exists in the database.  Add another?"<<endl;
										cin >> answ;	//if you want to enter more Customer even though you messed this one up.
										if(answ == 'y' || answ == 'Y'){	//yes makes the program ask you to enter it again, but correctly this time.
										cout << "Enter Customer ID, first name, last name, password payment, address and zip code." << endl;
										}else{
										return;}	//get out of this function if you don't want to enter anymore people.
					}else{
						 
			//add to database
		CustomerDatabase.addCustomer(s);	//this is what actually writes the information into the Customer database
		COUNT++;	//counts to keep track of Customer added
						cout << "Do you want to enter additional Customer to the database? y/n" << endl;	//loop for allowing more Customer information to be entered
						cin >> answ;	//same question as before, but instead of asking after you entered incorrectly it asks after you've entered correctly.
									if(answ == 'y' || answ == 'Y'){
		cout << "Enter Customer information by ID, First name, last name, password, payment, address and zip code." << endl;
									}else{
									return;}	//leaves the function and returns to the menu.
									}
}	}

//* * * * * ******** * * * * * *
//D E L E T E  C U S T O M E R *
//* * * * * ******** * * * * * *
//@pre menu selected delete Customer
//@post selected Customer removed from database
void deleteCustomer(CustomerList& CustomerDatabase, Customer& s, int& COUNT){
	
	char ans;	//variable declarations
	bool flag2;
	int counter = 1;
	
	cout << "Enter the Customer to be deleted by ID, first name, last name, password, payment, address and zip code.  do not add spaces in the address"<<endl;
		for (int i=0; i< counter; ++i){			//this function works on the same principle as the add Customer function
			//get one Customer					//the only difference is that it works on it's own counter, otherwise the for loop wouldn't function
			cin >> s;							//properly.  here you get your Customer information for deletion
				flag2 = CustomerDatabase.deleteCustomer(s);
					if(flag2 == false){	//test to see if the Customer exists and can be deleted.
								cout<<"This Customer doesn't exist in the database.  Delete another?"<<endl;
										cin >> ans;
										if(ans == 'y' || ans == 'Y'){
										cout << "Enter Customer ID, first name, last name, password, payment, address and zip code." << endl;
										counter++;
										}else{
										return;}
					}else{
						 
			//delete from database
		CustomerDatabase.deleteCustomer(s);
		COUNT--;
		counter ++;
						cout << "Do you want to delete another Customer y/n" << endl;	//loop for allowing more employees information to be entered
						cin >> ans;
									if(ans == 'y' || ans == 'Y'){
									
		cout << "Enter the customer to be deleted by first name, last name, password, payment, address and zip code."<<endl;
									} else{
									return;}
									}
}	}	


//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\
//D I S P L A Y   C U S T O M E R \
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\
//@pre-The Customer information remains undisplayed, and you don't know what you have
//@post-Would you look at that, there's your Customer information.
void displayCustomers(CustomerList& CustomerDatabase, CustomerList& searchCustomer, Customer& s, int COUNT){
	cout<<"That database now has"<<endl;
			for (int i=0; i<COUNT; ++i)	//for loop that displays all available Customer information
			cout<<CustomerDatabase.searchCustomer(i)<<endl;
			cout << endl; }
//***************
//sign up       *
//***************

void signUp(CustomerList& CustomerDatabase, int& COUNT, Customer& s){
	
	//variable declarations
	char answ;	//asks if want to continue
	bool flag;	//flag for testing if Customer have already been added.
	
	cout<< "Enter your information by way of ID number, first name, last name, password(all integers for a password), payment, address, and zip code do not add spaces in the address" << endl;
	cout << "for example, 12333rdstreetnorth "<<endl;
		for (int i=-1; i< COUNT; ++i){ //for loop for adding to an array
			//get one Customer
			cin >> s;
				flag = CustomerDatabase.addCustomer(s);	//this flag tests if entered Customer information is the same as Customer information already stored
					if(flag == false){
								cout<<"This Customer already exists in the database.  try again?"<<endl;
										cin >> answ;	//if you want to enter more Customer even though you messed this one up.
										if(answ == 'y' || answ == 'Y'){	//yes makes the program ask you to enter it again, but correctly this time.
										cout << "Enter Customer ID, first name, last name, password payment, address and zip code." << endl;
										}else{
										return;}	//get out of this function if you don't want to enter anymore people.
					}else{
						 
			//add to database
					CustomerDatabase.addCustomer(s);}//this is what actually writes the information into the Customer database
					COUNT++;
					return;

}	}
//*************
// L O G I N N*
//**************
bool logIn(CustomerList& CustomerDatabase){
	
	int index;	//variable declarations
	int location;
	char answer, yn;
	int loginPassword;
	int passwordIndex;
	
	
	do{	//do while loop in case you want to modify more than one employee's stored information
	cout<<"Enter customer ID to log in"<< endl;
	cin>>location;	//find location uses this to get the index of the employee's information by just the ID
	index = CustomerDatabase.findLocation(location);
		while(index == -1){	//If the find location doesn't find the name in the database, it returns -1 and the ID does not exist.
				cout<<"No such customer, enter a different name? y/n"<<endl;
				cin>>yn;	//condition that tests if you want to leave the function after unsuccessfully searching for name
					if (yn == 'n' || yn == 'N'){
					return false;
					} else {
					cout<<"Enter id to log in"<<endl; }
				cin>>location;
				index = CustomerDatabase.findLocation(location); }	//if you want to try again after the first unsuccessful search
	cout<<"enter password"<<endl;
	cin>>loginPassword;
	passwordIndex = CustomerDatabase.findLocation2(loginPassword);
		if(passwordIndex == index){
				return true;
		}else{
			return false;}

}while(answer == 'y' || answer == 'Y');
}
//
//order function
//
int getOrder(){
	
	/////////////this is variables what
	string Fname;
	string Lname;
	string addy;
	int toppings = .5;
	int order;
	int total;
	
	cout<<"enter first name"<<endl;
	cin>>Fname;
	
	cout<<"enter last name"<<endl;
	cin>>Lname;
	
	cout<<"enter address "<<endl;
	cin>>addy;
	
	cout<<"Enter number of toppings"<<endl;
	cin>>order;
	
	total = order * toppings;
	
return total;
}
// * * * * * * * * * * * * * * *
//T H I S  I S  topings database *
// * * * * * * * * * * * * * * *
int toppings ()
{	
	const int SIZE = 50; //array size
	char Array[SIZE]; //holds file array
	int counter = 0;
	
	char any;
	ifstream inFile;
	
	
	//open file
	inFile.open("toppings.txt");
	if(inFile.is_open()){
			for(int j = 0; j < SIZE; ++j){
	while(	inFile.get(Array, SIZE)) {
	
	
	
	

	cout << "These are the toppings" << endl;
	for (int display = 0; display < SIZE; display++){
		cout<<Array[display]; }
	
	
	//close file
	inFile.close(); }
	}}
	
return 0;
}
	