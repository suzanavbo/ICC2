/* Implementação de algoritmos de ordenação
 *    Executa a ordenação de todos os subvetores de um vetor (fornecido pelo usuário) de tamanho N             
 *    (especificado pelo usuário) fazendo uso dos algoritmos de ordenação SHELL e QUICK 
 * 
 *    Digite o tamanho N do vetores. Em seguida, digite os elementos do vetor.
 *
 *    Autora: Suzana Vilas Boas de Oliveira
 *    Nº USP: 10262777
 *    Disciplina: ICC2 - 2020
 *    
 */

#include <stdio.h>
#include <stdlib.h>

/*  Função que armazena o tamanho de cada subvetor do vetor passado pelo usuário
 *        
 *    Entrada:  - lengh       ==> tamanho do vetor passado pelo usuário
 *    Saída:    - sub_lengh   ==> endereço do primeiro byte do primeiro elemento do vetor
 *                                que armazena o tamanho dos subvetores
 */
int* sublengh(int lengh){ 
  int i;
  int j;
  int* sub_lengh = malloc(lengh*sizeof(int));       //Alocação dinâmica na memória RAM. 
                                                    //Aloca apenas o espaço estritamente
                                                    //necessário. 
  j = 1;  
  //Fazendo a leitura do vetor
  for (i = 0; i < lengh; i++){
    sub_lengh[i] = j;
    j++;  
  }

  
  //Verificação de leitura
  /*for (i = 0; i < lengh; i++){
    printf("sub_lengh[%d] = %d\n", i, sub_lengh[i]);
  }*/

  return sub_lengh;
}



/*  Função que faz a leitura dos vetores, de elementos são inteiros,
 *    passados pelo usuário
 *    
 *    Entradas: - lengh       ==> endereço da primeira posição do vetor que armazena os tamanhos dos vetores
 *              - numb_vector ==> quantidade de vetores a serem lidos
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


/*  Função que faz a divisão do vetor em todos os seus subvetores
 *    
 *    
 *    Entradas: - lengh       ==> tamanho do vetor = quantidade de subvetores
 *              - vector      ==> vetor a ser analisado
 *    Saída:    - sub_vector  ==> endereço do primeiro byte do primeiro elemento do primeiro subvetor
 *                                Obs.: sub_vector[][] é uma matriz onde cada linha representa um subvetor do 
 *                                vetor passado pelo usuário
 */
int** subvector(int lengh, int vector[]){ 
  int i;
  int j;
  int** sub_vector = malloc(lengh*sizeof(int*));  //Alocação dinâmica na memória RAM referente 
                                                  //ao número de linhas que terá a matriz vector[][]
                                                  //ou seja, referente ao número subvetores
  j = 1;
  for (i = 0; i < lengh; i++){
      sub_vector[i] = malloc(j*sizeof(int));       //Alocação dinâmica na memória RAM referente 
      j++;                                           //ao número de colunas de cada linha, ou seja, 
                                                   //referente ao tamanho de cada vetor
    }

  //Fazendo a leitura dos vetores
  for (i = 0; i < lengh; i++){
    for (j = 0; j <=i; j++)
    sub_vector[i][j] = vector[j];
  }

  
  //Verificação de leitura
  /*for (i = 0; i < lengh; i++){
    for (j = 0; j <= i; j++)
    printf("sub_vector[%d][%d] = %d\n", i,j, sub_vector[i][j]);
  }*/

  return sub_vector;
}


/*  Função responsável por alocar em um vetor temporário, o vetor a ser ordenado 
 *    nesse caso especificamente pela função SHELL, já que esta ordenação é realizada
 *    antes de se realiar a ordenação com o algorítmo QUICK, e não queremos que o QUICK venha a
 *    ordenar um vetor já ordenado pelo SHELL.
 *    
 *    Entradas: - sub_vector[] ==> endereço da primeira posição do vetor a ser ordenado pelo shell
 *                                 e por isso a ser armazenado em um vetor temporário
 *              - lengh        ==> tamanho do vetor a ser ordenado/armazenado
 *    Saída:    - temp         ==> endereço do primeiro byte do primeiro elemento do vetor a ser ordenado
 *                                 agora armazenado em um vetor temporário
 */
int* temporary(int sub_vector[], int lengh){
  int* temp = malloc(lengh*sizeof(int));
  int i;

  for (i = 0; i < lengh; i++){
    temp[i] = sub_vector[i];
  }
 
  return temp;
}


/*  Função responsável ordenar um vetor por meio do algoritmo de ordenação SHELL SORT.
 *    
 *    Entradas: - vector[] ==> endereço da primeira posição do vetor a ser ordenado pelo shell
 *              - lengh    ==> tamanho do vetor a ser ordenado/armazenado
 *              - data     ==> endereço da primeira posição de um vetor que armazena dados referentes
 *                              à quantidade de trocas e comparações realizadas pelo processo 
 *    Saída:    - void 
 *     
 */
void shell (int vector[], int lengh, int* data){
    int compare = 0;
    int copy = 0;
    int gap = 1;

    while(gap <= lengh){
      gap *= 2;
  
    }
    gap = gap/2 - 1;
    while(gap > 0){
      for (int k = 0; k < gap; k++){
        for (int i = k + gap; i < lengh; i += gap){
            int x = vector[i];
            copy++;
            int j = i - gap;
	        //printf("Fora == %d - %d  ", j, i);
	        while (j >= 0 && vector[j] > x){
               compare++;
	        //printf("Dentro == %d - %d  ", j, i);
               vector[j + gap] = vector[j];
               copy++;
               j-= gap;
            }
            if(j>=0){
            compare++;                
            }
            vector[j + gap] = x;
            copy++;
        }
        
      }
      gap /= 2;
    }
   data[0] = compare + copy; 
   printf("Subvetor ordenado pelo SHELL: ");
   for(int i = 0; i < lengh; i++){
   printf("%d ", vector[i]);
   //printf("\n compare = %d, copy = %d\n", compare, copy);
   }
}

/*  Função responsável ordenar um vetor por meio do algoritmo de ordenação QUICKSORT.
 *    
 *    Entradas: - vector[]  ==> endereço da primeira posição do vetor a ser ordenado
 *              - begin     ==> posição do primeiro elemento do vetor a ser ordenado
 *              - end       ==> posição do último elemento do vetor a ser ordenado
 *              - data      => endereço da primeira posição de um vetor que armazena dados referentes
 *                              à quantidade de trocas e comparações realizadas pelo processo  
 *    Saída:    - void 
 *
 */
void quick (int vector[], int begin, int end, int* data){
  int compare = 0;
  int copy = 0;
  
  if (begin >= end){      //caso base
    return; 
  }

  int m = (begin + end)/2;       //posição do pivot
  int pivot = vector[m];         //pivot
  copy++;
  int i = begin;
  int j = end;

  while(1){
    while(vector[i] < pivot){
      compare++;
      i++;
    }compare++;//vector[i] >= pivot

    while(vector[j] > pivot){
      compare++;
      j--;
    }compare++;// vector[j] =< pivot

    if(j <= i){
      break;
    }

    int aux = vector[i];
    vector[i] = vector[j];
    vector[j] = aux;
    copy = copy + 3;
    i++;
    j--;
  }

  data[1] = data[1] + copy + compare;
  quick(vector, begin, j, data);
  quick(vector, j+1, end, data);
}



int main (int argc, char* argv[]){
  
  //Alocar espaco na memoria stack
  int i;
  int j;
  int lengh;
  int* temp;
  int* sub_lengh;
  int* vector;
  int** sub_vector;  
  int* data = malloc(2*sizeof(int));    //data aponta para o primeiro endereço
                                        //de memória de um bloco de 2 inteiros. No primeiro
                                        //(*data_m) armazenaremos o número operações feitas pelo shell. 
                                        //No segundo *(data_m+1) armazenamos as operações feitas pelo quick                          
  
  scanf("%d", &lengh);
  

  vector = leitura_vetor(lengh);        //Leitura e armazenamento do vetor
  sub_vector = subvector(lengh,vector); //Divisão do vetor em subvetores
  sub_lengh = sublengh(lengh);          //Armazena em cada posição do vetor sub_lengh
                                        //o tamanho de um subvetor
  data[0] = 0;
  data[1] = 0;
  for(i = 0; i < lengh; i++){
    temp = temporary(sub_vector[i], sub_lengh[i]);
    shell(temp, sub_lengh[i], data);
    printf("\nOperações = %d \n", data[0]);
    free(temp);
    quick(sub_vector[i], 0, sub_lengh[i]-1, data);
    printf("Subvetor ordenado pelo QUICK: ");
    for(int k = 0; k < sub_lengh[i]; k++){
      printf("%d ", sub_vector[i][k]);
    }
    printf("\nOperações = %d\n\n\n", data[1]);
    data[1] = 0;
  }
   

  //Liberando memória
  for (j = 0; j < lengh; j++){
       free(sub_vector[j]); 
  } 
  
  free(sub_vector);
  free(vector);
  free(sub_lengh);
  free(data);
  return 0;
}
