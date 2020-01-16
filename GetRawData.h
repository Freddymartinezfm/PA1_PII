#include <iostream>

class GetRawData {
private:
	std::string source; // filename
	std::string data;


public:
	GetRawData();
	GetRawData(std::string&);
	void getRawData();



};