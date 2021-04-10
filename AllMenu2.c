#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MAX=100;
typedef char itemType;
typedef struct {
	itemType data[100];
	int count;
} stack;

void initialisasi(stack *s);
int kosong(stack *s);
int penuh(stack *s);
void push(itemType x, stack *s);
itemType pop(stack *s);

void cekData();

char operasi[30];
stack tumpukan;
int derajat(char);

int main(){
	char pilih;
	
	do{
		initialisasi(&tumpukan);
		printf("Masukkan operasi bilangan : ");
		scanf("%s", &operasi);
		fflush(stdin);
		cekData();
		
		printf("\n\n");
		printf("Operasi lagi (y)");
		pilih = getchar();
		fflush(stdin);
		
	} while(pilih=='y' || pilih=='Y');
		
}

void cekData(){
	int panjang, i, j;
	panjang = strlen(operasi);
	
	for(i=0; i<panjang; i++){
		if(operasi[i] >= 65 && operasi[i] <= 90 ){
			printf("%c", operasi[i]);
		} else if(operasi[i] == '('){
			push(operasi[i], &tumpukan);
		} else if(operasi[i] == ')'){
			j = i;
			while(tumpukan.data[j] != '('){
				printf("%c ", pop(&tumpukan));
				j--;
			}
		} else {
			if(kosong(&tumpukan)){
				push(operasi[i], &tumpukan);
			} else {
				while(derajat(operasi[i] <= tumpukan.data[tumpukan.count])){
					printf("%c", pop(&tumpukan));
				}
				if(derajat(operasi[i] > tumpukan.data[tumpukan.count]))
					push(operasi[i], &tumpukan);
			}
		}

	}
	while(!kosong(&tumpukan)){
		printf("%c", pop(&tumpukan));
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

