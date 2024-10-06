#include <iostream>

int main() {

	const int size = 3;

	struct student {
		std::string name;
		std::string surname;
		int age;
		std::string group;
		int idCard;
	} spisok[size];


	for (int i = 0; i < size; i++) {
		std::cout << "Enter student name: ";
		std::cin >> spisok[i].name;

		std::cout << "Enter student surname: ";
		std::cin >> spisok[i].surname;

		std::cout << "Enter how much age student: ";
		std::cin >> spisok[i].age;

		std::cout << "Enter which group the student is in: ";
		std::cin >> spisok[i].group;

		std::cout << "Enter student idCard number: ";
		std::cin >> spisok[i].idCard;
	}

	for (int i = 0; i < size; i++) {
		std::cout << "N: " << i + 1 << " Name: " << spisok[i].name << " Surname: " << spisok[i].surname << " Age: " << spisok[i].age << " Group: " << spisok[i].group << " IdCard: " << spisok[i].idCard << std::endl;
	}

	int parametr = 1;
	int counter;

	while (parametr != 0) {
		// std::cout << "Enter number of paramater for search: \n [0] - exit \n [1] - name \n [2] - surname \n [3] - age \n [4] - group \n [5] - idCard \n [6] - all \n";
		counter = 0;
		std::cout << "\nParametrs: \n[0] - exit \n[1] - name \n[2] - surname \n[3] - age \n[4] - group \n[5] - idCard \n[6] - all \nEnter number of paramater for search: ";
		std::cin >> parametr;
		switch (parametr) {

		case 0:
			break;

		case 1: {
			std::string name;
			bool finded = false;
			std::cout << "Enter student name: ";
			std::cin >> name;
			for (int i = 0; i < size; i++) {
				if (spisok[i].name == name) {
					std::cout << "Struct number which this name: " << i + 1 << std::endl;
					finded = true;
					counter++;
				}
			}
			if (!finded) {
				std::cout << "Struct number which this name not found" << std::endl;
			}
			else {
				std::cout << "count find elements:" << counter << std::endl;
			}

			break;
		}

		case 2: {
			std::string surname;
			bool finded = false;
			std::cout << "Enter student surname: ";
			std::cin >> surname;
			for (int i = 0; i < size; i++) {
				if (spisok[i].surname == surname) {
					std::cout << "Struct number which this surname: " << i + 1 << std::endl;
					finded = true;
					counter++;
				}
			}
			if (!finded) {
				std::cout << "Struct number which this surname not found" << std::endl;
			}
			else {
				std::cout << "count find elements:" << counter << std::endl;
			}
			break;
		}

		case 3: {
			int age;
			bool finded = false;
			std::cout << "Enter student age: ";
			std::cin >> age;
			for (int i = 0; i < size; i++) {
				if (spisok[i].age == age) {
					std::cout << "Struct number which this age: " << i + 1 << std::endl;
					finded = true;
					counter++;
				}
			}
			if (!finded) {
				std::cout << "Struct number which this age not found" << std::endl;
			}
			else {
				std::cout << "count find elements:" << counter << std::endl;
			}
			break;
		}

		case 4: {
			std::string group;
			bool finded = false;
			std::cout << "Enter student group: ";
			std::cin >> group;
			for (int i = 0; i < size; i++) {
				if (spisok[i].group == group) {
					std::cout << "Struct number which this group: " << i + 1 << std::endl;
					finded = true;
					counter++;
				}
			}
			if (!finded) {
				std::cout << "Struct number which this group not found" << std::endl;
			}
			else {
				std::cout << "count find elements:" << counter << std::endl;
			}
			break;
		}

		case 5: {
			int idCard;
			bool finded = false;

			std::cout << "Enter student idCard: ";
			std::cin >> idCard;
			for (int i = 0; i < size; i++) {
				if (spisok[i].idCard == idCard) {
					std::cout << "Struct number which this idCard: " << i + 1 << std::endl;
					finded = true;
					counter++;
				}
			}
			if (!finded) {
				std::cout << "Struct number which this idCard not found" << std::endl;
			}
			else {
				std::cout << "count find elements:" << counter << std::endl;
			}
			break;
		}

		case 6: {
			std::string name;
			std::string surname;
			int age;
			std::string group;
			int idCard;

			bool finded;

			std::cout << "Enter student name: ";
			std::cin >> name;

			std::cout << "Enter student surname: ";
			std::cin >> surname;

			std::cout << "Enter how much age student: ";
			std::cin >> age;

			std::cout << "Enter which group the student is in: ";
			std::cin >> group;

			std::cout << "Enter student idCard number: ";
			std::cin >> idCard;

			for (int i = 0; i < size; i++) {
				if (spisok[i].name == name &&
					spisok[i].surname == surname &&
					spisok[i].age == age &&
					spisok[i].group == group &&
					spisok[i].idCard == idCard) {
					std::cout << "Struct number which this all: " << i + 1 << std::endl;
					finded = true;
					counter++;
				}
			}
			if (!finded) {
				std::cout << "Struct number which this all parametrs not found" << std::endl;
			}
			else {
				std::cout << "count find elements:" << counter << std::endl;
			}
			break;
		}

		default:
			std::cout << "Enter available parametr" << std::endl;
			break;
		}

	}

}