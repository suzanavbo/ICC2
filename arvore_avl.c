/* Implementação de algoritmos de busca
 *    Realiza a busca, por meio do conceito de ÁRVORE AVL DE BUSCA 
 *    de de K elementos (fornecidos pelo usuário) em um conjunto de N
 *    elementos, também fornecidos pelo usuário. 
 *     
 *    Digite o número N de elementos a serem organizados em árvore para 
 *    a realização de busca. Em seguida, digite cada um dos elementos a
 *    serem organizados em ÁRVORE AVL para a realização da busca. A
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
 *   height: altura do nó
 *   left: endereço do primeiro byte do primeiro parâmetro de uma struct (tipo) node
 *   right: endereço do primeiro byte do primeiro parâmetro de uma struct (tipo) node
 */
typedef struct node{
  int value;
  int height;
  struct node* left;
  struct node* right;
} NODE;


/*  Função responsável por determinar a altura à esquerda de determinado nó da árvore AVL.
 *    
 *    Entrada:  - node        ==> endereço do primeiro byte do pirmeiro parâmetro de uma
 *                                struct (tipo) node sobre a qual pretende-se obter informação
 *                                de altura à esquerda
 *     
 *    Saída:    - left_height ==> altura à esquerda do nó em análise                                
 */
int left_height_f(NODE* node){
  int left_height;
	
  if(node == NULL){
    return 0;
  }
	
  //Nó sem filhos à esquerda
  if(node->left == NULL){
    left_height = 0;
  }
  else{
    left_height = 1 + node->left->height;
  }
  return left_height;
}


/*  Função responsável por determinar a altura à direita de determinado nó da árvore AVL.
 *    
 *    Entrada:  - node         ==> endereço do primeiro byte do pirmeiro parâmetro de uma
 *                                 struct (tipo) node sobre a qual pretende-se obter informação
 *                                 de altura à direita
 *     
 *    Saída:    - right_height ==> altura à direita do nó em análise                                
 */
int right_height_f(NODE* node){
  int right_height;
	
  if(node == NULL){
    return 0;
  }
	
  //Nó sem filhos à esquerda
  if(node->right == NULL){
    right_height = 0;
  }
  else{
    right_height = 1 + node->right->height;
  }
  return right_height;
}

		
/*  Função responsável por determinar a altura de determinado nó da árvore AVL.
 *    
 *    Entrada:  - node         ==> endereço do primeiro byte do pirmeiro parâmetro de uma
 *                                 struct (tipo) node sobre a qual pretende-se obter informação
 *                                 de altura
 *     
 *    Saída:    - height       ==> altura do nó em análise                                
 */
int height_f(NODE* node){
  int height;
  int left_height;
  int right_height;
	
  if(node == NULL){
    return 0;
  }
	
  left_height = left_height_f(node);
  right_height = right_height_f(node);
  
  if(left_height > right_height){
    height = left_height;
  }
  else{
    height = right_height;
  }

  return height;
}


/*  Função responsável por determinar o balanceamento de um nó da árvore AVL.
 *    
 *    Entrada:  - node         ==> endereço do primeiro byte do pirmeiro parâmetro de uma
 *                                 struct (tipo) node sobre a qual pretende-se obter informação
 *                                 de balanceamento
 *     
 *    Saída:    - balance      ==> balanceamento do nó em análise                                
 */
int balance(NODE* node){
  int balance;

  if(node == NULL){
    return 0;
  }
	
  balance = left_height_f(node) - right_height_f(node);
 
  return balance;
}


/*  Função responsável por realizar a rotação para a direita de um nó de uma árvore AVL.
 *    
 *    Entrada:  - node         ==> endereço do primeiro byte do pirmeiro parâmetro de uma
 *                                 struct (tipo) node que pretende-se rotacionar
 *     
 *    Saída:    - aux          ==> endereço do primeiro byte do primeiro parâmetro da 
 *                                 struct após a realização da rotação                                
 */
NODE* rotate_right(NODE *node){
	NODE* aux;
	
  aux = node->left;
	node->left = aux->right;
	aux->right= node;
	node->height= height_f(node);
	aux->height = height_f(aux);
	return aux;
}


/*  Função responsável por realizar a rotação para a esquerda de um nó de uma árvore AVL.
 *    
 *    Entrada:  - node         ==> endereço do primeiro byte do pirmeiro parâmetro de uma
 *                                 struct (tipo) node que pretende-se rotacionar
 *     
 *    Saída:    - aux          ==> endereço do primeiro byte do primeiro parâmetro da 
 *                                 struct após a realização da rotação                                
 */
NODE* rotate_left(NODE* node){
	NODE* aux;

	aux = node->right;
	node->right = aux->left;
	aux->left = node;
	node->height = height_f(node);
	aux->height = height_f(aux);
	
	return aux;
}


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
  aux->height = 0;
  return aux;
}


/*  Função que faz a inserção de elementos em árvore AVL.
 *    
 *    Entradas: - node     ==> endereço do primeiro byte do pirmeiro parâmetro de uma
 *                             struct (tipo) node na qual se pretende fazer a inserção
 *		        - newValue ==> valor a ser incluído na árvore
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
      if (balance(node) == 2){
        if (newValue < node->left->value){
          node = rotate_right(node);
        }
        else{
          node->left = rotate_left(node->left);
          node = rotate_right(node);
        }
      }
    }
    else{
      node->right = insertNode(node->right, newValue);
      if (balance(node) == -2){
        if (newValue < node->right->value){
          node->right = rotate_right(node->right);
          node = rotate_left(node);
        }
        else{
          node = rotate_left(node);
        }
      }
    }
  }

  node->height = height_f(node);

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
		              //root aponta para o endereço de uma struct node (raiz da árvore). 
  
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
