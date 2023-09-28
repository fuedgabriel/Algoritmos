#include <stdio.h>
#include <stdlib.h>


typedef struct no{
    int conteudo;
    struct no *esquerda, *direita;
} No; 

typedef struct {
    No *raiz;
} ArvB;


void inserirEsquerda(No *no, int valor){
     if(no->esquerda == NULL){
        No *novo = (No*)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        no->esquerda = novo;
     }
     else{
        if(valor < no->esquerda->conteudo){
            inserirEsquerda(no->esquerda, valor);
        }
        else{
            inserirDireita(no->esquerda, valor);
        }
     }
}

void inserirDireita(No *no, int valor){
    if(no->direita == NULL){
        No *novo = (No*)malloc(sizeof(No));
        novo->conteudo= valor;
        novo->esquerda=NULL;
        novo->direita=NULL;
        no->direita = novo;
    }
    else{
        if(valor > no->direita->conteudo){
            inserirDireita(no->direita, valor);
        }
        else{
            inserirEsquerda(no->direita, valor);
        }
    }
}


void inserir(ArvB *arv, int valor){
    if(arv->raiz == NULL){
        No *novo = (No*)malloc(sizeof(No));
        novo-> conteudo = valor;
        novo-> esquerda = NULL;
        novo-> direita = NULL;
        arv -> raiz = novo;
    }
    else{
        if(valor < arv->raiz->conteudo){
            inserirEsquerda(arv->raiz, valor);
        }
        else{
            inserirDireita(arv->raiz, valor);
        }
    }

}

void imprimir(No *raiz){
    if(raiz != NULL){
        imprimir(raiz->esquerda);
        printf("%d", raiz->conteudo);
        imprimir(raiz->direita);
    }
}

int main(){
    int op, valor;
    ArvB arv;
    arv.raiz = NULL;

    do{
        printf("\n 0 - sair\n 1 - inseir\n 2 - imprimir\n");
        scanf("%d", &op);

        switch(op){
            case 0:
                printf("\nsaindo...");
                break;
            case 1:
                printf("\nDigite um valor: ");
                scanf("%d", &valor);
                inserir(&arv, valor);
                break;
            case 2:
                printf("\n primindo a arvore");
                imprimir(arv.raiz);
                break;
            default:
                printf("\nopcao invalida...\n");
        }

    }while(op!=0);
    return 0;
}