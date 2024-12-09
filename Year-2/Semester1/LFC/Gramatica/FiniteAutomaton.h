#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include "PairHashSpecialization.h"

class FiniteAutomaton
{
private:
	std::vector<std::string> states;
	std::vector<std::string> inputAlphabet;
	std::unordered_multimap<std::pair<std::string, std::string>, std::string, custom::hash_pair, custom::MyKeyEqual> transitionFunction;
	std::string initialState;
	std::vector<std::string> finalStates;
public:
	bool isValidTransition();
	bool VerifyAutomaton();
	bool CheckWord(std::string word);
	bool IsDeterministic();

	friend std::ostream& operator<<(std::ostream& os, const FiniteAutomaton& automata);
	friend class Grammar;
};

