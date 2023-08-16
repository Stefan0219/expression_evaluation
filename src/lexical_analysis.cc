//
// Created by piggy on 7/11/22.
//

#include <lexical_analysis.h>

#define ARRLEN(arr) (int)(sizeof(arr)/sizeof(arr[0]))
using namespace T_P;
enum {FORWARD,BACKWARD};
static struct rule{
    const char *regex;
    int token_type;
} rules[] ={
        {"0|[1-9][0-9]*",TK_NUM},
        {" +",TK_NOTYPE},
        {"\\(",'('},
        {"\\)",')'},
        {"\\*",'*'},
        {"/",'/'},
        {"-",'-'},
        {"\\+",'+'},
        {"0x[0-9a-fA-F]+",TK_HEX},
        {R"(\{([^\{\}]*)\})",TK_IMG_NUM}
};
#define NR_REGEX ARRLEN(rules)
static regex_t re[NR_REGEX] = {};

void init_regex(){
    int i ;
    char error_msg[128];
    int ret;

    for ( i = 0; i < NR_REGEX; ++i) {
        ret = regcomp(&re[i],rules[i].regex,REG_EXTENDED);
        if (ret != 0){
            regerror(ret,&re[i],error_msg,128);
            printf("failed to compile the regex expression\n");
            assert(0);
        }

    }
}
Token tokens[32] __attribute__((used)) = {};
int nr_token __attribute__((used)) = 0;
bool make_token(char *e){
    int position = 0;
    int i,j;
    regmatch_t pmatch;
    nr_token = 0;
    bool isHex = false;
    while (e[position]!='\0'){
        for(i= 0;i<NR_REGEX;i++){
            if(isHex == true && i==0){
                continue;
            }
            if(regexec(&re[i], e+position,1,&pmatch,0)==0 &&pmatch.rm_so == 0){
                char *substr_start = e + position;
                if(substr_start[0]=='0'&&substr_start[1]=='x'&& isHex == false){
                    isHex = true;
                    continue;
                }
                int substr_len = pmatch.rm_eo;
                position += substr_len;

                switch (rules[i].token_type){
                    case TK_EQ:
                    case '+':
                    case '-':
                    case '*':
                    case '/':
                    case '(':
                    case ')':
                        tokens[nr_token++].type = rules[i].token_type;
                        break;
                    case TK_NUM:
                    case TK_HEX:
                        assert(substr_len<=32);
                        tokens[nr_token].type = rules[i].token_type;
                        for(j = 0;j<substr_len;j++){
                            tokens[nr_token].str[j] = substr_start[j];
                        }
                        tokens[nr_token].str[substr_len] = '\0';
                        nr_token++;
                        break;
                    case TK_NOTYPE:
                        break;
                    case TK_IMG_NUM:
                        tokens[nr_token].type = rules[i].token_type;
                        for(j = 1;j<substr_len-1;j++){
                            tokens[nr_token].str[j-1] = substr_start[j];
                        }
                        tokens[nr_token].str[substr_len-2] = '\0';
                        nr_token++;
                        break;
                }
                break;
            }
        }
        if (i == NR_REGEX){
            printf("nomatch at position %d\n%s\n%*.s^\n",position,e,position,"");
            return false;
        }
        isHex = false;
    }
    for (int i = 0; i < nr_token; ++i) {//check conflict
        //printf("The %d(/st/rd/th)'s token is %s \n",i,tokens[i].str);
        int cur_type = tokens[i].type;
        switch (cur_type) {
            case '-':
                if(i==0){
                    move_tokens(i,FORWARD,&nr_token);
                    reverse_sign(tokens[i].str);
                } else{
                    int front_type = tokens[i-1].type;
                    switch (front_type) {
                        case '(':
                        case '+':
                        case '-':
                        case '*':
                        case '/':
                            move_tokens(i,FORWARD,&nr_token);
                            reverse_sign(tokens[i].str);
                            break;
                        default:
                            break;

                    }
                }
                break;
            }
        }
    return true;
    }
void reverse_sign(char * num){
    int len = (int)strlen(num);
    for (int i = len; i >0 ; --i) {
        num[i] = num[i-1];
    }
    num[0] = '-';
    num[len+1] = '\0';
    return;
}
void move_tokens(int pos,int dir,int *nr_token){
    switch (dir) {
        case FORWARD:
            for(int i = pos;i<*nr_token-1;i++){
                tokens[i] = tokens[i+1];
            }
            *nr_token-=1;
            break;
        case BACKWARD:
            //TODO
            break;
    }
}