#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct no{
    int item;
    struct no *esq, *dir;

 };
typedef struct no ptno;

ptno *tree;

ptno* desaloca_no(ptno *p){
    free(p);
}
ptno* esvazia(ptno **tree){
    if(*tree!=NULL){
        esvazia(&(*tree)->esq);
        esvazia(&(*tree)->dir);
        desaloca_no(tree);
        *tree=NULL;
    }
}
int altura(ptno *tree){
    int altesq, altdir;
    if(tree!=NULL){
        if(tree->esq==NULL && tree->dir==NULL)
            return 0;
        altesq=altura(tree->esq);
        altdir=altura(tree->dir);
        if(altesq>altdir)
            return altesq+1;
        else
            return altdir+1;
    }
    return 0;
}
int estritbin(ptno *tree){
    if(tree==NULL)
        return 1;
    if(tree->esq!=NULL && tree->dir!=NULL)
        return estritbin(tree->esq) && estritbin(tree->dir);
    return tree->esq==NULL && tree->dir==NULL;
}

ptno *aloca_no(){struct no{
    int item;
    struct no *esq, *dir;

};

typedef struct no ptno;

ptno *tree;

ptno* desaloca_no(ptno *p){
    free(p);
}
ptno *esvazia(ptno **tree){
    if(*tree!=NULL){
        esvazia(&(*tree)->esq);
        esvazia(&(*tree)->dir);
        desaloca_no(tree);
        *tree=NULL;
        return 1;
    }
}
int altura(ptno *tree){
    int altesq, altdir;
    if(tree!=NULL){
        if(tree->esq==NULL && tree->dir==NULL)
            return 0;
        altesq=altura(tree->esq);
        altdir=altura(tree->dir);
        if(altesq>altdir)
            return altesq+1;
        else
            return altdir+1;
    }
    return 0;
}
    ptno *p;
    p=(ptno *)malloc(sizeof(ptno));
    return p;
 }
 void prefixado(ptno *tree){
    if(tree!=NULL){
        printf("%d\n", tree->item);
        prefixado(tree->esq);
        prefixado(tree->dir);
    }
}
 void interfixado(ptno *tree){
    if(tree!=NULL){
        interfixado(tree->esq);
        printf("%d\n", tree->item);
        interfixado(tree->dir);
    }
}
 void posfixado(ptno *tree){
    if(tree!=NULL){
        posfixado(tree->esq);
        posfixado(tree->dir);
        printf("%d\n", tree->item);
    }
}

int conta_no(ptno *tree){
    if(tree==NULL)
        return 0;
    else
        return (conta_no(tree->esq)+conta_no(tree->dir)+1);
}

ptno* insere(ptno **tree, int x){
    if(*tree == NULL){
        *tree=aloca_no();
        (*tree)->esq=NULL;
        (*tree)->dir=NULL;
        (*tree)->item=x;
        return *tree;
    }else{
        if(x<(*tree)->item)
            insere(&(*tree)->esq, x);
        else
            insere(&(*tree)->dir, x);
    }
}

ptno* busca(ptno* tree, int x){
    if(tree!=NULL){
        if(tree->item==x)
            return tree;
        if(x<tree->item)
            return busca(tree->esq, x);
        return busca(tree->dir, x);
    }
    return NULL;
}


int main(){
    int x, op, op2;
    ptno *aux;
    ptno* p;
    ptno* q;
    ptno* tree;
    tree=NULL;
    op = 0;
    while(op != 8){
        printf("********MENU********\n");
        printf("\n1- Insercao\n");
        printf("2- Percurso\n");
        printf("3- Busca\n");
        printf("4- Altura da Arvore\n");
        printf("5- Conta Nos\n");
        printf("6- Se e Binario\n");
        printf("7- Esvazia\n");
        printf("8- Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);
        switch(op){
            case 1:{
                printf("Digite um valor a ser inserido: ");
                scanf("%d", &x);
                aux = insere(&tree, x);
                if(aux == -1){
                    printf("Sem Sucesso\n");
                }else{
                    printf("Com Sucesso\n");
                }
            break;
            }
            case 2:{
                op2 = 0;
                while(op2 != 4){
                    printf("\n  1- Prefixado");
                    printf("\n  2- Interfixado");
                    printf("\n  3- Posfixado");
                    printf("\n  4- Sair\n");
                    printf("Opcao: ");
                    scanf("%d", &op2);
                        if(op2 == 1){
                                 prefixado(tree);
                        }
                        if(op2 == 2){
                                interfixado(tree);
                        }
                        if(op2 == 3){
                                posfixado(tree);
                        }
                        if(op2 == 4){
                                break;
                        }
                    }
            break;
            }
            case 3:{
                printf("Digite um valor a ser Buscado: ");
                scanf("%d", &x);
                aux = busca(tree, x);
                if(aux == NULL){
                    printf("Sem Sucesso\n");
                }else{
                    printf("Com Sucesso\n");
                }
            break;
            }
            case 4:{
                x=altura(tree);
                printf("A altura da arvore e: %d",x);
                getch();
             break;
            }
            case 5:{
                x=conta_no(tree);
                printf("O numero de nos na arvore e: %d", x);
                getch();
            break;

            }
            case 6:{
                x=estritbin(tree);
                if(x==1)
                    printf("Arvore estritamente binaria!");
                else
                    printf("Arvore NAO e estritamente binaria!");
                getch();
            break;
            }
            case 7:{
                aux = esvazia(&tree);
                if(aux = 1){
                    printf("Lista Vazia");
                }
                else printf("Lista nao foi esvaziada");
                break;
            }
        }
    }
getch();
}
