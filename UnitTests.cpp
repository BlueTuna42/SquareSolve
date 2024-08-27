#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Common.h"
#include "SolveEquation.h"
#include "UnitTests.h"


struct test {
    coeff equation;
    roots results;
    int nRootsRef;
    unsigned int testNumber;
};

const static test testArr [] = {
//     a      b          c          x1         x2      nRoots    nTest
    {    1,      0,          -4,        -2,         2,         2,     0},
    {    1,      2,          -3,        -3,         1,         2,     1},
    {    2,    0.5,       -0.25,      -0.5,      0.25,         2,     2},
    {    0,      0,           0,       NAN,       NAN, INF_ROOTS,     3},
    {    1,      0,           0,         0,         0,         1,     4},
    {0.356, -0.145,      -1.458,   -1.8303,   2.23761,         2,     5},
    { 1432,   9032, -90123.1242, -11.69064,   5.38338,         2,     6}
};


static int SolverTests (coeff abc, roots refRoots, int nRootsRef, unsigned int testNumber) {
    roots results = {NAN, NAN};

    int nRoots = SolveEquation(abc, &results);

    if (!floatEqual(results.x1, refRoots.x1)) {
        if (!isnan(results.x1) && !isnan(refRoots.x1)) {
            RedTx();
            printf("ERROR Test %i. x1 != x1Ref. x1 = %lg, x1Ref = %lg \n", testNumber, results.x1, refRoots.x1);
            GrayTx();
            return 0;
        }

        if (!isnan(results.x2) && !isnan(refRoots.x2)) {
            RedTx();
            printf("ERROR Test %i. x2 != x2Ref. x2 = %lg, x1Ref = %lg \n", testNumber, results.x2, refRoots.x2);
            txSetConsoleAttr (FOREGROUND_LIGHTGRAY | BACKGROUND_BLACK);
            return 0;
        }

        if (nRoots != nRootsRef) {
            RedTx();
            printf("ERROR Test %i. nRoots != nRootsRef. nRoots = %i, nRootsRef = %i \n", testNumber, nRoots, nRootsRef);
            GrayTx();
            return 0;
        }
    }
    return 1;
}


void runTests () {
    bool fail = 0;

    unsigned int testsNumber = sizeof(testArr) / sizeof(test);
    for (unsigned int i = 0; i < testsNumber; i++) {
        if (SolverTests(testArr[i].equation, testArr[i].results, testArr[i].nRootsRef, testArr[i].testNumber)) {
            GreenTx();
            printf("Test %i passed \n", i);
            GrayTx();;
        } else {
            fail = 1;
        }
    }

    if (!fail) {
        GreenTx();
        printf("All tests passed successfully!");
        GrayTx();
    }
}
