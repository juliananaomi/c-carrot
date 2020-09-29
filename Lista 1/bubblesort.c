#include <stdio.h>

void ordernar(int v[]) {
    int aux, i, j, trocado;
    trocado = 1;
    for(j=4; (j>=1) && (trocado==1);j--) {
      trocado=0;
      for (i=0; i<j; i++) {
        if (v[i] > v[i+1]) {
            aux = v[i+1];
            v[i+1] = v[i];
            v[i] = aux;
            trocado = 1;
        }
      }
    }
}

int main(void)  {
    int i, n, v[5];
    n=5;
    for (i=0; i<n; i++)    {
        printf("Digite os numeros a serem ordenados %d: ", i+1);
        scanf("%d", &v[i]);
    }
    ordernar(v);
    for(i=0; i<n; i++)printf("%d ", v[i]);
    return(0);
}