#include<stdio.h>
#include <stdlib.h>
#include<conio.h>
#define N 50

int opc, i, j, aux, p_max, A[N], x;

void bubblesort()
{
    for(i=0; i<N-1; i++)
    {
        for(j=0; j<N-1; j++)
        {
            if(A[j] > A[j+1])
            {
                aux=A[j];
                A[j]=A[j+1];
                A[j+1]=aux;
            }
        }
    }
 }

int main(){

    printf("******MENU******\n\nMetodo de entrada da ARRAY:\n1- Ja Ordenado\n2- Aleatorio\n3- Ordem Inversa\n4- Exit\n\nOpcao: ");
    scanf("%d", &opc);
    while(opc != 4)
    {
        switch(opc)
        {
            case 1:{
                printf("\nVETOR DADO\n");
                for(i=0; i<N; i++){
                    A[i] = i;
                    printf("%d \n", A[i]);
                }
                bubblesort();
                printf("\nVETOR ORDENADO\n");
                for(i=0; i<N; i++){
                    printf("%d \n", A[i]);
                }
            break;
            }
            case 2:{
                printf("\nVETOR DADO\n");
                for(i=0; i<N; i++){
                    A[i] = rand() % 100;
                    printf("%d \n", A[i]);
                }
                bubblesort();
                printf("\nVETOR ORDENADO\n");
                for(i=0; i<N; i++){
                    printf("%d \n", A[i]);
                }
            break;
            }
            case 3:{
                x = N;
                printf("\nVETOR DADO\n");
                for(i=0; i<N; i++){
                    A[i] = x;
                    x--;
                    printf("%d \n", A[i]);
                }
                bubblesort();
                printf("\nVETOR ORDENADO\n");
                for(i=0; i<N; i++)
                    {
                    printf("%d \n", A[i]);
                }
            break;
            }
        }
    }
    getch();
}
