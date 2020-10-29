/* Implementação de algoritmos de ordenação
 *    Executa a ordenação de um vetor (fornecido pelo usuário) de tamanho N       
 *    (especificado pelo usuário) fazendo uso do algoritmo COUNTING SORT
 * 
 *    Digite o a quantidade K de elementos distos presentes no vetor. Em seguida, 
 *     digite a quantidade N de elementos presentes no vetor. Por último, digite 
 *     os elementos do vetor.
 *
 *    Autora: Suzana Vilas Boas de Oliveira
 *    Nº USP: 10262777
 *    Disciplina: ICC2 - 2020
 *    
 */

#include <stdio.h>
#include <stdlib.h>

/*  Esta função é resposável por separar na memória RAM um espaço
 *   destinado ao armazenamento da quantidade de cada tipo de     
 *   elemento do vetor
 * 
 *    Entrada:  - elements ==> variável que destaca quantos distintos elementos
 *                             estão presentes no vetor e quais são eles (0 -- elements-1) 
 *    Saída:    - counter  ==> retorna o endereço do primeiro elemento do vetor counter
 */
int* numb_counter(int elements){ 
  int i;
  int* counter = malloc(elements*sizeof(int));     //Alocação dinâmica na memória RAM. 
                                                    //Aloca apenas o espaço estritamente
                                                    //necessário.
   for (i = 0; i < elements; i++){          //Zerando os contadores
    counter[i] = 0;
  }                                                  
return counter;
  
}



/*  Função que faz a leitura dos vetores, de elementos são inteiros,
 *    passados pelo usuário
 *    
 *    Entradas: - lengh       ==> endereço da primeira posição do vetor que armazena os 
 *                                tamanhos dos vetores
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
void counting(int* vector, int lengh, int elements, int* counter){ 
  int i;
  int j;
  int aux_position;
  int* position = malloc(elements*sizeof(int));
  int* aux_vector = malloc(lengh*sizeof(int)); //Vetor auxiliar para ordenação
  
  //Fazendo contagem dos elementos
  for (i = 0; i < lengh; i++){
    j = elements;
    while(vector[i] != elements-j){
      j--;
    }
    counter[elements-j] = counter[elements-j]+1; 
  }
  
  //Armazenando no vetor position a posição relativa do primeiro elemento de cada contador
  //Ex. counter[0] responsável por contar a quantidade de elementos 0 presente no vetor
  //de modo que position[0] armazene a posição onde deve entrar o primeiro dos elementos 0
  position[0] = 0;
  for(i = 1; i < elements; i++){
    position[i] = position[i-1]+counter[i-1]; 
  }

  //Contrução do vetor ordenado auxiliar
  for (i = 0; i < lengh; i++){
   j = elements;
   while(vector[i] != elements-j){
     j--;
   }
   aux_position = position[elements-j];
   aux_vector[aux_position] = vector[i];
   printf("%d %d\n", vector[i], position[elements-j]);
   position[elements-j] = position[elements-j] + 1; 
  }

  //Ordenação final
  for (i = 0; i < lengh; i++){
    vector[i] = aux_vector[i];
  }
  
  //Verificação de ordenação
  /*for (i = 0; i < lengh; i++){
    printf("vector[%d] = %d\n", i, vector[i]);
 }*/

 free(position);
 free(aux_vector);
}

int main (int argc, char* argv[]){
  
  //Alocar espaco na memoria stack
  int elements;     //Variável responsável por armazenar a quantidade de diferentes 
                    //elementos presentes no vetor
  int lengh;        //Variável responsável por armazenar o tamanho do vetor
  int* counter;     //Vetor de contadores
  int* vector;      //Vetor que armazenará em si os elementos do vetor a ser ordenado
        
  scanf("%d", &elements);
  counter = numb_counter(elements);   

  scanf("%d", &lengh);
  vector = leitura_vetor(lengh);        //Leitura e armazenamento do vetor
  
  counting(vector, lengh, elements, counter);
   
  //Liberando memória
  free(counter);
  free(vector);
  return 0;
}

