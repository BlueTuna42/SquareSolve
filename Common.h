#pragma once
#include "TXLib.h"

#define RUN_TESTS 0
#define NDEBUG 0

#if !NDEBUG
    #define myAssert(condition, err_msg, retcode)                               \
                do {                                                            \
                    if (condition) {                                            \
                        RedTx();                                                \
                        printf ("[%s, %d]: %s\n", __func__, __LINE__, err_msg); \
                        exit(retcode);                                          \
                    }                                                           \
                } while (0)
#else
    #define myAssert(condition, err_msg, retcode)
#endif

enum ERROR_CODES {
    ERR_TOO_MANY_ROOTS = -128,
    INPUT_ERROR = -127,
    ERR_NULL_POINTER = -126

};

enum RootsNumber {
    INF_ROOTS = -1,
    ZERO_ROOTS = 0,
    ONE_ROOT = 1,
    TWO_ROOTS = 2
};

struct coeff {
    double a;
    double b;
    double c;

};

struct roots {
    double x1;
    double x2;
};

bool isZero(double x);
bool floatEqual(double a, double b);
void GrayTx();
void RedTx();
void GreenTx();
