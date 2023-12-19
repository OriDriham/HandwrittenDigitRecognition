#ifndef ACTIVATION_H
#define ACTIVATION_H

#include "iostream"
#include "Matrix.h"
#include "cmath"

/**
 * @enum ActivationType
 * @brief Indicator of activation function.
 */
enum ActivationType {
    RELU,
    SOFTMAX
};


class Activation {
 private:
  ActivationType _act_type;

 public:
  /**
 * Constructor for Activation with two valid values: RELU and SOFTMAX
 * @param act_type - enum ActivationType: RELU or SOFTMAX
 */
  explicit Activation (ActivationType);

  /**
 * Getter for _act_type
 * @return _act_type (enum ActivationType)
 */
  ActivationType get_activation_type() const;

  /**
 * Applies activation function on input
 * @param input Matrix&, the input to apply the function on
 * @return the output after applying the function on the Matrix, by reference
 */
  Matrix operator() (const Matrix &) const;
};

#endif
