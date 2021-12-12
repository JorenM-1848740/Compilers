#include "../absyn.hpp"

PackageClause_::PackageClause_(char* p){
    packageName = p;
}

void PackageClause_::print(int d){
    std::cout << std::string(d*printWidth, ' ') << "PackageClause"<< "\n";
    std::cout << std::string((d+1)*printWidth, ' ') << "PackageName: "<< packageName <<  "\n";
}