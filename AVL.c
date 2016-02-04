#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct tree
{
  int num;
  int bal;
  struct tree* pai;
  struct tree* sad;
  struct tree* sae;
} Tree;

int Tree_height(Tree *node )
{
    int sae, sad;


    if ( node == NULL ) return -1;


    sae = Tree_height ( node->sae );
    sad = Tree_height ( node->sad );


    if ( sae > sad )
        return sae + 1;
    else
        return sad + 1;
}

int contarNos(Tree* t){

   if(t == NULL)
        return 0;
   else
        return 1 + (contarNos(t->sae) + contarNos(t->sad));

}

Tree *busca(Tree* t, int x)
{
  Tree *p;
  if(t!=NULL)
  {
             if(t->num==x)
             return(t);
             p=busca(t->sae, x);
             if(p!=NULL) return p;
             return(busca(t->sad, x));
  }
  return(NULL);
}

int maior(int a, int b){
    if(a > b)
        return a;
    else
        return b;
}

void desaloca_no(Tree* t)
{
     free(t);
     }

void esvazia_tree(Tree** t)
{
     if(*t!=NULL){
        esvazia_tree(&(*t)->sae);
        esvazia_tree(&(*t)->sad);
        desaloca_no(*t);
        *t=NULL;
        }
     }

int altura(Tree* pRaiz){
   if((pRaiz == NULL) || (pRaiz->sae == NULL && pRaiz->sad == NULL))
       return 0;
   else
       return 1 + maior(altura(pRaiz->sae), altura(pRaiz->sad));
}

Tree* criaTree()
{
  return NULL;
}


int tree_vazia(Tree* t)
{

  return t == NULL;

}

void mostraTree_Inter(Tree* t)
{
    if(t != NULL)
    {
        mostraTree_Inter(t->sae);
        printf("\n%d", t->num);
        mostraTree_Inter(t->sad);
    }
}


void mostraTree_pos(Tree* t)
{
    if(t != NULL)
    {
        mostraTree_pos(t->sae);
        mostraTree_pos(t->sad);
        printf("\n%d", t->num);
    }
}

void mostraTree_pre(Tree* t)
{
  if(t != NULL){
    printf("\n%d ", t->num);
    mostraTree_pre(t->sae);
    mostraTree_pre(t->sad);
  }
}

Tree *rotacaoLL(Tree *p)
{
     Tree *q;

    q = p->sae;
    p->sae = q->sad;
    if ( q->sad != NULL )
        q->sad->pai = p;
    q->sad = p;
    q->pai = p->pai;
    if ( p->pai != NULL )
    {
        if ( p->pai->sae == p )
            p->pai->sae = q;
        else
            p->pai->sad = q;
    }
    p->pai = q;

    q->bal = Tree_height ( q->sae ) - Tree_height ( q->sad );
    p->bal = Tree_height ( p->sae ) - Tree_height ( p->sad );


    return q;
}


Tree *rotacaoRR (Tree *p )
{
    Tree *q;


    q = p->sad;

    p->sad = q->sae;
    if ( q->sae != NULL )
        q->sae->pai = p;
    q->sae = p;
    q->pai = p->pai;
    if ( p->pai != NULL )
    {
        if ( p->pai->sae == p )
            p->pai->sae = q;
        else
            p->pai->sad = q;
    }
    p->pai = q;

    q->bal = Tree_height ( q->sae ) - Tree_height ( q->sad );
    p->bal = Tree_height ( p->sae ) - Tree_height ( p->sad );


    return q;
}


void inserirTree(Tree **pRaiz, Tree **PAI, int numero)
{
    if(*pRaiz == NULL)
    {
        * pRaiz = (Tree *) malloc(sizeof(Tree));
        (*pRaiz)->sae = NULL;
        (*pRaiz)->sad = NULL;
        (*pRaiz)->num = numero;
        (*pRaiz)->pai=(*PAI);
        (*pRaiz)->bal=0;
    }
    else
    {
        if(numero <(*pRaiz)->num)
        {
            inserirTree(& (*pRaiz)->sae,& (*pRaiz), numero);
            (*pRaiz)->bal= Tree_height ( (*pRaiz)->sae ) - Tree_height ( (*pRaiz)->sad );
            if( (*pRaiz)->bal==2)
            {
                if(  (*pRaiz)->sae->bal==1)
                    (*pRaiz)= rotacaoLL ( (*pRaiz) );
                else if(  (*pRaiz)->sae->bal==-1)
                {
                    (*pRaiz)->sae =rotacaoRR ( (*pRaiz)->sae );
                    (*pRaiz)=  rotacaoLL ( (*pRaiz) );
                }
            }




        }
        else
        {
            if(numero >(*pRaiz)->num)
            {
                inserirTree(& (*pRaiz)->sad,& (*pRaiz), numero);
                (*pRaiz)->bal=Tree_height ( (*pRaiz)->sae ) - Tree_height ( (*pRaiz)->sad );
                if( (*pRaiz)->bal==-2)
                {
                    if(  (*pRaiz)->sad->bal==-1)
                        (*pRaiz)= rotacaoRR ( (*pRaiz) );
                    else if(  (*pRaiz)->sad->bal==1)
                    {
                        (*pRaiz)->sad=rotacaoLL ( (*pRaiz)->sad);
                        (*pRaiz)= rotacaoRR ( (*pRaiz) );
                    }
                }
            }
}
}
}

int elemento_Tree(Tree* t, int num) {

  if(tree_vazia(t)) {
    return 0;
  }


  return (t->num==num || elemento_Tree(t->sae, num) || elemento_Tree(t->sad, num));
}
int estrit_bin(Tree* t){

  if(t==NULL)
     return 1;
     if (t->sae !=NULL && t-> sad !=NULL)
        return (estrit_bin(t->sae)&& estrit_bin(t->sad));
        return (t->sae==NULL && t-> sad==NULL);

}

int main()
{
  int numero, op=0, op2=0, x, a;

  Tree* p;

  Tree* t = criaTree();
  Tree* L;
  Tree* aux;
  aux = NULL;
  L = aux;

  do{
      printf("\n1-Inserir \n2-Conta no \n3-Altura \n4-Esvazia \n5-Percurso \n6-Busca \n7-Se e Estritamente Binaria \n8-Sair");
      printf("\n\nOpcao: ");

      scanf("%d", &op);

      switch(op){
                  case 1:{
                       printf("\nDigite um numero: ");
                       scanf("%d", &numero);
                       inserirTree(&t, &aux, numero);
                       break;
                  }
                  case 2:{
                       printf("\nO numero de nos = %d", contarNos(t));
                       printf("\n");
                       break;
                  }
                  case 3:{
                       printf("\nA altura e = %d", altura(t));
                       printf("\n");
                       break;
                  }
                  case 4:{
                       esvazia_tree(&t);
                       break;
                  }
                  case 5:{
                      op2 = 0;
                      while(op2 != 4){
                            printf("\n  1- Prefixado");
                            printf("\n  2- Interfixado");
                            printf("\n  3- Posfixado");
                            printf("\n  4- Voltar ao Menu\n");
                            printf("Opcao: ");
                            scanf("%d", &op2);
                            if(op2 == 1){
                                     mostraTree_pre(t);
                            }
                            if(op2 == 2){
                                    mostraTree_Inter(t);
                            }
                            if(op2 == 3){
                                    mostraTree_pos(t);
                            }
                            if(op2 == 4){
                                    printf("voltando...\n");
                                    break;
                            }
                        }
                    break;
                    }
                    case 6:{
                       printf("\nDigite o numero da busca: ");
                       scanf("%d", &numero);
                       p = busca(t,numero);
                       if(p==NULL) printf("\nElemento nao existe\n");
                       else printf("\nElemento existe\n");
                       break;
                    }
                    case 7:{
                        if (estrit_bin(t))
                           printf("Sim");
                        else
                           printf("Nao");
                           break;
                    }
                    case 8:{
                        printf("Saindo...");
                        break;
                    }
        }
    }while(op != 8);

  getch();
}
