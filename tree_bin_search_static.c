#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAXTREE 30

int cont, i, x, cont, op;
int tree[MAXTREE];

int insercao(int *tree, int i, int x){
    if(i>=MAXTREE)
            return -1;
    if(tree[i] == -1){
        tree[i] = x;
        return (i);
    }
    if(x<tree[i]){
            return (insercao(tree, i*2, x));
    }
    return (insercao(tree, ((i*2)+1), x));
}

void percuso_pre(int tree, int i){
    if(i<MAXTREE){
        if(tree[i] != -1){
            printf("%d \n", tree[i]);
            percuso_pre(tree, i*2);
            percuso_pre(tree, (i*2)+1);
        }
    }
}

void percuso_inter(int tree, int i){
    if(i<MAXTREE){
        if(tree[i] != -1){
            percuso_inter(tree, i*2);
            printf("%d \n", tree[i]);
            percuso_inter(tree, (i*2)+1);
        }
    }
}

void percuso_pos(int tree, int i){
    if(i<MAXTREE){
        if(tree[i] != -1){
            percuso_pos(tree, i*2);
            percuso_pos(tree, (i*2)+1);
            printf("%d \n", tree[i]);
        }
    }
}

int busca(int tree, int i, int x){
    if(i<MAXTREE){
        if(tree[i] == (-1)){
            return (-1);
        }
        else if(tree[i] == x){
            return i;
        }
        else if(x<tree[i]){
            return (busca(tree, i*2, x));
        }
        return (busca(tree, (i*2)+1, x));
    }
    return (-1);
}

void esvazia(int *tree){
    for(cont=0; cont<MAXTREE; cont++){
        tree[cont] = (-1);
    }
}

int main(){

    i=0;
    esvazia(&tree);

    printf("********MENU********\n");
    printf("\n1- Insercao\n");
    printf("2- Percurso\n");
    printf("3- Busca\n");
    printf("4- Esvazia\n");
    printf("5- Sair\n");
    while(op != 5){
        switch(op){
            case 1:
                printf("Digite um valor a ser inserido: ");
                scanf("%d ", &x);
                i++;
                insercao(&tree, 1, x);
            break;
            case 2:
                printf("\n  1- Prefixado");
                printf("\n  2- Interfixado");
                printf("\n  3- Posfixado");
                printf("\n  4- Sair\n");
                while(op != 4){
                    switch(op){
                        case 1:
                            i++;
                            percuso_pre(tree, i);
                        break;
                        case 2:
                            i++;
                            percuso_inter(tree, i);
                        break;
                        case 3:
                            i++;
                            percuso_pos(tree, i);
                        break;
                    }
                }
            break;
            case 3:
                printf("Digite um valor a ser Buscado: ");
                scanf("%d ", &x);
                busca(tree, i, x);
            break;
            case 4:
                esvazia(tree);
            break;
        }
    }
getch();
}
