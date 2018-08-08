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

struct littab{
    char lit[3];
    int addr;
}l[50];

int main(){
    int i=0,lengh,LC=0,si=0,k,f=0,addr_size=0;
    char lit_ch[5];
    FILE *fp;
    fp = fopen("program.txt","r");
    while(!(feof(fp))){
        fscanf(fp,"%s %s %s %s",p[i].lable,p[i].inst,p[i].op1,p[i].op2);
        i++;
    }

    lengh = i;
    LC = atoi(p[0].op1);

    for(i=1;i<=lengh;i++){
        if(strcmp(p[i].lable,"*")){
            if( !(strcmp(p[i].inst,"DS")) || !(strcmp(p[i].inst,"DC"))){
                
                for(k=0;k<si;k++){
                    if(!(strcmp(s[k].sym,p[i].lable))){
                        s[k].addr = LC;
                        addr_size = atoi(p[i].op1);
                        LC = LC + addr_size;    
                    }
                }

                for(k=0;k<=si;k++){
                    if(!(strcmp(s[k].sym,p[i].lable))){
                        f=1;
                    }
                }

                if(f!=1){
                    strcpy(s[si].sym,p[i].lable);
                    s[si].addr = LC;
                    si++;
                    addr_size = atoi(p[i].op1);
                    LC = LC + addr_size;
                }

            }
        }

        else{

            strcpy(lit_ch,p[i].op2);

            if(!(strcmp(lit_ch,"=5"))){
                printf("It is lit\n");
            }

            else if( ( strcmp(p[i].op1,"AREG") || strcmp(p[i].op1,"BREG") || strcmp(p[i].op1,"CREG") || strcmp(p[i].op1,"DREG") ) ){

                for(k=0;k<=si;k++){
                    if(!(strcmp(s[k].sym,p[i].op2))){
                        f=1;
                    }
                }
                if(f!=1){
                    if(strcmp(p[i].op1,"*")){
                        strcpy(s[si].sym,p[i].op2);
                        si++;
                    }
                }
            }

            else{
                for(k=0;k<=si;k++){
                    if(!(strcmp(s[k].sym,p[i].op2))){
                        f=1;
                    }
                }

                if(f!=1){
                    strcpy(s[si].sym,p[i].op2);
                    si++;
                }
            }

            f=0;
            LC++;
        }
    }
    printf("|---------------|\n");
    printf("| Symbol Table  |\n");
    printf("|---------------|\n");
    printf("|Symbol\t|Address|\n");
    printf("|------\t|-------|\n");
    for(i=0;i<si;i++){
        printf("|   %s\t|  %d\t|\n",s[i].sym,s[i].addr);
    }
    printf("|---------------|\n");
    return 0;
}
