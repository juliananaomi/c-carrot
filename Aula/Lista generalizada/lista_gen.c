
typedef char elem;

typedef struct {
    struct bloco {

    }info;
    int tipo; //atomo ou sublista
    struct bloco *prox;
} no;

typedef struct {
    no* inicio;
} ListaGen;

int esta_na_lista_principal(Lista Gen *L, elem *x) {
    no *p=L->inicio;
    while (p!=NULL) {
        if ((p->tipo==0) &&(p->info.atomo==*x))
            return(1);
        else p= p->prox;
    }
    return(0);
}

int esta_na_lista(no *p, elem*x) {
    if (p==NULL)
        return(0);
    
    else if (p->tipo==0) { //nó do tipo atomo
        if (p->info.atomo==*x) return(1);
        else return(esta_na_lista(p->prox, x))
    }

    else if (p->tipo==1) { //nó do tipo sublista
        if (esta_na_lista(p->info.sublista,x))
            return(1);
        else return(esta_na_lista(p->prox,x));
    }
}