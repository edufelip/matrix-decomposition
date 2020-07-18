#include <stdio.h>

int main (void) {
    int dim, i, j, k, w, maiorInd, worstScenario = 0;
    printf("INSERT THE DIMENSION OF THE MATRIX?\n");
    scanf("%d", &dim);
    double a[dim][dim], b[dim], x[dim], c;
    double maior, sup, comp;
    int log[dim][2];
    for(i = 0; i < dim; i++){
        log[i][0] = 0;
        log[i][1] = 0;
    }
    printf("INSERT MATRIX A\n");
    for(i = 0; i < dim; i++){
        for(j = 0; j < dim; j++){
            scanf("%lf", &a[i][j]);
        }
    }
    printf("INSERT MATRIX B\n");
    for(i = 0; i < dim; i++){
        scanf("%lf", &b[i]);
    }

    for(i = 0; i < dim; i++){
        j = i;
        // TOTAL PIVOTING
        if(a[i][i] < 0){
            maior = a[i][i] * -1;
        } else {
            maior = a[i][i];
        }
        maiorInd = i;
        // CHECK PARTIAL
        for(k = i+1; k < dim; k++){
            if(a[k][i] < 0){
                comp = a[k][i] * -1;
            } else {
                comp = a[k][i];
            }
            if(comp > maior){
                maior = comp;
                maiorInd = k;
                worstScenario = 0;
            }
        }
        // CHECK TOTAL
        for(k = i+1; k < dim; k++){
            if(a[i][k] < 0){
                comp = a[i][k] * -1;
            } else {
                comp = a[i][k];
            }
            if(comp > maior){
                maior = comp;
                maiorInd = k;
                worstScenario = 1;
            }
        }
        if(!worstScenario){
            sup = b[i];
            b[i] = b[maiorInd];
            b[maiorInd] = sup;
            for(k = i; k < dim; k++){
                sup = a[i][k];
                a[i][k] = a[maiorInd][k];
                a[maiorInd][k] = sup;
            }
        } else {
            log[i][0] = i;
            log[i][1] = maiorInd;
            for(k = 0; k < dim; k++){
                sup = a[k][i];
                a[k][i] = a[k][maiorInd];
                a[k][maiorInd] = sup;
            }
        }
        //
        for(k = i+1; k < dim; k++){
            c = a[k][i]/a[i][i];
            for(w = i; w < dim; w++){
                if(w == i){
                    a[k][w] = 0;
                } else {
                    a[k][w] = a[k][w] - (a[i][w] * c);
                }
            }
            b[k] = b[k] - (b[i] * c);
        }
    }

    printf("MATRIX A\n");
    for(i = 0; i < dim; i++){
        for(j = 0; j < dim; j++){
            printf("%lf ", a[i][j]);
        }
        printf("\n");
    }
    printf("MATRIX B\n");
    for(i = 0; i < dim; i++){
        printf("%lf\n", b[i]);
    }

    //  UPPER TRIANGULAR RESOLUTION
    for(i = dim-1 ; i >= 0; i--){
        x[i] = b[i];
        for(j = dim-1; j > i; j--){
            x[i] = x[i] - a[i][j] * x[j];
        }
        x[i] = x[i]/a[i][j];
    }

    //  UNDO PIVOTING COLUMN EXCHANGE
    for(i = 0; i < dim; i++){
        sup = x[log[i][0]];
        x[log[i][0]] = x[log[i][1]];
        x[log[i][1]] = sup;
    }

    printf("MATRIX X (RESOLUTION)\n");
    for(i = 0; i < dim; i++){
        printf("%lf\n", x[i]);
    }
    return 0;
}