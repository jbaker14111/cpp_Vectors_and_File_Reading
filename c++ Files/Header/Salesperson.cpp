#include "Salesperson.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;


SalesPerson::SalesPerson() { //default constructor
	name = "UNKOWN";
	dealership = "UNKOWN";
	salesGoal = 0;
	commissionPerc = 0;
}
SalesPerson::SalesPerson(std::string n) { //one parameter constructor
	name = n;
	dealership = "UNKOWN";
	salesGoal = 0;
	commissionPerc = 0;
}
SalesPerson::SalesPerson(std::string n, std::string dealer) {//two parameter constructor
	name = n;
	dealership = dealer;
	salesGoal = 0;
	commissionPerc = 0;
}
SalesPerson::SalesPerson(std::string n, std::string dealer, int sale) {//three parameter constructor
	name = n;
	dealership = dealer;
	salesGoal = sale;
	commissionPerc = 0;
}
SalesPerson::SalesPerson(std::string n, std::string dealer, int sale, double com) {//four parameter constructor

	name = n;
	dealership = dealer;
	salesGoal = sale;
	commissionPerc = com;

}

void SalesPerson::setName(std::string n) {//sets private variable "name" equal to n
	name = n;
}
std::string SalesPerson::getName() const {//returns name for public access
	return name;
}
void SalesPerson::setDealership(std::string deal) {//sets private variable "dealership" equal to deal
	dealership = deal;
}
std::string SalesPerson::getDealership() const {//return dealership for public access
	return dealership;
}
void SalesPerson::setGoal(int goal) {//sets private variable "salesGoal" equal to goal
	salesGoal = goal;
}
int SalesPerson::getGoal() const {//returns salesGoal for public access
	return salesGoal;
}
void SalesPerson::setCommission(double com){//sets private variable "commissionPerc" equal to com
	commissionPerc = com;
}
double SalesPerson::getCommission() const {//returns commissionPerc for public access
	return commissionPerc;
}
void SalesPerson::addSalesAmmount(int s) {//add integer to private, vector variable "sales"
	sales.push_back(s);
}
void SalesPerson::sortSalesAmmounts() {//sorts sales vector from lowest to highest
	sort(sales.begin(), sales.end());
}

double SalesPerson::calcAverageSale() const{//finds the average of the sales vector and returns it
	double sum = 0;
	for (int i : sales) {
		sum += i;
	}
	 return (sum / static_cast<double>(sales.size()));
}

int SalesPerson::getSmallestSale() const { //returns smallest value in sales vector
	int lowest = sales[0];
	for (int i = 0; i < sales.size(); i++) {
		if (sales[i] < lowest) {
			lowest = sales[i];
		}
	}
	return lowest;
}
int SalesPerson::getLargestSale() const { //returns largest value in sales vector
	int highest = sales[0];
	for (int i = 0; i < sales.size(); i++) {
		if (sales[i] > highest) {
			highest = sales[i];
		}
	}
	return highest;
}
int SalesPerson::getNumberSales() const{ //returns size of sales vector
	return sales.size();
}

int SalesPerson::calcTotalSales() const { //sums all sales together and returns it
	int sum = 0;
	for (int i : sales) {
		sum += i;
	}
	return sum;
}

double SalesPerson::calcCommissionEarned() const {//calculates commission earned and returns it
									//uses equation (total sales amount * commission percentage)
	return (static_cast<double>(calcTotalSales()) * (commissionPerc / 100));
}
void SalesPerson::displaySalesInfo() {//displays all information for class SalesPerson for user
	int w = 25;
	cout << setw(w) << "Dealership: " << dealership << endl;
	cout << setw(w) << "Sales Person: " << name << endl;
	cout << setw(w) << "Sales Goal: " << salesGoal << endl;
	cout << setw(w) << "Total Sales: " << calcTotalSales() << endl;
	cout << setw(w) << "Number of Sales: " << getNumberSales() << endl;
	cout << setw(w) << "Average Sale: " << calcAverageSale() << endl;
	cout << setw(w) << "Commission Percentage: " << commissionPerc << endl;
	cout << setw(w) << "Commission Earned: " << calcCommissionEarned() << endl;
	cout << setw(w) << "Smallest Sale: " << getSmallestSale() << endl;
	cout << setw(w) << "Largest Sale: " << getLargestSale() << endl;
	cout << setw(w) << "list of Sorted Sales:" << endl;
	sortSalesAmmounts();
	for (int i : sales) {
		cout << setw(w) << i << endl;
	}
}