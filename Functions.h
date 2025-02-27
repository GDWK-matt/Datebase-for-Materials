#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>

struct Contract {
	int contractNumber;
	char productName[50];
	int quantity;
	int pricePerUnit;


	void printContract(std::ofstream& file) {
		file << contractNumber << "\t"
			<< productName << "\t"
			<< quantity << "\t"
			<< pricePerUnit << std::endl;
	}

	void readContract(std::ifstream& file) {
		file >> contractNumber
			>> productName
			>> quantity
			>> pricePerUnit;
	}
};
static Contract contract[20];

int numberOfContracts;

void saveContractsToFile(const char* filename) {
	std::ofstream file(filename);
	file << numberOfContracts << std::endl;
	for (int i = 0; i < numberOfContracts; ++i) {
		contract[i].printContract(file);
	}
	file.close();
}
void loadContractsFromFile(const char* filename)
{
	std::ifstream file(filename);
	file >> numberOfContracts;
	for (int i = 0; i < numberOfContracts; ++i) {
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
		std::cin >> numberOfContracts;
		if (std::cin.fail() || std::cin.peek() != '\n')
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\n_________________________________\n";
			std::cout << "\n Nevernoe znachenie. Vvedite chislovoe znachenie  \n";
			std::cout << "\n_________________________________\n";
			continue;
		}
		else
			flag = false;
	}
	for (int i = 0; i < numberOfContracts; i++)
	{
		bool flag = true;
		while (flag)
		{
			std::cout << "\n Nomer " << i + 1 << " yacheiki: ";
			std::cin >> contract[i].contractNumber;
			if (std::cin.fail() || std::cin.peek() != '\n')
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "\n______________________________________________\n";
				std::cout << "\n Nevernoe znachenie. Vvedite chislovoe znachenie (bez probela) \n";
				std::cout << "\n______________________________________________\n";

				continue;
			}
			else
				flag = false;

		}
		std::cout << "\n Nazvanie " << i + 1 << " yacheiki: ";;
		std::cin >> contract[i].productName;
		flag = true;
		while (flag)
		{
			std::cout << "\n Kolichestvo materiala: ";
			std::cin >> contract[i].quantity;
			if (std::cin.fail() || std::cin.peek() != '\n')
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "\n______________________________________________\n";
				std::cout << "\n Nevernoe znachenie. Vvedite chislovoe znachenie (bez probela)\n";
				std::cout << "\n______________________________________________\n";

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
				std::cout << "\n______________________________________________\n";
				std::cout << "\n Nevernoe znachenie. Vvedite chislovoe znachenie (bez probela) \n";
				std::cout << "\n______________________________________________\n";

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
	printf("*****************************************************************************\n");
	for (i = 0; i < numberOfContracts; i++) {
		printf("%d\t%-20s\t%-10d\t%-10d\n", contract[i].contractNumber, contract[i].productName,
			contract[i].quantity, contract[i].pricePerUnit);
	}
	printf("\n");
	saveContractsToFile("Materialy.txt");
}
void sortContractInformation()
{
	Contract temp;
	for (int i = 0; i < numberOfContracts; i++)
	{
		for (int j = 0; j < numberOfContracts - i - 1; j++)
		{
			if (contract[j].contractNumber > contract[j + 1].contractNumber)
			{
				temp = contract[j];
				contract[j] = contract[j + 1];
				contract[j + 1] = temp;
			}
		}
	}
	saveContractsToFile("Materialy.txt");
}
void addContractInformation()
{
	bool flag = true;
	while (flag)
	{
		std::cout << "\n Vvedite nomer " << numberOfContracts + 1 << " yacheiki: ";
		std::cin >> contract[numberOfContracts].contractNumber;
		if (std::cin.fail() || std::cin.peek() != '\n')
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\n______________________________________________\n";
			std::cout << "\n Nevernoe znachenie. Vvedite chislovoe znachenie (bez probela) \n";
			std::cout << "\n______________________________________________\n";

			continue;
		}
		else
			flag = false;

	}
	std::cout << "\n Nazvanie " << numberOfContracts + 1 << " yacheiki: ";;
	std::cin >> contract[numberOfContracts].productName;
	flag = true;
	while (flag)
	{
		std::cout << "\n Kolichestvo materiala: ";
		std::cin >> contract[numberOfContracts].quantity;
		if (std::cin.fail() || std::cin.peek() != '\n')
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\n______________________________________________\n";
			std::cout << "\n Nevernoe znachenie. Vvedite chislovoe znachenie (bez probela) \n";
			std::cout << "\n______________________________________________\n";

			continue;
		}
		else
			flag = false;

	}
	flag = true;
	while (flag)
	{
		std::cout << "\n Cena za edinicy materiala: ";;
		std::cin >> contract[numberOfContracts].pricePerUnit;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\n______________________________________________\n";
			std::cout << "\n Nevernoe znachenie. Vvedite chislovoe znachenie (bez probela)\n";
			std::cout << "\n______________________________________________\n";

			continue;
		}
		else
			flag = false;

	}
	numberOfContracts++;
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
			std::cout << "\n______________________________________________\n";
			std::cout << "\n Nevernoe znachenie. Vvedite chislovoe znachenie (bez probela)\n";
			std::cout << "\n______________________________________________\n";
			continue;
		}
		else
			flag = false;
	}

	int contractIndex = -1;
	for (int i = 0; i < numberOfContracts; i++)
	{
		if (numberOfContractToChange == contract[i].contractNumber)
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
			std::cout << "\n Vash vibor: ";
			std::cin >> choice;
			if (std::cin.fail() || std::cin.peek() != '\n')
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "\n__________________________________________________\n";
				std::cout << "\n Nevernoe znachenie. Vvedite chislovoe znachenie (bez probela) \n";
				std::cout << "\n__________________________________________________\n";
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
			std::cin >> contract[contractIndex].productName;
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
						std::cout << "\n______________________________________________\n";
						std::cout << "\n Nevernoe znachenie. Vvedite chislovoe znachenie (bez probela) \n";
						std::cout << "\n______________________________________________\n";

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
						std::cout << "\n______________________________________________\n";
						std::cout << "\n Nevernoe znachenie. Vvedite chislovoe znachenie (bez probela) \n";
						std::cout << "\n______________________________________________\n";

						continue;
					}
					else
						flag = false;

			}
			break;
		default:
			std::cout << "\n_________________________________\n";
			std::cout << "\n Nevernoe znachenie\n";
			std::cout << "\n_________________________________\n";
			break;
		}
	}
	else
	{
		std::cout << "\n_____________________________________________________\n";
		std::cout << "\n Nevernoe znachenie. Net yacheiki s takim znacheniem\n";
		std::cout << "\n_____________________________________________________\n";
	}
	saveContractsToFile("Materialy.txt");
}