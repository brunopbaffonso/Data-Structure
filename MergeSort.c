#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define N 30
#define M 1000

int A[N], opc, i, j, aux, p_max, x;

void merge(left, middle, right){
    int i,j,k;
    i = left;
    j = left;
    k = middle + 1;
    int tempA[N];
    while(j<=middle && k<=right){
        if(A[j]<A[k]){
            tempA[i]=A[j];
            i++;
            j++;
        }
        else{
            tempA[i]=A[k];
            i++;
            k++;
        }
    }
    while(j<=middle){
        tempA[i]=A[j];
        i++;
        j++;
    }
    for(i=left;i<k;i++)
        A[i]=tempA[i];
}

void sort(left,right){
    int middle;
    if(left<right){
        middle = (left + right)/2;
        sort(left,middle);
        sort(middle + 1,right);
        merge(left,middle,right);
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
                sort(0, N-1);
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
                sort(0, N-1);
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
                sort(0, N-1);
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


