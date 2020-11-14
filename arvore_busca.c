/* Implementação de algoritmos de busca
 *    Realiza a busca, por meio do conceito de ÁRVORE BINÁRIA DE BUSCA 
 *    de de K elementos (fornecidos pelo usuário) em um conjunto de N
 *    elementos, também fornecidos pelo usuário. 
 *     
 *    Digite o número N de elementos a serem organizados em árvore para 
 *    a realização de busca. Em seguida, digite cada um dos elementos a
 *    serem organizados em ÁRVORE BINÁRIA para a realização da busca. A
 *    posteriori especifique a quantidade K de elementos a serem buscados.
 *    Por fim, especifique os elementos a serem buscados.
 *
 *    Autora: Suzana Vilas Boas de Oliveira
 *    Nº USP: 10262777
 *    Disciplina: ICC2 - 2020
 *    
 */

#include <stdio.h>
#include <stdlib.h>

/* Construção de um tipo (struct) node que reúne em si
 *   os elementos básicos de um nó de uma árvore binária
 *   permitindo assim sua contrução.
 *   
 *   value: valor do nó
 *   left: endereço do primeiro byte do primeiro parâmetro de uma struct (tipo) node
 *   right: endereço do primeiro byte do primeiro parâmetro de uma struct (tipo) node
 */
typedef struct node{
  int value;
  struct node* left;
  struct node* right;
} NODE;


/*  Função que faz a contrução dos nós de uma árvore binária.
 *    
 *    Entradas: - newValue ==> valor a ser incluído na árvore
 *     
 *    Saída:    - aux      ==> endereço do primeiro byte do primeiro parâmetro de uma 
 *                             struct (tipo) node                               
 */
NODE* newNode(int newValue){
  NODE* aux = (NODE*) malloc(sizeof(NODE)); //Alocação dinâmica de memória. Aloca na
					    //heap o espaço esritamente necessário para a
                                            //utilização de um tipo NODE
  //Criação de um nó da árvore binária
  aux->value = newValue;
  aux->left = NULL;
  aux->right = NULL;
  return aux;
}


/*  Função que faz a inserção de elementos em árvore binária.
 *    
 *    Entradas: - node     ==> endereço do primeiro byte do pirmeiro parâmetro de uma
 *                             struct (tipo) node na qual se pretende fazer a inserção
 *		- newValue ==> valor a ser incluído na árvore
 *     
 *    Saída:    - node     ==> endereço do primeiro byte do primeiro parâmetro da 
 *                             struct (tipo) node na qual se fez a inserção                              
 */
NODE* insertNode(NODE* node, int newValue){
  if (node == NULL){
    return newNode(newValue);
  }
  else{
    if (newValue < node->value){
      node->left = insertNode(node->left, newValue);
    }
    else{
      node->right = insertNode(node->right, newValue);
    }
  }

  return node;
}


/*  Função que faz a busca de elementos em árvore binária.
 *    
 *    Entradas: - node        ==> endereço do primeiro byte do pirmeiro parâmetro de uma
 *                             struct (tipo) node na qual se pretende fazer a busca
 *		- valueSearch ==> valor a ser buscado na árvore
 *     
 *    Saída:    - node     ==> endereço do primeiro byte do primeiro parâmetro da 
 *                             struct (tipo) node na qual fora encontrado o elemento
 *                             buscado                              
 */
NODE* searchNode(NODE* node, int valueSearch){
  if (node == NULL){
    return NULL;
  }
  else if(node->value == valueSearch){
    return node;
  }
  else if(valueSearch < node->value){
    return searchNode(node->left, valueSearch);
  }
  else{
    return searchNode(node->right, valueSearch);
  }
}


/*  Função que faz a leitura dos elementos (inteiros),
 *  passados pelo usuário a serem organizados em árvore.
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


/*  Função responsável por acessar os nós da árvore binária,
 *  desalocando a memória ocupada por cada tipo NODE.
 *    
 *    Entradas: - node  ==> endereço do primeiro byte do pirmeiro parâmetro de uma
 *                                struct (tipo) node cujo espaço pretende ser desalocado
 *		
 *    Saída:    - void                               
 */
void free_tree(NODE* node){
  if (node != NULL){
    free_tree(node->left);
    free_tree(node->right);
    free(node);
  }

}



int main (int argc, char* argv[]){
  
  //Alocar espaco na memoria stack
  int lengh;          //Variável responsável por armazenar a quantidade de elementos
		      //a serem organizados em uma árbove binária de busca
  int lengh_search;   //Variável resposnável por armzenar a quantidade de elementos
		      //a serem buscados na árvore
  int aux;            //Variável que armazenará em si os elementos a serem organizados
		      // em árvore
  int* search_vector; //Vetor que armazenará em si os elementos a serem buscados
  
  NODE* root;         //Ponteiro (struct node) responsável pela contrução da árvore. 
		      //root aponta para o endereço de uma struct node. 
  
  NODE* search;	      //Ponteiro (struct node) responsável pela busca em árvore. 
		      //search aponta para o endereço de uma struct node.	

  
  scanf("%d", &lengh);                //Leitura da quantidade de elementos da árvore
  
  //Contrução da árvore binária de busca
  root = NULL;
  for(int i = 0; i < lengh; i++){
    scanf("%d", &aux);
    root  = insertNode(root, aux);
  }
  
  scanf("%d", &lengh_search);                  //Leitura da quantidade de elementos a serem buscados  
  search_vector = leitura_vetor(lengh_search); //Leitura e armazenamento dos elementos em um vetor

    
  //Processo de busca em árvore
  for(int j = 0; j<lengh_search; j++){
    search = searchNode(root, search_vector[j]);
    if(search == NULL){
      printf("0\n");
    }
    else{
      printf("1\n");
    }
  }
  
  //Liberando memória
  free_tree(root);
  free(search_vector);
  return 0;
}
