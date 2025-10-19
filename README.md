# cML  
A minimal machine learning library written in C.

## Overview  
**cML** is a collection of simple machine learning algorithms implemented purely in C, designed for educational and experimental use.  
It focuses on clear, lightweight implementations to help understand how algorithms work at a low level, without depending on external libraries.

## Features  
- Basic CSV file reading utility  
- Perceptron (binary linear classifier)  
- Linear regression (ordinary least squares)  
- Example usage and test data  

## Project Structure  
`cML/
├── main.c # Entry point and demo runner
├── read_csv.c # CSV reader
├── perceptron.c # Perceptron implementation
├── linear_regression.c # Linear regression implementation
├── ml_demo/ # Sample data and example runs
└── README.md`


## Build and Run  
1. Clone the repository:
   ```
   git clone https://github.com/IamKrisshK/cML.git
   cd cML
2. Compile:
   `gcc -o ml_demo main.c read_csv.c perceptron.c linear_regression.c -lm`
3. Run:
   `./ml_demo`
