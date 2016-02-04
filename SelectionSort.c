#include<stdio.h>
#include <stdlib.h>
#include<conio.h>
#define N 50

int opc, i, j, aux, p_max, A[N], x;

int selectionSort(){
    for(i=N; i>1; i--){
        p_max=0;
        for(j=1; j<i; j++){
            if(A[j] > A[p_max]){
                p_max=j;
            }
        aux = A[i-1];
        A[i-1] = A[p_max];
        A[p_max] = aux;
        }
    }
    return p_max;
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
                selectionSort();
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
                selectionSort();
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
                selectionSort();
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
