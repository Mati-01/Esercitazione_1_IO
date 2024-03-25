#include <iostream>
#include <fstream>
#include <vector>

// Funzione per mappare un valore dall'intervallo [1, 5] all'intervallo [-1, 2]
double map_point(double value) {
    return (value - 1) * (2 - (-1)) / (5 - 1) + (-1);
}

// Funzione per calcolare la media di una lista di valori mappati
double compute_mean(const std::vector<double>& mapped_values) {
    double sum = 0.0;
    for (double val : mapped_values) {
        sum += val;
    }
    return sum / mapped_values.size();
}

int main() {
    std::ifstream infile("data.csv");
    if (!infile) {
        std::cerr << "Errore nell'apertura del file data.csv" << std::endl;
        return 1;
    }

    std::vector<double> values;
    double value;
    while (infile >> value) {
        values.push_back(value);
    }

    // Mappa i valori
    std::vector<double> mapped_values;
    for (double val : values) {
        mapped_values.push_back(map_point(val));
    }

    // Calcola la media per ogni i
    std::ofstream outfile("result.csv");
    if (!outfile) {
        std::cerr << "Errore nell'apertura del file result.csv" << std::endl;
        return 1;
    }

    outfile << "# N Mean" << std::endl;
    for (size_t i = 1; i <= mapped_values.size(); ++i) {
        double mean = compute_mean(std::vector<double>(mapped_values.begin(), mapped_values.begin() + i));
        outfile << i << " " << mean << std::endl;
    }

    std::cout << "Risultato scritto nel file result.csv" << std::endl;

    return 0;
}
