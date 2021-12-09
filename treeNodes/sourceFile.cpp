#include "../absyn.hpp"

SourceFile_::SourceFile_(PackageClause p, TopLevelDeclList t){
    packageClause = p;
    topLevelDeclList = t;
}

void SourceFile_::print(int d){
    std::cout << std::string(d*printWidth, ' ') << "SourceFile" << "\n";
    packageClause->print(d+1);
    topLevelDeclList->print(d+1);
}