int buscar(no *p, elem *x) {
    if(p==NULL) return(0);
    else if (p->info==*x)
        return(1);
    else if (*x<p->info)
        return(buscar(p->esq, x));
    else return (buscar(p->dir, x));
}

int inserir(no **p, elem *x) {
    if (p==NULL) {
        *p=(no*) malloc(sizeof(no));
        (*p)->esq=NULL;
        (*p)->dir=NULL;
        (*p)->info=*x;
        return(1);
    }
    else if ((*p)->info==*x)
        return(0);
    else if (*x<(*p)->info)
        return(inserir((*p)->esq,x))
    else return(inserir((*p)->dir, x));
}