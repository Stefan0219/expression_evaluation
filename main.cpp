#include "headers/lexical_analysis.h"
#include "headers/number.h"
#include "headers/evaluation.h"
int main() {
/*
 Notes:
       I chose to code in Linux environment.
       But the Chinese IME somehow is unavailable in the IDE which I am currently using.
       So most of the comments are written in English.
       The Chinese comments come from the project which I used done.
       If there is any problem in running my program, please email me at tpq0219@qq.com.
       Best wishes.
*/

    //begin for testing lexical analysis && part of the final work
    init_regex();
    char expression[200];
    printf("Input the expression you wanna evaluate:\n");
    scanf("%[^\n]",expression);
    assert(make_token(expression));
    // end for testing lexical analysis


    number * value_of_expr = eval(0,nr_token-1);
    printf("The value of the expression is:\n");
    value_of_expr->output();

    //begin for testing syntatic analysis
    /*
    check_parentheses(0,nr_token-1,&good_expr);
    if(!good_expr){
        printf("Syntax error! Type again!\n");
        assert(0);
    }
    //end for testing syntatic analysis
    */

    //begin for testing number.cpp
    /*
    real_number a("12");
    //real_number b("6");
    imag_number c("1+1i");
    //imag_number d("1-2i");
    number * num ;
    num = operater(&a,&c,'/');
    num->output();
    //c.output();
    //d.output();
    */
    //end for testing number.cpp && done!

}
