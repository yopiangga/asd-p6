#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 50

typedef struct{
    char data[MAX];
    int count;
}stack;

void inisial(stack *s);
int penuh(stack *s);
int kosong(stack *s);
void push(char e, stack *s);
char pop(stack *s);
void cetak(stack *s);
int prioritas(char e);

int main()
{
    stack tumpuk;
    int i;
    char expMTK[MAX];
    char *checkFungsi;
    char jawab, operasi;

    inisial(&tumpuk);

    do{

        printf("Masukkan expresi dalam notasi infix : ");
        scanf(" %s", &expMTK);
        fflush(stdin);

        checkFungsi = expMTK;

        while(*checkFungsi != '\0'){
            if(isalnum(*checkFungsi))
                printf("%c ", *checkFungsi);
            else if(*checkFungsi == '(')
                push(*checkFungsi, &tumpuk);
            else if(*checkFungsi == ')'){
                while((operasi = pop(&tumpuk)) != '(')
                    printf("%c ", operasi);
            }
            else{
                while(prioritas(tumpuk.data[tumpuk.count-1]) >= prioritas(*checkFungsi))
                    printf("%c ", pop(&tumpuk));
                push(*checkFungsi, &tumpuk);
            }

        checkFungsi++;
        }

        for(i = 0 ; i < tumpuk.count; i++){
            printf("%c ", pop(&tumpuk));
        }

        printf("\n\nIngin Mengulang? [y/t] ");
        scanf("%c", &jawab);

    }while(jawab == 'y' || jawab == 'Y');
}

int prioritas(char e)
{
    if(e == '(')
        return 0;
    else if(e == '+' || e == '-')
        return 1;
    else if(e == '*' || e == '/')
        return 2;
    else if(e == '^')
        return 3;
    return 0;
}

void inisial(stack *s)
{
    s->count = 0;
}

void push(char e, stack *s)
{

    s->data[s->count] = e;
    s->count++;

}

char pop(stack *s)
{
    char temp;

    --s->count;
    temp = s->data[s->count];

    return temp;
}
