#ifndef MATRIX_H
#define MATRIX_H

#include "istream"

using std::istream;

/**
 * @struct matrix_dims
 * @brief Matrix dimensions container. Used in MlpNetwork.h and main.cpp
 */
typedef struct matrix_dims {
    int rows, cols;
} matrix_dims;


class Matrix {
 private:
  int _rows;
  int _cols;
  int _size = _rows * _cols;
  float *_matrix = nullptr;

 public:
  /**
 * Constructor to Matrix with 2 int arguments
 * @param rows - number of rows in the matrix
 * @param cols - number of columns in the matrix
 */
  Matrix (int rows, int cols);

  /**
 * Default constructor to Matrix with rows=1 and cols=1
 */
  Matrix ();

  /**
 * Copy constructor to Matrix
 * @param m - matrix to copy from
 */
  Matrix (const Matrix &);

  /**
 * Destructor to Matrix. Delete the memory allocated for _matrix
 */
  ~Matrix ();

  /**
 * Getter for _rows
 * @return the _rows value of the matrix
 */
  int get_rows () const;

  /**
 * Getter for _cols
 * @return the _cols value of the matrix
 */
  int get_cols () const;

  /**
 * Transpose the rows and cols of the matrix
 * @return *this - a pointer the 'this' matrix, allow chaining
 */
  Matrix &transpose ();

/**
 * Transform a matrix into a column vector
 */
  Matrix &vectorize ();

  /**
 * Plain print the matrix with " " after each element and a new line after
 * each row
 */
  void plain_print () const;

  /**
 * Return a new matrix (by value) which it's elements are the sum (entry-entry)
 * of the current matrix's elements and the given matrix's elements.
 * @param m - the given matrix the sum with
 * @return a new matrix with the sum values
 */
  Matrix dot (const Matrix &) const;

/**
 * Return the Frobenius norm of the matrix
 * @return Frobenius norm (double) of the matrix
 */
  float norm () const;

  /**
   * Fills matrix elements as per section 2.3. in the exercise.
   * Read input stream fully, otherwise - error.
   * @return istream - is.
   */
  friend istream &read_binary_file (istream &, Matrix &);

  /**
   * Matrix addition
   * @return a new matrix after the addition
   */
  Matrix operator+ (const Matrix &) const;

  /**
 * Matrix assignment
 * @param rhs - Matrix to assign from
 * @return *this - The matrix (lhs) after the assignment
 */
  Matrix &operator= (const Matrix &);

  /**
 * Matrix multiplication
 * @param rhs - Matrix to multiply on the right
 * @return a matrix (by value) after the multiplication
 */
  Matrix operator* (const Matrix &) const;

  /**
 * Scalar multiplication ton the right
 * @param c - scalar (float type) to multiply at
 * @return a matrix after the multiplication
 */
  Matrix operator* (const float &) const;

  /**
 * Scalar multiplication ton the left
 * @param c - scalar (float type) to multiply at
 * @return a matrix after the multiplication
 */
  friend Matrix operator* (const float &, const Matrix &);

  /**
 * Matrix addition accumulation
 * @return *this - The matrix (lhs) after the addition accumulation
 */
  Matrix &operator+= (const Matrix &);

  /**
 * return the element of the matrix at (i,j)
 * @param i - index i (row) in the matrix (starting from  1)
 * @param j - index j (col) in the matrix (starting from  1)
 * @return float& - the element of the matrix at (i,j) index
 */
  float &operator() (const int &, const int &);

  /**
 * return the value of the matrix at (i,j)
 * @param i - index i (row) in the matrix (starting from  1)
 * @param j - index j (col) in the matrix (starting from  1)
 * @return float - the value of the matrix at (i,j) index
 */
  float operator() (const int &, const int &) const;

  /**
* return the element of the matrix at the i'th index
* @param i - index i (in the general _size) in the matrix (starting from  1)
* @return float& - the element of the matrix at the i'th index
 */
  float &operator[] (const int &);

  /**
* return the value of the matrix at the i'th index
* @param i - index i (in the general _size) in the matrix (starting from  1)
* @return float - the value of the matrix at the i'th index
 */
  float operator[] (const int &) const;

  /**
 * Output stream for a Matrix - pretty export
 * @param os - ostream
 * @param m - Matrix to print
 * @return ostream - os.
 */
  friend std::ostream &operator<< (std::ostream &, const Matrix &);
};

#endif
