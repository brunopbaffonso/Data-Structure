#include<stdio.h>
#include<stdlib.h>
#define N 11

int hash[N];

int insercao(int x){
    int pos, i=1;
    pos = (2*x+5)% N;
    if(hash[pos] == -1 || hash[pos] == -2){
        hash[pos] = x;
        return(1);
    }else{
        while(hash[pos] != -1 && hash[pos] != -2){
            pos = ((2*x)+5+(i*i))%N;
            if(hash[pos] == -1 || hash[pos] == -2){
                hash[pos] = x;
                return (1);
            }
            i++;
        }

    }
    return(0);
}

int remover(int x){
    int pos, i = 1;
    pos = (2*x+5)% N;
    if(hash[pos] == x){
        hash[pos] = -2;
        return(1);
    }else{
        while(hash[pos] != -1 && hash[pos] !=-2){
            pos = ((2*x)+5+(i*i))%N;
            if(hash[pos] == x){
                hash[pos] = -2;
                return(1);
            }
            i++;
        }
    }
    return (0);
}

int busca(int x){
    int pos, i = 1;
    pos = (2*x+5)% N;
    if(hash[pos] == x){
        return (pos);
    }else{
        while(hash[pos] != -1){
            pos = ((2*x)+5+(i*i))%N;
            if(hash[pos] == x){
                return(pos);
            }
            i++;
        }
    }
    return(-1);
}

exibir(){
    int i;
    for(i =0; i<N; i++){
        printf("hash[%d]: %d\n", i, hash[i]);
    }
}

int main(){
    int i, opc, chave, n=0, j;
    float fchave, x, y;

    for(i=0; i<N; i++){
        hash[i] = -1;
    }

    do{
        printf("\n\n1- Inserir\n2- Remover\n3- Buscar\n4- Exibir\n5- Sair\n");
        printf("\nOpcao: ");
        scanf("%d", &opc);

        switch(opc){
        case 1:
            printf("Numero: ");
            scanf("%d", &chave);
            if(n!=N){
                j = insercao(chave);
                if(j==1){
                    n++;
                    printf("Inserido\n");
                    x = n; y = N; fchave = x/y;
                    printf("Fator chave: %.2f", fchave);
                }
                else
                    printf("Nao inserido");
                break;
            }else
                printf("Tabela cheia\n");

        case 2:
            printf("Numero: ");
            scanf("%d", &chave);
            j = remover(chave);
            if(j == 1){
                printf("Removeu\n");
                n--;
                x = n; y = N; fchave = x/y;
                printf("\nFator chave: %.2f", fchave);
            }else  printf("\nNao Encontrado");
            break;

        case 3:
            printf("Numero: ");
            scanf("%d", &chave);
            j = busca(chave);
            if(j != -1){
                printf("\nAchou na Posicao: %d", j);
            }else{
                printf("\nNao Encontrado");
            }
            break;

        case 4:
            exibir();
            break;

        case 5:
            printf ("\nSaindo...\n");
            break;

        default: printf ("\nOpcao invalida\n");
       }
    }while (opc!=5);


    return 0;
}
