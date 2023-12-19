#include "Matrix.h"
#include "iostream"
#include "istream"
#include <cmath>

#define SQUARE 2
#define PRINT_VALUE 0.1

using std::cout;
using std::endl;
using std::cerr;
using std::string;

/**
 * Constructor to Matrix with 2 int arguments
 * @param rows - number of rows in the matrix
 * @param cols - number of columns in the matrix
 */
Matrix::Matrix (const int rows, const int cols) : _rows (rows), _cols (cols)
{
  _matrix = new (std::nothrow) float[_size];
  string check_r = typeid (rows).name ();
  string check_c = typeid (cols).name ();
  string int_type = typeid (int).name ();
  if (!_matrix || check_r != int_type || check_c != int_type)
    {
      cerr << "Error: bad alloc in the constructor" << endl;
      exit (EXIT_FAILURE);
    }
  for (int i = 0; i < _rows; i++)
    {
      for (int j = 0; j < _cols; j++)
        {
          _matrix[i * _cols + j] = 0;
        }
    }
}

/**
 * Default constructor to Matrix with rows=1 and cols=1
 */
Matrix::Matrix () : Matrix (1, 1)
{}

/**
 * Copy constructor to Matrix
 * @param m - matrix to copy from
 */
Matrix::Matrix (const class Matrix &m) : _rows (m._rows), _cols (m._cols)
{
  _matrix = new (std::nothrow) float[_size];
  if (!_matrix)
    {
      cerr << "Error: bad alloc in the constructor" << endl;
      exit (EXIT_FAILURE);
    }
  for (int i = 0; i < _rows; i++)
    {
      for (int j = 0; j < _cols; j++)
        {
          _matrix[i * _cols + j] = m._matrix[i * _cols + j];
        }
    }
}

/**
 * Destructor to Matrix. Delete the memory allocated for _matrix
 */
Matrix::~Matrix ()
{
  delete[] _matrix;
  _matrix = nullptr;
}

/**
 * Getter for _rows
 * @return the _rows value of the matrix
 */
int Matrix::get_rows () const
{ return _rows; }

/**
 * Getter for _cols
 * @return the _cols value of the matrix
 */
int Matrix::get_cols () const
{ return _cols; }

/**
 * Matrix addition
 * @return a new matrix after the addition
 */
Matrix Matrix::operator+ (const Matrix &rhs) const
{
  if (_size != rhs._size)
    {
      cerr << "Error: Can't sum matrices with different dimensions" << endl;
      exit (EXIT_FAILURE);
    }
  Matrix new_m (_rows, _cols);
  for (int i = 0; i < _size; i++)
    {
      new_m[i] = _matrix[i] + rhs._matrix[i];
    }
  return new_m;
}

/**
 * Matrix assignment
 * @param rhs - Matrix to assign from
 * @return *this - The matrix (lhs) after the assignment
 */
Matrix &Matrix::operator= (const Matrix &rhs)
{
  if (&rhs == this)
    {
      return *this;
    }
  _rows = rhs._rows;
  _cols = rhs._cols;
  _size = rhs._size;

  delete[] _matrix;
  _matrix = nullptr;
  _matrix = new float[rhs._size];
  for (int i = 0; i < _rows; i++)  // cpy
    {
      for (int j = 0; j < _cols; j++)
        {
          _matrix[i * _cols + j] = rhs._matrix[i * _cols + j];
        }
    }
  return *this;
}

/**
 * Matrix multiplication
 * @param rhs - Matrix to multiply on the right
 * @return a matrix (by value) after the multiplication
 */
Matrix Matrix::operator* (const Matrix &rhs) const
{
  if (_cols != rhs._rows)
    {
      cerr << "Error: Multiply matrices is not defined with the given "
              "dimensions" << endl;
      exit (EXIT_FAILURE);
    }
  Matrix new_m = Matrix (_rows, rhs._cols);
  for (int i = 0; i < new_m._rows; i++)
    {
      for (int j = 0; j < new_m._cols; j++)
        {
          float sum_row_col = 0;
          for (int k = 0; k < _cols; k++)  // sum of row * col
            {
              sum_row_col += _matrix[i * _cols + k] *
                             rhs._matrix[k * rhs._cols + j];
            }
          new_m._matrix[i * new_m._cols
                        + j] = sum_row_col;  // assign in new_m
        }
    }
  return new_m;
}

/**
* Scalar multiplication ton the right
* @param c - scalar (float type) to multiply at
* @return a matrix after the multiplication
*/
Matrix Matrix::operator* (const float &c) const
{
  Matrix new_m (_rows, _cols);
  for (int i = 0; i < _rows; i++)
    {
      for (int j = 0; j < _cols; j++)
        {
          new_m[i * _cols + j] = _matrix[i * _cols + j] * c;
        }
    }
  return new_m;
}

/**
* Scalar multiplication ton the left
* @param c - scalar (float type) to multiply at
* @return a matrix after the multiplication
*/
Matrix operator* (const float &c, const Matrix &m)
{
  return m * c;  // same as multiply on the right
}

/**
 * Matrix addition accumulation
 * @return *this - The matrix (lhs) after the addition accumulation
 */
Matrix &Matrix::operator+= (const Matrix &rhs)
{
  *this = *this + rhs;
  return *this;  // same as +
}

/**
 * return the element of the matrix at (i,j)
 * @param i - index i (row) in the matrix (starting from  1)
 * @param j - index j (col) in the matrix (starting from  1)
 * @return float& - the element of the matrix at (i,j) index
 */
float &Matrix::operator() (const int &i, const int &j)
{
  return _matrix[i * _cols + j];
}

/**
* return the value of the matrix at (i,j)
* @param i - index i (row) in the matrix (starting from  1)
* @param j - index j (col) in the matrix (starting from  1)
* @return float - the value of the matrix at (i,j) index
*/
float Matrix::operator() (const int &i, const int &j) const
{
  return _matrix[i * _cols + j];
}

/**
* return the element of the matrix at the i'th index
* @param i - index i (in the general _size) in the matrix (starting from  1)
* @return float& - the element of the matrix at the i'th index
 */
float &Matrix::operator[] (const int &i)
{
  if (i >= _size)
    {
      cerr << "Error: index i not in the matrix" << endl;
      exit (EXIT_FAILURE);
    }
  return _matrix[i];
}

/**
* return the value of the matrix at the i'th index
* @param i - index i (in the general _size) in the matrix (starting from  1)
* @return float - the value of the matrix at the i'th index
*/
float Matrix::operator[] (const int &i) const
{
  if (i >= _size)
    {
      cerr << "Error: index i not in the matrix" << endl;
      exit (EXIT_FAILURE);
    }
  return _matrix[i];

}

/**
* Output stream for a Matrix - pretty export
* @param os - ostream
* @param m - Matrix to print
* @return ostream - os.
*/
std::ostream &operator<< (std::ostream &os, const Matrix &m)
{
  for (int i = 0; i < m._rows; i++)
    {
      for (int j = 0; j < m._cols; j++)
        {
          if (m._matrix[i * m._cols + j] >= PRINT_VALUE)
            os << "  ";
          else
            os << "**";
        }
      os << endl;
    }
  return os;
}

/**
 * Transpose the rows and cols of the matrix
 * @return *this - a pointer the 'this' matrix, allow chaining
 */
Matrix &Matrix::transpose ()
{
  Matrix new_m (_cols, _rows);
  for (int i = 0; i < _rows; i++)
    {
      for (int j = 0; j < _cols; j++)
        {
          new_m._matrix[j * _rows + i] = _matrix[i * _cols + j];
        }
    }
  *this = new_m;
  return *this;
}

/**
 * Transform a matrix into a column vector
 */
Matrix &Matrix::vectorize ()
{
  _rows = _rows * _cols;
  _cols = 1;
  return *this;
}

/**
 * Plain print the matrix (elements) - With " " after each element and a
 * new line after each row
 */
void Matrix::plain_print () const
{
  for (int i = 0; i < _rows; i++)
    {
      for (int j = 0; j < _cols; j++)
        {
          cout << _matrix[i * _cols + j] << " ";
        }
      cout << endl;
    }
}

/**
 * Return a new matrix (by value) which it's elements are the sum (entry-entry)
 * of the current matrix's elements and the given matrix's elements.
 * @param m - the given matrix the sum with
 * @return a new matrix with the sum values
 */
Matrix Matrix::dot (const Matrix &m) const
{
  if ((_rows != m._rows) || (_cols != m._cols))  // sum is not defined
    {
      cerr << "Error: matrix sum is not defined on matrices with different "
              "size" << endl;
      exit (EXIT_FAILURE);
    }
  Matrix dot_m (_rows, _cols);
  for (int i = 0; i < _rows * _cols; i++)
    {
      dot_m._matrix[i] = _matrix[i] * m._matrix[i];
    }
  return dot_m;
}

/**
 * Return the Frobenius norm of the matrix
 * @return Frobenius norm (double) of the matrix
 */
float Matrix::norm () const
{
  float sum_square = 0;
  for (int i = 0; i < _rows; i++)
    {
      for (int j = 0; j < _cols; j++)
        {
          sum_square += (float) (pow ((_matrix[i * _cols + j]), SQUARE));
        }
    }
  return sqrtf (sum_square);
}

/**
 * Fills matrix elements as per section 2.3. in the exercise.
 * Read input stream fully, otherwise - error.
 */
istream &read_binary_file (istream &is, Matrix &m)
{
  if (!is)
    {
      cerr << "Error: can't read from file" << endl;
      exit (EXIT_FAILURE);
    }
  unsigned int n_bytes = m._rows * m._cols * sizeof (float);
  is.read ((char *) (m._matrix), n_bytes);
  if (!is.good ())
    {
      cerr << "Error: can't read from file" << endl;
      exit (EXIT_FAILURE);
    }
  return is;
}
