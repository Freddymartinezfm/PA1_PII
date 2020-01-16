#include <string>


class OnOptionsMenu {

public:
	OnOptionsMenu();
	OnOptionsMenu(std::string title);
	void menu();

private:
	int leftOffSet;
	int rightOffSet;
	int middle;
	std::string title;



};