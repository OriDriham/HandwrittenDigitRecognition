#ifndef C___PROJECT_DENSE_H
#define C___PROJECT_DENSE_H

#include "Activation.h"


class Dense {
 private:
  Matrix _weights;
  Matrix _bias;
  ActivationType _activation;

 public:
  /**
 * Constructor for Dense with 2 matrices and activation type
 * @param w - weight matrix
 * @param bias - bias vector (matrix)
 * @param type - enum ActivationType: RELU or SOFTMAX
 */
  Dense (Matrix &, Matrix &, ActivationType);

  /**
 * Getter for _weights
 * @return _weights (Matrix), by value - forbids modification
 */
  Matrix get_weights () const;

  /**
 * Getter for _bias
 * @return _bias (Matrix), by value - forbids modification
 */
  Matrix get_bias () const;

  /**
 * Getter for _activation
 * @return _activation (ActivationType), by value - forbids modification
 */
  ActivationType get_activation () const;

  /**
 * Applies the layer in input and returns output matrix
 * @return output matrix after applying layer on input, by references
 */
  Matrix operator() (Matrix &) const;
};

#endif
