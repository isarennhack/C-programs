/*Você é o responsável por gerar a informação sobre o tempo de duração jogos de tênis em um clube, por isso você resolveu desenvolver um programa em C para auxiliar no cálculo da duração de cada jogo em horas; Para conseguir calcular a duração deve-se informar a hora de início e de fim do jogo (considerando apenas horas inteiras). Considere que a duração máxima do jogo é de 24 horas e que o jogo pode iniciar em um dia e terminar no dia seguinte.

Elabore o programa para automatizar a tarefa de cálculo da duração do jogo.

Realize as consistências necessárias para que o programa consiga calcular a duração da partida.*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int inicio, fim;
    
    printf("Informe o horário de início do jogo (00 - 24): ");
    scanf("%d", &inicio);
    
    if(inicio >= 0 && inicio <= 24){
        printf("\nInforme o horário de término do jogo (00 - 24): ");
        scanf("%d", &fim);
        
        if(fim >= 0 && fim <= 24){
            if(inicio <= fim){
                printf("\n\nO jogo durou %dh.", fim - inicio);
            }
            else {
                printf("\n\nO jogo durou %dh.", fim + (24-inicio));
            }
        }
        else{
            printf("\n\nInforme um horário de término válido.");
        }
    }
    else {
        printf("\n\nInforme um horário de início válido.");
    }
    
    return 0;
}