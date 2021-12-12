#include "../absyn.hpp"

Arguments_::Arguments_(){

}
Arguments_::Arguments_(ExpressionList el){
    expressionList = el;
}
Arguments_::Arguments_(Type t){
    type = t;
}
Arguments_::Arguments_(Type t, ExpressionList el){
    type = t;
    expressionList = el;
}

void Arguments_::print(int d){
    std::cout << std::string(d*printWidth, ' ') << "Arguments" << "\n";
    if (type != nullptr){
        type->print(d+1);
    }
    if (expressionList != nullptr){
        expressionList->print(d+1);
    }
}