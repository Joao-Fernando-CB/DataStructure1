#include <stdio.h>

typedef struct {
    int codigo;
    double preco;
}Produto;

void aplicarDesconto(Produto *p, double percentual){
    p->preco = p->preco * ((100*percentual)/100);
}

void main(){
    Produto prod;
    prod.codigo = 1;
    prod.preco = 100.93;
    
    
}