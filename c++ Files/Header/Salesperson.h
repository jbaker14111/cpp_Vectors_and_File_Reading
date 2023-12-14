#include <string>
#include <vector>
#include <algorithm>

class SalesPerson {
public:
	SalesPerson();
	//default constructor
	//Postcondition: name = UNKOWN
	//				 dealership = UNKOWN
	//				 salesGoal = 0
	//				 commissionPerc = 0

	SalesPerson(std::string);
	//constructor with one parameter
	//Postcondition: name = parameter 1
	//				 dealership = UNKOWN
	//				 salesGoal = 0
	//				 commissionPerc = 0
	SalesPerson(std::string, std::string);
	//constructor with two parameters
	//Postcondition: name = parameter 1
	//				 dealership = parameter 2
	//				 salesGoal = 0
	//				 commissionPerc = 0
	SalesPerson(std::string, std::string, int);
	//constructor with three parameters
	//Postcondition: name = parameter 1
	//				 dealership = parameter 2
	//				 salesGoal = parameter 3
	//				 commissionPerc = 0
	SalesPerson(std::string, std::string, int, double);
	//constructor with four parameters
	//Postcondition: name = parameter 1
	//				 dealership = parameter 2
	//				 salesGoal = parameter 3
	//				 commissionPerc = parameter 4

	void setName(std::string);
	//function that sets name variable in private
	//Postcondtion: name = parameter

	std::string getName() const;
	//function that returns private variable "name"
	//Postcondition: returns string "name"
	void setDealership(std::string);
	//function that sets dealership variable
	//Postcondition: dealership = parameter

	std::string getDealership() const;
	//returns private variable "dealership" 
	//Postcondition: return string "dealership

	void setGoal(int);
	//function that sets salesGoal 
	//Postcondition: salesGoal = parameter

	int getGoal() const;
	//function that returns salesGoal 
	//Postcondition: return integer "salesGoal"

	void setCommission(double);
	//function that sets commission percentage into variable "commissionPerc"
	//Postcondition: commissionPerc = parameter

	double getCommission() const;
	//function that returns commission percentage
	//Postcondition: return double "comissionPerc"

	void addSalesAmmount(int);
	//function that adds integer to vector quantity "sales" through push_back 
	//Postcondition: parameter appended to sales

	void sortSalesAmmounts();
	//function that sorts sales low to high ammounts through the function "sort"
	//Postcondition: sorts sales variables lowest to highest

	double calcAverageSale() const;
	//function that calculates the average of all the variables in sales and returns it
	//Is calculated by adding all the sales together, than dividing that by amount of sales
	//Postcondition: return average of all sales

	int getSmallestSale() const;
	//function that finds the smallest variable within sales
	//does this by searching through entire list for smallest entry
	//Postcondition: return smallest variable in sales

	int getLargestSale() const;
	//function that finds the largest variable within sales
	//does this by searching through entire list for largest entry
	//Postcondition: return largest variable in sales

	int getNumberSales() const;
	//function that gets the total number of sales
	//does this by using the size function for vectors
	//Postcondition: return vector "sales" size

	int calcTotalSales() const;
	//function that calculates sum of all sales
	//does this by adding all variables in sales vector through a for loop
	//Postcondition: return sum of all sales

	double calcCommissionEarned() const;
	//function that calculates commission earned
	//uses equation (sum of all sales * commission percentage)
	//Postcondition: return commission earned

	void displaySalesInfo();
	//function that displays all information about Salesperson 
	//Postcondition: output variables for user to see
private:
	std::vector<int> sales; //vector variable to store all sales
	std::string name; //string variable to store name of salesman
	std::string dealership; //string variable to store name of dealership
	int salesGoal; //integer variable to store sales goal
	double commissionPerc; //double variable to store commission percentage
};
