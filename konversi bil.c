#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 100

typedef int itemType;
typedef struct {
	itemType data[MAX];
	int count;
} stack;

itemType initialisasi(stack *s);
void push(itemType x, stack *s);
itemType pop(stack *s);
int penuh(stack *s);
int kosong(stack *s);
void tampil(stack *s);

void menu();

void biner(int x, stack *s);
void oktal(int x, stack *s);
void heksaDesimal(int x, stack *s);

stack tumpukan;
int pilihan;

int main(){
	do 
		menu();
	while (pilihan != 4);
}

void menu(){
	int bilangan;
	printf("========================\n");
	printf(" Konversi Bilangan\n");
	printf("========================\n");
	printf("1. Biner\n");
	printf("2. Oktal\n");
	printf("3. Heksadesimal\n");
	printf("4. Keluar\n");
	printf("%-25s", "Pilih Menu"); printf(": ");
	scanf("%d", &pilihan);
	fflush(stdin);
	
	if(pilihan >= 1 && pilihan <= 3){
		printf("%-25s", "Masukkan Bilangan"); printf(": ");
		scanf("%d", &bilangan);
		fflush(stdin);
	}
	
	switch(pilihan){
		case 1:
			biner(bilangan, &tumpukan);
			break;
		case 2:
			oktal(bilangan, &tumpukan);
			break;
		case 3:
			heksaDesimal(bilangan, &tumpukan);
			break;
	}
	if(pilihan >= 1 && pilihan <= 3)
		tampil(&tumpukan);
	printf("\n\n");
}


void biner(int x, stack *s){
	printf("Hasil Konversi Desimal %d adalah Biner : ", x); 
	while(x != 0){
		push(x % 2, s);
		x = x/2;
	}
}

void oktal(int x, stack *s){
	printf("Hasil Konversi Desimal %d adalah Oktal : ", x); 
	while(x != 0){
		push(x % 8, s);
		x = x/8;
	}
}

void heksaDesimal(int x, stack *s){
	int hasil, sisa;
	printf("Hasil Konversi Desimal %d adalah Heksadesimal : ", x); 
	while(x != 0){
		if(x % 16 == 10)
			sisa = 'A';
		else if(x % 16 == 11)
			sisa = 'B';
		else if(x % 16 == 12)
			sisa = 'C';
		else if(x % 16 == 13)
			sisa = 'D';
		else if(x % 16 == 14)
			sisa = 'E';
		else if(x % 16 == 15)
			sisa = 'F';
		else 
			sisa = x % 16;
		
		push(sisa, s);
		x = x/16;
	}
}

void tampil(stack *s){
	int hasil;
	while(s->count > 0){
		hasil = pop(s);
		if(hasil < 10)
			printf("%d", hasil);
		else
			printf("%c", hasil);
	}
}

itemType initialisasi(stack *s) {
	s->count = 0;	
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

int penuh(stack *s) {
	if(s->count == MAX){
		printf("Stack penuh gengs");
		return(1);
	} else {
		return(0);
	}
}

int kosong(stack *s) {
	if(s->count== 0)
		return(1);
	else
		return(0);
}







