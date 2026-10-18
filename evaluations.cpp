#include <iostream>
#include <map>
#include <vector>
#include "evaluations.hpp"

const std::string operations = "+-*x/()";

/*
 * Creating an anonimun namespace for private functions of this file
*/
namespace {
    int simpleCalculator(int a, int b, char operation){
        switch (operation){
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return a / b;
            case '%': return a % b;
            case '|': return a | b;
            case '&': return a & b;
            case '^': return a ^ b;
            default: return 0;
        }
    }

    //transfor infix expresions to postfix notation for easyer evaluation using Shunting yard algorithm
    std::string infix_postfix(std::string infix){
        std::string postfix;
        std::string operationStack = "";

        std::map<char, int> preference = {
            {' ', 0},
            {'+', 2}, {'-', 2},
            {'*', 3}, {'x', 3}, {'/', 3},
        };

        for (char character : infix){
            if (operations.find(character) == std::string::npos){
                postfix += character;
            }
            else{
                if (!operationStack.empty()){
                    if (character == ')'){
                        postfix += operationStack.substr(0, operationStack.find('('));
                        operationStack = operationStack.substr(operationStack.find('(')+1);
                        continue;
                    }else if (character == '('){
                        operationStack = character + operationStack;
                        continue;
                    }else if (preference[character] <= preference[operationStack[0]]){
                        postfix += operationStack[0];
                        operationStack = operationStack.substr(1);
                    }
                }
                operationStack = character + operationStack;
            }
        }

        postfix += operationStack;
        
        return evaluations::remplazar(postfix, ' ');
    }
}

namespace evaluations{
    std::string remplazar(std::string texto, char remplazar, char remplazo){
        for (char& letra : texto){
            if (letra == remplazar){
                letra = remplazo;
            }
        }
        return texto;
    }

    int evaluar(std::string function){ 
        std::vector<char> letras = {'A', 'B', 'C', 'D', 'E', 'F', 'G',
                            'H', 'I', 'J', 'K', 'L', 'M', 'N',
                            'O', 'P', 'Q', 'R', 'S', 'T', 'U',
                            'V', 'W', 'X', 'Y', 'Z'};
        std::string postfixFunction = infix_postfix(function);
        std::cout << postfixFunction << std::endl;
        std::vector<char> stack;
        
        for (char simbol : postfixFunction){
            if (operations.find(simbol) == std::string::npos){
                stack.push_back(simbol);
            }else{
                int a = stack.back() - '0';
                stack.pop_back();

                int b = stack.back() - '0';
                stack.pop_back();

                stack.push_back(simpleCalculator(b, a, simbol) + '0');
            }
        }

        return stack[0] - '0';
    }
}