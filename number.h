//
// Created by piggy on 7/11/22.
//

#ifndef EXPR_NUMBER_H
#define EXPR_NUMBER_H

#include <cstdio>
#include <string>

typedef int oper;
using namespace std;
enum {REAL_NUM = 500,IMAG_NUM};




class number{
private:
public:
    double realpart;
    double imaginarypart;
    int type;
    double value;
    string literal;
    number(char *s){
        this->literal = s;
    }
    number() = default;
    virtual void output(){}
    int get_type(){
        return this->type;
    }
    int get_value(){
        if(this->type == REAL_NUM){
            return this->value;
        } else{
            printf("Failed to get the value of this number!\n");
            assert(0);
        }
    }
};
class real_number: public number{
public:
    bool isHexnum;
    real_number(char *s1) : number(s1) {
        this->type = REAL_NUM;
        if(s1[0] == '0'&&s1[1]=='x'){
            sscanf(this->literal.c_str(),"%x",&this->value);
            this->isHexnum = true;
        } else{
            sscanf(this->literal.c_str(),"%lf",&this->value);
            this->isHexnum = false;
        }
    }
    real_number(double v){
        this->type = REAL_NUM;
        this->value = v;
    }
    void output(){
        if (isHexnum)
            printf("0x%x\n",value);
        else
            printf("%.2lf\n",value);
    }
};
class imag_number: public number{
public:
    imag_number(char* s1): number(s1){
        this->type = IMAG_NUM;
        //TODO
    }
    imag_number(double real,double ima){
        this->type = IMAG_NUM;
        this->realpart = real;
        this->imaginarypart = ima;
    }
    void output(){
        if(imaginarypart>=0)
            printf("%.2f + %.2fi\n",realpart,imaginarypart);
        else
            printf("%.2f %.2fi\n",realpart,imaginarypart);
    }
};


number* operater(number*a,number *b,oper op);
#endif //EXPR_NUMBER_H
