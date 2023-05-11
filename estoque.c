/*Um empresário possui um estabelecimento que vende três tipos de produtos. Você deverá elaborar um programa que realize operações sobre o estoque dos produtos. Para isso, informe o código do produto (1, 2 ou 3), o preço unitário de cada um e a quantidade estocada.

O programa deverá fornecer as seguintes informações: 

- os códigos dos produtos que possuem peço superior a 50,00;

- o preço médio dos três produtos estocados;

- o valor total que existe estocado (em reais);

- o produto que possui menos de 10 itens estocados.

Faça as consistências necessárias.*/

#include <stdio.h>

#include <stdlib.h>



int main() {

    int qtd1, qtd2, qtd3;

    //int cd, qtd;

    float vl1, vl2, vl3, media, vl_total;

    

    printf("Produtos: 1, 2 e 3");

    

    printf("\nInforme o valor do produto 1: ");

    scanf("%f", &vl1);

    

    if(vl1 > 0){

        printf("\nInforme a quantidade do produto 1 existente no estoque: ");

        scanf("%d", &qtd1);

    

        if(qtd1>=0){

            printf("\nInforme o valor do produto 2: ");

            scanf("%f", &vl2);

        

            if(vl2 > 0){

                printf("\nInforme a quantidade do produto 2 existente no estoque: ");

                scanf("%d", &qtd2);

                

                if(qtd2 >=0){

                    printf("\nInforme o valor do produto 3: ");

                    scanf("%f", &vl3);

                        

                    if(vl3 > 0){

                        printf("\nInforme a quantidade do produto 3 existente no estoque: ");

                        scanf("%d", &qtd3);

                        

                        if(qtd3 >=0){

                            media = (vl1+vl2+vl3)/3;

                            vl_total = (vl1*qtd1)+(vl2*qtd2)+(vl3*qtd3);

                            

                            printf("\n\nA média dos valores dos produtos é: R$%.2f.", media);

                            printf("\nO valor total existente no estoque é: R$%.2f.", vl_total);

                            

                            if (vl1 >= 50){

                                if(vl2 >= 50){

                                    if(vl3>=50){

                                        printf("\nOs produtos 1, 2 e 3 têm valor superior a R$50,00.");

                                    }

                                    else{

                                        printf("\nOs produtos 1 e 2 têm valor superior a R$50,00.");

                                    }

                                }

                                else{

                                    printf("\nO produto 1 tem valor superior a R$50,00.");

                                }

                            }

                            else {

                                if(vl2>=50){

                                    if(vl3>=50){

                                        printf("\nOs produtos 2 e 3 têm valor superior a R$50,00.");

                                    }

                                    else{

                                        printf("\nO produto 2 tem valor superior a R$50,00.");

                                    }

                                }

                                else{

                                    if(vl3>=50){

                                        printf("\nO produto 3 tem valor superior a R$50,00.");

                                    }

                                    else{

                                        printf("\nNenhum produto tem valor superior a R$50,00.");

                                    }

                                }

                            }

                            if (qtd1 <= 10){

                                if(qtd2 <= 10){

                                    if(qtd3<=10){

                                        printf("\nOs produtos 1, 2 e 3 têm quantidade inferior a 10 unidades estocadas.");

                                    }

                                    else{

                                        printf("\nOs produtos 1 e 2 têm quantidade inferior a 10 unidades estocadas.");

                                    }

                                }

                                else{

                                    printf("\nO produto 1 tem quantidade inferior a 10 unidades estocadas.");

                                }

                            }

                            else {

                                if(qtd2<=10){

                                    if(qtd3<=10){

                                        printf("\nOs produtos 2 e 3 têm quantidade inferior a 10 unidades estocadas.");

                                    }

                                    else{

                                        printf("\nO produto 2 tem quantidade inferior a 10 unidades estocadas.");

                                    }

                                }

                                else{

                                    if(qtd3<=10){

                                        printf("\nO produto 3 tem quantidade inferior a 10 unidades estocadas.");

                                    }

                                    else{

                                        printf("\nNenhum produto possui quantidade inferior a 10 unidades estocadas.");

                                    }

                                }

                            }

                        }

                        else{

                            printf("\n\nA quantidade não pode ser negativa.");

                        }

                    }

                    else{

                        printf("\n\nO valor do produto deve ser maior do que zero.");

                    }

                    

                }

                else{

                    printf("\n\nA quantidade não pode ser negativa.");

                }

            }

            else{

                printf("\n\nO valor do produto deve ser maior do que zero.");

            }

        }

        else{

            printf("\n\nA quantidade não pode ser negativa.");

        }

        

    }

    else{

        printf("\n\nO valor do produto deve ser maior do que zero.");

    }

    

    return 0;

}