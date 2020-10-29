/* Implementação de algoritmos de ordenação
 *    Executa a ordenação de um vetor (fornecido pelo usuário) de tamanho N       
 *    (especificado pelo usuário) fazendo uso do algoritmo RADIX SORT. A base B
 *    com a qual o algoritmo fará a ordenação, também é fornecida pelo usuário.
 * 
 *    Digite a base B com a qual você quer que o algoritmos faça a ordenação. 
 *    Em seguida, digite a quantidade N de elementos presentes no vetor. 
 *    Por último, digite os elementos do vetor.
 *
 *    Autora: Suzana Vilas Boas de Oliveira
 *    Nº USP: 10262777
 *    Disciplina: ICC2 - 2020
 *    
 */

#include <stdio.h>
#include <stdlib.h>

/*  Função que faz a leitura dos vetores, de elementos são inteiros,
 *    passados pelo usuário
 *    
 *    Entradas: - lengh       ==> endereço da primeira posição do vetor que armazena os tamanhos dos vetores
 *     
 *    Saída:    - vector      ==> endereço do primeiro byte do primeiro elemento do vetor
 *                                
 */
int* leitura_vetor(int lengh){ 
  int i;
  int* vector = malloc(lengh*sizeof(int));         //Alocação dinâmica na memória RAM. 
                                                    //Aloca apenas o espaço estritamente
                                                    //necessário. 
    
  //Fazendo a leitura do vetor
  for (i = 0; i < lengh; i++){
    scanf("%d", &vector[i]);
  }

  
  //Verificação de leitura
  /*for (i = 0; i < lengh; i++){
    printf("vector[%d] = %d\n", i, vector[i]);
  }*/

  return vector;
}

/*  Função responsável ordenar um vetor por meio do algoritmo de ordenação COUNTING SORT.
 *    
 *    Entradas: - vector[] ==> endereço da primeira posição do vetor a ser ordenado
 *              - lengh    ==> tamanho do vetor a ser ordenado/armazenado
 *              - counter[]==> endereço da primeira posição de um vetor que armazena a 
 *                             quantidade de cada elemento contido no vetor (contadores) 
 *                            
 *    Saída:    - void 
 *     
 */
void radix(int base, int lengh, int* vector){ 
  int i;
  int j;
  int d = 1;
  int k = 0;
  int max = 0;
  int* aux_vector = malloc(lengh*sizeof(int)); //Vetor auxiliar para ordenação
  
  //Determinação do valor máximo do vetor
  for (i = 0; i < lengh; i++){
    if(vector[i]> max){
      max = vector[i];
    }

  }

  
  //Fazendo contagem dos elementos
  while(d <= max){                  //Separação dos algarismos de cada elemento segundo a base
    for (i = 0; i < base; i++){     //Varre as possibilidades de algarismos para cada tipo de base
                                    //Ex. Base 10 - varre de 0 a 9. Base 2 - varre de 0 a 1.
      for(j = 0; j < lengh; j++){   //Análise para cada elemento do vetor
        if((vector[j]/d)%base == i){
          aux_vector[k] = vector[j];
          printf("%d ", aux_vector[k]);
          k++; 
        }
      }
    }
    printf("\n");
    for (k = 0; k < lengh; k++){
    vector[k] = aux_vector[k];
    }
    k = 0;
    d *= base;
  }


 free(aux_vector);
}

int main (int argc, char* argv[]){
  //Alocar espaco na memoria stack
  int base;     //Variável responsável por armazenar a base com a qual
                //será feita a ordenação do vetor.

  int lengh;        //Variável responsável por armazenar o tamanho do vetor
  int* vector;      //Vetor que armazenará em si os elementos do vetor a ser ordenado
        
  scanf("%d", &base);
  scanf("%d", &lengh);
  vector = leitura_vetor(lengh);        //Leitura e armazenamento do vetor
  
  radix(base, lengh, vector);
   
  //Liberando memória
  free(vector);
  return 0;
}

