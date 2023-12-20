# Handwritten Digit Recognition

This project implements a handwritten digit recognition system using a Multi-Layer Perceptron (MLP) neural network.\
The system is designed to identify digits in images of size 28x28 pixels.\
The neural network consists of four dense layers with Rectified Linear Unit (ReLU) activation functions in the first three layers and a Softmax activation function in the output layer.

![mlpExample](https://github.com/OriDriham/HandwrittenDigitRecognition/assets/145263130/667baae4-25a1-4422-af9c-45ab3d2cd523)


# File Descriptions

### Activation.cpp & Activation.h:
Implements an Activation class with support for ReLU and Softmax activation functions.

### Dense.cpp & Dense.h:
Implements a Dense class representing a dense layer in the neural network.\
It includes a weight matrix, bias vector, and activation type (ReLU or Softmax).

### Digit.h:
Defines a digit structure representing an identified digit with an associated probability.

### main.cpp:
Contains the main program that serves as a command-line interface (CLI) for the MLP network.\
It loads MLP parameters from provided weight and bias files, allows users to input images, and displays network predictions.

### Makefile:
Defines rules for compiling the program using g++.\
It includes dependencies on the Matrix.h, Activation.h, Dense.h, MlpNetwork.h, and Digit.h files.

### Matrix.cpp & Matrix.h:
Implements a Matrix class representing a mathematical matrix.\
It includes various matrix operations such as addition, multiplication, transpose, and vectorization.

### MlpNetwork.cpp & MlpNetwork.h:
Implements an MlpNetwork class representing the entire MLP neural network.\
It applies the network on input images and returns the identified digit with an associated probability.


# Usage

To compile the program, use the provided Makefile:

```sh
make
```

The compiled executable is named mlpnetwork. Run the program with the following command:

```sh
./mlpnetwork w1 w2 w3 w4 b1 b2 b3 b4
```

`wi` - Path to the weight file for the i-th layer.\
`bi` - Path to the bias file for the i-th layer.

Example (using weightsAndBiases directory):
```sh
./mlpnetwork weightsAndBiases\w1 weightsAndBiases\w2 weightsAndBiases\w3 weightsAndBiases\w4 weightsAndBiases\b1 weightsAndBiases\b2 weightsAndBiases\b3 weightsAndBiases\b4
```

The program will prompt you to enter the path to an image.\
Example (using exampleImages directory):
```sh
exampleImages\im0
```

It reads the image, processes it through the MLP network, and displays the image along with the predicted digit and its probability.\
Repeat the process until you enter "q" to quit (Note: it's case sensitive).


# Notes

The Makefile assumes that all source files and headers are in the same directory.\
Update the paths accordingly if the file structure changes.

The program expects the weight and bias files to be in a specific order corresponding to the layers in the neural network.
