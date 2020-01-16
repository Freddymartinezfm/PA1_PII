
#include "GetRawData.h"
#include <fstream>
#include <iostream>
#include <string>


GetRawData::GetRawData(std::string &fileName) : source{fileName}{
	data = " ";
}

GetRawData::GetRawData(){

}

void GetRawData::getRawData(){
	std::ifstream inFile {source};
	if (!inFile){
		return;
	}
	

	while (!inFile.eof()){
		inFile >> data;
		std::cout << data << " ";


	}
}