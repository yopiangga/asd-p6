#include <stdio.h>
#include <stdlib.h>

int MAX = 5;
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

int main(){
	
	stack tumpukan;
	char jawab;
	itemType x;
	
	printf("Implementasi stack menggunakan array\n");
	initialisasi(&tumpukan);
	printf("Mengisi stack \n");
	do {
		fflush(stdin);
		printf("Masukkan elemen : ");
		scanf("%c", &x);
		push(x, &tumpukan);
		fflush(stdin);
		printf("ada data lagi? ");
		scanf("%c", &jawab);
		puts(" ");
	} while(jawab=='y'|| jawab=='Y');
	
	puts("");
	
	while(!kosong(&tumpukan)){
		printf("%c\n", pop(&tumpukan));
	}
	return 0;
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











