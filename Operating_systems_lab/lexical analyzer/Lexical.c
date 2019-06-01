#include<stdio.h> 
#include<string.h> 
#include<stdlib.h>
#include<ctype.h>

char op[8]={'+','-','*','/','=','<','>','%'}; 
char del[9]={'}','{',';','(',')','[',']',',', '#'}; 
char *key[]={"auto","double","int","struct","break","else","long","switch",
"case","enum","register","typedef","char","extern","return","union","const",
"float","short","unsigned","continue","for","signed","void","default","goto",
"sizeof","volatile","do","if","static","while"}; 

//<token>i/j variables

int ci=0, li=0, lj=0, oi=0, di=0, ki=0, ii=0, lti=0;

//Global Variables

char constant[20]={'\0'}, lines[50][100]={'\0'}, operator[30]={'\0'}, delemeter[50]={'\0'},
keyword[30][10]={'\0'}, identifier[30][10]={'\0'}, literal[15][40]={'\0'};

//comparisons

int isop(char *c){
	int f=0;
	for(int i=0; i<8; i++){
		if(op[i]==*c){
			f=1;
			break;
		}
	}
	return f;
}

int isdelem(char *c){
	int f=0;
	for(int i=0; i<9; i++){
		if(del[i]==*c){
			f=1;
			break;
		}
	}
	return f;
}

int iskey(char a[]){
	int f=0;
	for(int i=0; i<32; i++){
		if(strcmp(key[i], a)==0){
			f=1;
			break;
		}
	}
	return f;
}

//To identify constant, delemeter, operator when reading a character from the file

void parsing(char *c){	
	if(isdigit(*c)){
		constant[ci]=*c;
		ci++;
	}
	else if(isop(c)){
		operator[oi]=*c;
		oi++;
	}
	else if(isdelem(c)){
		delemeter[di]=*c;
		di++;
	}
}

//To seperate identifiers from keywords

void newfunction(char t[]){
	if(iskey(t)){
		strcpy(keyword[ki], t);
		ki++;
	}
	else{
		strcpy(identifier[ii], t);
		ii++;
	}
}

//Seperates identifiers and literals from the input line

void seperate(){
	int i=0;
	while(i<li){
		int j=0;
		while(lines[i][j]!='\0'){
			if(isalpha(lines[i][j])||lines[i][j]=='_'){
				char temp[15]={'\0'};
				int ti=0;
				while(isalpha(lines[i][j])||lines[i][j]=='_'||lines[i][j]=='.'){
					temp[ti++]=lines[i][j++];
				}
				temp[ti]='\0';
				newfunction(temp);
			}
			else if(lines[i][j]=='"'){
				int ltj=0;
				literal[lti][ltj++]=lines[i][j++];
				for(; lines[i][j]!='"'; j++){
					literal[lti][ltj++]=lines[i][j];
				}
				literal[lti][ltj++]=lines[i][j];
				literal[lti][ltj]='\0';
				lti++;
				ltj=0;
			}
			j++;
		}
		i++;
	}
}

//stores the input in array of strings, each element in the array is a line in the file

void lexical(char *c){
	if(*c=='\t'){}
	else if(*c=='\n'){
		li++;
		lj=0;
	}
	else{
		lines[li][lj]=*c;
		parsing(c);
		lj++;
	}
}

//Removes duplicates in 1D array

int duplicates(char a[], int size){
	for(int i=0; i<size; i++){
		for(int j=i+1; j<size;){
			if(a[j]==a[i]){
				for(int k=j; k<size; k++){
					a[k]=a[k+1];
				}
				size--;
			}
			else{
				j++;
			}
		}
	}
	return size;
}

//Removes duplicates in 2D array

int duplicate(char a[][10], int size){
	for(int i=0; i<size; i++){
		for(int j=i+1; j<size;){
			if(strcmp(a[j],a[i])==0){
				for(int k=j; k<size; k++){
					strcpy(a[k],a[k+1]);
				}
				size--;
			}
			else{
				j++;
			}
		}
	}
	return size;
}

//Removing duplicates and display output

void display(){
	
	ci=duplicates(constant, ci);
	oi=duplicates(operator, oi);
	di=duplicates(delemeter, di);
	ki=duplicate(keyword, ki);
	ii=duplicate(identifier, ii);
	
	printf("\nConstants: \n");
	for(int i=0; i<ci; i++){
		printf("%d, %c\n",i+1,constant[i]);
	}
	printf("\nOperators: \n");
	for(int i=0; i<oi; i++){
		printf("%d, %c\n",i+1,operator[i]);
	}
	printf("\nDelemeters: \n");
	for(int i=0; i<di; i++){
		printf("%d, %c\n",i+1,delemeter[i]);
	}
	printf("\nKeywords: \n");
	for(int i=0; i<ki; i++){
		printf("%d, %s\n", i+1, keyword[i]);
	}
	printf("\nIdentifiers: \n");
	for(int i=0; i<ii; i++){
		printf("%d, %s\n", i+1, identifier[i]);
	}
	printf("\nString literals: \n");
	for(int i=0; i<lti; i++){
		printf("%d, %s\n", i+1, literal[i]);
	}
}

void file(FILE *fp){
	char ch='\0';
	printf("Program: \n");
	printf("===========================================================\n");
	while(1){
		ch=fgetc(fp);
		if(feof(fp)){
			break;
		}
		printf("%c", ch);
		lexical(&ch);
	}
	printf("===========================================================\n");
	fclose(fp);
}

void main(){
	FILE *f;
	f=fopen("input.txt", "r");
	if(!f){
		printf("File not opened.");
		exit(1);
	}
	printf("==================File opened sucessfully==================\n");
	file(f);
	seperate();
	display();
	printf("\n==================File parsed sucessfully==================\n");
}
