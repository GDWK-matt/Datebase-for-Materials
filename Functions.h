#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>

struct Yacheika {
	int Number;
	char Name[50];
	int quantity;
	int pricePerUnit;


	void printContract(std::ofstream& file) {
		file << Number << "\t"
			<< Name << "\t"
			<< quantity << "\t"
			<< pricePerUnit << std::endl;
	}

	void readContract(std::ifstream& file) {
		file >> Number
			>> Name
			>> quantity
			>> pricePerUnit;
	}
};
static Yacheika contract[20];

int numberOfY;

void saveContractsToFile(const char* filename) {
	std::ofstream file(filename);
	file << numberOfY << std::endl;
	for (int i = 0; i < numberOfY; ++i) {
		contract[i].printContract(file);
	}
	file.close();
}
void loadContractsFromFile(const char* filename)
{
	std::ifstream file(filename);
	file >> numberOfY;
	for (int i = 0; i < numberOfY; ++i) {
		contract[i].readContract(file);
	}
	file.close();
}
void enterContractInformation()
{

	bool flag = true;

	while (flag)
	{
		std::cout << "\n Kolichestvo yacheek: ";
		std::cin >> numberOfY;
		if (std::cin.fail() || std::cin.peek() != '\n')
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\n Nevernoe znachenie. Vvedite chislovoe znachenie  \n";
			continue;
		}
		else
			flag = false;
	}
	for (int i = 0; i < numberOfY; i++)
	{
		bool flag = true;
		while (flag)
		{
			std::cout << "\n Nomer " << i + 1 << " yacheiki: ";
			std::cin >> contract[i].Number;
			if (std::cin.fail() || std::cin.peek() != '\n')
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "\n Nevernoe znachenie. Vvedite chislovoe znachenie (bez probela) \n";
				continue;
			}
			else
				flag = false;

		}
		std::cout << "\n Nazvanie " << i + 1 << " yacheiki: ";;
		std::cin >> contract[i].Name;
		flag = true;
		while (flag)
		{
			std::cout << "\n Kolichestvo materiala: ";
			std::cin >> contract[i].quantity;
			if (std::cin.fail() || std::cin.peek() != '\n')
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "\n Nevernoe znachenie. Vvedite chislovoe znachenie (bez probela)\n";
				continue;
			}
			else
				flag = false;

		}
		flag = true;
		while (flag)
		{
			std::cout << "\n Cena za edinicy materiala: ";;
			std::cin >> contract[i].pricePerUnit;
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "\n Nevernoe znachenie. Vvedite chislovoe znachenie (bez probela) \n";
				continue;
			}
			else
				flag = false;

		}
		saveContractsToFile("Materialy.txt");
	}
}
void printContractInformation()
{
	int i;
	printf("\n");
	printf("#\t%-20s\t%-10s\t%-10s\n", "Nazvanie", "Kolichestvo", "Cena za edinicy");
	for (i = 0; i < numberOfY; i++) {
		printf("%d\t%-20s\t%-10d\t%-10d\n", contract[i].Number, contract[i].Name,
			contract[i].quantity, contract[i].pricePerUnit);
	}
	printf("\n");
	saveContractsToFile("Materialy.txt");
}
void sortContractInformation()
{
	std::cout << "\n Vibirite parametr sortirovki: ";
	bool flag = true;
	int choice;
	while (flag)
	{
		std::cout << "\n 1. Po nomery yacheiki";
		std::cout << "\n 2. Po nazvaniu materiala";
		std::cout << "\n 3. Po kolichestvu materiala\n";
		std::cin >> choice;
		if (std::cin.fail() || std::cin.peek() != '\n')
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\nNevernoe znachenie\n";
			continue;
		}
		else
			flag = false;
	}
	switch (choice)
	{
	case 1:
		Yacheika temp;
		for (int i = 0; i < numberOfY; i++)
		{
			for (int j = 0; j < numberOfY - i - 1; j++)
			{
				if (contract[j].Number > contract[j + 1].Number)
				{
					temp = contract[j];
					contract[j] = contract[j + 1];
					contract[j + 1] = temp;
				}
			}
		}
		saveContractsToFile("Materialy.txt");
		break;
	case 2: 
		for (int i = 0; i < numberOfY - 1; i++) {
			int minIndex = i;
			for (int j = i + 1; j < numberOfY; j++) {
			if (strcmp(contract[j].Name, contract[minIndex].Name) < 0) {
						minIndex = j;
					}
			}
			if (minIndex != i) {
				Yacheika temp = contract[i];
				contract[i] = contract[minIndex];
				contract[minIndex] = temp;
			}
		}

		saveContractsToFile("Materialy.txt");
		break;
	case 3:
	{
		for (int i = 1; i < numberOfY; i++) {
			Yacheika key = contract[i];
			int j = i - 1;

			while (j >= 0 && contract[j].quantity > key.quantity) {
				contract[j + 1] = contract[j];
				j--;
			}
			contract[j + 1] = key;
		}

		saveContractsToFile("Materialy.txt");
	}
	break;
	}
	
}
void addContractInformation()
{
	bool flag = true;
	while (flag)
	{
		std::cout << "\n Vvedite nomer " << numberOfY + 1 << " yacheiki: ";
		std::cin >> contract[numberOfY].Number;
		if (std::cin.fail() || std::cin.peek() != '\n')
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\n Nevernoe znachenie. Vvedite chislovoe znachenie (bez probela) \n";

			continue;
		}
		else
			flag = false;

	}
	std::cout << "\n Nazvanie " << numberOfY + 1 << " yacheiki: ";;
	std::cin >> contract[numberOfY].Name;
	flag = true;
	while (flag)
	{
		std::cout << "\n Kolichestvo materiala: ";
		std::cin >> contract[numberOfY].quantity;
		if (std::cin.fail() || std::cin.peek() != '\n')
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\n Nevernoe znachenie. Vvedite chislovoe znachenie (bez probela) \n";
			continue;
		}
		else
			flag = false;

	}
	flag = true;
	while (flag)
	{
		std::cout << "\n Cena za edinicy materiala: ";;
		std::cin >> contract[numberOfY].pricePerUnit;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\n Nevernoe znachenie. Vvedite chislovoe znachenie (bez probela)\n";

			continue;
		}
		else
			flag = false;

	}
	numberOfY++;
	saveContractsToFile("Materialy.txt");
}
void changeContractInformation()
{
	int numberOfContractToChange;
	bool flag = true;
	while (flag)
	{
		std::cout << "\n Vvedite nomer yacheiki: ";
		std::cin >> numberOfContractToChange;
		if (std::cin.fail() || std::cin.peek() != '\n')
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\n Nevernoe znachenie. Vvedite chislovoe znachenie (bez probela)\n";
			continue;
		}
		else
			flag = false;
	}

	int contractIndex = -1;
	for (int i = 0; i < numberOfY; i++)
	{
		if (numberOfContractToChange == contract[i].Number)
		{
			contractIndex = i;
		}
	}

	if (contractIndex != -1)
	{
		std::cout << "\nChto vi hotite izmenit'";
		std::cout << "\n1. Nazvanie";
		std::cout << "\n2. Kolichestvo";
		std::cout << "\n3. Cena";
		int choice;
		flag = true;
		while (flag)
		{
			std::cout << "\n Vash vibor: \n";
			std::cin >> choice;
			if (std::cin.fail() || std::cin.peek() != '\n')
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "\n Nevernoe znachenie. Vvedite chislovoe znachenie (bez probela) \n";
				continue;
			}
			else
				flag = false;
		}

		switch (choice)
		{
		case 1:
		{
			std::cout << "\n Novoe nazvanie yacheiki: ";
			std::cin >> contract[contractIndex].Name;
			break;
		}
		break;
		case 2:
			flag = true;
			while (flag)
			{
					std::cout << "\n Novoe kolichestvo materiala: ";
					std::cin >> contract[contractIndex].quantity;
					if (std::cin.fail())
					{
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						std::cout << "\n Nevernoe znachenie. Vvedite chislovoe znachenie (bez probela) \n";

						continue;
					}
					else
						flag = false;

			}
			break;
		case 3:
			flag = true;
			while (flag)
			{
					std::cout << "\n Novay cena za edinichu: ";
					std::cin >> contract[contractIndex].pricePerUnit;
					if (std::cin.fail())
					{
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						std::cout << "\n Nevernoe znachenie. Vvedite chislovoe znachenie (bez probela) \n";

						continue;
					}
					else
						flag = false;

			}
			break;
		default:
			std::cout << "\n Nevernoe znachenie\n";
			break;
		}
	}
	else
	{
		std::cout << "\n Nevernoe znachenie. Net yacheiki s takim znacheniem\n";
	}
	saveContractsToFile("Materialy.txt");
}