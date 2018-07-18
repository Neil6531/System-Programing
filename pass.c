#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct prog{
    char lable[5];
    char inst[5];
    char op1[5];
    char op2[5];
}p[50];

struct symtab{
    char sym[5];
    int addr;
}s[50];

int main(){
    int i=0,lengh,LC=0,si=0;
    FILE *fp;
    fp = fopen("program.txt","r");
    while(!(feof(fp))){
        fscanf(fp,"%s %s %s %s",p[i].lable,p[i].inst,p[i].op1,p[i].op2);
        i++;
    }

    lengh = i;
    LC = atoi(p[0].op1);
    LC++;

    for(i=1;i<=lengh;i++){
        if(strcmp(p[i].lable,"*")){
            strcpy(s[si].sym,p[i].lable);
            if( !(strcmp(p[i].inst,"DS")) || !(strcmp(p[i].inst,"DC"))){
                s[si].addr = LC;
                si++;
            }
        }

        else{
            if( ( strcmp(p[i].op1,"AREG") || strcmp(p[i].op1,"BREG") || strcmp(p[i].op1,"CREG") || strcmp(p[i].op1,"DREG") ) ){
                if(strcmp(p[i].op1,"*")){
                    strcpy(s[si].sym,p[i].op2);
                    si++;
                }
            }
            else{
                    strcpy(s[si].sym,p[i].op2);
                    si++;
            }
        }
        LC++;
    }

    for(i=0;i<si;i++){
        printf("%s %d\n",s[i].sym,s[i].addr);
    }


    return 0;
}