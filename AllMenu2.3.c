#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef char itemType;
typedef struct {
	itemType data[MAX];
	int count;
} stack;

void initialisasi(stack *s);
int kosong(stack *s);
int penuh(stack *s);
void push(itemType x, stack *s);
itemType pop(stack *s);

void cekData(stack *s);

itemType operasi[MAX];
stack tumpukan;
itemType derajat(itemType);

int main(){
	char pilih;
	
	do{
		initialisasi(&tumpukan);
		printf("Masukkan operasi bilangan : ");
		scanf("%s", &operasi);
		fflush(stdin);
		
		cekData(&tumpukan);
		
		printf("\n\n");
		printf("Operasi lagi (y)");
		pilih = getchar();
		fflush(stdin);
		
	} while(pilih=='y' || pilih=='Y');
		
}

void cekData(stack *s){
	int panjang, i;
	itemType oper;
	panjang = strlen(operasi);
	
	for(i=0; i<panjang; i++){
		if(operasi[i] >= 65 && operasi[i] <= 90 || operasi[i] >= 48 && operasi[i] <= 57 || operasi[i] >= 97 && operasi[i] <= 122){
			printf("%c", operasi[i]);
		} else if(operasi[i] == '('){
			push(operasi[i], s);
		} else if(operasi[i] == ')'){
			while((oper = pop(s)) != '('){
				printf("%c", oper);
			}
		} else {
			if(kosong(s) || (derajat(operasi[i]) > derajat(s->data[s->count-1])))
				    push(operasi[i], s);
			else{
				while(derajat(operasi[i]) < derajat(s->data[s->count-1]))
				    printf("%c", pop(s));
				push(operasi[i], s);
			}

		} 	
		if(i==panjang-1){
			while(!kosong(s)){
					printf("%c", pop(s));
			}
		}
	}
}

itemType derajat(itemType x){
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
		case '(' : 
			return(0);
			break;
	}
}

void initialisasi(stack *s) {
	s->count = 0;
}

int kosong(stack *s){
	if(s->count== 0)
		return(1);
	else
		return(0);
}

int penuh(stack *s) {
	if(s->count == MAX)
		return(1);
	else 
		return(0);
}

void push(itemType x, stack *s) {
	if(penuh(s))
		printf("Stack penuh, tidak bisa menyimpan data\n");
	else {
		s->data[s->count] = x;
		s->count++;
	}
}

itemType pop(stack *s) {
	itemType x;
	
	if(kosong(s)){
		printf("stack kosong, tidak ada data ");
		return(0);
	} else {
		x = s->data[--s->count];
		return(x);		
	}
}
