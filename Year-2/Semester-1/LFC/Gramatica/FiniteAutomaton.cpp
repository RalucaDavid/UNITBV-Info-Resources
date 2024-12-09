#include "FiniteAutomaton.h"

bool FiniteAutomaton::isValidTransition()
{
    for (const auto& element : transitionFunction)
    {
        if (std::find(states.begin(), states.end(), element.first.first) == states.end())
            return false;
        if (std::find(inputAlphabet.begin(), inputAlphabet.end(), element.first.second) == inputAlphabet.end())
            return false;
        if (std::find(states.begin(), states.end(), element.second) == states.end())
            return false;
    }
    return true;
}

bool FiniteAutomaton::VerifyAutomaton()
{
    if (states.empty())
        return false;
    if (inputAlphabet.empty())
        return false;
    if (std::find(states.begin(),states.end(),initialState)==states.end())
        return false;
    for (const auto& finalState : finalStates)
    {
        if (std::find(states.begin(), states.end(), finalState) == states.end())
            return false;
    }
    if (!isValidTransition())
        return false;
    return true;
}

bool FiniteAutomaton::CheckWord(std::string word)
{
    std::vector<std::string> currentStates = { initialState };
    while (!word.empty())
    {
        std::vector<std::string> nextStates;
        for (const auto& currentState : currentStates)
        {
            std::pair<std::string, std::string> currentTransition = std::make_pair(currentState, std::string(1, word[0]));
            auto transitions = transitionFunction.equal_range(currentTransition);
            for (auto it = transitions.first; it != transitions.second; it++)
            {
                nextStates.push_back(it->second);
            }
        }
        if (nextStates.empty())
            return false;
        currentStates = nextStates;
        word = word.substr(1);
    }
    for (const auto& currentState : currentStates)
    {
        if (std::find(finalStates.begin(), finalStates.end(), currentState) != finalStates.end())
            return true;
    }
    return false;
}

bool FiniteAutomaton::IsDeterministic()
{
    std::unordered_set<std::pair<std::string, std::string>, custom::hash_pair, custom::MyKeyEqual> seenTransitions;
    for (const auto& element : transitionFunction)
    {
        const auto& pair = element.first;
        if (seenTransitions.find(pair) != seenTransitions.end())
            return false;
        seenTransitions.insert(pair);
    }
    return true;
}

std::ostream& operator<<(std::ostream& os, const FiniteAutomaton& automata)
{
    os << "M = ( {";
    for (int index = 0; index < automata.states.size() - 1; index++)
        os << automata.states[index] << ", ";
    os << automata.states[automata.states.size() - 1] << "}, {";
    for (int index = 0; index < automata.inputAlphabet.size() - 1; index++)
        os << automata.inputAlphabet[index] << ", ";
   os << automata.inputAlphabet[automata.inputAlphabet.size() - 1] << "}, delta, " << automata.initialState << ", {";
    for (int index = 0; index < automata.finalStates.size() - 1; index++)
        os << automata.finalStates[index] << ", ";
    os << automata.finalStates[automata.finalStates.size() - 1] << "} )\n";
    os << "Delta is built this way:\n";
    for (int index = 0; index < automata.inputAlphabet.size(); index++)
        os << "      " << automata.inputAlphabet[index];
    os << "\n";
    for (int stateIndex = 0; stateIndex < automata.states.size(); stateIndex++)
    {
        os << " " << automata.states[stateIndex] << " ";
        for (int inputIndex = 0; inputIndex < automata.inputAlphabet.size(); inputIndex++)
        {
            auto transitions = automata.transitionFunction.equal_range({ automata.states[stateIndex], automata.inputAlphabet[inputIndex] });
            if (transitions.first != automata.transitionFunction.end())
            {
                os << " { ";
                for (auto it = transitions.first; it != transitions.second; it++)
                {
                    os << it->second << " ";
                }
                os << "} ";
            }
            else
                os << "   -   ";
        }
        os << "\n";
    }
    return os;
}
