#include <iostream>
#include <stdio.h>
#include <string.h>
#include "Functions.h"

int main()
{
	const char* filename = "Materialy.txt";
	loadContractsFromFile(filename);
	bool programFlag = true;
	while (programFlag)
	{
		bool flag = true;
		int choice;
		while (flag)
		{
			std::cout << "\n Menu";
			std::cout << "\n 1.Sozdat'tablichu materialov";
			std::cout << "\n 2.Pokazat' informatiu";
			std::cout << "\n 3.Sortirovka ";
			std::cout << "\n 4.Dobavit' yacheiku";
			std::cout << "\n 5.Redactirovanie informatii";
			std::cout << "\n 6.Exit\n";
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
		case 1: enterContractInformation();
			break;
		case 2: printContractInformation();
			break;
		case 3:
		{
			sortContractInformation();
			std::cout << "\n Yacheiki otsortirovani\n";
		}
		break;
		case 4:
		{
			addContractInformation();
			std::cout << "\n Yacheika dobavlena\n";
		}
		break;
		case 5:
		{
			changeContractInformation();
			std::cout << "\n Yacheika izmenena\n";
		}
		break;
		case 6:
		{
			std::cout << "\n Vihod iz programmi \n";
			saveContractsToFile(filename);
			programFlag = false;
		}
		break;
		default:
		{
			std::cout << "\n Nevernoe znachenie\n";
		}
		break;
		}
	}
}