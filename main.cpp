// The purpose o
#include "Search_tree.h"
#include "Employee.h"
#include <string>
#include <iomanip>
#include "OnOptionsMenu.h"
#include <cstring>
#include "GetRawData.h"
#include <fstream>
#include <string>


void read();
std::vector<std::string> fields;
Employee earray[20];

int main(){
	OnOptionsMenu menuOptions;
	bool running = true;
	Search_tree<Employee*> searchTree;
	std::string fileName = "employees.txt";
	GetRawData data(fileName);
	menuOptions.menu();

	while (running){
		std::string menuSelection;
		std::cin >> menuSelection;

		switch(std::stoi(menuSelection)){
			case 1:
				std::cout << "option one selected results shown here " << std::endl;
				//TODO search by SSN
				menuOptions.menu();

				break;
			// TODO add 2, 3, 4, 5, 

			case 6:
				std::cout << "option six selected results shown here " << std::endl;
				//TODO size and display
				
				// data.getRawData();

				read();
				menuOptions.menu();

				break;
			case 7:
				std::cout << "Program ended " << std::endl;
				//TODO size and display
				running = false;
				
				break;
			default:
				std::cout << "Invalid " << std::endl;
				menuOptions.menu();
				break;
		}

	}
	// 	if (menuSelection == "i"){
	// 		std::cout << "Enter new integer keys to insert. Enter 'q' to quit " << std::endl;
	// 		std::string key;
			
	// 		while(std::cin >> key){	
	// 			if (key == "q"){
	// 				break;
	// 			}
	// 			try {
	// 				searchTree.insert(std::stoi(key));

	// 			} catch (exception &e){
	// 				std::cout << "Invalid input to insert: '" << e.what() << "'" << " error.";
	// 			}	
	// 			searchTree.print();
	// 		}
	// 		menuOptions.menu();
			
	// 	} else if (menuSelection == "d"){
	// 		std::cout << "Enter new integer keys to delete. Enter 'q' to quit " << std::endl;
	// 		std::string key;
			
	// 		while(std::cin >> key){	
	// 			if (key == "q"){
	// 				std::cout << "quit";
	// 				menuOptions.menu();
	// 				break;
	// 			}

	// 			try {
	// 				searchTree.remove(std::stoi(key));
	// 			} catch (exception &e){
	// 				std::cout << "Invalid input to remove: '" << e.what() << "'" << " error. ";
	// 			}	
	// 			searchTree.print();
	// 		}

	// 	} else if (menuSelection == "h"){
	// 		std::cout << "The height of the binary tree is " <<  searchTree.height() << std::endl;
	// 		menuOptions.menu();
	// 	}  else if (menuSelection == "s"){
	// 		std::cout << "The size of the binary tree is " <<  searchTree.size() << std::endl;
	// 		menuOptions.menu();
	// 	} else if (menuSelection == "c"){
	// 		searchTree.clear();
	// 		menuOptions.menu();
	// 	} else if (menuSelection == "p"){
	// 		searchTree.print();
	// 		menuOptions.menu();
	// 	} else if (menuSelection == "x"){
	// 		std::cout << "Program ended " << std::endl;
	// 		running = false;
	// 		exit(1);
	// 		}
	// 	} 
	return 0;
}


void read(){
	std::ifstream inFile {"employees.txt"};
	if (!inFile){
		return;
	}
	
	std::string data;

	while (!inFile.eof()){
		inFile >> data;
		std::cout << data << " ";
	}
}