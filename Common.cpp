#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Common.h"

static const double Epsilon = 1e-4;

bool isZero(double x) {
    return fabs(x) < Epsilon;
}

bool floatEqual(double a, double b) {
    return fabs(a - b) < Epsilon;
}

void GrayTx() {
    txSetConsoleAttr (FOREGROUND_LIGHTGRAY | BACKGROUND_BLACK);
}

void RedTx() {
    txSetConsoleAttr (FOREGROUND_RED | BACKGROUND_BLACK);
}

void GreenTx() {
    txSetConsoleAttr (FOREGROUND_GREEN | BACKGROUND_BLACK);
}

