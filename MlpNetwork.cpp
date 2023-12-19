#include "MlpNetwork.h"

#define W1 0
#define W2 1
#define W3 2
#define W4 3
#define B1 0
#define B2 1
#define B3 2
#define B4 3
#define I1 0
#define I2 1
#define I3 2
#define I4 3
#define PERCENT 100

/**
 * Constructor for MlpNetwork
 * @param weights - array of matrices
 * @param biases - array of matrices
 */
MlpNetwork::MlpNetwork (Matrix *weights, Matrix *biases) :
    _mlp{Dense (weights[W1], biases[B1], RELU),
         Dense (weights[W2], biases[B2], RELU),
         Dense (weights[W3], biases[B3], RELU),
         Dense (weights[W4], biases[B4], SOFTMAX)}
{}

/**
 * Applies the entire network on input
 * @param input - vector (matrix) by reference
 * @return digit struct - the output (by value)
 */
digit MlpNetwork::operator() (Matrix &input)
{
  Matrix r1 = _mlp[I1] (input);
  Matrix r2 = _mlp[I2] (r1);
  Matrix r3 = _mlp[I3] (r2);
  Matrix r4 = _mlp[I4] (r3);
  float max = r4[0];
  unsigned int max_ind = 0;
  for (int i = 1; i < r4.get_rows (); i++)
    {
      if (r4[i] > max)
        {
          max = r4[i];
          max_ind = i;
        }
    }
  max *= PERCENT;  // *100 : in %
  digit d = {max_ind, max};
  return d;
}
