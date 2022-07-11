#include <iostream>
#include "lexical_analysis.h"
#include <cassert>
#include "number.h"
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

    //begining for test number.cpp
    real_number a("12");
    real_number b("0x124");
    imag_number c(1,3);
    a.output();
    b.output();
    c.output();
    //end for test number.cpp
}
