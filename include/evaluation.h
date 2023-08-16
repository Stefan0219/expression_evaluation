//
// Created by piggy on 7/13/22.
//

#ifndef EXPR_EVALUATION_H
#define EXPR_EVALUATION_H
#include <lexical_analysis.h>
#include <number.h>
using namespace T_P;
extern Token tokens[32];
extern int nr_token;
enum {NO_MATCH=1000,ADD_SUB,MUL_DIV}; //precedence of the operator
number* eval(int p,int q);
int op_pre_cmp(oper oper1,oper oper2);
oper get_main_op(int p,int q ,int *position);
void test();
#endif //EXPR_EVALUATION_H
