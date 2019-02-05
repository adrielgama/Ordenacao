/*
Construa um programa escrito em C que:
1 - Leia um arquivo de texto ;
2 - Carregue os dados em um vetor de caracteres;
3 - Possibilite que o usuário escolha um dos algoritmos de ordenação estudados em sala de aula (pelo menos três opções);
*/


#include <stdio.h>
#include <stdlib.h>

#define TAM 10 //Deve-se mudar o tamanho da entrada de acordo a vontade do usuário.

void BubbleSort();
void SelectionSort();
void InsertionSort();
int menu();


int main (){

	int iCont, jCont, aux = 0;
	int vetor[TAM];
	int sair = 0, op;
    
    FILE *ent;
    
    ent = fopen("teste.txt", "r"); //Lembrar de mudar o DEFINE para cada tamanho de entrada
    
	if(ent == NULL){
		printf("Erro, nao consegui abrir o arquivo...\n");
		exit(1);
	}
	

	for(iCont = 0; iCont < TAM; iCont++){
		//printf("Lendo posicao %d\n", iCont);
		if(fscanf(ent, "%d", &vetor[iCont]) == EOF){
				setbuf(stdin, NULL);
			printf("Opa, tentei ler alem do final do arquivo...\n");
			break;
		}
	}
	
	    while (!sair) {
        op = menu();
	        switch (op) {
	            case 0: { //Sair do programa
	                
	                system("cls");
	                sair = 1;
	                break;
	            }
	            case 1: { //Ordena usando BubbleSort
	            
					//printf("\n\n");
	                system("cls");
    				BubbleSort(vetor);
    				sair = 1;
					break;
	            }
	
	            case 2: { //Ordena usando SelectionSort
	                
					//printf("\n\n");
	                system("cls");
    				SelectionSort(vetor);
    				sair = 1;
	                break;
	            }
	            
	            case 3 : { //Ordena usando InsertionSort
	            	
	            	//printf("\n\n");
	            	system("cls");
    				InsertionSort(vetor);
    				sair = 1;
					break;
				}
	
	            default: { //Caso nao seja uma opcao valida
	            
	                system("cls");
					printf("Ops! Opcao invalida.\n");
					sair = 1;
	            }
	        }
    	}
	
        printf("\n\n");
    
    fclose( ent );
	

    return 0;
}

int menu(){
	int op;
	
    printf("\n\n");
    printf("\tEscolha o algoritmo de ordenacao desejado\n");
    printf("\t1 - Bubble Sort\n");
    printf("\t2 - Selection Sort\n");
    printf("\t3 - Insertion Sort\n");
    printf("\n");
    printf("\t0 - Sair\n");
        scanf("%d", &op);
        printf("\n\n");
    return op;
}

void BubbleSort(int vetor[]){
    int iCont, jCont, aux = 0;
  
    for(iCont = TAM - 1; iCont > 0; iCont--){
        for(jCont = 0; jCont < iCont; jCont++){
            if (vetor[jCont] > vetor[jCont + 1]){
                aux = vetor[jCont];
                vetor[jCont] = vetor[jCont + 1];
                vetor[jCont + 1] = aux;
            }
        }
}
	
	printf("Bubble Sort Ordenado\n");
	for(iCont = 0; iCont < TAM; iCont++){
		printf("%d ", vetor[iCont]);
	}
}

void SelectionSort(int vetor[]){ 
	int iCont, jCont, min, aux = 0;
	
	for(iCont = 0; iCont < TAM - 1; iCont++){
		min = iCont;
		
		for(jCont = iCont + 1; jCont < TAM; jCont++){
			if(vetor[jCont] < vetor[min]) 
				min = jCont;
     	}
     	
	if(iCont != min){
		aux = vetor[min];
		vetor[min] = vetor[iCont];
		vetor[iCont] = aux;
     }
}

	printf("Selection Sort Ordenado\n");
	for(iCont = 0; iCont < TAM; iCont++){
		printf("%d ", vetor[iCont]);
	}
}

void InsertionSort(int vetor[]){ 
	int iCont, jCont, min, aux = 0;
	
	for (iCont = 1 ; iCont <= TAM - 1; iCont++) {
    	min = iCont;
		while ( min > 0 && vetor[min - 1] > vetor[min]) {
	      	aux = vetor[min];
	      	vetor[min]   = vetor[min - 1];
	      	vetor[min - 1] = aux;
	      	min--;
	    }
	}

	printf("Insertion Sort Ordenado\n");
	for(iCont = 0; iCont < TAM; iCont++){
		printf("%d ", vetor[iCont]);
	}
}
