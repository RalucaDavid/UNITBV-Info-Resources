#include "Grammar.h"

Grammar::Grammar()
{
	/*empty*/
}

Grammar::Grammar(std::vector<std::string> Vnonterminals, std::vector<std::string> Vterminals, std::string Start, std::vector<Production> productions) :
	m_Vnonterminals(Vnonterminals), m_Vterminals(Vterminals), m_Start(Start), m_productions(productions)
{
	/*empty*/
}

void Grammar::ReadGrammar()
{
	std::ifstream fin("date.txt");
	int nr_Vn, nr_Vt, nr_P;
	std::string character;
	std::string m_Stang, m_Drept;
	fin >> nr_Vn;
	for (int index = 0; index < nr_Vn; index++)
	{
		fin >> character;
		m_Vnonterminals.push_back(character);
	}
	fin >> nr_Vt;
	for (int index = 0; index < nr_Vt; index++)
	{
		fin >> character;
		m_Vterminals.push_back(character);
	}
	fin >> m_Start;
	fin >> nr_P;
	for (int index = 0; index < nr_P; index++)
	{
		fin >> m_Stang >> m_Drept;
		Production prod = Production(m_Stang, m_Drept);
		m_productions.push_back(prod);
	}
	fin.close();
}

bool Verificare1(const std::vector<std::string>& m_Vnonterminals, const std::vector<std::string>& Vterminals)
{
	for (int index = 0; index < m_Vnonterminals.size(); index++)
		for (int jndex = 0; jndex < Vterminals.size(); jndex++)
			if (m_Vnonterminals[index] == Vterminals[jndex])
				return false;
	return true;
}

bool Verificare2(const std::vector<std::string>& Vnonterminals,std::string Start)
{
	for (int index = 0; index < Vnonterminals.size(); index++)
		if (Start == Vnonterminals[index])
		{
			return true;
		}
	return false;
}

bool Verificare3(std::vector<Production> products, const std::vector<std::string>& Vnonterminals)
{
	bool ok = false;
	for (int index = 0; index < products.size(); index++)
	{
		for (int jndex = 0; jndex < Vnonterminals.size(); jndex++)
			if (products[index].GetLeftSide().find(Vnonterminals[jndex]) != std::string::npos)
			{
				ok = true;
				break;
			}
		if (ok == false)
			return false;
		ok = false;
	}
	return true;
}

bool Verificare4(std::vector<Production> products, std::string Start)
{
	for (int index = 0; index < products.size(); index++)
	{
		if (products[index].GetLeftSide() == Start && products[index].GetLeftSide().length() == 1)
			return true;
	}
	return false;
}

bool Verificare5(std::vector<Production> productii, const std::vector<std::string>& Vneterminale, const std::vector<std::string>& Vterminale)
{
	for (Production& rule : productii) {
		std::string left = rule.GetLeftSide();
		for (int i = 0; i < left.length(); i++) {
			if (std::find(Vneterminale.begin(), Vneterminale.end(), std::string(1,left[i])) == Vneterminale.end() && std::find(Vterminale.begin(), Vterminale.end(), std::string(1,left[i])) == Vterminale.end())
				return false;
		}
		std::string right = rule.GetRightSide();
		for (int i = 0; i < right.length(); i++) {
			if (std::find(Vneterminale.begin(), Vneterminale.end(), std::string(1,right[i])) == Vneterminale.end() && std::find(Vterminale.begin(), Vterminale.end(), std::string(1,right[i])) == Vterminale.end())
				return false;
		}
	}
	return true;
}

bool Grammar::VerifyGrammar()
{
	if (Verificare1(m_Vnonterminals, m_Vterminals) == false)
		return false;
	if (Verificare2(m_Vnonterminals, m_Start) == false)
		return false;
	if (Verificare3(m_productions, m_Vnonterminals) == false)
		return false;
	if (Verificare4(m_productions, m_Start) == false)
		return false;
	if (Verificare5(m_productions, m_Vnonterminals, m_Vterminals) == false)
		return false;
	return true;
}

void Grammar::PrintGrammar()
{
	std::cout << "G = ( { ";
	for (int index = 0; index < m_Vnonterminals.size() - 1; index++)
		std::cout << m_Vnonterminals[index] << ", ";
	std::cout << m_Vnonterminals[m_Vnonterminals.size() - 1] << " }, { ";
	for (int index = 0; index < m_Vterminals.size() - 1; index++)
		std::cout << m_Vterminals[index] << ", ";
	std::cout << m_Vterminals[m_Vnonterminals.size()-2] << " }, ";
	std::cout << m_Start << ", P ) \n";
	std::cout << "P contains the following productions:\n";
	for (int index = 0; index < m_productions.size(); index++)
		std::cout << "(" << index + 1 << ") " << m_productions[index].GetLeftSide() << " -> " << m_productions[index].GetRightSide() << "\n";
}

bool Grammar::IsRegular()
{
	for (auto& rule : m_productions)
	{
		std::string left = rule.GetLeftSide();
		for (int i = 0; i < left.length(); i++) 
		{
			if (std::find(m_Vnonterminals.begin(), m_Vnonterminals.end(), std::string(1, left[i])) == m_Vnonterminals.end())
				return false;
		}
		std::string right = rule.GetRightSide();
		if (right.size() > 2)
			return false;
		if (right.size() == 1)
		{
			if (std::find(m_Vterminals.begin(), m_Vterminals.end(), right) == m_Vterminals.end())
				return false;
		}
		else
		{
			if (std::find(m_Vterminals.begin(), m_Vterminals.end(), std::string(1,right[0])) == m_Vterminals.end())
				return false;
			if (std::find(m_Vnonterminals.begin(), m_Vnonterminals.end(), std::string(1, right[1])) == m_Vnonterminals.end())
				return false;
		}
	}
	return true;
}

size_t PickRandom(size_t nr) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(0, static_cast<int>(nr));
	return distrib(gen);
}

std::string Grammar::GenerateWord()
{
	std::vector<int> applicableRules;
	std::string word = "";
	word += m_Start;
	while (true)
	{
		for (int index=0;index<m_productions.size();index++)
		{
			size_t pos = word.find(m_productions[index].GetLeftSide());
			if (pos != std::string::npos)
			{
				applicableRules.push_back(index);
			}
		}
		if (applicableRules.empty())
			break;
		int index = PickRandom(applicableRules.size()-1);
		size_t pos = word.find(m_productions[applicableRules[index]].GetLeftSide());
		std::cout << word << " => ";
		word.replace(pos, m_productions[applicableRules[index]].GetLeftSide().length(), m_productions[applicableRules[index]].GetRightSide());
		std::cout << word << "\n";
		applicableRules.clear();
	}
	return word;
}

FiniteAutomaton Grammar::GenerateAutomaton()
{
	FiniteAutomaton automaton;

	for (int index=0;index<m_Vnonterminals.size();index++)
	{
		automaton.states.push_back(m_Vnonterminals[index]);
	}

	for (int index = 0; index < m_Vterminals.size(); index++)
	{
		automaton.inputAlphabet.push_back(m_Vterminals[index]);
	}

	automaton.initialState = m_Start;

	std::string currentSymbol;
	bool ok = false;
	int symbol = 43;
	while (ok == false)
	{
		ok = true;
		currentSymbol = std::string(1, symbol);
		for (int index = 0; index < m_Vnonterminals.size(); index++)
		{
			if (m_Vnonterminals[index] == currentSymbol)
				ok = false;
		}
		if (ok)
			automaton.finalStates.push_back(currentSymbol);
		symbol++;
	}
	automaton.states.push_back(currentSymbol);

	for (Production production : m_productions)
	{
		if (std::find(m_Vnonterminals.begin(), m_Vnonterminals.end(), std::string(1, production.GetRightSide().back())) != m_Vnonterminals.end())
		{
			automaton.transitionFunction.emplace(
				std::make_pair(production.GetLeftSide(), std::string(1,production.GetRightSide().front())),std::string(1,production.GetRightSide().back()));
		}
		else
		{
			automaton.transitionFunction.emplace(
				std::make_pair(production.GetLeftSide(), std::string(1,production.GetRightSide().front())),currentSymbol);
		}
	}

	return automaton;
}
