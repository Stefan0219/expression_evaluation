#include "util.h"
using namespace std;
int main() {
    //begin for testing lexical analysis && required TODO
    /*
    init_regex();
    bool make_token_success;
    char expression[200];
    scanf("%[^\n]",expression);
    assert(make_token_success = make_token(expression));
     */
    // end for testing lexical analysis

    //begin for testing number.cpp
    real_number a("12");
    real_number b("6");

    imag_number c(1,3);
    imag_number d(2,4);
    number * num ;
    num = operater(&c,&d,'-');
    cout<<"here ";
    num->output();
    //a.output();
    //b.output();
    //c.output();
    //d.output();
    //end for testing number.cpp
}
