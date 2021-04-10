#include <stdio.h>
#include <stdio.h>
#include <string.h>
#define MAX 100

typedef char itemType;
typedef struct element Node;
struct element {
	itemType data;
	Node *next;
};

Node *tos, *p;

void initialise();
void push(itemType);
itemType pop();
int kosong();

void alokasi();
void tambah();
void ambil();
void tampil();

void menu();

int pilihanMenu;

int main(){
	
	initialise();
	
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
	
	switch(pilihanMenu){
		case 1:
			tambah();
			break;
		case 2:
			ambil();
			break;
		case 3:
			tampil();
			break;
	}
	printf("\n");
}

void initialise() {
	tos = NULL;
}

int kosong(){
	if(tos== 0)
		return(1);
	else
		return(0);
}

void alokasi(){
	int x;
	
	printf("%-25s", "Masukkan data "); printf(": ");
	scanf("%c", &x);
	fflush(stdin);
	
	p = malloc(sizeof(Node));
	
	if(p ==NULL){
		printf("Alokasi memori gagal");
		exit(0);
	}
	
	p->data = x;
	p->next = NULL;
}

void tambah(){
	alokasi();
	
	push(p->data);
}

void push(itemType x){

	if(tos != NULL)
		p->next = tos;
	tos = p;
}

void ambil(){
	printf("%c ", pop());
}

itemType pop() {
	itemType x;
	
	if(tos == NULL){
		printf("stack kosong, tidak ada data ");
		return(0);
	} else {
		x = tos->data;
		tos = tos->next;
		return(x);	
	}
}

void tampil(){
	Node *jalan;
	jalan = tos;
	while(jalan != NULL){
		printf("%c ", jalan->data);
		jalan = jalan->next;
	}
}




