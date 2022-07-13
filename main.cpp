#include "util.h"
#include "lexical_analysis.h"
#include "number.h"
#include "syntatic_analysis.h"
using namespace std;
int main() {
    //begin for testing lexical analysis && required TODO a part of the final work

    init_regex();
    bool make_token_success;
    char expression[200];
    scanf("%[^\n]",expression);
    assert(make_token_success = make_token(expression));
    bool good;
    // end for testing lexical analysis

    //begin for testing syntatic analysis  TODO a part of the final work
    check_parentheses(0,nr_token-1,&good);
    if(!good){
        printf("Syntax error! Type again!\n");
        assert(0);
    }
    //end for testing syntatic analysis

    /*
    //begin for testing number.cpp
    real_number a("12");
    real_number b("6");

    imag_number c(1,3);
    imag_number d(2,4);
    number * num ;
    num = operater(&c,&d,'-');
    cout<<"here ";
    num->output();
    a.output();
    b.output();
    c.output();
    d.output();
    //end for testing number.cpp and DONE!
    */
}
