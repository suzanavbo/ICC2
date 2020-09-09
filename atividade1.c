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
  int* vector = malloc(lengh*sizeof(int));  //Alocação dinâmica na memória RAM referente 
                                            //ao tamanho do vetor a ser lido 

  //Fazendo a leitura do vetor
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
  int temp;       //Variável temporária para auxiliar no processo de troca
  int index;      //Armazena a posição do menor elemento
  int i;          //Variável auxiliar - caminhar pelo vetor
  int j;          //Armazena a posição para a qual o menor elemento será levado
   
  
  //Varrendo o vetor
  for(j = 0; j < (lengh-1); j++){      //A variável auxiliar j armeza a posição para a 
                                       //qual o menor elemento do vetor será levado as comparações
    index = j;                         //Inicializa o processo assumindo que o elemnto da atual posição
                                       //de análise é o menor

    //Processo que analisa cada elemento do vetor, comparando-o com o menor até então
    for(i = j+1; i < lengh; i++){      
      printf("C %d %d\n", index, i);
      if (vector[i] < vector[index]){  //Caso encontre um elemento menor que o até então considerado menor,
                                       //atualiza-se a variável
        index = i;                     //index com sua posição
      }
    }

    // Processo de troca
    if(index != j){
      temp = vector[j];
      vector[j] = vector[index];
      vector[index] = temp;
      printf("T %d %d\n", j, index);
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
  int temp;     //Variável temporária para auxiliar no processo de troca
  int troca;    //Usada para evitar que verificações desnecessárias sejam realizadas
  int i;        //Variável auxiliar - caminhar pelo vetor
  int j;        //Variável auxiliar - usada para indicar até qual posição do vetor caminhar
  int k;

  //Varrendo o vetor
  for(j = 0; j < lengh-1; j++){
    troca = 0;    
    k = j;
    for (i = 1; i < lengh-k; i++){
      //printf("i = %d\n",i);
      printf("C %d %d\n", i-1, i);
      if (vector[i-1] > vector[i]){  //Compara 2 elementos subsequentes. 
        temp = vector[i-1];          //Caso o elemento em maior posição seja menor
        vector[i-1] = vector[i];     //faz-se a troca desses elementos
        vector[i] = temp;            //Este processo acaba por levar para a 
        printf("T %d %d\n", i-1, i); //posição (lengh - (j-1)) o maior elemento do vetor
        j = lengh - (i+1);           //Sentinela - verifica a ultima troca e atualiza j
        troca++;
      }
    } if (troca == 0){
        break;
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
      bubble_s(lengh, vector);
  }
  else{
    printf("Digite um método válido.");
  }
  free(vector);
  printf("\n");
  
  return 0;
}

