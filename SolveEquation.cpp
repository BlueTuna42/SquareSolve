#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Common.h"
#include "SolveEquation.h"


static int SolveSquare(coeff abc, roots* answers) {
    myAssert(answers == NULL, "ERROR. NULL pointer \n", ERR_NULL_POINTER);

    int nRoots = ERR_TOO_MANY_ROOTS;

    double D = abc.b * abc.b - 4 * abc.a * abc.c;

    if (isZero(D)) {
        answers->x1 = -abc.b / (2 * abc.a);
        answers->x2 = answers->x1;
        nRoots = 1;
    } else if (D < 0) {
        return 0;
    } else {
        double sqrt_D = sqrt(D);
        answers->x1 = (-abc.b - sqrt_D) / (2 * abc.a);
        answers->x2 = (-abc.b + sqrt_D) / (2 * abc.a);
        nRoots = 2;
    }

    return nRoots;
}

static int SolveLinear(coeff bc, roots* answer) {
    myAssert(answer == NULL, "ERROR. NULL pointer \n", ERR_NULL_POINTER);

    if (isZero(bc.b)) {
        if (isZero(bc.c)) {
            return INF_ROOTS;
        } else {
            return 0;
        }
    } else {
        (*answer).x1 = (-bc.c) / bc.b;
        if (isZero(answer->x1)) {
            answer->x1 = 0;
        }
        return 1;
    }
}

int SolveEquation (coeff abc, roots* answers) {
    int nRoots = ERR_TOO_MANY_ROOTS;

    if (isZero(abc.a)) {
        nRoots = SolveLinear(abc, answers);
    } else {
        nRoots = SolveSquare(abc, answers);
    }

    return nRoots;
}

