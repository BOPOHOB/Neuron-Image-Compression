#ifndef NEURALSPAN_H
#define NEURALSPAN_H

#include "kernel/cmatrix.h"


class NeuralSpan : public CMatrix
{
public:
    NeuralSpan(int n, int l);
};

#endif // NEURALSPAN_H
