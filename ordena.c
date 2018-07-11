#include <stdio.h>
#include <stdlib.h>

#define TAM 10000

void BubbleSort_1();
void BubbleSort_2();
void BubbleSort_3();
void BubbleSort_4();

int main (){        

	int iCont, jCont, aux = 0, vetor[TAM];
    
    FILE *ent;
    
    ent = fopen("teste.txt", "r");
    
	if(ent == NULL){
		printf("Erro! Nao consegui abrir o arquivo...\n");
		exit(1);
	}

	for(iCont = 0; iCont < TAM; iCont++){
		printf("Lendo posicao %d\n", iCont);
		if(fscanf(ent, "%d", &vetor[iCont]) == EOF){
				setbuf(stdin, NULL);
			printf("Opa, tentei ler alem do final do arquivo...\n");
			break;
		}
	}

    //BubbleSort_1(vetor);
    //BubbleSort_2(vetor);
    //BubbleSort_3(vetor);
    BubbleSort_4(vetor);
      
    
    fclose( ent );
	
	printf("\n\nOrdenado: \n\n");
	for(iCont = 0; iCont < TAM; iCont++){
		printf("%d ", vetor[iCont]);
	}
	
    printf("\n\n\n\n");

    return 0;
}

void BubbleSort_1(int vetor[]){
    int iCont, jCont, aux = 0;

    for(iCont = 0; iCont < TAM; iCont++){
        for(jCont = iCont + 1; jCont < TAM; jCont++){
            if (vetor[iCont] > vetor[jCont]){
                aux = vetor[iCont];
                vetor[iCont] = vetor[jCont];
                vetor[jCont] = aux;
            }
        }
    }    

}

void BubbleSort_2(int vetor[]){
    int iCont, jCont, aux = 0;

    for(iCont = 1; iCont < TAM; iCont++){
        for(jCont = 0; jCont < TAM - iCont; jCont++){
            if (vetor[jCont] > vetor[jCont + 1]){
                aux = vetor[jCont];
                vetor[jCont] = vetor[jCont + 1];
                vetor[jCont + 1] = aux;
            }
        }
    }    

}

void BubbleSort_3(int vetor[]){
    int iCont, jCont, aux = 0;

    for(iCont = 0; iCont < TAM - 1; iCont++){
        for(jCont = 0; jCont < TAM - iCont - 1; jCont++){
            if (vetor[jCont] > vetor[jCont + 1]){
                aux = vetor[jCont];
                vetor[jCont] = vetor[jCont + 1];
                vetor[jCont + 1] = aux;
            }
        }
    }    

}

void BubbleSort_4(int vetor[]){
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

}
