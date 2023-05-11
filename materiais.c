/*Uma loja de materiais de construção está realizando promoções. Para o cliente ter descontos deverá seguir algumas regras. No caixa da loja será utilizado o programa que você irá desenvolver. No programa aparecerá um menu para a seleção do tipo de material a ser comprado. Cada cliente compra apenas 1 tipo de material por vez. O menu que deve ser apresentado é o seguinte:

1 – Tijolo

2 – Telha

3-   Pedra

4 – Torneira

5-  Pia

 O caixa da loja seleciona o tipo de material que o cliente está comprando e informa a quantidade que está sendo comprada, assim como o valor da unidade. A promoção ocorrerá nas seguintes situações:

- Na compra de Telhas, se o cliente estiver comprando mais de 10 unidades terá desconto de 7% no valor unitário;

- Na compra de tijolos o desconto será de 2% na unidade para compras de 200 até 999 unidades e de 5% quando comprar mais de 1000 unidades;

- Na compra de pedras ou torneiras 15% de desconto na unidade, se as compras forem superiores a 7 unidades;

- Ao comprar pia  terá desconto de 3% em uma unidade e de 5% na unidade se comprar mais de uma unidade.

Informe o tipo de material que está sendo comprado, a quantidade, o valor unitário do produto. A saída do programa deve informar: o produto comprado, o valor unitário, o valor total sem o desconto e o valor a ser pago pelo cliente.

Realize as consistências necessárias para que o programa funcione adequadamente.
*/

#include <stdio.h>

#include <stdlib.h>



int main() {

    int produto, qtd;

    float vl_unidade;

    

    printf("Produtos:");

    printf("\n1 - Tijolo");

    printf("\n2 - Telha");

    printf("\n3 - Pedra");

    printf("\n4 - Torneira");

    printf("\n5 - Pia");

    printf("\n\nInforme o produto que está sendo comprado: ");

    scanf("%d", &produto);

    

    if(produto > 0 && produto <= 5){

        printf("\n\nInforme a quantidade do produto: ");

        scanf("%d", &qtd);

        

        if(qtd > 0){

            

            printf("\n\nInforme o valor da unidade do produto: ");

            scanf("%f", &vl_unidade);

            

            if(vl_unidade > 0){

                

                switch (produto)

                {

                case 1:

                    if(qtd >= 200 && qtd <=999){

                        printf("\n\nProduto: Tijolo");

                        printf("\nValor Unitário: R$%.2f", vl_unidade);

                        printf("\nValor total sem desconto: R$%.2f", vl_unidade*(float)qtd);

                        printf("\nValor total com desconto: R$%.2f", (vl_unidade*.98)*(float)qtd);

                    }

                    else{

                        if(qtd >= 1000){

                            printf("\n\nProduto: Tijolo");

                            printf("\nValor Unitário: R$%.2f", vl_unidade);

                            printf("\nValor total sem desconto: R$%.2f", vl_unidade*(float)qtd);

                            printf("\nValor total com desconto: R$%.2f", ((vl_unidade*.95)*(float)qtd));

                        }

                        else{

                            printf("\n\nProduto: Tijolo");

                            printf("\nValor Unitário: R$%.2f", vl_unidade);

                            printf("\nValor Total: R$%.2f", vl_unidade*(float)qtd);

                            }

                        }

                    

                 break;

                 case 2:

                    if(qtd >= 10) {

                        printf("\n\nProduto: Telha");

                        printf("\nValor Unitário: R$%.2f", vl_unidade);

                        printf("\nValor total sem desconto: R$%.2f", vl_unidade*(float)qtd);

                        printf("\nValor total com desconto: R$%.2f", (vl_unidade*.93)*(float)qtd);

                    }

                    else{

                        printf("\n\nProduto: Telha");

                        printf("\nValor Unitário: R$%.2f", vl_unidade);

                        printf("\nValor Total: R$%.2f", vl_unidade*(float)qtd);

                    }

                    

                 break;

                 case 3:

                    if(qtd >= 7){

                        printf("\n\nProduto: Pedra");

                        printf("\nValor Unitário: R$%.2f", vl_unidade);

                        printf("\nValor total sem desconto: R$%.2f", vl_unidade*(float)qtd);

                        printf("\nValor total com desconto: R$%.2f", (vl_unidade*.85)*(float)qtd);

                    }

                    else{

                        printf("\n\nProduto: Pedra");

                        printf("\nValor Unitário: R$%.2f", vl_unidade);

                        printf("\nValor Total: R$%.2f", vl_unidade*(float)qtd);

                    }

                    

                  break;

                  case 4:

                    if(qtd >= 7){

                        printf("\n\nProduto: Torneira");

                        printf("\nValor Unitário: R$%.2f", vl_unidade);

                        printf("\nValor total sem desconto: R$%.2f", vl_unidade*(float)qtd);

                        printf("\nValor total com desconto: R$%.2f", (vl_unidade*.85)*(float)qtd);

                    }

                    else{

                        printf("\n\nProduto: Torneira");

                        printf("\nValor Unitário: R$%.2f", vl_unidade);

                        printf("\nValor Total: R$%.2f", vl_unidade*(float)qtd);

                    }

                    

                 break;

                 case 5:

                    if(qtd == 1){

                        printf("\n\nProduto: Pia");

                        printf("\nValor Unitário: R$%.2f", vl_unidade);

                        printf("\nValor total sem desconto: R$%.2f", vl_unidade*(float)qtd);

                        printf("\nValor total com desconto: R$%.2f", (vl_unidade*.97)*(float)qtd);

                    }

                    else{

                        printf("\n\nProduto: Pia");

                        printf("\nValor Unitário: R$%.2f", vl_unidade);

                        printf("\nValor total sem desconto: R$%.2f", vl_unidade*(float)qtd);

                        printf("\nValor total com desconto: R$%.2f", (vl_unidade*.95)*(float)qtd);

                    }

                    

                 break;

                }

            }

            else{

                printf("\n\nO valor unitário deve ser maior do que zero.");

            }

        }

        else{

            printf("\n\nA quantidade deve ser maior do que zero.");

        }

    }

    else{

        printf("\n\nInforme um produto válido.");

    }

    

    return 0;

}