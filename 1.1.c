#include <stdlib.h>
#include <stdio.h>

int MAX = 5;
typedef char itemType;
typedef struct {
	itemType data[100];
	int count;
} stack;

void initialise(stack *s);
void push(itemType x, stack *s);
itemType pop(stack *s);
int penuh(stack *s);
int kosong(stack *s);

int main(){
	stack tumpukan;
	char jawab;
	itemType x;
	
	printf("Stack Gengs\n");
	
	do {
		printf("Masukkan data : ");
		scanf("%c", &x);
		fflush(stdin);
		push(x, &tumpukan);
		
		printf("Masukkan data lagi (y) : ");
		scanf("%c", &jawab);
		fflush(stdin);
	} while(jawab=='y' || jawab=='Y');
	
	printf("\n");
	
	while(!kosong(&tumpukan)){
		printf("%c ", pop(&tumpukan));
	}
}

void initialise(stack *s) {
	s->count = 0;	
}

void push(itemType x, stack *s) {
	if(penuh(s)){
		printf("Stack Penuh Gan");
	} else {
		s->data[s->count] = x;
		s->count++;
	}	
}

itemType pop(stack *s) {
	itemType x;
	
	if(kosong(s)){
		printf("Stack kosong, belum ada data");
		return(0);
	} else {
		x = s->data[--s->count];
		return(x);
	}
}

int penuh(stack *s) {
	if(s->count == MAX){
		return(1);
	} else {
		return(0);
	}
}

int kosong(stack *s){
	if(s->count == 0){
		return(1);
	} else {
		return(0);
	}
}

