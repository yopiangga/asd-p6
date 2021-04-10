#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char itemType;
typedef struct {
	itemType data[100];
	int count;
} stack;

void initialisasi(stack *s);
int kosong(stack *s);
int penuh(stack *s);
void push(itemType x, stack *s);
void pop(itemType x, stack *s);

int derajat(char);

int main(){
	char operasi[30];
	int panjang, i;
	stack tumpukan;
	
	printf("Masukkan operasi bilangan : ");
	scanf("%s", &operasi);
	fflush(stdin);
	
	panjang = strlen(operasi);
	
	for(i=0; i<panjang; i++){
		if(operasi[i] >= 65 && operasi[i] <= 90 ){
			printf("%c", operasi[i]);
		} else if(operasi[i] == '('){
			push(operasi[i], &tumpukan);
		} else if(operasi[i] == ')'){
			while(!kosong(&tumpukan) || tumpukan->data != ')'){
				printf("%c ", pop(&tumpukan));
			}
		} else {
			if(kosong(tumpukan))
		}

	}
}

int derajat(char x){
	switch(x){
		case '+' :
			return(1);
			break;
		case '-' :
			return(1);
			break;
		case '*' :
			return(2);
			break;
		case '/' :
			return(2);
			break;
		case '^' :
			return(3);
			break;
	}
}
