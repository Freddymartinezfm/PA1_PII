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
Error_code search();
Error_code secOps(std::string&);
Error_code devDevelopers(std::string&, std::string&);
void sort(Employee *arr[], int size, bool (*compareFncPtr)(Employee &, Employee&));
bool ascendingSSN(Employee  &lhs, Employee &rhs);
bool descendingSSN(Employee  &lhs, Employee &rhs);
void print();

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
		std::string s = "SecOps";
		std::string devOps = "DevOps";
		std::string developer = "Developer";



		if (!(std::cin >> menuSelection).good()){
			std::cin.clear();
			std::cin.ignore(256, '\n');
		} else {
			switch (menuSelection){
			case 1:
				search();
				break;
			case 2:
				secOps(s);
				break;
			case 3:
				devDevelopers(devOps, developer);
				break;
			case 4:
				print();
				break;
			case 5:
				sort(list, MAX_CAPACITY,  ascendingSSN);
				print();
				break;
			case 6:
				sort(list, MAX_CAPACITY, descendingSSN);
				print();
				break;
			case 7:
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

// test
	Search_tree<Employee*> tree;
	std::cout << "Number of employees is: " << empCount << "\n";
	for (int i = 0; i < MAX_CAPACITY; i++){
		std::cout << *list[i] << std::endl;
		tree.insert(list[i]);
	}
}

Error_code search(){ 
	std::string  criteria;
	std::cout << "Enter a SSN: ";

	while (!(std::cin >> criteria).good()){
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cout << "Enter a SSN: ";	
	} 

	for (int i =0; i <= MAX_CAPACITY; i++){
		Employee *item = list[i];
		std::string s = item->getSSN();
		if (s.compare(criteria) == 0){
			std::cout << *item;
			return success;
		}
	}
	std::cerr << "Not found " << std::endl;
	return not_present;
}


Error_code secOps(std::string& c){
	Employee *temp;

	for (int i =0; i <= MAX_CAPACITY; i++){
		temp = list[i];
		std::string department = temp->getDept();

		if (department.compare(c) == 0){
			std::cout << *temp << std::endl;
		}
	}
	return not_present;

}

Error_code devDevelopers(std::string& department,std::string& role ){
	Employee *temp;

	for (int i =0; i <= MAX_CAPACITY; i++){
		temp = list[i];
		std::string d = temp->getDept();
		std::string r = temp->getRole();

		if (d.compare(department) == 0){
			std::cout << *temp << std::endl;
		}
	}
	return not_present;

}



void print(){
	for (int i =0; i < MAX_CAPACITY; i++){
		std::cout << *list[i] << std::endl;
	}
}



void sort(Employee *arr[], int size, bool (*compareFncPtr)(Employee &, Employee&)){
	for (int i = 0; i < MAX_CAPACITY; i++){
		int best = i;
		for (int curr = i + 1; curr < MAX_CAPACITY; curr ++){
			Employee *temp = list[best];
			Employee *t = list[curr];
			if (compareFncPtr(*temp, *t)){
				best = curr;
			}
		}
		std::swap(list[i], list[best]);
	}
}

bool ascendingSSN(Employee & lhs, Employee& rhs){
	return lhs > rhs;
}

bool descendingSSN(Employee & lhs, Employee& rhs){
	return lhs.getSSN() < rhs.getSSN();
}