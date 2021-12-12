#include "../absyn.hpp"

void StatementList_::print(int d){
    std::cout << std::string(d*printWidth, ' ') << "StatementList" << "\n";
}