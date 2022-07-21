//
// Created by piggy on 7/13/22.
//

#include "../include/evaluation.h"
#include "../include/syntatic_analysis.h"
oper get_main_op(int p,int q,int *position){
    oper mainop = -1;//the latest operator which been calculated in current (sub)expression
    bool ignore = false;// the operators which are surround by () are not the mainop
    int op_pos = -1; // the position of the main operator
    int nr_br = 0; // the number of the unmatched brackets
    int precedence = NO_MATCH; // init
    int cmp_val = 0;
    int cur_type;//current operator type during the running of the program.
    for (int i = p; i <=q; ++i) {
        cur_type = tokens[i].type;
        switch (cur_type) {
            case TK_NUM:
            case TK_HEX:
            case TK_IMG_NUM:
                break; // since they are not operator
            case '(':
                ignore = true;
                ++nr_br;
                break;
            case ')':
                assert(nr_br);
                if(--nr_br == 0)
                    ignore = false;
                break;
            case '+':
            case '-':
                if (ignore)
                    break;
                cmp_val = op_pre_cmp(precedence,ADD_SUB);
                //printf("cmp_val = %d \n",cmp_val);
                if(cmp_val< 0 && precedence != NO_MATCH){
                    break;
                } else{
                    op_pos = i;
                    precedence = ADD_SUB;
                    mainop = cur_type;
                    break;
                }
            case '*':
            case '/':
                if (ignore)
                    break;
                cmp_val = op_pre_cmp(precedence,MUL_DIV);
                if(cmp_val<0 && precedence != NO_MATCH)
                    break;
                else {
                    op_pos = i;
                    precedence = MUL_DIV;
                    mainop = cur_type;
                    break;
                }
            default:
                printf("How can you reach here, jerk!\n");
                break;

        }
    }
    *position = op_pos;
    //printf("op's position at %d\n",*position);
    return mainop;
}
int op_pre_cmp(oper oper1,oper oper2){// valued by the precedence of oper1 and oper2
    if(oper1>oper2){
        return 1;
    } else if(oper1 == oper2){
        return 0;
    } else{
        return -1;
    }
}
number* eval(int p,int q){
    number* ret_val;
    bool good_expr;
    oper  op;
    int position;
    if(p>q){
        printf("error in evaluation!\n");
        printf("And Error's position is at %d\n",p);
        assert(0);
    } else if(p == q){
        int type = tokens[p].type;
        switch (type) {
            case TK_NUM:
            case TK_HEX:
                ret_val = new real_number(tokens[p].str);
                break;
            case TK_IMG_NUM:
                ret_val = new imag_number(tokens[p].str);
                break;
        }
        return ret_val;
    } else if(check_parentheses(p,q,&good_expr)){
        //this expression is surrounded by a pair of parentheses
        assert(good_expr);
        return eval(p+1,q-1);
    } else{
        op = get_main_op(p,q,&position);
        number* val1,*val2;
        val1 = eval(p,position-1);
        val2 = eval(position+1,q);
       // return operater(val1,val2,op);
        switch (op) {
            case '+':
                return operater(val1,val2,'+');
            case '-':
                return operater(val1,val2,'-');
            case '*':
                return operater(val1,val2,'*');
            case '/':
                assert(!(val2->get_type() == REAL_NUM && val2->get_value() == 0));
                return operater(val1,val2,'/');
            default:
                assert(0);

        }
    }
    return nullptr;
}
