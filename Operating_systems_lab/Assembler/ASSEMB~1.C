#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<malloc.h>
//#include<label.h>
#include<stdlib.h>
int lc=0,flag1=0;
FILE *f1,*f2,*f3;
char a[22] [10]={"STOP","ADD","SUB","MULT","MOVER","MOVEM","COMP",
"BC","DIV","READ","PRINT","DS","DC","START","END","ORIGIN","EQU","LTORG","LDA","STA"};
char b[22] [3]={"IS","IS","IS","IS","IS","IS","IS","IS","IS","IS","IS","DL","DL","AD"
,"AD","AD","AD","AD","IS","IS"};
char c[22] [3]={"00","01","02","03","04","05","06","07","08","09","10","02","01","01","02","03","04","05","11","12"};
void check(char []);
int mnemo(char m[])
{
int i;
for(i=0;i<20;i++)
{
if(strcmp(a[i],m)==0)
return 1;
}
return 0;
}
void intercode(char s[])
{
int i;
for(i=0;i<20;i++)
{
if(strcmp(a[i],s)==0)
{
fprintf(f2,"(%s,",b[i]);
fprintf(f2,"%s)",c[i]);
fprintf(f3,"(%s,",b[i]);
fprintf(f3,"%s)",c[i]);
return;
}
}
}
int cons(char s[])
{
char d[10][3]={"0","1","2","3","4","5","6"};
int i;
for(i=0;i<6;i++)
{
if((strcmp(s,d[i]))==0)
return 1;
}
return 0;
}
int literal(char f[])
{
char g[10][5]={"='0'","='1'","='2'","='3'","='4'","='5'","='6'"};
int i;
for(i=0;i<8;i++)
{
if((strcmp(f,g[i]))==0)
return 1;
}
return 0;
}
struct optab
{
char opcode[10];
char class[5];
struct optab *next;
}*headop,*top,*cop;
struct symtab
{
char sym[3];
int add;
struct symtab *next;
}*headsy,*tsy,*csy;
struct littab
{
int add;
char lit[5];
struct littab *next;
}*headlit,*tlit,*clit;
struct pooltab
{
int litno;
struct pooltab *next;
}*headpool,*tailpool,*tpool;
struct forref
{
char t[5];
int data;
struct forref *next;
}*headfor,*tfor,*cfor;
int symbol(char s[])
{
for(tsy=headsy;tsy!=NULL;tsy=tsy->next)
{
if(strcmp(tsy->sym,s)==0)
{
fprintf(f3,"(S,");
fprintf(f3,"%d)",tsy->add);
fprintf(f2,"(S,");
fprintf(f2,"%d)",tsy->add);
return 1;
}
}
return 0;
}
void main()
{
int i,j;
char s[50],s1[50],s2[10],s3[50],name[10];
clrscr();
f1=fopen("v.c","r");
f2=fopen("output.c","w");
f3=fopen("outfinal.c","w");
fprintf(f2,"INTERMEDIATE CODE\n");
fprintf(f3,"INTERMEDIATE CODE\n");
headpool=(struct pooltab*)malloc(sizeof(struct pooltab));
tailpool=(struct pooltab*)malloc(sizeof(struct pooltab));
headpool->next=tailpool;
tailpool->next=NULL;
while(!feof(f1))
{
fprintf(f2,"\n");
fgets(s,strlen(s),f1);
i=0;
while(i<=8)
{
fscanf(f1,"%s",s1);
if(strcmp(s1,"START")==0)
{
fscanf(f1,"%s",s2);
lc=atoi(s2);
i+=strlen(s2);
}
check(s1);
i+=strlen(s1)+1;
}
fprintf(f3,"\n");
if(strcmp(s1,"END")==0)
break;
}
for(tfor=headfor;tfor!=NULL;tfor=tfor->next)
{
for(tsy=headsy;tsy!=NULL;tsy=tsy->next)
{
if(strcmp(tfor->t,tsy->sym)==0)
{
fprintf(f3,"(S,%d)",tsy->add);
}
}
}
printf("SYMTAB\n");
for(tsy=headsy;tsy!=NULL;tsy=tsy->next)
printf("\n%s\t%d",tsy->sym,tsy->add);
printf("\nOPTEB\n");
for(top=headop;top!=NULL;top=top->next)
printf("\n%s\t%s",top->opcode,top->class);
printf("\nLITTAB\n");
for(tlit=headlit;tlit!=NULL;tlit=tlit->next)
printf("\n%s\t%d",tlit->lit,tlit->add);
printf("\nPOOLTAB\n");
for(tpool=headpool;tpool!=NULL;tpool=tpool->next)
printf("\n%d",tpool->litno);
printf("\nFORWARD REFERENCE TABLE\n");
for(tfor=headfor;tfor!=NULL;tfor=tfor->next)
printf("\n%s",tfor->t);
getch();
}
void check(char s[])
{
if((label(s)==1)&&(flag1==0))
{
tsy=(struct symtab*)malloc(sizeof(struct symtab));
tsy->next=NULL;
strcpy(tsy->sym,s);
tsy->add=lc;
if(headsy==NULL)
headsy=tsy;
else
csy->next=tsy;
csy=tsy;
}
else if(mnemo(s)==1)
{
top=(struct optab*)malloc(sizeof(struct optab));
top->next=NULL;
strcpy(top->opcode,s);
if(headop==NULL)
headop=top;
else
cop->next=top;
cop=top;
if(((strcmp(s,"START"))==0)||(strcmp(s,"END")==0))
strcpy(top->class,"AD");
else if(((strcmp(s,"DC"))==0)||(strcmp(s,"DS")==0))
strcpy(top->class,"DL");
else
strcpy(top->class,"IS");
if(strcmp(s,"START")!=0)
lc++;
intercode(s);
if(strcmp(s,"START")==0)
flag1=0;
else
flag1=1;
}
else if((cons(s)==1))
{

fprintf(f3,"(C,");
fprintf(f3,"%s)\n",s);
fprintf(f2,"(C,");
fprintf(f2,"%s)\n",s);
flag1=0;
}
else if((literal(s))==1)
{
fprintf(f3,"(L,");
fprintf(f3,"%s)\n",s);
fprintf(f2,"(L,");
fprintf(f2,"%s)\n",s);
tlit=(struct littab*)malloc(sizeof(struct littab));
tlit->next=NULL;
strcpy(tlit->lit,s);
tlit->add=lc-1;
if(headlit==NULL)
{
headlit=tlit;
headpool->litno=1;
tailpool->litno=1;
}
else
{
clit->next=tlit;
tailpool->litno+=1;
}
clit=tlit;
flag1=0;
}
else
{
if((symbol(s)==1)&&(flag1==1))
{
flag1=0;
}
else
{
fprintf(f2,"(S,");
fprintf(f2,"--)");
tfor=(struct forref*)malloc(sizeof(struct forref));
tfor->next=NULL;
strcpy(tfor->t,s);
if(headfor==NULL)
headfor=tfor;
else
cfor->next=tfor;
cfor=tfor;
flag1=0;
}
}
}
