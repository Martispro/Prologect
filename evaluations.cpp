#include <iostream>
#include <map>
#include <vector>
#include "evaluations.hpp"

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
        std::string operationStack = " ";
        std::string operations = "+-*x/()";

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
                if (character == ')'){
                    for (int i = operationStack.length()-1; i > operationStack.find('('); i--){
                        postfix += operationStack[i];
                    }
                    //postfix += operationStack.substr(operationStack.find('(')+1, operationStack.length() - operationStack.find('('));
                    operationStack = operationStack.substr(0, operationStack.find('('));
                    continue;
                }else if (character == '('){
                    operationStack += character;
                    continue;
                }else if (preference[character] <= preference[operationStack[operationStack.length()-1]]){
                    postfix += operationStack[operationStack.length()-1];
                    operationStack.pop_back();
                }
                operationStack += character;
            }
        }

        for (int i = operationStack.length()-1; i > 0; i--){
            postfix += operationStack[i];
        }
        
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
        std::string operadores = "+-*/%|&^";
        
        for (char simbol : postfixFunction){
            if (operadores.find(simbol) == std::string::npos){
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