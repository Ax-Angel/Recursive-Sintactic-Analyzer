#include<stdio.h>
#include<stdlib.h>


void Parser(char string[], int *index);
void E(char string[], int *index);
void EP(char string[], int *index);
void T(char string[], int *index);
void TP(char string[], int *index);
void F(char string[], int *index);
void error(char string[], int *index);

void main(){
	int index = 0;
	char exp[10];
	printf("Ingrese la expresion a evaluar: \n");
	if(fgets(exp, sizeof(exp), stdin)){
		Parser(exp, &index);
		printf("La expresion: %s es valida\n", exp);
	}
}

void E(char string[], int *index){
	
	if ( string[*index]=='(' || string[*index]=='a' || 	string[*index]=='n' || 	string[*index]=='c' ){
		T(string, index);
		EP(string, index);
		return;
	}else{
		error(string, index);
	}
}

void EP(char string[], int *index){
	printf("\n*******\n\n%c   en funcion EP\n\n*******\n",string[*index]);
	if( string[*index]=='+' || string[*index]=='-'){

		(*index)++;
		printf("\n\nSe incrementa index a: %d\n\n", *index);
		T(string, index);
		EP(string, index);
		return;
	}else if(string[*index]==')' || string[*index]=='\n'){
		return;
	}else{
		error(string, index);
	}
}

void T(char string[], int *index){
	printf("\n*******\n\n%c    en funcion T\n\n*******\n",string[*index]);
	if ( string[*index]=='(' || string[*index]=='a' || 	string[*index]=='n' || 	string[*index]=='c' ){
		F(string, index);
		TP(string, index);
		return;
	}else{
		error(string, index);
	}
}

void TP(char string[], int *index){
	printf("\n*******\n\n%c     en funcion TP\n\n*******\n",string[*index]);
	if( string[*index]=='*' || string[*index]=='/'){

		(*index)++;
		printf("\n\nSe incrementa index a: %d\n\n", *index);
		F(string, index);
		TP(string, index);
		return;
	}else if(string[*index]=='+' || string[*index]=='-' || string[*index]==')' || string[*index]=='\n'){
		return;
	}else{
		error(string, index);
	}
}

void F(char string[], int *index){
	printf("\n*******\n\n%c     en funcion F\n\n*******\n",string[*index]);
	if( string[*index]=='('){

		(*index)++;
		printf("\n\nSe incrementa index a: %d\n\n", *index);
		E(string, index);
		if( string[*index]==')'){

			(*index)++;
			printf("\n\nSe incrementa index a: %d\n\n", *index);
		}else{
			error(string, index);
		}
	}else if( string[*index]=='a' || string[*index]=='n' || string[*index]=='c'){

		(*index)++;
		printf("\n\nSe incrementa index a: %d\n\n", *index);
		return;
	}else{
		error(string, index);
	}
}

void error(char string[], int *index){
	printf("Error en la expresion: %s\nEn el indce: %d\n",string, *index);
	exit(0);
}

void Parser(char string[], int *index){
	E(string, index);
	return;
}