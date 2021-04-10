#include <stdio.h>
#include <stdio.h>
#define MAX 100

typedef char itemType;
typedef struct {
	itemType data[MAX];
	int count;
} stack;

void initialise(stack *s);
void push(itemType x, stack *s);
itemType pop(stack *s);
int penuh(stack *s);
int kosong(stack *s);

void tambah();
void ambil();
void tampil();

void menu();

int pilihanMenu;
stack tumpukan;

int main(){
	
	initialise(&tumpukan);
	
	do {
		menu();
	} while (pilihanMenu != 4);
}

void menu(){
	printf("========================\n");
	printf(" Menu Stack\n");
	printf("========================\n");
	printf("1. Push\n");
	printf("2. Pop\n");
	printf("3. Cetak Data\n");
	printf("4. Keluar\n");
	printf("%-25s", "Pilih Menu"); printf(": ");
	scanf("%d", &pilihanMenu);
	fflush(stdin);
	
	if(kosong(&tumpukan) && pilihanMenu == 2 || kosong(&tumpukan) && pilihanMenu == 3)
		printf("Data masih kosong");
	else {
		switch(pilihanMenu){
			case 1:
				tambah();
				break;
			case 2:
				ambil();
				break;
			case 3:
				tampil(&tumpukan);
				break;
		}
	}
	
	printf("\n");
}

void initialise(stack *s) {
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

void tambah(){
	itemType x;
	
	printf("%-25s", "Masukkan elemen"); printf(": ");
	scanf("%c", &x);
	push(x, &tumpukan);
}

void ambil(){
	printf("%c ", pop(&tumpukan));
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

void tampil(stack *s){
	int i;
	if(kosong(s)){
		printf("stack kosong, tidak ada data ");
	} else {
		for(i=s->count-1; i>=0; i--){
			printf("%c ", s->data[i]);
		}
	}	
}



