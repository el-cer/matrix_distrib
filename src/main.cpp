#include "matrix.h"
#include <iostream>
#include <iomanip>   // pour formater la sortie

int main() {
    Matrix A(10000, 300);
    A.fillRandom(-1.0, 1.0);

    // Calcul des stats
    Matrix::MatrixStats stats = A.describe(); // ou juste A.describe(A.data) si public

    // Affichage formaté
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Statistiques de la matrice :\n";
    std::cout << " - Moyenne  : " << stats.moyenne  << "\n";
    std::cout << " - Variance : " << stats.variance << "\n";
    std::cout << " - Min      : " << stats.min      << "\n";
    std::cout << " - Max      : " << stats.max      << "\n";
}