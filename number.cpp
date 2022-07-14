//
// Created by piggy on 7/11/22.
//

#include "number.h"
number* operater(number*a,number *b,oper op){
    number *ret;
    if(a->get_type() ==REAL_NUM && b->get_type() == REAL_NUM){
        switch (op) {
            case '+':
                ret = new real_number(a->value+b->value);
                break;
            case '-':
                ret = new real_number(a->value-b->value);
                break;
            case '*':
                ret = new real_number(a->value*b->value);
                break;
            case '/':
                ret = new real_number(a->value/b->value);
                break;
        }
    } else if(a->get_type() ==REAL_NUM && b->get_type() == IMAG_NUM){
        switch (op) {
            case '+':
                ret = new imag_number(a->value+b->realpart,b->imaginarypart);
                break;
            case '-':
                ret = new imag_number(a->value-b->realpart,b->imaginarypart);
                break;
            case '*':
                ret = new imag_number(a->value*b->realpart,b->imaginarypart*a->value);
                break;
            case '/':
                //TOD
                double denominator = pow(b->imaginarypart,2)+pow(b->realpart,2);
                double real_numer= a->value * b->realpart;
                double imag_numer = -(a->value*b->imaginarypart);
                ret = new imag_number(real_numer / denominator, imag_numer / denominator);
                break;
        }
    } else if (a->get_type() ==IMAG_NUM && b->get_type() == REAL_NUM){
        switch (op) {
            case '+':
                ret = new imag_number(a->realpart+b->value,a->imaginarypart);
                break;
            case '-':
                ret = new imag_number(a->realpart-b->value,a->imaginarypart);
                break;
            case '*':
                ret = new imag_number(a->realpart*b->value,a->imaginarypart*b->value);
                break;
            case '/':
                ret = new imag_number(a->realpart/b->value,a->imaginarypart/b->value);
                break;
        }

    } else if (a->get_type() == IMAG_NUM && b->get_type() == IMAG_NUM){
        switch (op) {
            case '+':
                ret = new imag_number(a->realpart+b->realpart,a->imaginarypart+b->imaginarypart);
                break;
            case '-':
                ret = new imag_number(a->realpart-b->realpart,a->imaginarypart-b->imaginarypart);
                break;
            case '*':
                ret = new imag_number(a->realpart*b->realpart-a->imaginarypart*b->imaginarypart,a->realpart*b->imaginarypart+a->imaginarypart*b->realpart);
                break;
            case '/':
                double denominator,numerator_real,numerator_imaginary;
                denominator = pow(b->imaginarypart,2)+pow(b->realpart,2);
                numerator_real = (a->realpart*b->realpart) + (a->imaginarypart*b->imaginarypart);
                numerator_imaginary = (a->imaginarypart*b->realpart)-(a->realpart*b->imaginarypart);
                ret = new imag_number(numerator_real/denominator,numerator_imaginary/denominator);
                break;
        }
    }

    return ret;
}
