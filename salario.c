#include <stdio.h>
#include <stdlib.h>

int main() {
    int setor;
    float salario;
    
    printf("Informe o seu salário:");
    scanf("%f", &salario);
    
    if (salario > 0){
    
        printf("\nSetores:");
        printf("\n1 - A");
        printf("\n2 - B");
        printf("\n3 - C");
        printf("\n4 - D");
        printf("\n5 - E");
        printf("\n\nInforme o setor em que você trabalha:");
        scanf("%d", &setor);
        
        if(setor > 0 && setor <= 5){
            switch (setor) 
                {case 1:
                printf("\n\nO seu novo salário é: R$%.2f", salario*1.10);
                break;
                case 2:
                printf("\n\nO seu novo salário é: R$%.2f", salario*1.15);
                break;
                case 3:
                printf("\n\nO seu novo salário é: R$%.2f", salario*1.20);
                break;
                case 4:
                printf("\n\nO seu novo salário é: R$%.2f", salario*1.25);
                break;
                case 5:
                printf("\n\nO seu novo salário é: R$%.2f", salario*1.20);
                break;
                }
                
        }
        else {
            printf("\nSetor inválido.");
        }
    }
    else {
        printf("\n\nO salário deve ser maior do que zero.");
    }
    
    return 0;
}