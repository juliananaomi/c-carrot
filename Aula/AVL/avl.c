void DD (no **r) { \\direita-direita, rotaciona para a esquerda
    no *pai = *r;
    no *filho=pai->dir;
    filho->dir=filho->esq;
    filho->esq = pai;
    pai->fb=0;
    filho->fb=0;
    *r=filho;
}