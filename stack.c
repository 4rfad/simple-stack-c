#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pilha{
  int idade;
  char primeiro_nome[15];
  struct pilha *prox;
}PILHA;

void limpar_tela(void){
   system("clear");
}
void inic(PILHA *p){
   p->prox = NULL;
}
void push(PILHA *p){
  PILHA *tmp;
  tmp = (PILHA *) malloc(sizeof(PILHA));
  putchar('\n');
  printf("Digite o primeiro nome da pessoa: "); scanf("%s",tmp->primeiro_nome);
  printf("Idade: "); scanf("%d",&tmp->idade);
  tmp->prox = p->prox;
  p->prox = tmp;
}
void pop(PILHA *p){
  PILHA *tmp;
  if(p == NULL) return;
  tmp = p->prox;
  p->prox = tmp->prox;
  printf("Atual: %d\n",p->idade);
}
void exibir(PILHA p){
  PILHA *tmp;
  putchar('\n');
  while(tmp != NULL){
    printf("%d,%s\n",tmp->idade,tmp->primeiro_nome);
    tmp = tmp->prox;
  }
}
void pesquisa_NOME(PILHA p,char *N){
  PILHA *tmp;
  if(p.prox == NULL) return; /*Lista vazia*/
  tmp = p.prox;
   while(tmp != NULL){
     if(strcmp(N,tmp->primeiro_nome) == 0){
       printf("%d,%s",tmp->idade,tmp->primeiro_nome);
       putchar('\n');
     }tmp = tmp->prox;
    }  
  
}
void pesquisa_IDADE(PILHA p,int id){
  PILHA *tmp;
  if(p.prox == NULL) return; /*Lista vazia*/
  tmp = p.prox;
   while(tmp != NULL){
     if(tmp->idade == id){
       printf("%d,%s",tmp->idade,tmp->primeiro_nome);
       putchar('\n');
     }tmp = tmp->prox;
    }  
  
}
int main(void){
  PILHA f;
  int op,ida;
  char nome[15]; 
  inic(&f); /*INICIA A PILHA COM PONTEIRO APONTANDO PARA NULL*/
  do{
    putchar('\n');
    printf("\n1. PUSH\n");
    printf("2. POP\n");
    printf("3. EXIBIR\n");
    printf("4. PESQUISA POR NOME\n");
    printf("5. PESQUISA POR IDADE\n");
    printf("0. DAR NO PÉ | 66. LIMPAR TELA\n");
    printf("ESCOLHA: "); scanf("%d",&op);

    switch (op) {
      case 66: limpar_tela(); break;
      case 1: push(&f); break;
      case 2: pop(&f); break;
      case 3: exibir(f); break;
      case 4: printf("Digite o nome que quer pesquisar:"); scanf("%s",nome); 
              pesquisa_NOME(f,nome); 
              break;
      case 5: printf("Digite a idade que quer pesquisar:"); scanf("%d",&ida);
              pesquisa_IDADE(f,ida); 
              break;
      case 0: break;
      default: printf("OPÇÃO INEXISTENTE! EROU!\n"); continue;
    }
  }while(op != 0);  }
