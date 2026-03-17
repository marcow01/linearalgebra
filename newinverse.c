#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

// →

void show(float *p, int N){

    printf("\n");

    for(int i = 0; i < N * N; i++){

        //printf("→ %p → %.2f", p + i, *(p + i));
        printf("[%.2f]", *(p + i));

        if((i + 1) % N == 0){

            printf("\n");

        }
    }
}

void receive(float *p, int N, bool *ishomogeneouspointer){

    printf("\n");

    for(int i = 0; i < N * N; i++){
        printf("→ %p \n", p + i);
        scanf("%f", &*(p + i));

        if(*(p + i) != 0){

            *ishomogeneouspointer = false;

        }
    }


}

int verifyhomogeneity(bool *ishomogeneouspointer){

    if (*ishomogeneouspointer){
        printf("\nsistema indeterminado, infinitas soluções! \n");
        return 0;
    }
}

int pivot(float *p, int N){

    // printf("início da memória → [%p] \n", p);
    printf("\n");

    //transformando de linear pra matriz

    float A[N][N];

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){

            A[i][j] = *(p + i*N + j);

        }
    }

    //exibindo matriz

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){

            if(i == j){

                if(A[i][j] != 0){

                    printf(GREEN "[%.2f]" RESET, A[i][j]);

                }
                else{ 

                    printf(RED"[%.2f]" RESET, A[i][j]);
                }

            }
            else{
                printf("[%.2f]", A[i][j]);
            }

        }

        printf("\n");
    }

    //fim da exibicao da matriz

    //verificando se o pivô é válido

    printf("\n");

    for(int i = 0; i < N; i++){
        
        if(A[i][i] == 0){}

        else{ 

            float pivot = A[i][i];

            //deixou o pivô unitário

            for(int j = 0; j < N; j++){

                A[i][j] /= pivot;

                printf("DIVISAO DA LINHA %d, ITEM %d POR %.2f \n", i + 1, j, pivot);

            }

            //zerar os elementos abaixo da linha

            for(int k = 0; k < N; k++){

                if(k == i) continue;

                float factor = A[k][i];

                for(int j = 0; j < N; j++){
                    A[k][j] -= factor * A[i][j];
                }

            }


        }

    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){

            if(i == j){

                if(A[i][j] != 0){

                    printf(GREEN "[%.2f]" RESET, A[i][j]);

                }
                else{ 

                    printf(RED"[%.2f]" RESET, A[i][j]);
                }

            }
            else{
                printf("[%.2f]", A[i][j]);
            }

        }

        printf("\n");
    }

}

int main(void){

    int N;
    bool ishomogeneous = true;
    bool *ishomogeneouspointer = &ishomogeneous;

    printf("[N]: \n");
    scanf("%d", &N);

    float A[N][N];
    float *p = &A[0][0];
    receive(p, N, ishomogeneouspointer);
    show(p, N);
    verifyhomogeneity(ishomogeneouspointer);

    // for(int i = 0; i < N; i++){
    //     pivot(p, N, i);
    //     printf("\n");
    // }

    pivot(p, N);

}