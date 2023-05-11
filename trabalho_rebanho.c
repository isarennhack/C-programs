// trabalho - controle do rebanho

#include <stdio.h>
#include <stdlib.h>

int cad_femea(int v[10], float pv[10], int ta[10], float pta[10]);
int cad_macho(int b[10], float pb[10], int to[10], float pto[10]);
int remove_terneiro(int indice, int t[10], float pto[10], int ta[10], float pta[10]);
int total(int vacas[10], int bois[10], int terneiras[10], int terneiros[10]);
float p_bois(float pb[10]);
int animais_raca(int v[10], int b[10], int ta[10], int to[10]);
float altera_peso(int indice, float pvaca[10], int v[10], float pboi[10], int b[10], float pterneira[10], int ta[10], float pterneiro[10], int to[10]);
int menu(int op);
void limpa();

int main() {
    int opcao, vacas[10]={0}, terneiras[10]={0}, bois[10]={0}, terneiros[10]={0}, i;
    float peso_bois[10]={0}, peso_vacas[10]={0}, peso_terneiros[10]={0}, peso_terneiras[10]={0}, total_peso_bois;
    char resp, vt;
    
    do{
      opcao=menu(opcao);
      total_peso_bois=p_bois(peso_bois);
    
      switch (opcao){
          case 1:
            limpa();
            printf("Cadastro de Fêmeas");
            cad_femea(vacas, peso_vacas, terneiras, peso_terneiras);
            break;
          case 2:
            limpa();
            printf("Cadastro de Machos");
            cad_macho(bois, peso_bois, terneiros, peso_terneiros);
            break;
          case 3:
            limpa();
            printf("Remoção de Terneiro");
            remove_terneiro(i, terneiros, peso_terneiros, terneiras, peso_terneiras);
            break;
          case 4:
            limpa();
            printf("Quantidade total de animais no rebanho");
            total(vacas, bois, terneiros, terneiras);
            break;
          case 5:
            limpa();
            printf("Peso total dos bois");
            printf("\n%.2f Kg", total_peso_bois);
            break;
          case 6:
            limpa();
            printf("Quantidade de animais por raça");
            animais_raca(vacas, bois, terneiras, terneiros);
            break;
          case 7:
            limpa();
            printf("Alteração de peso do animal");
            altera_peso(i, peso_vacas, vacas, peso_bois, bois, peso_terneiras, terneiras, peso_terneiros, terneiros);
            break;
          default: 
            limpa();
            printf("\nFim do programa.");
      }
    }
    while (opcao!=8);
  
    return 0;
}

int menu(int op){
  //int op;
    
    printf("\n\nInforme a opção desejada:");
    printf("\n\n1 - Cadastrar fêmeas");
    printf("\n\n2 - Cadastrar machos");
    printf("\n\n3 - Remover terneiro");
    printf("\n\n4 - Quantidade total de animais no rebanho");
    printf("\n\n5 - Peso total dos bois");
    printf("\n\n6 - Quantidade total de animais de determinada raça");
    printf("\n\n7 - Alteração do peso do animal");
    printf("\n\n8 - Fim\n\n");
    scanf("%d", &op);    
    
    while (op <= 0 || op > 8){
        printf("\nInforme a opção desejada: ");
        scanf("%d", &op);
    }
  return (op);
}

void limpa(){
  system("clear");
}

int total(int vacas[10], int bois[10], int terneiros[10], int terneiras[10]){
  int total_geral=0, total_vacas=0, total_bois=0, total_terneiros=0, total_terneiras=0;
  int i;
  for(i=0; i<10; i++){
    if(vacas[i]!=0){
      total_geral++;
      total_vacas++;
    }
    if(bois[i]!=0){
      total_geral++;
      total_bois++;
    }
    if(terneiros[i]!=0){
      total_geral++;
      total_terneiros++;
    }
    if(terneiras[i]!=0){
      total_geral++;
      total_terneiras++;
    }
  }
  printf("\n\nTotal geral: %d", total_geral);
  printf("\nVacas: %d", total_vacas);
  printf("\nBois: %d", total_bois);
  printf("\nTerneiras: %d", total_terneiras);
  printf("\nTerneiros: %d", total_terneiros);
}

float p_bois(float pb[10]){
  int i;
  float total_peso=0;
  for (i=0; i<10; i++){
    total_peso+=pb[i];
  }
  return (total_peso);
}

int cad_femea(int v[10], float pv[10], int ta[10], float pta[10]){
  char vt, sn;
  int i=0;
  printf("\n\nVocê deseja cadastrar uma vaca ou uma terneira? (v/t) ");
  scanf("%s", &vt);

  while(vt!='v' && vt!='t'){
    printf("\n\nDigite 'v' para vaca e 't' para terneira ");
    scanf("%s", &vt);
  }
  
  printf("\nRaças");
  printf("\n\n1-Nelore");
  printf("\n\n3-Gir, e");
  printf("\n\n4-Jersey");
  
  if(vt=='v'){  
    for(i=0; i<10; i++){
        if(v[i]==0){
          printf("\n\nInforme a raça da vaca %d: ", i);
          scanf("%d", &v[i]);
          while(v[i]<=0 || v[i]==2 || v[i]>4){
            printf("\nValor inválido.");
            printf("\n\nInforme a raça da vaca %d: ", i);
            scanf("%d", &v[i]);
          }
          printf("\nInforme o peso da vaca %d: ", i);
          scanf("%f", &pv[i]);
          while(pv[i]<=100){
            printf("\nUma vaca deve ter peso superior a 100kg.");
            printf("\n\nInforme o peso da vaca %d: ", i);
            scanf("%f", &pv[i]);
          }
          printf("\nDeseja continuar? (s/n) ");
          scanf("%s", &sn);
          while(sn!='s'&&sn!='n'){
            printf("\nDigite 's' para sim e 'n' para não ");
            scanf("%s", &sn);
          }
          if(sn=='n') i=11;
        }     
      }
    if(i==10) printf("\nJá existem 10 animais nessa categoria.");
    }
    else{
      if(vt=='t'){
        for(i=0; i<10; i++){
          if(ta[i]==0){
            printf("\n\nInforme a raça da terneira %d: ", i);
            scanf("%d", &ta[i]);
            while(ta[i]<=0 || ta[i]==2 || ta[i]>4){
              printf("\nValor inválido.");
              printf("\n\nInforme a raça da terneira %d: ", i);
              scanf("%d", &ta[i]);
            }
            printf("\nInforme o peso da terneira %d: ", i);
            scanf("%f", &pta[i]);
            while(pta[i]<=20 || pta[i]>100){
              printf("\nUma terneira deve ter peso entre 20kg e  100kg.");
              printf("\n\nInforme o peso da terneira %d: ", i);
              scanf("%f", &pta[i]);
            }
            printf("\nDeseja continuar? (s/n) ");
            scanf("%s", &sn);
            while(sn!='s'&&sn!='n'){
            printf("\nDigite 's' para sim e 'n' para não ");
            scanf("%s", &sn);
            }
            if(sn=='n') i=11;
          }
      }
        if(i==10) printf("\nJá existem 10 animais nessa categoria.");
    }
  }
}
  
int cad_macho(int b[10], float pb[10], int to[10], float pto[10]){
  char bt, sn;
  int i=0, repete;
  printf("\n\nVocê deseja cadastrar um boi ou um terneiro? (b/t) ");
  scanf("%s", &bt);
  while(bt!='b' && bt!='t'){
    printf("\n\nDigite 'b' para boi e 't' para terneiro. ");
  scanf("%s", &bt);
  }
  
  printf("\nRaças");
  printf("\n\n1-Nelore");
  printf("\n\n2-Angus");
  printf("\n\n3-Gir, e");
  
  if(bt=='b'){
    for(i=0; i<10; i++){
        if(b[i]==0){
          printf("\n\nInforme a raça do boi %d: ", i);
          scanf("%d", &b[i]);
          while(b[i]<=0 || b[i]>=4){
            printf("\nValor inválido.");
            printf("\n\nInforme a raça do boi %d: ", i);
            scanf("%d", &b[i]);
          }
          printf("\nInforme o peso do boi %d: ", i);
          scanf("%f", &pb[i]);
          while(pb[i]<=120){
            printf("\nUma vaca deve ter peso superior a 120kg.");
            printf("\n\nInforme o peso do boi %d: ", i);
            scanf("%f", &pb[i]);
          }
          printf("\nDeseja continuar? (s/n) ");
          scanf("%s", &sn);
          while(sn!='s'&&sn!='n'){
            printf("\nDigite 's' para sim e 'n' para não ");
            scanf("%s", &sn);
          }
          if(sn=='n') i=11;
        }
    }
    if(i==10) printf("\nJá existem 10 animais nessa categoria.");
  }
  else{
    if(bt=='t'){
      for(i=0; i<10; i++){
          if(to[i]==0){
            printf("\n\nInforme a raça do terneiro %d: ", i);
            scanf("%d", &to[i]);
            while(to[i]<=0 || to[i]>=4){
              printf("\nValor inválido.");
              printf("\n\nInforme a raça do terneiro %d: ", i);
              scanf("%d", &to[i]);
            }
            printf("\nInforme o peso do terneiro %d: ", i);
            scanf("%f", &pto[i]);
            while(pto[i]<=20 || pto[i]>120){
              printf("\nUma terneiro deve ter peso entre 20kg e  120kg.");
              printf("\n\nInforme o peso do terneiro %d: ", i);
              scanf("%f", &pto[i]);
            }
            printf("\nDeseja continuar? (s/n) ");
            scanf("%s", &sn);
            while(sn!='s'&&sn!='n'){
            printf("\nDigite 's' para sim e 'n' para não ");
            scanf("%s", &sn);
            }
            if(sn=='n') i=11;
          }
      }
      if(i==10) printf("\nJá existem 10 animais nessa categoria.");
    }  
  }
}

int animais_raca(int v[10], int b[10], int ta[10], int to[10]){
  int raca, nelore=0, vnelore=0, tanelore=0, bnelore=0, tonelore=0 , angus=0, bangus=0, toangus=0, gir=0, vgir=0, tagir=0, bgir=0, togir=0, jersey=0, vjersey=0, tajersey=0, i;
  printf("\n\nRaças");
  printf("\n\n1-Nelore");
  printf("\n\n2-Angus");
  printf("\n\n3-Gir, e");
  printf("\n\n4-Jersey");
  printf("\nInforme a raça que deseja consultar: ");
  scanf("%d", &raca);
  while(raca<=0 || raca>4){
    printf("\nCódigo inválido.");
    printf("\nInforme a raça que deseja consultar: ");
    scanf("%d", &raca);
  }
  switch(raca){
    case 1:
      for(i=0; i<10; i++){
        if(v[i]==1) {
          nelore++;
          vnelore++;
          }
        if(b[i]==1) {
          nelore++;
          bnelore++;
          }
        if(ta[i]==1) {
          nelore++;
          tanelore++;
          }
        if(to[i]==1) {
          nelore++;
          tonelore++;
          }
      }
      printf("\n\nNelore");
      printf("\n\nTotal: %d", nelore);
      printf("\nVacas: %d", vnelore);
      printf("\nBois: %d", bnelore);
      printf("\nTerneiras: %d", tanelore);
      printf("\nTerneiros: %d", tonelore);
      break;
    case 2:
      for(i=0; i<10; i++){
        if(b[i]==1) {
          angus++;
          bangus++;
          }
        if(to[i]==1) {
          angus++;
          toangus++;
          }
      }
      printf("\n\nAngus");
      printf("\n\nTotal: %d", angus);
      printf("\nBois: %d", bangus);
      printf("\nTerneiros: %d", toangus);
      break;
    case 3:
      for(i=0; i<10; i++){
        if(v[i]==1) {
          gir++;
          vgir++;
          }
        if(b[i]==1) {
          gir++;
          bgir++;
          }
        if(ta[i]==1) {
          gir++;
          tagir++;
          }
        if(to[i]==1) {
          gir++;
          togir++;
          }
      }
      printf("\n\nGir, e");
      printf("\n\nTotal: %d", gir);
      printf("\nVacas: %d", vgir);
      printf("\nBois: %d", bgir);
      printf("\nTerneiras: %d", tagir);
      printf("\nTerneiros: %d", togir);
      break;
    case 4:
      for(i=0; i<10; i++){
        if(v[i]==1) {
          jersey++;
          vjersey++;
          }
        if(ta[i]==1) {
          jersey++;
          tajersey++;
          }
      }
      printf("\n\nJersey");
      printf("\n\nTotal: %d", jersey);
      printf("\nVacas: %d", vjersey);
      printf("\nTerneiras: %d", tajersey);
      break;
  }
}

int remove_terneiro(int indice, int t[10], float pto[10], int ta[10], float pta[10]){
  char fm;
  printf("\nVocê deseja remover uma fêmea ou um macho? (f/m)");
  scanf("%s", &fm);
  while(fm!='f'&&fm!='m'){
    printf("\nDigite 'f' para fêmea e 'm' para macho.");
    scanf("%s", &fm);
  }
  if(fm=='m'){
    printf("\n\nInforme o íncice do terneiro que você deseja remover: ");
    scanf("%d", &indice);

    while(indice<0 || indice>=10){
      printf("\nÍndice inexistente.");
      printf("\n\nInforme o íncice do terneiro que você deseja remover: ");
    scanf("%d", &indice);
    }

    if(t[indice]==0){
      printf("\nNão há um terneiro cadastrado com esse índice.");
    }
    else{
      printf("\nTerneiro removido.");
      t[indice]=0;
      pto[indice]=0;
    }
  }
  else {
    if(fm=='f'){
      printf("\n\nInforme o íncice da terneira que você deseja remover: ");
      scanf("%d", &indice);

      while(indice<0 || indice>=10){
        printf("\nÍndice inexistente.");
        printf("\n\nInforme o íncice da terneira que você deseja remover: ");
      scanf("%d", &indice);
      }

      if(ta[indice]==0){
        printf("\nNão há uma terneira cadastrada com esse índice.");
      }
        else{
          printf("\nTerneira removida.");
          ta[indice]=0;
          pta[indice]=0;
        }
      }
    }
  }

float altera_peso(int indice, float pvaca[10], int v[10], float pboi[10], int b[10], float pterneira[10], int ta[10], float pterneiro[10], int to[10]){
  int tipo, i;
  
  printf("\nAnimais");
  printf("\n1-Vaca");
  printf("\n2-Boi");
  printf("\n3-Terneira");
  printf("\n4-Terneiro");
  printf("\n\nInforme qual animal você deseja alterar o peso: ");
  scanf("%d", &tipo);

  while(tipo<=0 || tipo>4){
    printf("\nCódigo inválido.");
    printf("\nInforme qual animal você deseja alterar o peso: ");
    scanf("%d", &tipo);
  }

  switch(tipo){
    case 1:
      printf("\nInforme o índice da vaca a qual você deseja alterar o peso: ");
      scanf("%d", &indice);
      while(indice<0 || indice>9){
        printf("\nÍndice inválido.");
        printf("\n\nInforme o índice da vaca a qual você deseja alterar o peso: ");
      scanf("%d", &indice);
      }
      if(pvaca[indice]!=0){
        printf("\nInforme o novo peso: ");
        scanf("%f", &pvaca[indice]);
        while(pvaca[indice]<=100){
          printf("\nAs vacas devem ter peso superior a 100kg.");
          printf("\nInforme o novo peso: ");
          scanf("%f", &pvaca[indice]);
        }
      }
      else {
        printf("\nNão há nenhum animal registrado nesse índice.");
        }
      break;
    case 2:
      printf("\n\nInforme o índice do boi que você deseja alterar o peso: ");
      scanf("%d", &indice);
      while(indice<0 || indice>9){
        printf("\nÍndice inválido.");
        printf("\n\nInforme o índice do boi que você deseja alterar o peso: ");
      scanf("%d", &indice);
      }
      if(pboi[indice]!=0){
        printf("\n\nInforme o novo peso: ");
        scanf("%f", &pboi[indice]);
        while(pboi[indice]<=120){
          printf("\nOs bois devem ter peso superior a 120kg.");
          printf("\nInforme o novo peso: ");
          scanf("%f", &pboi[indice]);
        }
      }
      else {
        printf("\nNão há nenhum animal registrado nesse índice.");
      }
      break;
    case 3:
      printf("\n\nInforme o índice da terneira a qual você deseja alterar o peso: ");
      scanf("%d", &indice);
      while(indice<0 || indice>9){
        printf("\nÍndice inválido.");
        printf("\n\nInforme o índice da terneira a qual você deseja alterar o peso: ");
        scanf("%d", &indice);
      }
      if(pterneira[indice]!=0){
        printf("\n\nInforme o novo peso: ");
        scanf("%f", &pterneira[indice]);
        while(pterneira[indice]<20){
          printf("\nAs terneiras devem ter peso superior a 20kg.");
          printf("\nInforme o novo peso: ");
          scanf("%f", &pterneira[indice]);
        }
        if(pterneira[indice]>100){
          for(i=0; i<10; i++){
            if(v[i]==0){
              v[i]=ta[indice];
              pvaca[i]=pterneira[indice];
              pterneira[indice]=0;
              ta[indice]=0;
            }
            else{
              pterneira[indice]=0;
              ta[indice]=0;
            }
          }
          if(v[i]==0){
            printf("\nA terneira ultrapassou o peso de sua categoria e foi removida mas, não foi possível juntá-la com as vacas");
          }
          else{
            printf("\nA terneira ultrapassou o peso de sua categoria e foi movida para junto das vacas");
          }
        }
      }
      else {
        printf("\nNão há nenhum animal registrado nesse índice.");
      }
      break;
    case 4:
      printf("\n\nInforme o índice do terneiro que você deseja alterar o peso: ");
      scanf("%d", &indice);
      while(indice<0 || indice>9){
        printf("\nÍndice inválido.");
        printf("\n\nInforme o índice do terneiro que você deseja alterar o peso: ");
      scanf("%d", &indice);
      }
      if(pterneiro[indice]!=0){
        printf("\n\nInforme o novo peso: ");
        scanf("%f", &pterneiro[indice]);
        while(pterneiro[indice]<20){
          printf("\nOs terneiros devem ter peso superior a 20kg.");
          printf("\nInforme o novo peso: ");
          scanf("%f", &pterneiro[indice]);
        }
        if(pterneiro[indice]>120){
          for(i=0; i<10; i++){
            if(b[i]==0){
              b[i]=to[indice];
              pboi[i]=pterneiro[indice];
              pterneiro[indice]=0;
              to[indice]=0;
            }
            else{
              pterneiro[indice]=0;
              to[indice]=0;
            }
          }
          if(b[i]==0){
            printf("\nO terneiro ultrapassou o peso de sua categoria e foi removido mas, não foi possível juntá-lo com os bois.");
          }
          else{
            printf("\nO terneiro ultrapassou o peso de sua categoria e foi movido para junto dos bois.");
          }
      }
      else {
        printf("\nNão há nenhum animal registrado nesse índice.");
      }
      break;
    }
  }
}

