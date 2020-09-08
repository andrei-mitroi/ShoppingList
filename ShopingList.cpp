#include <iostream>

#include <vector>
#include <utility>
#include <algorithm>
#include <string>

#include <stdlib.h>



class shoppingList {

	std::vector <std::pair <std::string, double>> list;
	std::string itemName{};
	double itemCost{}, sum{};

public:

	shoppingList() {
		std::cout << "Hello and thank you for using this program!\nI'm here to help you make a shopping list as easy as possible.\nAll you need to do is type in the item that you want to buy, along with it's price!\nLet's get started! \n\n";
	}

	void addItem();
	void addPrice();
	void addToBascket();
	void displayList();
	void ascSort();
	void desSort();
	void alphaSort();
	double getSum();
	void clearBascket();

};

void shoppingList::addItem() {

	std::cout << "What is the item that you would like to add to the list? \n";
	std::getline(std::cin, itemName);
}

void shoppingList::addPrice() {

	std::cout << "How much does " << itemName << " cost?\n";
	std::cin >> itemCost;
}

void shoppingList::addToBascket() {

	list.push_back(make_pair(itemName, itemCost));
}

void shoppingList::displayList() {

	system("cls");

	std::cout << "Your shopping list consists of the following items: " << "\n\n";

	for (int i = 0; i < list.size(); i++) {
		std::cout << list[i].first << " " << list[i].second << " RON\n";
	}	
}

double shoppingList::getSum() {

	for (int i = 0; i < list.size(); i++) {
		sum = sum + list[i].second;
	}

	std::cout << "\nTotal price: " << sum << "\n\n";

	return sum;
}

bool descSortByPrice(const std::pair<std::string, double> &a, const std::pair<std::string, double> &b) {

	return a.second > b.second;
}

bool ascSortByPrice(const std::pair<std::string, double> &a, const std::pair<std::string, double> &b) {

	return a.second < b.second;
}

bool alphaSortByName(const std::pair<std::string, double>& a, const std::pair<std::string, double>& b) {

	return a.first < b.first;
}

void shoppingList::desSort() {

	std::sort(list.begin(), list.end(), descSortByPrice);

}

void shoppingList::ascSort() {

	std::sort(list.begin(), list.end(), ascSortByPrice);

}

void shoppingList::alphaSort() {

	std::sort(list.begin(), list.end(), alphaSortByName);

}

void shoppingList::clearBascket() {
	
	list.clear();

}


int main() {
	
	shoppingList list;

	char option{}, option1{}, option2{}, option3{}; //for looping the program
	bool repeat = true;

	do {
		do {

			list.addItem();
			list.addPrice();
			list.addToBascket();

			std::cout << "Would you like to add another item?(y/n)" << std::endl;
			std::cin >> option;
			std::cin.ignore(256, '\n');
			system("cls");

		} while (option == 'Y' || option == 'y');

		list.displayList();
	
		std::cout << "\nWould you like to sort your list?(y/n) \n";
		std::cin >> option1;
		std::cin.ignore(256, '\n');

		if (option1 == 'Y' || option1 == 'y') {

			while (repeat) {
				std::cout << "Please choose a way to sort your Shopping List: \n"
					<< "1. By price in ascending order: \n"
					<< "2. By price in descending order: \n"
					<< "3. By name of item in alphabetical order: \n";

				std::cin >> option2;
				switch (option2) {

				case '1':
					list.ascSort();
					std::cout << "Your sorted list contains the following: \n";
					list.displayList();
					list.getSum();
					break;

				case '2':
					list.desSort();
					std::cout << "Your sorted list contains the following: \n";
					list.displayList();
					list.getSum();
					break;

				case '3':
					list.alphaSort();
					std::cout << "Your sorted list contains the following: \n";
					list.displayList();
					list.getSum();
					break;

				default:
					std::cout << "Please enter a valid option!\n\n";
					continue;
				}
				break;
			}
			std::cout << "\nWould you like to make another list?(y/n) \n";
			std::cin >> option3;
			std::cin.ignore(256, '\n');
			list.clearBascket();
			system("cls");

		} else {
			list.displayList();
			list.getSum();
		}

	} while (option3 == 'Y' || option3 == 'y');

	return 0;
}

