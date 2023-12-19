#include "Activation.h"

/**
 * Constructor for Activation with two valid values: RELU and SOFTMAX
 * @param act_type - enum ActivationType: RELU or SOFTMAX
 */
Activation::Activation (ActivationType act_type) : _act_type (act_type)
{
  if (act_type != RELU && act_type != SOFTMAX)
    {
      std::cerr << "Error: act_type in not RELU or SOFTMAX";
      exit (EXIT_FAILURE);
    }
}

/**
 * Getter for _act_type
 * @return _act_type (enum ActivationType)
 */
ActivationType Activation::get_activation_type () const
{
  return _act_type;
}

/**
 * Applies activation function on input
 * @param input Matrix&, the input to apply the function on
 * @return the output after applying the function on the Matrix, by reference
 */
Matrix Activation::operator() (const Matrix &input) const
{
    Matrix output (input);  // cpy ctr
  if (_act_type == RELU)
    {
      for (int i = 0; i < input.get_rows (); i++)
        {
          for (int j = 0; j < input.get_cols (); j++)
            {
              if (input (i, j) < 0)  // if >= 0 : stays the same
                  output (i, j) = 0;
              else
                  output (i, j) = input (i, j);
            }
        }
    }
  else  // _act_type == SOFTMAX
    {
      float sum = 0;
      for (int i = 0; i < input.get_rows ()*input.get_cols(); i++)
        {
          float et = std::exp (input [i]);
          // et = e^t, t = Xk coordinate
            output [i] = et;  // fill v with et: e1,...,en (1<=t<=n)
          sum += et;
        }
        output = (1/sum) * output;  // changes input
    }
  return output;  // output by value
}
