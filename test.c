#include "stdio.h"
#include "string.h"

int main(){
    char keywords[32][15] = { "break", "case", "char", "const", "continue", "default", "do", "else", "enum", "extern", "float", "for", "goto", "if", "long", "register", "return", "short", "signed", "sizeof", "static", "switch", "typedef", "union", "unsigned", "void", "volatile", "while", "auto", "double", "int", "struct" };
    
    char specialChar[17][3] = {",",";", "!", "@", "#", "$", "^", "&", "*", "(", ")", "()", "\'", "{", "}", "[", "]"};
    
    char operators[][5] = {"=", "<", ">", "!=", "==", "<=", ">=", "&&", "||", "+", "-", "*", "/", "$s", "%"};

    char funs[][8] = {"main", "printf", "scanf"};

    char s[15];
    char c;
    char key[15];
    int i=0,j,flag,cmp;
    int keycount=1,sc=1,oper=1,fun=1,iden=1;

    for(j=0;j<17;j++){
        printf("%s \n",specialChar[j]);
    }


    FILE *fp;
    //open file
    fp = fopen("//Users//neelpatel//Documents//Collage//sem 5//System-Programing//hello.c","r");
    //check file is open or not
    if( fp == NULL ){
        printf("Error in file open");
    }
    // while( (c = fgetc(fp)) != EOF ){

    //     if( c != ' ' && c != '\n'){
    //         s[i] = c;
    //         i++;   
    //     }

    //     else{
    //         s[i] = NULL;
    //         flag = 0;
    //         for(j=0; j<32 ;j++){
    //             if(strcmp(s,keywords[j]) == 0){
    //                 flag = 1;
    //                 break;
    //             }
    //         }

    //         for(j=0; j<strlen(specialChar); j++){
    //             if(strcmp(s,specialChar[j]) == 0){
    //                 flag = 2;
    //                 break;
                    
    //             }
    //         }

    //         for(j=0; j<strlen(operators);j++){
    //             if(strcmp(s,operators[j]) == 0){
    //                 flag = 3;
    //                 break;
    //             }
    //         }
                
                
    //             // else if(strcmp(s,funs[j]) == 0){
    //             //     flag = 4;
    //             // }

    //         if(flag == 1){
    //             printf("%s is keyword \n",s);
    //             keycount++;
    //         }
    //         else if(flag == 2){
    //             printf("%s is specialChar \n",s);
    //             sc++;
    //         }
    //         else if(flag == 3){
    //             printf("%s is operators \n",s);
    //             oper++;
    //         }
    //         else if(flag == 4){
    //             printf("%s is Functions \n",s);
    //             fun++;
    //         }
    //         else{
    //             printf("%s is identifier \n",s);
    //             iden++;
    //         }
    //         i=0;
    //     }
    // }

    printf("=======================--SUMMARY--=======================\n");
    printf("Keyword : %d\n",keycount);
    printf("Special Char : %d\n",sc);
    printf("Operators : %d\n",oper );
    printf("Function : %d\n",fun);
    printf("Identifier : %d\n",iden);
    
    return 0;
}