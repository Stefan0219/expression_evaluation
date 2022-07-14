#include "lexical_analysis.h"
#include "number.h"
#include "syntatic_analysis.h"
int main() {
/*
 Notes:
       I chose to code in Linux environment, since I feel more comfortable using git in CLI(shell).
       And the regex.h is handy for lexical analysis.
       But the Chinese IME somehow is unavailable in the IDE which I am currently using(Clion 2022.1).
       So most of the comments are written in English.
       The Chinese comments are come from the project which I used done(NJU "Introduction to Computer System fall 2021").
       If there is any problem in running my program, please email me at tpq0219@qq.com.
       Best wishes.
*/
    //begin for testing lexical analysis && part of the final work
    /*
    init_regex();
    bool good_expr;
    char expression[200];
    scanf("%[^\n]",expression);
    assert(make_token(expression));
    // end for testing lexical analysis
    */
    //begin for testing syntatic analysis && part of the final work
    /*
    check_parentheses(0,nr_token-1,&good_expr);
    if(!good_expr){
        printf("Syntax error! Type again!\n");
        assert(0);
    }
    //end for testing syntatic analysis
    */
    /*
    //begin for testing number.cpp
    real_number a("12");
    real_number b("6");
    imag_number c("1+2i");
    imag_number d("1-2i");
    number * num ;
    num = operater(&c,&d,'-');
    cout<<"here ";
    num->output();
    a.output();
    b.output();
    c.output();
    d.output();
    //end for testing number.cpp
    */
}
