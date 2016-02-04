#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#define N 11

//LISTA DINAMICA
struct no{
	int item;
	struct no *prox;
};

int chave, n=0, i, r;

struct no *hash[N];

struct no *aloca_no(){
	struct no *h;
	h= (struct no *)malloc(sizeof(struct no));
	return h;

}
void desaloca_no(struct no *h){
    free (h);
	h=NULL;
}
//FIM

//HASH
int pesquisa(){
	struct no *aux;
	int pos;
	pos=(2*chave+5)%N;
	aux = hash[pos];
	while(aux!=NULL){
		if((aux->item)==chave){
			printf("Com sucesso!");
            return 1;
        }
        else{
             aux = aux->prox;
        }
    }
    printf("Sem Sucesso");
}

void insercao(){
	struct no *aux, *p;
	int pos;
	pos=(2*chave +5)%N;
	aux = hash[pos];
	p=aloca_no();
	p->item=chave;
	p->prox=aux;
	hash[pos]=p;
	n++;
}
void exibicao(){

	struct no *aux;
	for(i=0; i<N; i++){
		printf("%d: ", i);
		aux = hash[i];
		while(aux!=NULL){
			printf("%d , ",aux->item);
			aux=aux->prox;
		}
		printf("\n\n");
	}
}
int remocao(){
	int pos;
	struct no *aux;
	struct no *ant;
	pos=(2*chave+5)%N;
	ant=NULL;
	aux=hash[pos];
	while(aux!=NULL){
		if(aux->item == chave){
			if(ant != NULL){
				ant->prox=aux->prox;
			}else{
				hash[pos]=aux->prox;
			}
				n--;
				desaloca_no(aux);
				aux=NULL;
				return 1;
		}else{
			ant=aux;
			aux=aux->prox;
			return 0;
		}
	}
}

//main
main(){
	int  op;
	for(i=0; i<N; i++){
		hash[i]=NULL;
	}

	 do{
        system("cls");
        printf("******MENU********* \n1- Insercão \n2- Remocao \n3- Pesquisa \n4- Exibicao \n5- Sair\n");

        printf("\nDigite a opcao: ");
        scanf("%d", &op);

        switch(op){
            case 1:
                printf("Digite o numero a ser inserido: ");
                scanf("%d", &chave);
                insercao();
		     	printf("FATOR DE CARGA: %d / %d ", n, N);
                getch();
                break;
            case 2:

            	printf("Digite o numero a ser Removido: ");
                scanf("%d", &chave);
		     	r=remocao();
		     	printf("FATOR DE CARGA: %d / %d ", n, N);
		      	if(r==1){
		       		printf("\nSucesso");
	         	}else{
		        	printf("\nSem sucesso!");
		       	}
                getch();
				break;
            case 3:
                 printf("Digite o valor a ser buscado: ");
                 scanf("%d", &chave);
                 pesquisa();
                 getch();
                 break;

            case 4:
                 exibicao();
                 getch();
                 break;

            default:
                printf("Opcao invalida!");
                getch();

        }

    }while(op!=5);

}
