/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: SalihaSAGOL
 *
 * Created on 01 Kasım 2020 Pazar, 19:30
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIZIBOYUT 500

float **matrixMatrixMultiply1(float**, float**);
float **matrixMatrixMultiply2(float**, float**);
float **matrixMatrixMultiply3(float**, float**);
float **matrixMatrixMultiply4(float**, float**);
float **matrixMatrixMultiply5(float**, float**);
float **matrixMatrixMultiply6(float**, float**);

int main(int argc, char** argv) {

    srand(time(NULL));

    int i, j, k;
    float atama1, atama2;

    // bellekte matris1 e yer ayırma

    float **matris1 = (float**) malloc(sizeof (float*)*DIZIBOYUT);
    for (i = 0; i < DIZIBOYUT; i++) {
        matris1[i] = (float*) malloc(sizeof (float)*DIZIBOYUT);
    }
    // bellekte matris2 ye yer ayırma
    float **matris2 = (float**) malloc(sizeof (float*)*DIZIBOYUT);
    for (i = 0; i < DIZIBOYUT; i++) {
        matris2[i] = (float*) malloc(sizeof (float)*DIZIBOYUT);
    }

    // random matris üretim

    for (i = 0; i < DIZIBOYUT; i++) {
        for (j = 0; j < DIZIBOYUT; j++) {
            atama1 = (rand() % 5) + 1.2;
            atama2 = (rand() % 6) + 2.2;
            matris1[i][j] = atama1;
            matris2[i][j] = atama2;
        }

    }


    float saniyeSayac;

    clock_t start, stop;

    start = clock(); // çarpımdan önce süreyi başlatma

    //fonksiyonları çağırma
    
    float **matrisSonuc1 = matrixMatrixMultiply1(matris1, matris2); // i-j-k
    //float **matrisSonuc2 = matrixMatrixMultiply2(matris1, matris2); // i-k-j
    //float **matrisSonuc3 = matrixMatrixMultiply3(matris1, matris2); // k-i-j
    //float **matrisSonuc4 = matrixMatrixMultiply4(matris1, matris2); // j-i-k
    //float **matrisSonuc5 = matrixMatrixMultiply5(matris1, matris2); // k-j-i
    //float **matrisSonuc6 = matrixMatrixMultiply6(matris1, matris2); // j-k-i


    stop = clock(); // çarpım bittikten sonra süreyi durdurma

    saniyeSayac = (float) (stop - start) / CLOCKS_PER_SEC; // saniye hesaplama

    // fonksiyonları yazdırma

    printf("i-j-k %dx%d siralamasi icin gecen saniye = %f\n ", DIZIBOYUT, DIZIBOYUT, saniyeSayac); // 1
    //printf("i-k-j %dx%d siralamasi icin gecen saniye = %f\n ", DIZIBOYUT, DIZIBOYUT, saniyeSayac); // 2
    //printf("k-i-j %dx%d siralamasi icin gecen saniye = %f\n ", DIZIBOYUT, DIZIBOYUT, saniyeSayac); // 3
    //printf("j-i-k %dx%d siralamasi icin gecen saniye = %f\n ", DIZIBOYUT, DIZIBOYUT, saniyeSayac); // 4
    //printf("k-j-i %dx%d siralamasi icin gecen saniye = %f\n ", DIZIBOYUT, DIZIBOYUT, saniyeSayac); // 5
    //printf("j-k-i %dx%d siralamasi icin gecen saniye = %f\n ", DIZIBOYUT, DIZIBOYUT, saniyeSayac); // 6


    free(matris1);
    free(matris2);


    return EXIT_SUCCESS;


}


float **matrixMatrixMultiply1(float **matris1, float **matris2) {// i-j-k
    int i, j, k;
    float **matrisSonuc1 = (float*) malloc(sizeof (float)*DIZIBOYUT);
    for (i = 0; i < DIZIBOYUT; i++) {
        matrisSonuc1[i] = (float *) malloc(sizeof (float)*DIZIBOYUT);
    }
    for (i = 0; i < DIZIBOYUT; i++) {
        for (j = 0; j < DIZIBOYUT; j++) {
            for (k = 0; k < DIZIBOYUT; k++) {
                matrisSonuc1[i][j] += matris1[i][k] * matris2[k][j];


            }


        }

    }

    return matrisSonuc1;


}

float **matrixMatrixMultiply2(float **matris1, float **matris2) {// i-k-j
    int i, j, k;
    float **matrisSonuc2 = (float *) malloc(sizeof (float)*DIZIBOYUT);
    for (i = 0; i < DIZIBOYUT; i++) {
        matrisSonuc2[i] = (float *) malloc(sizeof (float)*DIZIBOYUT);
    }
    for (i = 0; i < DIZIBOYUT; i++) {
        for (k = 0; k < DIZIBOYUT; k++) {
            for (j = 0; j < DIZIBOYUT; j++) {
                matrisSonuc2[i][k] += matris1[i][j] * matris2[j][k];
            }

        }

    }

    return matrisSonuc2;
}

float **matrixMatrixMultiply3(float **matris1, float **matris2) {// k-i-j
    int i, j, k;
    float **matrisSonuc3 = (float *) malloc(sizeof (float)*DIZIBOYUT);
    for (i = 0; i < DIZIBOYUT; i++) {
        matrisSonuc3[i] = (float *) malloc(sizeof (float)*DIZIBOYUT);
    }
    for (k = 0; k < DIZIBOYUT; k++) {
        for (i = 0; i < DIZIBOYUT; i++) {
            for (j = 0; j < DIZIBOYUT; j++) {
                matrisSonuc3[k][i] += matris1[k][j] * matris2[j][i];
            }

        }

    }

    return matrisSonuc3;
}

float **matrixMatrixMultiply4(float **matris1, float **matris2) {// j-i-k
    int i, j, k;
    float **matrisSonuc4 = (float *) malloc(sizeof (float)*DIZIBOYUT);
    for (i = 0; i < DIZIBOYUT; i++) {
        matrisSonuc4[i] = (float *) malloc(sizeof (float)*DIZIBOYUT);
    }
    for (j = 0; j < DIZIBOYUT; j++) {
        for (i = 0; i < DIZIBOYUT; i++) {
            for (k = 0; k < DIZIBOYUT; k++) {
                matrisSonuc4[j][i] += matris1[j][k] * matris2[k][i];
            }

        }

    }

    return matrisSonuc4;
}

float **matrixMatrixMultiply5(float **matris1, float **matris2) {// k-j-i
    int i, j, k;
    float **matrisSonuc5 = (float *) malloc(sizeof (float)*DIZIBOYUT);
    for (i = 0; i < DIZIBOYUT; i++) {
        matrisSonuc5[i] = (float *) malloc(sizeof (float)*DIZIBOYUT);
    }
    for (k = 0; k < DIZIBOYUT; k++) {
        for (j = 0; j < DIZIBOYUT; j++) {
            for (i = 0; i < DIZIBOYUT; i++) {
                matrisSonuc5[k][j] += matris1[k][i] * matris2[i][j];
            }

        }

    }

    return matrisSonuc5;
}

float **matrixMatrixMultiply6(float **matris1, float **matris2) {// j-k-i
    int i, j, k;
    float **matrisSonuc6 = (float *) malloc(sizeof (float)*DIZIBOYUT);
    for (i = 0; i < DIZIBOYUT; i++) {
        matrisSonuc6[i] = (float *) malloc(sizeof (float)*DIZIBOYUT);


    }
    for (j = 0; j < DIZIBOYUT; j++) {
        for (k = 0; k < DIZIBOYUT; k++) {
            for (i = 0; i < DIZIBOYUT; i++) {
                matrisSonuc6[j][k] += matris1[j][i] * matris2[i][k];

            }

        }

    }

    return matrisSonuc6;
}


