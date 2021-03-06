// bookshopapp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <stdio.h>


using namespace std;


#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <boost/tokenizer.hpp>
#include <string>





int main(int argc, char *argv[])
{
	

		sql::Driver *driver;
		sql::Connection *con;
		sql::ConnectOptionsMap connection_properties;
		

		connection_properties["hostName"] = "tcp://127.0.0.1/";
		connection_properties["port"] = 3306;
		connection_properties["OPT_RECONNECT"] = true;
		sql::Statement *stmt;
		sql::ResultSet *res;
		sql::ResultSet *pres;
		sql::PreparedStatement *pstmt;

		if (argc >= 3) {
			connection_properties["password"] = argv[2];
		}
		if (argc >= 2) {
			connection_properties["userName"] = argv[1];
		}
		else {
			connection_properties["userName"] = "root";
		}

		driver = get_driver_instance();
		/*
		con = driver->connect(connection_properties);
		con->setSchema("bookshop");
		pstmt = con->prepareStatement("SELECT title FROM books");
		res = pstmt->executeQuery();

		// Fetch in reverse = descending order!
		res->afterLast();
		while (res->previous())
			std::cout << "book " << res->getString("title") << endl;

		delete res;

		delete pstmt;
		delete con;
		*/
		//menu


		bool repeat = true;
		int choice = 0;
		while (repeat == true)
		{
			cout << endl
				<< " 1 - click to see all the books that in storage.\n"
				<< " 2 - click to see all the open books orders.\n"
				<< " 3 - click to see all clients.\n"
				<< " 3 - click to see all clients.\n"
				<< " 4 - click to see all suppliers.\n"
				<< " 5 - click to see all Transactions between date:y1 to date:y2.\n"
				<< " 6 - click to see all books that in sale.\n"
				<< " 7 - click to check if specific book x is now available on storage.\n"
				<< " 8 - click to see list of all suppliers of a specific book x.\n"
				<< " 9 - click to see how much copies of a specific book x has been sales since speific date y.\n"
				<< "10 - click to see how much books since specific date y Purchased costumer z.\n"
				<< "11 - click to see costumer details whos been purchased the highest ammount of books in the store since date y.\n" 
				<< "12 - click to see supplier details which has been order from him the highest ammount of books since date y.\n" 
				<< "13 - Click to see how many orders were made between the date y1 and date y2.\n" 
				<< "14 - Click to see how many orders were made between the date y1 and date y2 which eventually turned into sales.\n" 
				<< "15 - Click to see total store revenue during the first, second, third or fourth quarter.\n" 
				<< "16 - Click to see the total discount given to customer Z since date Y.\n"  
				<< "17 - Click to see how many new customers have joined since a specific date y.\n" 
				<< "18 - Click to see the total purchases in NIS from a specific supplier between the dates y1 to y2.\n" 
				<< "19 - Click to see the total sales of a specific seller in the store between the dates y1 to 2.\n" 
				<< "20 - Click to see the top 10 books sold between the dates y1 to y2.\n"
				<< "21 - Exit.\n" << endl


				<< " Enter your choice and press return: " << endl;
			cin >> choice;
			switch (choice)
			{
			case 1:
				con = driver->connect(connection_properties);
				con->setSchema("bookshop");
				pstmt = con->prepareStatement("SELECT title FROM books");
				res = pstmt->executeQuery();
				cout << "hey form case 2" << endl;

				// Fetch in reverse = descending order!
				res->afterLast();
				while (res->previous())
					cout << "The Name of book in storge: " << res->getString("title") << endl;

				delete res;

				delete pstmt;
				delete con;


				break;
			case 2:
				con = driver->connect(connection_properties);
				con->setSchema("bookshop");
				pstmt = con->prepareStatement("SELECT Customer_ID,purchases.Status FROM purchases WHERE purchases.Status NOT LIKE 'buy'");
				res = pstmt->executeQuery();
				// Fetch in reverse = descending order!
				res->afterLast();
				while (res->previous()) {
					cout << " View all open invitations : " << res->getString("Customer_ID") << endl;
					cout << " View all Status of the invitations : " << res->getString("Status") << endl;
				}


				delete res;
				delete pstmt;
				delete con;

				break;
			case 3:

				con = driver->connect(connection_properties);
				con->setSchema("bookshop");
				pstmt = con->prepareStatement("SELECT first_name,last_name FROM customers;");
				
				res = pstmt->executeQuery();
				pres = pstmt->executeQuery();

				// Fetch in reverse = descending order!
				res->afterLast();
				while (res->previous()) {
					cout << " View all the  first name of customers : " << res->getString("first_name") << endl;
					cout << "View all the last name of the customer : " << res->getString("last_name") << endl;
				}
				delete res;
				delete pstmt;
				delete con;

				break;
			case 4:
				con = driver->connect(connection_properties);
				con->setSchema("bookshop");
				pstmt = con->prepareStatement("SELECT first_name,last_name FROM suppliers;");

				res = pstmt->executeQuery();
				pres = pstmt->executeQuery();

				// Fetch in reverse = descending order!
				res->afterLast();
				while (res->previous()) {
					cout << " View all the  first name of Suppliers : " << res->getString("first_name") << endl;
					cout << " View all the last name of the Suppliers : " << res->getString("last_name") << endl;
				}
				delete res;
				delete pstmt;
				delete con;

				break;
			case 5:
				
				con = driver->connect(connection_properties);
				con->setSchema("bookshop");
				pstmt = con->prepareStatement("SELECT Customer_ID, purchases.Status, purchase_date FROM purchases WHERE(purchase_date BETWEEN '1991-01-09'AND'1991-06-06');");
				cout << "hey form case 5" << endl;
				res = pstmt->executeQuery();
				pres = pstmt->executeQuery();

				// Fetch in reverse = descending order!
				res->afterLast();
				while (res->previous()) {

					cout << " View all IDs that made transactions between the specific dates : " << res->getString("Customer_ID") << endl;
					cout << " View all Status that made transactions between the specific dates : " << res->getString("Status") << endl;
				}
				delete res;
				delete pstmt;
				delete con;
				break;
			case 6:
				con = driver->connect(connection_properties);
				con->setSchema("bookshop");
				pstmt = con->prepareStatement("SELECT  distinct books.title  FROM discount,books WHERE global_discount NOT LIKE '0';");
				
				res = pstmt->executeQuery();
				pres = pstmt->executeQuery();

				// Fetch in reverse = descending order!
				res->afterLast();
				while (res->previous()) {
					cout << " View all the name of the books of discounted : " << res->getString("title") << endl;

				}
				delete res;
				delete pstmt;
				delete con;
				break;

				break;
			case 7:
				con = driver->connect(connection_properties);
				con->setSchema("bookshop");
				pstmt = con->prepareStatement("SELECT s_number FROM Storge WHERE storge.IsExistsInStorge = 'YES' AND Storge.s_number = 1;");

				res = pstmt->executeQuery();
				pres = pstmt->executeQuery();

				// Fetch in reverse = descending order!
				res->afterLast();
				while (res->previous()) {
					cout << " View all the ID are in stock: " << res->getInt("s_number") << endl;
				}
				delete res;
				delete pstmt;
				delete con;
				break;

				break;
			case 8:
				con = driver->connect(connection_properties);
				con->setSchema("bookshop");
				pstmt = con->prepareStatement("SELECT first_name,last_name FROM Suppliers WHERE s_number = 1;");

				res = pstmt->executeQuery();
				//pres = pstmt->executeQuery();

				// Fetch in reverse = descending order!
				res->afterLast();
				while (res->previous()) {
					cout << " Displays the vendor's first name that supplies the book X : " << res->getString("first_name") << endl;
					cout << " Displays the vendor's last name that supplies the book X : " << res->getString("last_name") << endl;
				}
				delete res;
				delete pstmt;
				delete con;

				break;
			case 9:
				con = driver->connect(connection_properties);
				con->setSchema("bookshop");
				pstmt = con->prepareStatement("SELECT s_number FROM purchases WHERE purchase_date >='1990-02-01' AND purchases.Status='buy' AND purchases.s_number=6;");

				res = pstmt->executeQuery();
				pres = pstmt->executeQuery();

				// Fetch in reverse = descending order!
				res->afterLast();
				while (res->previous()) {
					cout << " Display some copies of the book x sold as of y : " << res->getInt("HowMuchItemsPerCustomer") << endl;
				}
				delete res;
				delete pstmt;
				delete con;

				break;
			case 10:
				con = driver->connect(connection_properties);
				con->setSchema("bookshop");
				pstmt = con->prepareStatement("SELECT Order_To_Customer.Customer_ID,Order_To_Customer.HowMuchItemsPerCustomer,Customers.first_name,Customers.last_name FROM Order_To_Customer ,Customers WHERE Order_To_Customer.DateOrder ='2017-02-02' AND Customers.Customer_ID = 1 ;");
				res = pstmt->executeQuery();
				pres = pstmt->executeQuery();

				// Fetch in reverse = descending order!
				res->afterLast();
				while (res->previous()) {
					cout << " Display some copies of the book x sold as of y : " << res->getInt("Customer_ID") << endl;
					cout << " Display some copies of the book x sold as of y : " << res->getInt("HowMuchItemsPerCustomer") << endl;
					cout << " Display some copies of the book x sold as of y : " << res->getString("first_name") << endl;
					cout << " Display some copies of the book x sold as of y : " << res->getString("last_name") << endl;
				}
				delete res;
				delete pstmt;
				delete con;

				break;
			case 11:

				con = driver->connect(connection_properties);
				con->setSchema("bookshop");
				pstmt = con->prepareStatement("SELECT MAX(Customer_ID) FROM purchases WHERE purchases.Status='buy'  AND purchases.purchase_date >='1990-02-01';");
				res = pstmt->executeQuery();
				pres = pstmt->executeQuery();

				// Fetch in reverse = descending order!
				res->afterLast();
				while (res->previous()) {
					cout << " Display some copies of the book x sold as of y : " << res->getInt("Customer_ID") << endl;
					cout << " Display some copies of the book x sold as of y : " << res->getInt("HowMuchItemsPerCustomer") << endl;
					cout << " Display some copies of the book x sold as of y : " << res->getString("first_name") << endl;
					cout << " Display some copies of the book x sold as of y : " << res->getString("last_name") << endl;
				}
				delete res;
				delete pstmt;
				delete con;

				break;

				break;
			case 12:

				con = driver->connect(connection_properties);
				con->setSchema("bookshop");
				pstmt = con->prepareStatement("SELECT  MAX(order_from_suppliers.HowMuchItemsHasOrdered),suppliers.first_name,suppliers.last_name ,Order_from_suppliers.supplier_id FROM suppliers,order_from_suppliers WHERE order_from_suppliers.DateSupplierOrder >='2013-04-02';");
				res = pstmt->executeQuery();
				pres = pstmt->executeQuery();
				
				// Fetch in reverse = descending order!
				res->afterLast();
				while (res->previous()) {
					cout << " View the supplier details from which the most books have been ordered since Y How Much Iteam Has Ordered : " << res->getInt("MAX(order_from_suppliers.HowMuchItemsHasOrdered)") << endl;
					cout << " View the supplier details from which the most books have been ordered since Y First Name : " << res->getString("first_name") << endl;
					cout << " View the supplier details from which the most books have been ordered since Y Last Name : " << res->getString("last_name") << endl;
					cout << " View the supplier details from which the most books have been ordered since Y Id : " << res->getInt("supplier_id") << endl;
				}
				delete res;
				delete pstmt;
				delete con;

				break;
			case 13:

				con = driver->connect(connection_properties);
				con->setSchema("bookshop");
				pstmt = con->prepareStatement("SELECT SUM(OrderSupplierNumber) FROM Order_From_Suppliers WHERE DateSupplierOrder BETWEEN '2011-01-08' AND '2013-04-02';");
				res = pstmt->executeQuery();
				pres = pstmt->executeQuery();

				// Fetch in reverse = descending order!
				res->afterLast();
				while (res->previous()) {
					cout << " View the supplier details from which the most books have been ordered since Y How Much Iteam Has Ordered : " << res->getInt("SUM(OrderSupplierNumber)") << endl;
				}
				delete res;
				delete pstmt;
				delete con;

				break;
			case 14:
				con = driver->connect(connection_properties);
				con->setSchema("bookshop");
				pstmt = con->prepareStatement("SELECT SUM(s_number) FROM purchases WHERE purchase_date BETWEEN '1991-12-01' AND '2015-08-13' AND purchases.Status='buy'; ");
				res = pstmt->executeQuery();
				pres = pstmt->executeQuery();

				// Fetch in reverse = descending order!
				res->afterLast();
				while (res->previous()) {
					cout << " Displays all orders between a certain date and a date X that have become sales : " << res->getInt("SUM(s_number)") << endl;
				}
				delete res;
				delete pstmt;
				delete con;

				break;
			case 15:
				con = driver->connect(connection_properties);
				con->setSchema("bookshop");
				pstmt = con->prepareStatement("SELECT SUM(Amount)/3 FROM Business_revenue WHERE business_revenue.quarterr=1;");
				res = pstmt->executeQuery();
				pres = pstmt->executeQuery();

				// Fetch in reverse = descending order!
				res->afterLast();
				while (res->previous()) {
					cout << " View all Q1 revenues : " << res->getInt("SUM(Amount)/3") << endl;
				}
				delete res;
				delete pstmt;
				delete con;

				con = driver->connect(connection_properties);
				con->setSchema("bookshop");
				pstmt = con->prepareStatement("SELECT SUM(Amount)/3 FROM Business_revenue WHERE business_revenue.quarterr=2;");
				res = pstmt->executeQuery();
				pres = pstmt->executeQuery();

				// Fetch in reverse = descending order!
				res->afterLast();
				while (res->previous()) {
					cout << " View all Q2 revenues : " << res->getInt("SUM(Amount)/3") << endl;
				}
				delete res;
				delete pstmt;
				delete con;

				con = driver->connect(connection_properties);
				con->setSchema("bookshop");
				pstmt = con->prepareStatement("SELECT SUM(Amount)/3 FROM Business_revenue WHERE business_revenue.quarterr=3;");
				res = pstmt->executeQuery();
				pres = pstmt->executeQuery();

				// Fetch in reverse = descending order!
				res->afterLast();
				while (res->previous()) {
					cout << " View all Q3 revenues : " << res->getInt("SUM(Amount)/3") << endl;
				}
				delete res;
				delete pstmt;
				delete con;

				con = driver->connect(connection_properties);
				con->setSchema("bookshop");
				pstmt = con->prepareStatement("SELECT SUM(Amount)/1 FROM Business_revenue WHERE business_revenue.quarterr=4;");
				res = pstmt->executeQuery();
				pres = pstmt->executeQuery();

				// Fetch in reverse = descending order!
				res->afterLast();
				while (res->previous()) {
					cout << " View all Q4 revenues : " << res->getInt("SUM(Amount)/1") << endl;
				}
				delete res;
				delete pstmt;
				delete con;

				break;
			case 16:
				con = driver->connect(connection_properties);
				con->setSchema("bookshop");
				pstmt = con->prepareStatement("SELECT SUM(discount.local_discount)/10 FROM discount,Order_To_Customer WHERE Order_To_Customer.DateOrder = '2016-04-05' AND Order_To_Customer.Customer_ID = 3 ; ");
				res = pstmt->executeQuery();
				pres = pstmt->executeQuery();

				// Fetch in reverse = descending order!
				res->afterLast();
				while (res->previous()) {
					cout << " Total discount received by customer Z since date Y in shekels  : " << res->getInt("SUM(discount.global_discount)") << endl;
				}
				delete res;
				delete pstmt;
				delete con;

				break;
			case 17:
				con = driver->connect(connection_properties);
				con->setSchema("bookshop");
				pstmt = con->prepareStatement("SELECT COUNT(Customer_ID) FROM Customers WHERE  Join_Date >='1991-04-06'; ");
				res = pstmt->executeQuery();
				pres = pstmt->executeQuery();

				// Fetch in reverse = descending order!
				res->afterLast();
				while (res->previous()) {
					cout << " View all new customers who have joined since the date :  " << res->getInt("COUNT(Customer_ID)") << endl;
				}
				delete res;
				delete pstmt;
				delete con;

				break;
			case 18:
				con = driver->connect(connection_properties);
				con->setSchema("bookshop");
				pstmt = con->prepareStatement("SELECT SUM(order_from_suppliers.Price) FROM order_from_suppliers,purchases WHERE purchases.purchase_date BETWEEN '1991-12-01' AND '1993-03-01' AND purchases.Status='buy'; ");
				res = pstmt->executeQuery();
				pres = pstmt->executeQuery();

				// Fetch in reverse = descending order!
				res->afterLast();
				while (res->previous()) {
					cout << " Shows all purchases from a particular vendor between date X and Y : " << res->getInt("SUM(order_from_suppliers.Price)") << endl;
				}
				delete res;
				delete pstmt;
				delete con;

				break;
			case 19:
				con = driver->connect(connection_properties);
				con->setSchema("bookshop");
				pstmt = con->prepareStatement("SELECT SUM(sales),firstName,lastName FROM worker WHERE selling_date = '2017-02-01' AND WorkerNumber = 1;");
				res = pstmt->executeQuery();
				pres = pstmt->executeQuery();

				// Fetch in reverse = descending order!
				res->afterLast();
				while (res->previous()) {
					cout << " View all Sales of employee : " << res->getInt("SUM(sales)") << endl;
					cout << " View all First Name of employee : " << res->getString("firstName") << endl;
					cout << " View all Last Name of employee : " << res->getString("lastName") << endl;
				}
				delete res;
				delete pstmt;
				delete con;
				break;
			case 20:

				con = driver->connect(connection_properties);
				con->setSchema("bookshop");
				pstmt = con->prepareStatement("SELECT DISTINCT books.title FROM books,purchases WHERE purchases.purchase_date BETWEEN '1991-12-01' AND '1993-03-01' AND  purchases.Status ='buy' ORDER BY title; ");
				res = pstmt->executeQuery();
				pres = pstmt->executeQuery();
		
				// Fetch in reverse = descending order!
				res->afterLast();
				while (res->previous()) {
					cout << " List All the most popular books from date X to date Y :  " << res->getString("title") << endl;
				}
				delete res;
				delete pstmt;
				delete con;

				break;
			case 21:
				cout << "End of Program.\n";
				repeat = false;

				break;
			default:
				cout << "Not a Valid Choice. \n"
					<< "Choose again.\n";
				break;

			}
		}



	
}

