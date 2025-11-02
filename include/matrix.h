#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <string>


class Matrix {
public:
    // Constructeur
    Matrix(int rows, int cols);

    struct MatrixStats {
    double moyenne;
    double variance;
    double min;
    double max;
    };
    // Méthodes
    void fillRandom(double min, double max);
    void print() const;
    const std::vector<std::vector<double>>& getData() const;


    MatrixStats describe() const;

    

private:
    int rows;
    int cols;
    std::vector<std::vector<double>> data;
};

#endif
