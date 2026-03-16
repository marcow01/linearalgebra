#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

    printf("início da memória → [%p] \n", p);

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

            if(i != j){
                printf("[%.2f]", A[i][j]);
            }
            else{
                printf("\033[32m[%.2f]\033[0m", A[i][j]);
            }

        }

        printf("\n");
    }

    for(int i = 0; i < N; i++){
        
        if(A[i][i] != 0){

            printf("\033[32m[%.2f] → pivô válido \033[0m\n", A[i][i]);

        }
        else{ 

            printf("\033[31m[%.2f] → pivô inválido \033[0m\n", A[i][i]);
        }
        
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
    // printf("[A] → %b \n", ishomogeneous);
    verifyhomogeneity(ishomogeneouspointer);

    // for(int i = 0; i < N; i++){
    //     pivot(p, N, i);
    //     printf("\n");
    // }

    pivot(p, N);

}