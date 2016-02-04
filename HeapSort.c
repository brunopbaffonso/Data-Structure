#include<stdio.h>
#include<conio.h>
#define n 6
#define m 1000
int A[n], lenght, i, j, opc, x, aux;

void constroi_heap()
{
	for(i=(n-1)/2; i>=0; i--){
		descer(i, n-1);
    }
}

void descer(i, lenght)
{
    j = (i*2)+1;
    while(j <= lenght){
        if(j < lenght && A[j+1] > A[j])
            j++;
        if(A[i] < A[j]){
            aux = A[i];
            A[i] = A[j];
            A[j] = aux;
            i = j;
            j =(i*2)+1;
        }
    else j = lenght+1;
	}
}

void heap_sort()
{
    constroi_heap ();
	for(i=n-1; i >= 1; i--){
        aux = A[0];
        A[0] = A[i];
        A[i] = aux;
        descer (0, i-1);
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
                for(i=0; i<n; i++){
                    A[i] = i;
                    printf("%d \n", A[i]);
                }
                heap_sort();
                printf("\nVETOR ORDENADO\n");
                for(i=0; i<n; i++){
                    printf("%d \n", A[i]);
                }
            break;
            }
            case 2:{
                printf("\nVETOR ORIGINAL\n");
                for(i=0; i<n; i++){
                    A[i] = rand() % m;
                    printf("%d \n", A[i]);
                }
                heap_sort();
                printf("\nVETOR ORDENADO\n");
                for(i=0; i<n; i++){
                    printf("%d \n", A[i]);
                }
            break;
            }
            case 3:{
                x = n;
                printf("\nVETOR ORIGINAL\n");
                for(i=0; i<n; i++){
                    A[i] = x;
                    x--;
                    printf("%d \n", A[i]);
                }
                heap_sort();
                printf("\nVETOR ORDENADO\n");
                for(i=0; i<n; i++)
                    {
                    printf("%d \n", A[i]);
                }
            break;
            }
        }
        getch();
    }
}
