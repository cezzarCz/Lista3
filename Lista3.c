#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PILOTOS 10
#define MAX_CIRC 10

typedef struct p {
  int cod, idade;
  char nome[50], origem[50];
  char sexo;
} Piloto;
typedef struct c {
  int cod, codMenor;
  char nome[50], origem[50];
  float tamanho, menorTempo;
} Circuito;

typedef struct m{
  int codPiloto, codCirc;
  char nomeEquipe[50];
  char data[50];
  float tempo;
} Melhorvolta;

int leValidaCod(Piloto p[]);
void leValidaNome(char nome[]);
int leValidaIdade();
char leValidaSexo(Piloto p[]);
int leValidaPais();
Piloto cadastroPiloto(Piloto pil[]);
int codCir(Circuito c[]);
void nomeCirc(char nome[]);
Circuito cadastroCirc(Circuito cir[]);

int main() {
  Piloto pilotos[MAX_PILOTOS];
  Circuito circ[MAX_CIRC];
  int i = 0, op;
  int escolha;
  do {
    printf("\n\tMENU\n");
    printf("\n\t1-Cadastro de piloto\n\t2-Cadastro de circuito\n\t3-Cadastro melhor volta\n");
    printf("\n\tOpcao: ");
    scanf("%d", &escolha);
    switch (escolha) {
    case 1:
      do {
        pilotos[i] = cadastroPiloto(pilotos);
        printf("\nInforme 0 para sair: ");
        scanf("%d", &op);
        i++;
      } while (op != 0);
      break;
    case 2:
      do {
        printf("\n\tCircuito\n");
        circ[i] = cadastroCirc(circ);
        printf("\nInforme 0 para sair: ");
        scanf("%d", &op);
      } while (op != 0);
      break;
    case 3:
      printf("\n\tMelhor volta\n");
      break;
    default:
      system("clear");
      printf("\n\tOpcao invalida! Tente novamente...\n");
    }
  } while (escolha < 1 || escolha > 3);

  return 0;
}

Piloto cadastroPiloto(Piloto pil[]) {
  Piloto pilotos;
  int i = 0, escolha, op;
  char nome[50];

  pilotos.cod = leValidaCod(pil);
  leValidaNome(nome);
  strcpy(pilotos.nome, nome);
  pilotos.idade = leValidaIdade();
  pilotos.sexo = leValidaSexo(pil);
  escolha = leValidaPais();
  switch (escolha) {
  case 1:
    strcpy(pilotos.origem, "Brasil");
    break;
  case 2:
    strcpy(pilotos.origem, "Estados Unidos");
    break;
  case 3:
    strcpy(pilotos.origem, "Canada");
    break;
  case 4:
    strcpy(pilotos.origem, "China");
    break;
  }
  return pilotos;
}
int leValidaCod(Piloto p[]) {
  int codigo, i, flag;
  do {
    flag = 0;
    printf("\nInforme o codigo: ");
    scanf("%d", &codigo);
    // system("clear");
    if (codigo < 101 || codigo > 499) {
      printf("\nO codigo deve ser maior que 100 e menor que 500!\n");
      printf("\nTente novamente...\n");
    } else {
      for (i = 0; i < 10; i++) {
        if (codigo == p[i].cod) {
          flag = 1;
          printf("\nCodigo ja utilizado! Tente novamente...\n");
        }
      }
    }
  } while (codigo < 101 || codigo > 499 || flag == 1);

  return codigo;
}
void leValidaNome(char nome[]) {
  do {
    printf("\nNome do piloto: ");
    fflush(stdin);
    __fpurge(stdin);
    fgets(nome, 49, stdin);
    if (nome[0] == '\0' || nome[0] == '\n') {
      system("clear");
      printf("----------------------\n");
      printf("Insira um nome valido!\n");
      printf("----------------------\n");
    } else {
      if (strlen(nome) > 50) {
        printf("\n-----------------------------------\n");
        printf("Nome muito grande! Tente novamente...");
        printf("\n-----------------------------------\n");
      }
    }
  } while (nome[0] == '\0' || nome[0] == '\n' || strlen(nome) > 50);
}
int leValidaIdade() {
  int id;
  do {
    printf("\nIdade do piloto: ");
    scanf("%d", &id);
    if (id < 1) {
      printf("\nIdade invalida! Tente novamente...\n");
    }
  } while (id < 1);

  return id;
}
char leValidaSexo(Piloto p[]) {
  char sexo;
  do {
    printf("\nSexo do piloto (m-masculino ou f-feminino): ");
    fflush(stdin);
    __fpurge(stdin);
    sexo = getchar();
    sexo = tolower(sexo);
    if (sexo != 'm' && sexo != 'f') {
      printf("\nSexo invalido! Tente novamente...\n");
    }
  } while (sexo != 'm' && sexo != 'f');

  return sexo;
}
int leValidaPais() {
  int escolha;

  do {
    printf("\n1 - Brasil\n2 - Estados Unidos\n3 - Canada\n4 - China\n");
    printf("\nOrigem: ");
    scanf("%d", &escolha);
    if (escolha < 1 || escolha > 4) {
      printf("\nOpcao invalida! Tente novamente...\n");
    }
  } while (escolha < 1 || escolha > 4);

  return escolha;
}
int codCir(Circuito c[]) {
  int codigo, i;
  do {
    codigo = rand();
    for (i = 0; i < MAX_CIRC; i++) {
      if (codigo == c[i].cod) {
        codigo = 0;
      }
    }
  } while (codigo == c[i].cod);

  return codigo;
}
Circuito cadastroCirc(Circuito cir[]) {
  char nome[50];
  Circuito c;
  int i = 0, escolha, op, j;
  c.cod = codCir(cir);
  nomeCirc(nome);
  strcpy(c.nome, nome);
  escolha = leValidaPais();
  switch (escolha) {
  case 1:
    strcpy(c.origem, "Brasil");
    break;
  case 2:
    strcpy(c.origem, "Estados Unidos");
    break;
  case 3:
    strcpy(c.origem, "Canada");
    break;
  case 4:
    strcpy(c.origem, "China");
    break;
  }
  printf("\nTamanho em KM: ");
  scanf("%f", &c.tamanho);
  printf ("\nMenor tempo: ");
  fflush(stdin);
  __fpurge(stdin);
  scanf ("%f", &c.menorTempo);
  for (j=0;j<MAX_CIRC; j++){
    if (cir[j].menorTempo < c.menorTempo){
      cir[j].menorTempo = c.menorTempo;
    }
  }
  printf ("\nIdentificacao do piloto com menor tempo: ");
  fflush(stdin);
  __fpurge(stdin);
  scanf ("%d", &c.codMenor);
  return c;
}
void nomeCirc(char nome[]) {
  do {
    printf("\nNome do circuito: ");
    fflush(stdin);
    __fpurge(stdin);
    fgets(nome, 49, stdin);
    if (nome[0] == '\0' || nome[0] == '\n') {
      system("clear");
      printf("----------------------\n");
      printf("Insira um nome valido!\n");
      printf("----------------------\n");
    } else {
      if (strlen(nome) > 50) {
        printf("\n-----------------------------------\n");
        printf("Nome muito grande! Tente novamente...");
        printf("\n-----------------------------------\n");
      }
    }
  } while (nome[0] == '\0' || nome[0] == '\n' || strlen(nome) > 50);
}
