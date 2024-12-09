#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <random>
#include <unordered_set>
#include <algorithm>
#include "Production.h"
#include "FiniteAutomaton.h"

class Grammar
{
private:
	std::vector<std::string> m_Vnonterminals;
	std::vector<std::string> m_Vterminals;
	std::string m_Start;
	std::vector<Production> m_productions;
public:
	Grammar();
	Grammar(std::vector<std::string> Vnonterminals, std::vector<std::string> Vterminals, std::string Start, std::vector<Production> productions);
	void ReadGrammar();
	bool VerifyGrammar();
	void PrintGrammar();
	bool IsRegular();
	std::string GenerateWord();
	FiniteAutomaton GenerateAutomaton();
};

