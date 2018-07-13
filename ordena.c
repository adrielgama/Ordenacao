	#include <stdio.h>
	#include <stdlib.h>
	#include <time.h>
	#include <windows.h>
	#include <sys/time.h>
	
	#define TAM 1000
	
	void BubbleSort_1();
	void BubbleSort_2();
	void SelectionSort_1();
	
	
	int main (){        
	
		clock_t n, tFim, tInicio, tDecorrido;
		srand(time(NULL));
		
		int iCont, jCont, aux = 0, vetor[TAM];
	    
	    FILE *ent;
	    
	    ent = fopen("teste1000.txt", "r");
	    
		if(ent == NULL){
			printf("Erro! Nao consegui abrir o arquivo...\n");
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

	    tInicio = clock();
    	Sleep(2);		
		
		//BubbleSort_1(vetor);    
	    BubbleSort_2(vetor);
	    //SelectionSort_1(vetor);
	    
    	tFim = clock();
    	printf("Tempo final: %d\n", tFim);	      
	    
	    fclose( ent );
		
		/*printf("\n\nOrdenado: \n\n");
		for(iCont = 0; iCont < TAM; iCont++){
			printf("%d ", vetor[iCont]);
		}*/
		
		tDecorrido = tFim - tInicio;
    	printf("Vetor gerado em %d milisegundos:\n", tDecorrido);
		
	    printf("\n\n\n\n");
	
	    return 0;
	}
	
	void BubbleSort_1(int vetor[]){
	    int iCont, jCont, aux = 0;
	
	struct timeval  tv1, tv2;
	gettimeofday(&tv1, NULL);

	  
	    for(iCont = 0; iCont < TAM; iCont++){
	        for(jCont = iCont + 1; jCont < TAM; jCont++){
	            if (vetor[iCont] > vetor[jCont]){
	                aux = vetor[iCont];
	                vetor[iCont] = vetor[jCont];
	                vetor[jCont] = aux;
	            }
	        }
	    }
	    
	gettimeofday(&tv2, NULL);
	printf ("Total time = %.8f seconds\n",
	         (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 +
	         (double) (tv2.tv_sec - tv1.tv_sec));
	
	}
	
	void BubbleSort_2(int vetor[]){
	    int iCont, jCont, aux = 0;
	
	struct timeval  tv1, tv2;
	gettimeofday(&tv1, NULL);
	
	    for(iCont = TAM - 1; iCont > 0; iCont--){
	        for(jCont = 0; jCont < iCont; jCont++){
	            if (vetor[jCont] > vetor[jCont + 1]){
	                aux = vetor[jCont];
	                vetor[jCont] = vetor[jCont + 1];
	                vetor[jCont + 1] = aux;
	            }
	        }
	    }
	    
	gettimeofday(&tv2, NULL);
	printf ("Total time = %.8f seconds\n",
	         (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 +
	         (double) (tv2.tv_sec - tv1.tv_sec));
	
	
	}
	
	void SelectionSort_1(int vetor[]){ 
		int iCont, jCont, min, aux = 0;
		
	struct timeval  tv1, tv2;
	gettimeofday(&tv1, NULL);
		
		for(iCont = 0; iCont < TAM - 1; iCont++){
			min = iCont;
			for(jCont = iCont + 1; jCont < TAM; jCont++){
				if(vetor[jCont] < vetor[min]) 
					min = jCont;
	     	}
		if(vetor[iCont] != vetor[min]){
			aux = vetor[iCont];
			vetor[iCont] = vetor[min];
			vetor[min] = aux;
	     }
	  }
	
	gettimeofday(&tv2, NULL);
	printf ("Total time = %.8f seconds\n",
	         (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 +
	         (double) (tv2.tv_sec - tv1.tv_sec));
	}
