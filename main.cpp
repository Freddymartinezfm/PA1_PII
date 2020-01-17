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
		std::string menuSelection;
		std::cin >> menuSelection;

		switch (std::stoi(menuSelection)){
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


void getRawData(){
	std::string empCode, ssn, first, last, dept, role, salary;
	int empCount;
	
	std::ifstream inFile {fileName};
	if (!inFile.eof()){
		while (inFile >> empCode >> ssn >> first >> last >> dept >> role >> salary){
		Employee *temp = new Employee;
		temp->setEmpCode(empCode);
		temp->setSSN(ssn);
		temp->setName(first, last);
		temp->setDept(dept);
		temp->setRole(role);
		temp->setSalary(std::stof(salary));

		list[empCount++] = temp;
		}	
	}

	std::cout << "Number of employees is: " << empCount << "\n";
	for (int i = 0; i < MAX_CAPACITY; i++){
		std::cout << *list[i] << std::endl;
	}

}



Error_code simpleSearch( ){ // pass in func pointer to qsort 
	std::string ssnCriteria;
	std::cout << "Enter a SSN: ";
	if (std::cin >> ssnCriteria){
	}

	std::cout << "Searching for " <<  ssnCriteria <<std::endl;
	for (int i =0; i <= MAX_CAPACITY; i++){
		Employee *item;
		item = list[i];

		if (item->getSSN() == ssnCriteria){
			std::cout << *item;
			return success;
		}

		// return not_present;
	}

	std::cout << "Not found " << std::endl;

	return not_present;

}





