#include <stdio.h>
#include <stdlib.h>


#include "Common.h"
#include "Print.h"

static const int COEF_NUMBER = 3;

int printResults(int nRoots, roots results) {
    printf("Results: ");

    switch (nRoots) {
        case ZERO_ROOTS:
            printf("No Roots \n");
            return 0;
            break;
        case ONE_ROOT:
            printf("%lg \n", results.x1);
            return 0;
            break;
        case TWO_ROOTS:
            printf("%lg %lg \n", results.x1, results.x2);
            return 0;
            break;
        case INF_ROOTS:
            printf("Infinite number of roots \n");
            return 0;
            break;
        default:
            RedTx();
            printf("ERROR. Unexpected number of roots \n");
            GrayTx();
            return ERR_TOO_MANY_ROOTS;
    }
}

int inputEquation (coeff* QuadCoeff) {
    printf("# Enter square equation coefficients: \n");
    if (scanf("%lg %lg %lg", &QuadCoeff->a, &QuadCoeff->b, &QuadCoeff->c) != COEF_NUMBER) {
        RedTx();
        printf("Input Error \n");
        GrayTx();
        return INPUT_ERROR;
    }

    return 0;
}
