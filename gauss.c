#include <stdio.h>

void exibirmatriz(float A[3][4]){

    printf("\n");
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            printf("[%.2f]", A[i][j]);

        }

        printf("\n");

    }

}

int main(){

    float A[3][4], indice, resultante[4];
    int i, j, homogenea = 1, pivos = 0, termosindependentes = 0;

    for(i = 0; i < 3; i++){
        for(j = 0; j < 4; j++){

            printf("[%d][%d]: \n", i, j);
            scanf("%f", &A[i][j]);
            
            if(A[i][j] != 0){
                homogenea = 0;
            }
        }
    }

    //SISTEMA HOMOGENEO, COMPOSTO APENAS DE 0

    if(homogenea){
        printf("\nSISTEMA INDETERMINADO, INFINITAS SOLUCOES!");
        return 0;
    }

    exibirmatriz(A);

    //PRIMEIRO PIVÔ
    //TRANSFORMA O PRIMEIRO PIVÔ EM 1

    if(A[0][0] == 0){ //CASO O PRIMEIRO PIVO SEJA 0

        int colunavalida = -1;

        for(i = 0; i < 3; i++){
            
            if(A[i][0] != 0){
                colunavalida = i;
                break;
            }
        }

        if (colunavalida != -1) {

            for (j = 0; j < 4; j++) {

                float temp = A[0][j];
                A[0][j] = A[colunavalida][j];
                A[colunavalida][j] = temp;

            }

            printf("\n[E1]: PERMUTACAO ENTRE L1 E L%d\n", colunavalida + 1);
        } else {
            printf("\nNENHUM PIVO NAO NULO NA PRIMERA COLUNA\n");
        }

        exibirmatriz(A);
        
    }
    
    if(A[0][0] != 0){

        float pivo = A[0][0];

        for(i = 0; i < 4; i++){
            A[0][i] /= pivo;
        }

        printf("\n[E2]: DIVISAO DA LINHA L1 POR %.2f\n", pivo);

        exibirmatriz(A);

    }

    //A[1][0] = 0 ABAIXO

    if(A[1][0] != 0){

        float indice = A[1][0] / A[0][0];

        for(i = 0; i < 4; i++){

            resultante[i] = A[0][i] * indice;
            A[1][i] = A[1][i] - resultante[i];

        }

        printf("\n[E3]: L2 → L2 - L1 * %.2f\n", indice);

    }

    //A[2][0] = 0 ABAIXO

    if(A[2][0] != 0){

        indice = A[2][0] / A[0][0];

        for(i = 0; i < 4; i++){

            resultante[i] = A[0][i] * indice;
            A[2][i] = A[2][i] - resultante[i];

        }

        printf("\n[E3]: L3 → L3 - L1 * %.2f\n", indice);

        exibirmatriz(A);

    }


    if(A[1][1] != 0){

        float pivo = A[1][1];

        for(i = 0; i < 4; i++){
            A[1][i] /= pivo;
        }

        printf("\n[E2]: DIVISAO DA LINHA L2 POR %.2f\n", pivo);

        exibirmatriz(A);
    }

    //A[0][1] = 0 ACIMA DO PIVÔ

    if(A[1][1] != 0 && A[0][1] != 0){

        indice = A[0][1] / A[1][1];

        for(i = 0; i < 4; i++){

            resultante[i] = A[1][i] * indice;
            A[0][i] = A[0][i] - resultante[i];
        }

        printf("\n[E3]: L1 → L1 - L2 * %.2f\n", indice);

    }

    //A[2][1] = 0 ABAIXO DO PIVÔ

    if(A[1][1] != 0 && A[2][1] != 0){

        indice = A[2][1] / A[1][1];

        for(i = 0; i < 4; i++){

            resultante[i] = A[1][i] * indice;
            A[2][i] = A[2][i] - resultante[i];
        }

        printf("\n[E3]: L3 → L3 - L2 * %.2f\n", indice);

        exibirmatriz(A);

    }


    //TERCEIRO PIVÔ
    //TRANSFORMA O TERCEIRO PIVÔ EM 1

    if(A[2][2] == 0){ //CASO O TERCEIRO PIVO SEJA 0

        exibirmatriz(A);

        return 0;
        
    }


    if(A[2][2] != 0){

        float pivo = A[2][2];

        for(i = 0; i < 4; i++){
            A[2][i] /= pivo;
        }

        printf("\n[E2]: DIVISAO DA LINHA L3 POR %.2f\n", pivo);

        exibirmatriz(A);

    }


    //A[1][2] = 0 ACIMA DO PIVÔ

    if(A[2][2] != 0 && A[1][2] != 0){

        float indice = A[1][2] / A[2][2];

        for(i = 0; i < 4; i++){

            resultante[i] = A[2][i] * indice;
            A[1][i] = A[1][i] - resultante[i];

        }

        printf("\n[E3]: L2 → L2 - L3 * %.2f\n", indice);

    }

    //A[0][2] = 0 ACIMA DO PIVÔ

    if(A[2][2] != 0 && A[0][2] != 0){

        float indice = A[0][2] / A[2][2];

        for(i = 0; i < 4; i++){

            resultante[i] = A[2][i] * indice;
            A[0][i] = A[0][i] - resultante[i];

        }

        printf("\n[E3]: L1 → L1 - L3 * %.2f\n", indice);

    }

    exibirmatriz(A);

    for(i = 0; i < 3; i++){
        
        if(A[i][i] == 1){
            pivos++;
        }

        if(A[i][3] != 0){
            termosindependentes++;
        }
        

    }

    if (pivos == termosindependentes && pivos == 3) {
        printf("SOLUCAO UNICA: SISTEMA POSSIVEL E DETERMINADO\n");
    } 
    else if (pivos == termosindependentes && pivos < 3) {
        printf("INFINITAS SOLUCOES: SISTEMA POSSIVEL E INDETERMINADO\n");
    } 
    else if (pivos < termosindependentes) {
        printf("NENHUMA SOLUCAO: SISTEMA IMPOSSIVEL\n");
    }

}
