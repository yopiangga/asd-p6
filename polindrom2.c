#include <stdio.h>
#include <stdio.h>
#include <string.h>
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

void menu();

void cekPolindrom(stack *s);
int validasi(stack *s);

int pilih;
char kalimat[MAX];

int main(){
	stack tumpukan;
	initialise(&tumpukan);
	
	do {
		printf("%-25s", "Masukkan kalimat"); printf(": ");
		scanf("%[^\n]", &kalimat);
		fflush(stdin);

		cekPolindrom(&tumpukan);
		
		printf("%-25s", "Cek Lagi (y)"); printf(": ");
		pilih = getchar();
		fflush(stdin);
	} while(pilih == 'y' || pilih == 'Y');
}

void cekPolindrom(stack *s){
	int i, panjang;
	panjang = strlen(kalimat);
	
	for(i=0; i<panjang; i++){
		push(kalimat[i], s);
	}
	
	if(!validasi(s))
		printf("Kalimat %s adalah Polindrom", kalimat);
	else 
		printf("Kalimat %s adalah bukan Polindrom", kalimat);
	printf("\n\n");
}

int validasi(stack *s){
	int i=0, notSame = 0;
	
	while(s->count != 0){
		if(pop(s) != kalimat[i]){
			notSame++;
			break;	
		}
		i++;
	}
	return(notSame);
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




