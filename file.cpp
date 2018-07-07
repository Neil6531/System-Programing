#include "iostream"

int main(){
    FILE *fp;
    char c;
    int word=1;
    fp = fopen("hello.c","r");
    while((c = fgetc(fp))!=EOF){
        printf("%c",c);
    }
    return 0;
}