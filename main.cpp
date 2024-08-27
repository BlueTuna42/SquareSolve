#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Common.h"
#include "SolveEquation.h"
#include "Print.h"
#include "UnitTests.h"

int main() {
#if RUN_TESTS
    runTests();
    return 0;
#else
    coeff QuadCoeff = {NAN, NAN, NAN};
    roots QuadRoots = {NAN, NAN};

    inputEquation(&QuadCoeff);

    int nRoots = SolveEquation(QuadCoeff, &QuadRoots);

    return printResults(nRoots, QuadRoots);

#endif
}
