#include <stdio.h>
#include <string.h>
#include <time.h>

int menu(){
    int opcao;

    printf("\n\nInforme a opcao desejada");
    printf("\n1-Cadastro de pais");
    printf("\n2-Paises com maior numero de copas");
    printf("\n3-Paises que tiveram sua ultima participacao em 1970");
    printf("\n4-Numero de paises com ultima participacao em determinado ano");
    printf("\n5-Encerrar\n");
    scanf("%d", &opcao);
    while (opcao<=0 || opcao>5)
    {
        printf("\nOpcao invalida.\nDigite novamente: ");
        scanf("%d", &opcao);
    }
    
    return opcao;
}

int main()
{
    FILE *pf;
    char pais[20], aux, winner[20];
    int wins, ano, op, i, moreWins=0, lastTime, cont=0;
    time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);
    FILE *rf;

    op=menu();
    while (op!=5)
    {
        switch (op)
        {
        case 1:
            pf = fopen("copa.txt", "a+t");
            if (pf == NULL) {
                printf("Erro ao abrir o arquivo. \n");
                return;
            } 
            else {
                fflush(stdin);
                printf("\nEntre com o nome do pais: ");
                gets(pais);
                printf("\nInforme a quantidade de copas ganhas: ");
                scanf("%d", &wins);
                while(wins<0){
                    printf("\nA quantidade de copas ganhas nao pode ser negativa.\nDigite novamente: ");
                    scanf("%d", &wins);
                }
                printf("\nInforme o ultimo ano de participacao em copas: ");
                scanf("%d", &ano);
                while(ano<1930 || ano>(tm.tm_year+1900)){
                    printf("\nO ultimo ano de participacao deve estar entre 1930 e %d.\nDigite novamente: ", tm.tm_year+1900);
                    scanf("%d", &ano);
                }
                fprintf(pf, "%s; %d %d", pais, wins, ano);
            }
            fclose(pf);
            op=menu();
            break;
        
        case 2:
            rf = fopen("copa.txt", "rt");
            
            if (rf != NULL) {
                //printf("\nArquivo aberto.\n");
                printf("\nO(s) maior(es) vencedor(es) de copas:\n");
                while (!feof(rf)) {
                    fflush(stdin);
                    fscanf(rf, "%c", &aux);
                    if (aux == ';') {
                        fscanf(rf, "%c", &aux);
                    }
                    i = 0;
                    while (aux != ';') {
                        pais[i++] = aux;
                        fscanf(rf, "%c", &aux);
                    }
                    pais[i] = '\0';
                    fscanf(rf, "%d", &wins);
                    fscanf(rf, "%d", &ano);
                    if(wins>=moreWins){
                        moreWins=wins;
                        strcpy(winner, pais);
                        //strcat(winner, pais); tentei juntar os com maior numero de vitorias, mas buscou de todos os anteriores tbm
                    }               
                }
                puts(winner);
                printf("Numero de vitorias: %d\n", moreWins);
                fclose(rf);
            } 
            else {
                printf("Erro ao abrir o arquivo. \n");
                return 0;
            }
            op=menu();
            break;

        case 3:
            rf = fopen("copa.txt", "rt");
            
            if (rf != NULL) {
                //printf("\nArquivo aberto.\n");
                printf("\nPais(es) que participou(participaram) pela ultima vez em 1970:");
                while (!feof(rf)) {
                    fflush(stdin);
                    fscanf(rf, "%c", &aux);
                    if (aux == ';') {
                        fscanf(rf, "%c", &aux);
                    }
                    i = 0;
                    while (aux != ';') {
                        pais[i++] = aux;
                        fscanf(rf, "%c", &aux);
                    }
                    pais[i] = '\0';
                    fscanf(rf, "%d", &wins);
                    fscanf(rf, "%d", &ano);
                    if(ano==1970){
                        printf("\n%s", pais);
                    }
                }
                fclose(rf);
            } 
            else {
                printf("Erro ao abrir o arquivo. \n");
                return 0;
            }
            op=menu();
            break;

        case 4:
            printf("\nInforme um ano de copa: ");
            scanf("%d", &lastTime);
            while(lastTime<1930 || lastTime >tm.tm_year+1900){
                printf("\nAno invalido.\nDigite novamente: ");
                scanf("%d", &lastTime);
            }

            rf = fopen("copa.txt", "rt");
            if (rf != NULL) {
                //printf("\nArquivo aberto.\n");
                while (!feof(rf)) {
                    fflush(stdin);
                    fscanf(rf, "%c", &aux);
                    if (aux == ';') {
                        fscanf(rf, "%c", &aux);
                    }
                    i = 0;
                    while (aux != ';') {
                        pais[i++] = aux;
                        fscanf(rf, "%c", &aux);
                    }
                    pais[i] = '\0';
                    fscanf(rf, "%d", &wins);
                    fscanf(rf, "%d", &ano);
                    
                        if(ano==lastTime){
                        cont++;
                    }
                }
                fclose(rf);
                printf("\nNumero de paises que participaram pela ultima vez em %d: %d\n", lastTime, cont);
            } 
            else {
                printf("Erro ao abrir o arquivo. \n");
                return 0;
            }
            op=menu();
            break;
        }
    }
    
    return 0;
}
