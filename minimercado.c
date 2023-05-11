# include <stdio.h>
# include <time.h>
# include <conio.h>

typedef struct dma {
	int dia;
	int mes;
	int ano;
} data;

typedef struct prod {
	int cod;
	data vencimento;
	float pCompra;
	float pVenda;
    int quantidade;	
} produto;

int validacaoData (int dia, int mes, int ano)
{
   int erro = 0, bissexto = 0;
   switch (mes)
   {
	   case 2: if (ano % 4 == 0)
	           {
			         	bissexto = 1;
			     	}
					else
					{
				    	if (ano % 100 == 0 && ano % 400 == 0)
						{
							bissexto = 1;
						}
					}
							
					if (dia > 28)
					{
					   if (dia == 29)
					   {
					  	  if (bissexto == 0)
						  {
							 erro = 1;
						  }
					   	}
					    else
					    {
					     	erro = 1;
					   	}
					}
							        									
					break;
			case 4:
			case 6:
			case 9:
			case 11: if (dia > 30)	
			         {
			         	erro = 1;
					 }	
					 break; 	 
	}

	return erro;
}


main() {
    int qtd, cont=1, i, dt, proxDias;
    float lucro, lucroTotal=0, perdas=0;
    data hoje;
    time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);
    
    printf("Informe a quantidade de produtos existentes no estabelacimento: ");
    scanf("%d", &qtd);
    while (qtd<=0){
        printf("\nA quantidade deve ser maior que zero\nInforme novamente: ");
        scanf("%d", &qtd);
    }

    produto estoque[qtd];

    for(i=0; i<qtd; i++){
        estoque[i].cod = cont;

        printf("\nInforme o dia de vencimento do produto %d: ", cont);
        scanf("%d", &estoque[i].vencimento.dia);
        while(estoque[i].vencimento.dia<=0 || estoque[i].vencimento.dia>31){
            printf("\nO dia deve estar entre 1 e 31.\nInforme novamente %d: ", cont);
            scanf("%d", &estoque[i].vencimento.dia);
        }
        printf("\nInforme o mes de vencimento do produto %d: ", cont);
        scanf("%d", &estoque[i].vencimento.mes);
        while(estoque[i].vencimento.mes<=0 || estoque[i].vencimento.mes>12){
            printf("\nO mes deve estar entre 1 e 12.\nInforme novamente %d: ", cont);
            scanf("%d", &estoque[i].vencimento.mes);
        }
        printf("\nInforme o ano de vencimento do produto %d: ", cont);
        scanf("%d", &estoque[i].vencimento.ano);
        while(estoque[i].vencimento.ano<=0){
            printf("\nO ano deve ser maior do que zero.\nInforme novamente %d: ", cont);
            scanf("%d", &estoque[i].vencimento.ano);
        }
        dt = validacaoData(estoque[i].vencimento.dia, estoque[i].vencimento.mes, estoque[i].vencimento.ano);
        if(dt){
            printf("\nErro. Data inconsistente.");
        }

        printf("\nInforme o preco de compra do produto: ");
        scanf("%f", &estoque[i].pCompra);
        while (estoque[i].pCompra<=0){
            printf("\nO preco deve ser maior que zero.\nDigite novamente: ");
            scanf("%f", &estoque[i].pCompra);
        }
        printf("\nInforme o preco de venda do produto: ");
        scanf("%f", &estoque[i].pVenda);
        while (estoque[i].pVenda<=estoque[i].pCompra){
            printf("\nO preco de venda deve ser maior do que o preco de compra.\nDigite novamente: ");
            scanf("%f", &estoque[i].pVenda);
        }
        printf("\nInforme a quantidade estocada do produto: ");
        scanf("%d", &estoque[i].quantidade);
        while (estoque[i].quantidade<=0){
            printf("\nA quantidade deve ser maior que zero.\nDigite novamente: ");
            scanf("%d", &estoque[i].quantidade);
        }
        cont++;
    }
    
    //por ter validado com a data do sistema, acredito que nem precisaria solicitar ao usuario
    printf("\nInforme o dia atual: ");
    scanf("%d", &hoje.dia);
    while (hoje.dia!=tm.tm_mday){
        printf("\nNao condiz com o dia do sistema.\nDigite novamente: ");
        scanf("%d", &hoje.dia);
    }
    printf("\nInforme o mes atual: ");
    scanf("%d", &hoje.mes);
    while (hoje.mes!=(tm.tm_mon+1)){
        printf("\nNao condiz com o mes do sistema.\nDigite novamente: ");
        scanf("%d", &hoje.mes);
    }
    printf("\nInforme o ano atual: ");
    scanf("%d", &hoje.ano);
    while (hoje.ano!=(tm.tm_year + 1900)){
        printf("\nNao condiz com o ano do sistema.\nDigite novamente: ");
        scanf("%d", &hoje.ano);
    }

    for(i=0; i<qtd; i++){
        lucro=0;
        if(estoque[i].vencimento.ano>tm.tm_year+1900){
            lucro = ((estoque[i].pVenda - estoque[i].pCompra)*estoque[i].quantidade);
            lucroTotal += lucro;
        }
        else{
            if(estoque[i].vencimento.mes>tm.tm_mon+1){
                lucro = ((estoque[i].pVenda - estoque[i].pCompra)*estoque[i].quantidade);
                lucroTotal += lucro;
            }
            else{
                if(estoque[i].vencimento.dia>tm.tm_mday){
                    lucro = ((estoque[i].pVenda - estoque[i].pCompra)*estoque[i].quantidade);
                    lucroTotal += lucro;
                }
                else{
                    lucro = ((estoque[i].pVenda - estoque[i].pCompra)*estoque[i].quantidade);
                    perdas += lucro;
                }
            }
        }
    }
    printf("\nLucro total dos produtos em estoque: R$%.2f", lucroTotal);
    printf("\nPerdas por prazo de validade: R$%.2f", perdas);

    for(i=0; i<qtd; i++){
        if(estoque[i].vencimento.ano == tm.tm_year+1900){
            if(estoque[i].vencimento.mes >= tm.tm_mon+1){
                if((estoque[i].vencimento.dia-tm.tm_mday== 10)){
                    printf("\nProduto de codigo %d esta para vencer em 10 dias", estoque[i].cod);
                    //nao consegui pensar em como validar para meses e anos diferentes
                }
            }
        }
    }

    return 0;
}
