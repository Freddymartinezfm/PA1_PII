// The purpose o
#include "Search_tree.h"
#include "Employee.h"
#include <string>
#include <iomanip>
#include "OnOptionsMenu.h"
#include <cstring>

int main(){
	OnOptionsMenu menuOptions;
	bool running = true;
	//Search_tree<Employee*> searchTree;
	menuOptions.menu();
	// while (running){
	// 	std::string menuSelection;
	// 	std::cin >> std::stoi(menuSelection);

	// 	std::cout << "Enter new integer keys to insert. Enter 'q' to quit " << std::endl;

	// 	Employee *test = new Employee;

		


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