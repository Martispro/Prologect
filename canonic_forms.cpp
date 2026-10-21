#include <iostream>
#include <map>
#include "canonic_forms.hpp"

namespace canonic_forms{
    std::map<int, int> get_minterms(std::map<int, int> tabla){
        std::map<int, int> minterms;

        for (std::pair<int, int> minterm : tabla){
            if (minterm.second == 1){
                minterms[minterm.first] = minterm.second;
            }
        }

        return minterms;
    }

    std::map<int, int> get_maxterms(std::map<int, int> tabla){
        std::map<int, int> maxterms;

        for (std::pair<int, int> maxterm : tabla){
            if (maxterm.second == 0){
                maxterms[maxterm.first] = maxterm.second;
            }
        }

        return maxterms;
    }
} // namespace canonic_forms
