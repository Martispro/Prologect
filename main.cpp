#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "evaluations.hpp"
using namespace std;

//function that converts a deciaml number to a binary number
int dec_binario(int num){
    int num_binario = 0;
    int posicion = 1;
    while (num > 0){
        num_binario += (num % 2) * posicion;
        num /= 2;
        posicion *= 10;
    }
    return num_binario;
}

//function that determins the nunber of variables that the boolean function has
int num_var(string bool_func){
    int num_variables = 0;
    string comprobados = "";
    string excepciones = "+ -()*!/";
    for (char letra : bool_func){
        if (comprobados.find(letra) == string::npos && excepciones.find(letra) == string::npos){
            comprobados.push_back(letra);
            num_variables += 1;
        }
    }
    return num_variables;
}

/*
 *investigate postfix notation for evaluation
 *Note: use bitwise logit instead of regular aritmetic operations (&:and(*); |:or(+); ^:xor)
 */

int tablaVerdad(string function, int dimension){
    map<int, int> tabla_verdad;
    
    for (int i = 0; i <= dimension; i++){
        tabla_verdad[i] = 0;
    }
    return 0;
}

int main(){
    cout << "Introduce la funcion booleana: ";
    string function;
    getline(cin, function);

    function = evaluations::replace(function, ' ');

    cout << num_var(function) << endl;
    cout << dec_binario(10) << endl;
    //cout << infix_postfix(function) << endl;
    cout << evaluations::evaluate(function) << endl;
}