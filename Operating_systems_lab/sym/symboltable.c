#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define SIZE 97

struct hash {
	int size;
	char table[SIZE][SIZE];
	int flag[SIZE];
};

int hashFunction(char *str, int len) {
    int i = 0, x = 0;
    for(;i<len;i++) {
        x += str[i]<<i;
        x %= SIZE;
    }
    return x;
}

int compare(char *s1,char *s2) {
    int flag = 0, i = 0;
    while(s1[i]!='\0' || s2[i]!='\0') {
            if(s1[i] !=  s2[i]) {
                flag= 1;
                break;
            }
            i++;
    }
    return flag;
}

void insert(struct hash* T,char *str) {

	int i = 0,x = 0,h1 = 0,h2 = 0;
	x = hashFunction(str,strlen(str));
	h2 = 93 - (x%93) ;
	while(T->flag[x] != 0) {
		i+=1;
		x = ( h1 + (i*h2)) % T->size;
	}
    strcpy(T->table[x],str);
	T->flag[x] = 1;
}

int search(struct hash* T,char *str) {
	int i = 0,x = 0,h1 = 0,h2 = 0;
	x = hashFunction(str,strlen(str));
	h2 = 93 - (x%93) ;
	while(T->flag[x] != 0 && compare(T->table[x],str)) {
		i+=1;
		x = ( h1 + (i*h2)) % T->size;
	}
	if(T->flag[x] == 0)
		return 0;
	return 1;
}

void preprocess(char *fname,int ch,struct hash *T) {
    FILE *f = fopen(fname,"r");
    char temp[SIZE];
    while(fscanf(f,"%s",temp) && !feof(f)) {
        switch(ch) {
            case 1:insert(T,temp);
                   break;
            case 2:insert(T,temp);
                   break;
            case 3:insert(T,temp);
                   break;
        }
    }
    fclose(f);
}

int main () {
	char temp[SIZE];
	FILE *fp;
	int i, j;
	struct hash *SymbolTable,*KeywordTable,*OprTable,*SplSymTable;

	KeywordTable = (struct hash*)calloc(1,sizeof(struct hash));
	OprTable = (struct hash*)calloc(1,sizeof(struct hash));
	SplSymTable = (struct hash*)calloc(1,sizeof(struct hash));
	SymbolTable = (struct hash*)calloc(1,sizeof(struct hash));

	KeywordTable->size = OprTable->size = SplSymTable->size = SymbolTable->size = SIZE;

	preprocess("keywords.txt",1,KeywordTable);
	preprocess("operators.txt",2,OprTable);
	preprocess("specialsymbols.txt",3,SplSymTable);

	fp = fopen("sam.c","r");

	while(fscanf(fp,"%s",temp) && !feof(fp)) {
        if(search(SymbolTable, temp)) ;
        
        else if(search(KeywordTable,temp))    strcat(temp, "\t\t|Keyword             |");
        
        else if(search(OprTable,temp))       strcat(temp, "\t\t|Operator            |");
        
        else if(search(SplSymTable,temp))  strcat(temp, "\t\t|Special Symbol      |");

        else if(isdigit(temp[0])) 	strcat(temp, "\t\t|Numeric Constant    |");

        else strcat(temp, "\t\t|Identifier          |");
        
		insert(SymbolTable, temp);
	}
	printf("--------------------------------------\n");
	printf("|Symbol\t\t|Tokens              |\n");
	printf("--------------------------------------\n");
	for(i=0; i < SymbolTable->size;i++){
		if(SymbolTable->flag[i])
				printf("|%-4s\n",SymbolTable->table[i]);
	}
	printf("--------------------------------------\n");
	fclose(fp);
	return 0;
}
