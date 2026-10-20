#include <iostream>
#include <map>
#include <vector>
#include "evaluations.hpp"
#include "McCluskey.hpp"

namespace{
    int num_ones(std::string number){
        int ones = 0;

        for (char c : number){
            if (c == 1){
                ones++;
            }
        }

        return ones;
    }
    
    std::map<int, int> get_minterms(std::map<int, int> tabla){
        std::map<int, int> minterms;

        for (std::pair<int, int> minterm : tabla){
            if (minterm.second == 1){
                minterms[minterm.first] = minterm.second;
            }
        }

        return minterms;
    }

    std::map<int, std::vector<int>> grupos_minterms(std::map<int, int> minterms){
        std::map<int, std::vector<int>> minterms_ordenados;

        for (std::pair<int, int> minterm : minterms){
            minterms_ordenados[num_ones(std::to_string(evaluations::dec_binario(minterm.first)))].push_back(minterm.first);
        }

        return minterms_ordenados;
    }
}

//Forma esperada de la TV: {{0, f(0)}, {1, f(1)}, {2, f(2)}, ...}
namespace McCluskey{

}