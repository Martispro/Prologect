#include <string>

namespace evaluations{
    std::string normalise(std::string function, char operation = '*');
    int evaluate(std::string function);
    std::string replace(std::string texto, char remplazar, char remplazo = '\0');
}