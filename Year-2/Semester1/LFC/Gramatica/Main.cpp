#include <iostream>
#include "Grammar.h"
#include <istream>

void Menu( Grammar grammar, std::ostream& output)
{
    grammar.ReadGrammar();
    if (!(grammar.VerifyGrammar()))
    {
        std::cout << "[ACCESS DENIED] Enter a valid grammar and try again.\n";
        return;
    }
    if (grammar.VerifyGrammar())
    {
        if (!(grammar.IsRegular()))
        {
            std::cout << "[ACCESS DENIED] Enter a valid grammar and try again.\n";
            return;
        }
        bool ok = true;
        int chosenNumber;
        if (grammar.IsRegular())
        {
            FiniteAutomaton automata;
            std::string word;

            while (ok)
            {
                system("cls");
                std::cout << "1. Print the grammar.\n2. Generate n number of words from the grammar.\n";
                std::cout << "3. Generate and print the equivalent finite automata.\n4. Verify whether a word is accepted by the finite automata or not.\n";
                std::cout << "5. Generate a word from the grammar and verify if it's accepted by the automata.\n";
                std::cout << "6. Exit the menu.\n\n";

                std::cout << "Your choice: ";
                std::cin >> chosenNumber;
                std::cout << "\n\n";

                switch (chosenNumber)
                {
                case 1:
                    grammar.PrintGrammar();
                    system("PAUSE");
                    break;
                case 2:
                    int number;
                    std::cout << "Enter the number of words you want to generate: ";
                    std::cin >> number; std::cout << "\n\n";
                    for (int i = 0; i < number; i++)
                    {
                        std::cout << grammar.GenerateWord();
                        std::cout << "\n\n";
                    }
                    system("PAUSE");
                    break;
                case 3:
                    automata = grammar.GenerateAutomaton();
                    std::cout << "Generated automata:\n\n";
                    std::cout << automata;
                    output << automata;
                    std::flush(output);
                    std::cout << "\n";
                    system("PAUSE");
                    break;
                case 4:
                    std::cout << "Enter the word you want to verify: ";
                    std::cin >> word; std::cout << "\n";
                    if (automata.CheckWord(word))
                        std::cout << "The word " << word << " has been accepted by the automata.\n\n";
                    else
                        std::cout << "The word " << word << " has been rejected by the automata.\n\n";
                    system("PAUSE");
                    break;
                case 5:
                    word = grammar.GenerateWord();
                    std::cout << "\n";
                    if (automata.CheckWord(word))
                        std::cout << "The word " << word << " has been accepted by the automata.\n\n";
                    else
                        std::cout << "The word " << word << " has been rejected by the automata.\n\n";
                    system("PAUSE");
                    break;
                case 6:
                    ok = false;
                    break;
                }

            }
        }
    }

}


int main()
{
    std::ofstream fileOutput("generatedAutomata.txt");
    Grammar grammar;
    Menu(grammar, fileOutput);
    fileOutput.close();
    return 0;
}