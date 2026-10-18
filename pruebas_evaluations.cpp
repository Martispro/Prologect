#include "evaluations.hpp"
#include <iostream>
#include <map>
using namespace std;

main(){
    cout << "introduce la función a evaluar: ";
    string function;
    getline(cin, function);

    cout << evaluations::evaluate(function) << endl;
}