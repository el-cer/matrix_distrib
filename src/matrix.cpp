#include "matrix.h"
#include <iostream>
#include <random>
#include <algorithm> 
#include <numeric>


Matrix::Matrix(int r, int c)
    : rows(r),
      cols(c),
      data(rows, std::vector<double>(cols, 0.0))
{
    // Tu peux afficher pour vérifier
    std::cout << "Matrice " << rows << "x" << cols << " initialisee à 0.0" << std::endl;
}

void Matrix::fillRandom(double min, double max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(min, max);

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            data[i][j] = dist(gen);
}

// Affichage
void Matrix::print() const {
    for (const auto& row : data) { //pas de copie de lignes
        for (auto v : row)
            std::cout << v << " ";
        std::cout << std::endl;
    }
}

const std::vector<std::vector<double>>& Matrix::getData() const {
    return data;
}

Matrix::MatrixStats Matrix::describe() const {
        const auto& X = getData();
        Matrix::MatrixStats result;

        int n = data.size(); 
        int m = data[0].size();

        std::vector<double> vMax(n);
        std::vector<double> vMin(n);
        
        double total = 0.0;
        double variance = 0.0;

        for(int i=0; i < n; i++){
            double max = *std::max_element(data[i].begin(), data[i].end());
            vMax[i] = max;

            double min = *std::min_element(data[i].begin(), data[i].end());
            vMin[i] = min;
            
            total += std::accumulate(data[i].begin(), data[i].end(), 0.0);
            

        }

        
        double globalMax = *std::max_element(vMax.begin(), vMax.end());
        double globalMin = *std::min_element(vMin.begin(), vMin.end()); 
        
        int length = n * m;
        double moyenne = total / static_cast<double>(length);

        for(int i=0; i < n; i++){
                for(int j=0; j < m; j++){
                    variance += (data[i][j] - moyenne) * (data[i][j] - moyenne);
                }
            }
        variance /= static_cast<double>(length);

        result.moyenne = moyenne;
        result.variance = variance;
        result.min = globalMin;
        result.max = globalMax;
        
        return result;
}