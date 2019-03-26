#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

//define a estrtura do nó

typedef struct TipoNo
{
    int valor;
    struct TipoNo *prox;
    struct TipoNo *ant;
}TNo;

//Cria início da lista
typedef struct TipoLista
{
    TNo *inicio = NULL;
    TNo *fim = NULL;
}TLista;

void inicializaLista(TLista *pLista)
{
    pLista->inicio = NULL;
    pLista->fim = NULL;

}

void inserirNoInicio(TLista *pLista)
{
    TNo *novoElemento;

    novoElemento = new TNo;

    printf("Informe o valor:");
    scanf("%d",&novoElemento->valor);

    novoElemento->proximo = NULL;
    novoElemento->anterior = NULL;

    if(pLista->inicio == NULL)
    {
        pLista->inicio = novoElemento;
        pLista->fim = novoElemento;
    }
    else
    {
        pLista->inicio->anterior = novoElemento;
        novoElemento->proximo = pLista->inicio;
        pLista->inicio = novoElemento;    
    }

}

void inserirNoFim(TLista *pLista)
{
    TNo *novoElemento;

    novoElemento = TNo;

    printf("Informe o valor:");
    scanf("%d",&novoElemento->valor);

    novoElemento->proximo = NULL;
    novoElemento->anterior = NULL;

    if(pLista->inicio == NULL)
    {
        pLista->inicio = novoElemento;
        pLista->fim = novoElemento;   
    }
    else
    {
        pLista->fim->proximo = novoElemento;
        novoElemento->anterior = pLista->fim;
        pLista->fim = novoElemento;
    }
}

void exibeLista(TLista *pLista){
    TNo *aux;
    if(pLista->inicio == NULL){
        printf("Lista Vazia");
    }
    aux = pLista->inicio;
    while(aux != NULL)
    {
        printf("Info = %dn", aux->valor);
    }
    printf("----------------fim-----------")
}

int main(void)
{
    int op;
    TLista listaDuplamenteEncadeada;

    inicializaLista(&listaDuplamenteEncadeada);

    inserirNoInicio(&listaDuplamenteEncadeada);
    inserirNoInicio(&listaDuplamenteEncadeada);
    inserirNoInicio(&listaDuplamenteEncadeada);
    inserirNoFim(&listaDuplamenteEncadeada);
    exibeLista(&listaDuplamanteEncadeada);
}