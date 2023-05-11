#include <stdio.h>

void impressao_recursiva(int vetor[], int tam){
    if(tam>=1){
        impressao_recursiva(vetor, tam-1);
        if(tam%2==0)
        printf("\n%d", vetor[tam]);
    }
    else {
        printf("\n%d", vetor[tam]);
    }
};

main(){
    int vet[10], i, n=9;

    for(i=0;i<10;i++){
        printf("Informe um valor para a posicao %d do vetor: ", i);
        scanf("%d", &vet[i]);
    }

    impressao_recursiva(vet, n);

    return 0;
}