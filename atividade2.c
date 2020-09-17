/* Implementação de algoritmos de ordenação
 *    Executa a ordenação de Q vetores (fornecido pelo usuário) de tamanho N             
 *    (especificado pelo usuário) de cada vetor fazendo uso do algoritmos de ordenação 
 *    INSERTION e MERGE.
 *
 *    Digite o número Q de vetores que dejasa ordenar. Posteriormente digite o tamanho N
 *    de cada um dos vetores. Em seguida, digite os elementos de cada vetor.
 *
 *    Autores: Daniel Torreao Correa Thiemann (4770077)
 *             Luiz Paulo Souto Monteiro (10684889)
 *             Suzana Vilas Boas de Oliveira (10262777)
 *    Grupo: 10
 *    Disciplina: ICC2 - 2020
 *    
 */

#include <stdio.h>
#include <stdlib.h>


/*  Função que faz a leitura do tamanho de cada vetor. 
 *    
 *    Entrada: - numb_vector  ==> indica a quantidade de vetores a serem ordenados 
 *    Saída:   - lengh_vector ==> endereco do primeiro byte do tamanho do primeiro
 *                                vetor.
 *
 */
int* lengh_vectors(int numb_vector){ 
  int i; 
  int* lengh_vec = malloc(numb_vector*sizeof(int));  //Alocação dinâmica na memória RAM referente 
                                                     //tamanho de cada vetor a ser lido
  
  //Armazena em cada posição do vetor lengh_vec o tamanho de um vetor a ser lido
  for (i = 0; i<numb_vector; i++){
    scanf("%d", &lengh_vec[i]);
  }

  return lengh_vec;
}



/*  Função que faz a leitura dos vetores, de elementos são inteiros,
 *    passados pelo usuário
 *    
 *    Entradas: - lengh       ==> endereço da primeira posição do vetor que armazena os tamanhos dos vetores
 *              - numb_vector ==> quantidade de vetores a serem lidos
 *    Saída:    - vector      ==> endereço do primeiro byte do primeiro elemento do primeiro vetor
 *                                Obs.: vector[][] é uma matriz onde cada linha representa um vetor passados 
 *                                pelo usuário
 */
int** leitura_vetor(int lengh[], int numb_vector){ 
  int i;
  int j;
  int** vector = malloc(numb_vector*sizeof(int*));  //Alocação dinâmica na memória RAM referente 
                                                    //ao número de linhas que terá a matriz vector[][]
                                                    //ou seja, referente ao número de vetores a serem lidos

  for (i = 0; i < numb_vector; i++){
      vector[i] = malloc(lengh[i]*sizeof(int));    //Alocação dinâmica na memória RAM referente 
  }                                                //ao número de colunas de cada linha, ou seja, 
                                                   //referente ao tamanho de cada vetor
    
  //Fazendo a leitura dos vetores
  for (i = 0; i < numb_vector; i++){
    for (j = 0; j < lengh[i]; j++)
    scanf("%d", &vector[i][j]);
  }

  
  //Verificação de leitura
  /*for (i = 0; i < numb_vector; i++){
    for (j = 0; j < lengh[i]; j++)
    printf("vector[%d][%d] = %d\n", i,j, vector[i][j]);
  }*/

  return vector;
}


/*  Função responsável por alocar em um vetor temporário, o vetor a ser ordenado 
 *    nesse caso especificamente pela função INSERTION, já que esta ordenação é realizada
 *    antes de se realiar a ordenação com o algorítmo MERGE, e não queremos que o MERGE tenha
 *    ordenar um vetor já ordenado pelo INSERTION.
 *    
 *    Entradas: - vector[]    ==> endereço da primeira posição do vetor a ser ordenado pelo insertion
 *                                e por isso a ser armazenado em um vetor temporário
 *              - lengh       ==> tamanho do vetor a ser ordenado/armazenado
 *    Saída:    - temp        ==> endereço do primeiro byte do primeiro elemento do vetor a ser ordenado
 *                                agora armazenado em um vetor temporário
 */
int* temporary(int vector[], int lengh){
  int* temp = malloc(lengh*sizeof(int));
  int i;

  for (i = 0; i < lengh; i++){
    temp[i] = vector[i];
  }
 
  return temp;
}
/*  Função que faz a ordenacao de um vetor, por meio do algoritmo INSERTION
 *    
 *    Entradas: - lengh     ==> indica o tamanho do vetor a ser ordenado
 *              - vector[]  ==> vetor a ser ordenado
 *    Saída:    - void 
 *
 */
void insertion(int vector[], int lengh){
  int compare = 0;
  int change = 0;

  for(int i = 1; i < lengh; i++){
      int x = vector[i];
      change++;
      int j = i-1;
      while(j>=0 && vector[j] > x){
        vector[j+1] = vector[j];
        j--;
        compare++;
        change++;
      }
      if(j == -1){
      vector[j+1] = x;
      change++;
      }else{
        compare++;
        vector[j+1] = x;
        change++;
      }
  }

  printf("I %d %d %d", lengh, change, compare);
  printf("\n");
}



/*  Função que intercala 2 vetores ordenados em 1 único vetor ordenado
 *    
 *    Entradas: - vector[]  ==> vetor completo a ser intercalado (vetor de 2 vetores ordenados)
 *              - begin1    ==> posição do primeiro elemento do primeiro vetor ordenado
 *              - end1      ==> posição do último elemento do primeiro vetor ordenado
 *              - begin2    ==> posição do primeiro elemento do segundo vetor ordenado
 *              - end2      ==> posição do último elemento do segundo vetor ordenado
 *              - data_m    ==> endereço da primeira posição de um vetor que armazena dados referentes
 *                              à quantidade de trocas e comparações realizadas pelo processo 
 *    Saída:    - void 
 *
 */
void intercalate(int vector[], int begin1, int end1, int begin2, int end2, int* data_m){
   
  int* aux = malloc((end2-begin1+1)*sizeof(int));
  int i = begin1;
  int j = begin2;
  int k = 0;        //Variável auxiliar - varre o vetor auxiliar preenchendo-o com os elementos a serem intercalados

  while(i <= end1 && j <= end2){
    if(vector[i]<=vector[j]){
      data_m[1]++;
      aux[k] = vector[i];
      data_m[0]++;
      k++;
      i++;
    }else{
      data_m[1]++;
      aux[k] = vector[j];
      data_m[0]++;
      k++;
      j++;
    }
  }
  while(i <= end1){
    aux[k] = vector[i];
    data_m[0]++;
    k++;
    i++;
  }
  while(j <= end2){
    aux[k] = vector[j];
    data_m[0]++;
    k++;
    j++;
  }
  k = 0;
  for(i = begin1; i<=end2; i++){
    vector[i] = aux[k];
    k++;
    data_m[0]++;
  }
 
  free(aux);
}


/*  Função que faz a ordenação de um vetor por meio do algoritmo MERGE
 *    
 *    Entradas: - vector[]  ==> endereço da primeira posição do vetor a ser ordenado
 *              - begin     ==> posição do primeiro elemento do vetor a ser ordenado
 *              - end       ==> posição do último elemento do vetor a ser ordenado
 *              - data_m    ==> endereço da primeira posição de um vetor que armazena dados referentes
 *                              à quantidade de trocas e comparações realizadas pelo processo 
 *    Saída:    - void 
 *
 */
void merge_r(int vector[], int begin, int end, int* data_m){
  int medial;

  if(end > begin){
    medial = (begin + end)/2;     //begin e end são inteiros e definimos medial como inteiro, então mesmo que o                                      //resultado não dê inteiro, vai fazer o arredondamento para baixo 
    merge_r(vector, begin, medial, data_m);
    merge_r(vector, medial+1, end, data_m);
    intercalate(vector, begin, medial, medial+1, end, data_m);
  }  
}


int main (int argc, char* argv[]){
  
  //Alocar espaco na memoria stack
  int i;
  int j;
  int numb_vector;
  int* lengh;
  int** vector;
  int* temp;
  int* data_m = malloc(2*sizeof(int));  //data_m aponta para o primeiro endereço
                                        //de memória de um bloco de 2 inteiros. No primeiro
                                        //(*data_m) armazenaremos o número de trocas feitas pelo 
                                        //merge. No segundo *(data_m+1) armazenaremos as comparações
                            
  
  scanf("%d", &numb_vector);

  lengh = lengh_vectors(numb_vector);

  vector = leitura_vetor(lengh, numb_vector);  //Leitura e armazenamento do vetor

  for(i = 0; i < numb_vector; i++){
    temp = temporary(vector[i], lengh[i]);
    insertion(temp, lengh[i]);
    free(temp);
    data_m[0] = 0;
    data_m[1] = 0;
    merge_r(vector[i], 0, lengh[i]-1, data_m);
    printf("M %d %d %d\n", lengh[i], data_m[0], data_m[1]);
  }
   

  //Liberando memória
  for (j = 0; j < numb_vector; j++){
       free(vector[j]); 
  } 
  
  free(vector);
  free(lengh);
  free (data_m);
  return 0;
}
