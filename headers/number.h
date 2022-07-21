//
// Created by piggy on 7/11/22.
//

#ifndef EXPR_NUMBER_H
#define EXPR_NUMBER_H

#include "util.h"
typedef int oper;
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
            int temp;
            //A bit ugly
            //FIXME
            sscanf(this->literal.c_str(),"%x",&temp);
            string temp_str=to_string(temp);
            sscanf(temp_str.c_str(),"%lf", &this->value);
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
        if (isHexnum) {
            cout << "This number is a Hexadecimal number " << this->literal << endl;
            printf("And it's decimal value is %.0lf\n", value);
        }
        else
            printf("%.2lf\n",value);
    }
};
class imag_number: public number{
public:
    void get_val_from_string(char*str){
        int lenth = strlen(str);
        string temp = str;
        bool neg_imag = false;
        int pos;
        for (int i = 0; i < lenth; ++i) {
           if(temp[i] == '-' && i != 0){
               neg_imag = true;
               temp[i] = '+';
               }
        }
        sscanf(temp.c_str(),"%lf%lfi",&this->realpart, &this->imaginarypart);
        if(neg_imag){
            this->imaginarypart = -this->imaginarypart;
        }
    }
    imag_number(char* s1): number(s1){
        this->type = IMAG_NUM;
        get_val_from_string(s1);
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
            printf("%.2f - %.2fi\n",realpart,-imaginarypart);
    }
};


number* operater(number*a,number *b,oper op);
#endif //EXPR_NUMBER_H
