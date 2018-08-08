%{
int l=0,w=0,c=0;
%}  
 
%%
\n   { l++;w++;c++;}
[\t ' '] { w++;c++;}
. {c++;}
%%
 
int yywrap(){} 
 
int main()
{

 
yyin = fopen("hello.c","r");
yyout = fopen("output.txt","w");
yylex();
fprintf(yyout,"Line : %d\n",l);
fprintf(yyout,"Word : %d\n",w);
fprintf(yyout,"Char : %d\n",c);
 
return 0;
}