// <Lab 3 - Vector Assignment> -- Create a class"SalesPerson" and create a vector list with sales in it
//CSIS 112-<D01>
/*
this program will use the class SalesPerson to take input from a file and output the sales 
of the salesman to the terminal for the user's review
*/

#include "./Header/Salesperson.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

//function prototypes
void returnFileName(string& fileName);
bool returnSalesman(ifstream& file, string& salesman);
bool returnDealership(ifstream& file, string& dealership);
bool returnSalesGoal(ifstream& file, int& salesGoal);
bool returnCommissionPerc(ifstream& file, double& commissionPerc);
bool returnSales(ifstream& file, SalesPerson& person);

int main() {
	
	//Variable Declarations
	SalesPerson person;
	ifstream inFile;
	string fileName;
	string salesman;
	string dealership;
	int salesGoal;
	double commissionPerc;
	returnFileName(fileName);//get valid file name
	inFile.open(fileName);
	//functions to get input from file and check for errors
	if (returnSalesman(inFile, salesman)) {
		if (returnDealership(inFile, dealership)) {
			if (returnSalesGoal(inFile, salesGoal)) {
				if (returnCommissionPerc(inFile, commissionPerc)) {
					if (returnSales(inFile, person)) {
						/*
						if all of the data is entered correctly, it is then set into the SalesPerson
						class and then displayed to the terminal
						*/
						person.setName(salesman);
						person.setDealership(dealership);
						person.setGoal(salesGoal);
						person.setCommission(commissionPerc);
						cout << endl << endl;
						person.displaySalesInfo();
						cout << endl << endl;
						system("pause");
					}
				}

			}
		}
	}
	return 0;
}



void returnFileName(string &fileName) {//returns file name after checking for errors in user input
	cout << "Enter File Name: ";
	ifstream inFile;
	getline(cin, fileName);
	inFile.open(fileName);
	if (inFile.fail()) {
		cout << "We could not find a file with that name. Please try again." << endl;
		returnFileName(fileName);
	}
	inFile.close();
}

bool returnSalesman(ifstream& file, string& salesman) { //gets salesman name
	if (file.eof()) {
		cout << "No salesman name included. Please include salesman name in file and try again." << endl;
		system("pause");
		return false;
	}
	getline(file, salesman);
	return true;
}

bool returnDealership(ifstream& file, string& dealership) { //gets dealership name
	if (file.eof()) {
		cout << "No dealership name included. Please include dealership name in file and try again." << endl;
		system("pause");
		return false;
	}
	getline(file, dealership);
	return true;
}

bool returnSalesGoal(ifstream& file, int& salesGoal) { //gets sales goal after checking for input error
	
	if (file.eof()) {
		cout << "No sales goal included. Please include sales goal in file and try again." << endl;
		system("pause");
		return false;
	}
	file >> salesGoal;
	
	if (file.fail()) {
		system("cls");
		cout << "A letter was entered rather than a number. Please modify the file " << endl <<
			"so that the THIRD line containes a number." << endl;
		system("pause");
		return false;
	}
	else if (salesGoal < 0) {
		system("cls");
		cout << "A negative number was entered rather than a positive. Please modify " << endl <<
			"the file so that the THIRD line has a positive number." << endl;
		system("pause");
		return false;
	}
	else {
		return true;
	}

}

bool returnCommissionPerc(ifstream& file, double& commissionPerc) { //gets commission percentage after checking for input error
	
	if (file.eof()) {
		cout << "No commission percentage included. Please include commission percentage in file and try again." << endl;
		system("pause");
		return false;
	}
	file >> commissionPerc;

	if (file.fail()) {
		system("cls");
		cout << "A letter was entered rather than a number. Please modify the file " << endl <<
			"so that the FOURTH line containes a number." << endl;
		system("pause");
		return false;
	}
	else if (commissionPerc < 0) {
		system("cls");
		cout << "A negative number was entered rather than a positive. Please modify " << endl <<
			"the file so that the FOURTH line has a positive number." << endl;
		system("pause");
		return false;
	}
	else {
		return true;
	}
}

bool returnSales(ifstream& file, SalesPerson& person) { //checks each sale for input error, and if error free, inputs it into SalesPerson
	bool noErrors = true;
	if (file.eof()) {
		noErrors = false;
		cout << "No sales included. Please include sales in file and try again." << endl;
		system("pause");
	}
	while (!file.eof() && noErrors) {
		int sale;
		file >> sale;
		if (file.fail()) {
			system("cls");
			cout << "A letter was entered in for one of the sales, or the there is an empty line at the end of the file. Please correct" << endl <<
				"this and try again." << endl;
			system("pause");
			noErrors = false;
		}
		else if (sale < 0) {
			cout << "A negative number was entered in for one of the sales. Please" << endl <<
				"correct this and try again." << endl;
			system("pause");
			noErrors = false;
		}
		else {
			person.addSalesAmmount(sale);
		}
	}
	if (noErrors) {
		return true;
	}
	else {
		return false;
	}
}