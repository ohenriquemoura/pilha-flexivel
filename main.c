#include <stdio.h>
#include <stdlib.h>
//===============================================
typedef struct Celula{
  int dado;
  struct Celula *prox;
}Celula;
//===============================================
Celula* new_celula(int dado){
  Celula *tmp = malloc(sizeof(Celula));
  tmp->dado = dado;
  tmp->prox = NULL;
  return tmp;
}
//===============================================
typedef struct Pilha{
  Celula *topo;
}Pilha;
//===============================================
void new_pilha(Pilha *p){
  p->topo = NULL;
}
//===============================================
void push(Pilha *p, int dado){
  Celula *tmp = new_celula(dado);
  tmp->prox = p->topo;
  p->topo = tmp;
}
//===============================================
int pop(Pilha *p){

  if(p->topo == NULL)
    return -1;

  int res = p->topo->dado;
  Celula *temp = p->topo;
  p->topo = p->topo->prox;
  free(temp);

  return res;
}
//===============================================
void print_pilha(Pilha *p){

  Celula *tmp = p->topo;

  while(tmp!=NULL){
    printf("%d\n", tmp->dado);
    tmp = tmp->prox;
  }

}


//===============================================

int main(void) {
  
  Pilha pilha;

  new_pilha(&pilha);
  push(&pilha,3);
  push(&pilha,5);
  push(&pilha,1);

  print_pilha(&pilha);

  pop(&pilha);
  pop(&pilha);
  pop(&pilha);




  return 0;
}