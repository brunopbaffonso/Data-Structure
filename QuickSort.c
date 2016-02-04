#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define N 30
#define M 1000

int A[N], opc, i, j, aux, p_max, x;

int particao(left,right){
    int i,j,aux;
    double x;
    x = A[right];
    i = left-1;
    for(j=left;j<=right-1;j++){
        if(A[j]<=x){
            //troca(A[i],A[j]);
            i++;
            aux=A[i];
            A[i]=A[j];
            A[j]=aux;
        }
    }
    //troca(A[i+1],A[right]);
    aux=A[i+1];
    A[i+1]=A[right];
    A[right]=aux;
    return (i+1);
}
void quicksort(left, right){
    int q;
    if (left<right){
        q = particao(left,right);
        quicksort (left, q-1);
        quicksort (q+1, right);
    }
}

int main(){

    while(opc != 4){
        printf("******MENU*******\n\n1 - Vetor Ordenado\n2 - Vetor Aleatorio\n3 - Vetor Ordem Inversa\n4 - Sair \n\nOpcao: ");
        scanf("%d", &opc);
        switch(opc)
        {
            case 1:{
                printf("\nVETOR ORIGINAL\n");
                for(i=0; i<N; i++){
                    A[i] = i;
                    printf("%d \n", A[i]);
                }
                quicksort(0, N-1);
                printf("\nVETOR ORDENADO\n");
                for(i=0; i<N; i++){
                    printf("%d \n", A[i]);
                }
            break;
            }
            case 2:{
                printf("\nVETOR ORIGINAL\n");
                for(i=0; i<N; i++){
                    A[i] = rand() % M;
                    printf("%d \n", A[i]);
                }
                quicksort(0, N-1);
                printf("\nVETOR ORDENADO\n");
                for(i=0; i<N; i++){
                    printf("%d \n", A[i]);
                }
            break;
            }
            case 3:{
                x = N;
                printf("\nVETOR ORIGINAL\n");
                for(i=0; i<N; i++){
                    A[i] = x;
                    x--;
                    printf("%d \n", A[i]);
                }
                quicksort(0, N-1);
                printf("\nVETOR ORDENADO\n");
                for(i=0; i<N; i++)
                    {
                    printf("%d \n", A[i]);
                }
            break;
            }
        }
    getch();
    }
}
