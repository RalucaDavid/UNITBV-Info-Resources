#include <iostream>
#include "Functions.h"
#include <fstream>

void ReadExpression(std::string& regularExpression)
{
	std::ifstream fin("data.in");
	fin >> regularExpression;
	fin.close();
	for (auto it = regularExpression.begin(); it != regularExpression.end() - 1; it++)
	{
		if ((std::isalpha(*it)) && ((it + 1) != regularExpression.end()) && (std::isalpha(*(it + 1))))
		{
			regularExpression.insert(it + 1, '.');
			it++;
		}
		else if (((std::isalpha(*it))) && ((it + 1) != regularExpression.end()) && (*(it + 1) == '('))
		{
			regularExpression.insert(it + 1, '.');
			it++;
		}
		else if ((*(it) == '*') && ((it + 1) != regularExpression.end()) && (std::isalpha(*(it + 1))))
		{
			regularExpression.insert(it + 1, '.');
			it++;
		}
	}
}

bool RegularExpressionValidation(std::string expression,std::string& polishF)
{
	std::stack<std::string> characters;
	std::string result;
	std::stack<char> polishForm;
	PolishForm(polishForm, expression);
	if (polishForm.empty())
		return false;
	polishF = CreatePolishForm(polishForm);
	for (char character : polishF)
	{
		if ((character == '|') || (character == '.'))
		{
			if (characters.empty())
			{
				return false;
			}
			result +=characters.top();
			characters.pop();
			if (characters.empty())
			{
				return false;
			}
			result += characters.top();
			characters.pop();
			characters.push(result);
		}
		else if (character == '*')
		{
			if (characters.empty())
			{
				return false;
			}
			result += characters.top();
			characters.pop();
			characters.push(result);
		}
		else if ((character == ')') || (character == '('))
		{
			return false;
		}
		else
			characters.push(std::to_string(character));
	}
	result = result + characters.top();
	characters.pop();
	return characters.empty();;
}

DeterministicFiniteAutomaton BuildAfdFromRegularExpression(std::string polishForm)
{
	FiniteAutomaton automaton;
	automaton = ExpressionEvaluation(polishForm);
	return ConvertToAFD(automaton);
}

void Menu(std::string r,std::string polishForm)
{
	int chosenNumber = 1;
	bool ok = true;
	DeterministicFiniteAutomaton automaton = BuildAfdFromRegularExpression(polishForm);
	while (ok)
	{
		system("cls");
		std::cout << "1. Afisare automat\n";
		std::cout << "2. Afisare expresie regulata din fisier\n";
		std::cout << "3. Verificare cuvant in automat\n";
		std::cout << "0. Inchidere aplicatie\n\n";

		std::cin >> chosenNumber;
		std::cout << "\n\n";

		std::string word;
		switch (chosenNumber)
		{
		case 1:
				{
					std::cout << automaton;
					std::ofstream fout("data.out");
					fout << automaton;
					fout.close();
					system("PAUSE");
					break;
				}
		case 2:
				std::cout << r << std::endl;
				system("PAUSE");
				break;
		case 3:
				std::cout << "Introduceti un cuvant: ";
				std::cin >> word;
				if (automaton.CheckWord(word))
					std::cout << "Cuvantul a fost acceptat\n";
				else
					std::cout << "Cuvantul a fost respins\n";
				system("PAUSE");
				break;
		case 0:
				ok = false;
				break;
		}
	}
}

int main()
{
	std::string regularExpression, polishForm;
	ReadExpression(regularExpression);
	if (RegularExpressionValidation(regularExpression, polishForm))
		Menu(regularExpression, polishForm);
	else 
		std::cout << "Expresia regulata nu este valida!\n";
	return 0;
}