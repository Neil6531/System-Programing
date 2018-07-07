#include "stdio.h"
#include "string.h"

int main(){
    char keywords[32][15] = { "break", "case", "char", "const", "continue", "default", "do", "else", "enum", "extern", "float", "for", "goto", "if", "long", "register", "return", "short", "signed", "sizeof", "static", "switch", "typedef", "union", "unsigned", "void", "volatile", "while", "auto", "double", "int", "struct" };
    
    char specialChar[][3] = { "!", "@", "#", "$", "%", "^", "&", "*", "(", ")", "()", "\"", "\'", "{", "}", "[", "]" };
    
    char operators[][5] = {"=", "<", ">", "!=", "==", "<=", ">=", "&&", "||", "+", "-", "*", "/", "%d", 
    "%c", "$s", ","};

    char funs[][8] = {"main", "printf", "scanf"};

    char s[15];
    char c;
    char key[15];
    int i=0,j,flag,cmp;
    int keycount=0,sc=0,oper=0,fun=0;

    FILE *fp;
    //open file
    fp = fopen("//Users//neelpatel//Documents//Collage//sem 5//sp//hello.c","r");
    //check file is open or not
    if( fp == NULL ){
        printf("Error in file open");
    }

    while( (c = fgetc(fp)) != EOF ){
        if( c != ' ' && c != '\n'){
            s[i] = c;
            i++;   
        }

        else{
            s[i] = NULL;
            flag = 0;
            for(j=0; j<32 ;j++){

                if(strcmp(s,keywords[j]) == 0){
                    flag = 1;   
                }

                else if(strcmp(s,specialChar[j]) == 0){
                    flag = 2;
                }

                else if(strcmp(s,operators[j]) == 0){
                    flag = 3;
                }

                else if(strcmp(s,funs[j]) == 0){
                    flag = 4;
                }


            }
            if(flag == 1){
                printf("%s is keyword \n",s);
                // goto NEXT;
            }

            else if(flag == 2){
                printf("%s is specialChar \n",s);
                // goto NEXT;
            }

            else if(flag == 3){
                printf("%s is operators \n",s);
                // goto NEXT;
            }

            else if(flag == 4){
                printf("%s is Functions \n",s);
                // goto NEXT;
            }

            else{
                printf("%s is identifier \n",s);
            }
            i=0;
        }
    }

    // while( (c = fgetc(fp)) != EOF ){
    //     if( c != ' ' && c != '/n'){
    //         s[i]=c;
    //         i++;
    //     }
    //     else{
    //         s[i]=NULL;
    //         flag=0;
    //         for(j=0;j < strlen(keywords);j++){
    //             if( strcmp(s,keywords[j]) == 0 ){
    //                 flag=1;
    //                 break;
    //             }
    //             else{
    //                 printf("%s is indentifier \n",s);
    //             }

    //             if(flag==0){
    //                 printf("%s is keyword.. \n",s);
    //             }
    //         }
    //         i=0;
    //     }
    // }
    return 0;
}