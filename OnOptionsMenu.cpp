#include <iomanip>
#include <string>
#include <iostream>
#include "OnOptionsMenu.h"

OnOptionsMenu::OnOptionsMenu(){
	
}

OnOptionsMenu::OnOptionsMenu(std::string title){
	this->leftOffSet = 80 - title.length();
	this->rightOffSet = 80 - title.length();
	this->title = title;

	
}

void OnOptionsMenu::menu(){
	


	std::cout << std::setw(17)  << std::setfill('=') << "Search Menu";
	std::cout << std::setw(17)  << std::setfill('=') << " "  << std::endl;

	std::cout << "1. Search an Employee by SSN " << std::endl;
	std::cout << "2. View SecOps team " << std::endl;
	std::cout << "3. View only DevOps Developers " << std::endl;
	// std::cout << "4. Print tree " << std::endl;
	// std::cout << "5. Print tree height " << std::endl;
	// std::cout << "6. Print tree size " << std::endl;
	std::cout << "7. Exit " << std::endl;

	std::cout << std::setw(17)  << std::setfill('=') << "Search Menu";
	std::cout << std::setw(17)  << std::setfill('=') << " "  << std::endl;

	std::cout << "Select an option: " ;
	


}