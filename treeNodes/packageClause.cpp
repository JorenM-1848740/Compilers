#include "../absyn.hpp"

PackageClause_::PackageClause_(const char* p){
    packageName = p;
}

void PackageClause_::print(int d){
    std::cout << std::string(d*printWidth, ' ') << "PackageClause"<< "\n";
    std::cout << std::string((d+1)*printWidth, ' ') << "PackageName: "<< packageName <<  "\n";
}

void PackageClause_::typeCheck(vector<string>& typeErrors){
    if (packageName != "main"){
        typeErrors.push_back("Package identifier must be \"main\"!");
    }
}