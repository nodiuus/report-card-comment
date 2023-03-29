#include <iostream>
#include <fstream>
#include <string>

int main() {
	std::string StudentName;
	std::string StudentRating;
	
	std::cout << "Name: ";
	std::cin >> StudentName;

	std::cout << "Rating: ";
	std::cin >> StudentRating;

	std::ifstream ChosenFile("Comments\\" + StudentRating);

	if (!ChosenFile) {
		std::cerr << "Error opening file!" << std::endl;
		return 1;
	}
	
	std::string Line;
	
	while (std::getline(ChosenFile, Line)) {
		for (int i = 0; i < Line.length(); i++) {
			if (Line[i] == 'X') {
				Line.replace(i, 1, StudentName);
				i += StudentName.length() - 1;
			}
		}
	}
	std::cout << Line << std::endl;

	return 0;
}