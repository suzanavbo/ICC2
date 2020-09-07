/* Implementação de algoritmos de ordenação
 *    Executa a ordenação de um vetor (fornecido pelo usuário) de tamanho N             
 *    (especificado pelo usuáio) fazendo uso do algoritmos de ordenação 
 *    SELECTION ou BUBBLE COM SENTINELA (escolha do usuário).
 *
 *    Caso queira que o processo de ordenação seja feito por meio do SELECTION, digite
 *    selecao. Caso queira que seja feito pelo método BUBBLE digite bolha.
 *    Posteriormente entra-se com o valor N de elementos do vetor, seguido pelo valor de
 *    cada elemento.
 *
 *    Autora: Suzana Vilas Boas de Oliveira
 *    Nº USP: 10262777
 *    Disciplina: ICC2 - 2020
 *    
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*  Função que faz a leitura de um vetor, cujos elementos são inteiros,
 *    passado pelo usuário
 *    
 *    Entrada: - lengh  ==> indica o tamanho do vetor
 *    Saída:   - vector ==> endereco do primeiro byte do primeiro
 *                              do primeiro elemento (do tipo int) 
 *
 */

int* leitura_vetor(int lengh){ 
  int i; 
  int* vector = malloc(lengh*sizeof(int));

  for (i = 0; i<lengh; i++){
    scanf("%d", &vector[i]);
  }

  return vector;
 }

 
/*  Função que faz a ordenacao de um vetor, por meio do algoritmos SELECTION
 *    
 *    Entradas: - lengh     ==> indica o tamanho do vetor a ser ordenado
                - vector[]  ==> vetor a ser ordenado
 *    Saída:    - void 
 *
 */
void selection(int lengh, int vector[]){
  int temp;
  int index;
  int i;
  int j;
   
  index = 0;     //Inicializa o processo assumindo que o primeiro elemento é o menor
  
  //Varrendo o vetor
  
  for(j = 0; j < (lengh-1); j++){
    for(i = j+1; i < lengh; i++){
      printf("C %d %d\n", index, i);
      if (vector[i] < vector[index]){
        index = i;
      }
    }

    // Processo de troca
    if(index != j){
      temp = vector[j];
      vector[j] = vector[index];
      vector[index] = temp;
      printf("T %d %d\n", j, index);
      index = j+1;
    } else{
        index = j+1;
      }
  }

  for(i = 0; i < lengh; i++){
    printf("%d ", vector[i]);
  }
}

/*  Função que faz a ordenacao de um vetor, por meio do algoritmos BUBBLE COM SENTINELA
 *    
 *    Entradas: - lengh     ==> indica o tamanho do vetor a ser ordenado
                - vector[]  ==> vetor a ser ordenado
 *    Saída:    - void 
 *
 */
void bubble_s(int lengh, int vector[]){
  int temp;
  int flag;
  int i;
  int j;
  
  //Varrendo o vetor
  for(j = 0; j < lengh-1; j++){
    for (i = 1; i < lengh-j; i++){
      printf("C %d %d\n", i-1, i);
      if (vector[i-1] > vector[i]){
        temp = vector[i-1];
        vector[i-1] = vector[i];
        vector[i] = temp;
        printf("T %d %d\n", i-1, i);
        flag = i;
      }
    }
    if (flag != lengh-(j-1)){
      j = lengh - (flag+1);
    }
  }
  for(i = 0; i < lengh; i++){
    printf("%d ", vector[i]);
  }
}
 
 
int main (int argc, char* argv[]){
  
  //Alocar espaco na memoria stack 
  char method[8];         //Separa um espaco na memoria para identificar o metodo
  int lengh;
  int* vector;
  
  scanf("%s", method);    //Determinação do método
  scanf("%d", &lengh);    //Determinação do tamanho do vector

  vector = leitura_vetor(lengh);  //Leitura e armazenamento do vetor

  if (strcmp(method,"selecao") == 0){
      selection(lengh, vector);
  } 
  else if(strcmp(method, "bolha") == 0) {
      bubble_s(lengh,vector);
  }
  else{
    printf("Digite um método válido.");
  }

  printf("\n");
  free(vector); 
  return 0;
}

