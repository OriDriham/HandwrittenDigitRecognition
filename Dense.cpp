#include "Dense.h"

/**
 * Constructor for Dense with 2 matrices and activation type
 * @param w - weight matrix
 * @param bias - bias vector (matrix)
 * @param type - enum ActivationType: RELU or SOFTMAX
 */
Dense::Dense (Matrix &w, Matrix &bias, ActivationType activation)
    : _weights (w), _bias (bias), _activation (activation)
{}

/**
 * Getter for _weights
 * @return _weights (Matrix), by value - forbids modification
 */
Matrix Dense::get_weights () const
{
  return _weights;
}

/**
 * Getter for _bias
 * @return _bias (Matrix), by value - forbids modification
 */
Matrix Dense::get_bias () const
{
  return _bias;
}

/**
 * Getter for _activation
 * @return _activation (ActivationType), by value - forbids modification
 */
ActivationType Dense::get_activation () const
{
  return _activation;
}

/**
 * Applies the layer in input and returns output matrix
 * @return output matrix after applying layer on input, by references
 */
Matrix Dense::operator() (Matrix &x) const
{
  Activation a (_activation);
  return a ((_weights * x) + _bias);
}
