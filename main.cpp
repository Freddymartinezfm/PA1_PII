// The purpose o
#include "Search_tree.h"
#include "Employee.h"
#include <string>
#include <iomanip>
#include <iostream>
#include "OnOptionsMenu.h"
#include <cstring>
#include <fstream>
#include <string>


void getRawData();
Error_code simpleSearch();
const int MAX_CAPACITY {22};
Employee *list [MAX_CAPACITY];
const std::string fileName = "employees.txt";

int main(){
	getRawData();
	bool running = true;

	while (running){
		OnOptionsMenu menuOptions("Search Menu");
		menuOptions.show();
		int menuSelection;

		if (!(std::cin >> menuSelection).good()){
			std::cin.clear();
			std::cin.ignore(256, '\n');
		} else {
			switch (menuSelection){
			case 1:
				simpleSearch();
				break;
			case 2:
				
				break;
			case 3:
				
				break;
			case 4:
				std::cout << "Program ended " << std::endl;
				running = false;
				break;
			default:
				std::cout << "Error \n";
			}
		}
	}
	
}


void getRawData(){
	std::string empCode, ssn, first, last, dept, role, salary;
	int empCount = 0;
	
	std::ifstream inFile {fileName}; // ifstream not on CS
	while (!inFile.eof()){
		if ((inFile >> empCode >> ssn >> first >> last >> dept >> role >> salary)){
			Employee *temp = new Employee;
			temp->setEmpCode(empCode);
			temp->setSSN(ssn);
			temp->setName(first, last);
			temp->setDept(dept);
			temp->setRole(role);
			temp->setSalary(std::stof(salary));

			list[empCount++] = temp;
		} else {
			std::cout << "Error reading file " << std::endl;
			exit(1);
		} 

	}

	inFile.close();

	std::cout << "Number of employees is: " << empCount << "\n";
	for (int i = 0; i < MAX_CAPACITY; i++){
		std::cout << *list[i] << std::endl;
	}
}

Error_code simpleSearch( ){ // pass in func pointer to qsort 
	double ssnCriteria;
	std::cout << "Enter a SSN: ";

	while (!(std::cin >> ssnCriteria).good()){
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cout << "Enter a SSN: ";	
	} 

	for (int i =0; i <= MAX_CAPACITY; i++){
		Employee *item;
		item = list[i];
		double key = std::stod(item->getSSN());

		if (key == ssnCriteria){
			std::cout << *item;
			return success;
		} else {
			std::cout << "Not found " << std::endl; 
			return not_present;
		}
	}
	return not_present;

}





