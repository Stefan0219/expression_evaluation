#include "include/lexical_analysis.h"
#include "include/number.h"
#include "include/evaluation.h"
int main() {
    init_regex();
    char expression[200];
    printf("Input the expression you wanna evaluate:\n");
    scanf("%[^\n]",expression);
    assert(make_token(expression));
    number * value_of_expr = eval(0,nr_token-1);
    printf("The value of the expression is:\n");
    value_of_expr->output();
}
