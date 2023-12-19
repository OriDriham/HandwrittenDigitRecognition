#ifndef MLPNETWORK_H
#define MLPNETWORK_H

#include "Matrix.h"
#include "Dense.h"
#include "Digit.h"

#define MLP_SIZE 4


const matrix_dims img_dims = {28, 28};
const matrix_dims weights_dims[] = {{128, 784},
                                    {64,  128},
                                    {20,  64},
                                    {10,  20}};
const matrix_dims bias_dims[] = {{128, 1},
                                 {64,  1},
                                 {20,  1},
                                 {10,  1}};


class MlpNetwork {
 private:
  Dense _mlp[MLP_SIZE];
 public:
  /**
 * Constructor for MlpNetwork
 * @param weights - array of matrices
 * @param biases - array of matrices
 */
  MlpNetwork (Matrix *, Matrix *);

  /**
 * Applies the entire network on input
 * @param input - vector (matrix) by reference
 * @return digit struct - the output (by value)
 */
  digit operator() (Matrix &);

};

#endif
