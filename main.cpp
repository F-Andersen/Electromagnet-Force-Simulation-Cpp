#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <iomanip>

#define _USE_MATH_DEFINES

const double MU_0 = 4 * M_PI * 1e-7; // Magnetic constant (H/m)

struct Electromagnet {
    int N;          // Number of turns
    double S;       // Cross-sectional area (m^2)
    double delta0;  // Initial air gap (m)
    double A;       // Amplitude of air gap variation (m)
    double omega;   // Angular frequency (rad/s)
    double I0;      // Maximum current (A)
};

double current(double I0, double omega, double t) {
    return I0 * cos(omega * t);
}

double airGap(double delta0, double A, double omega, double t) {
    return delta0 + A * sin(omega * t);
}

double tractionForce(const Electromagnet& em, double t) {
    double I = current(em.I0, em.omega, t);
    double delta = airGap(em.delta0, em.A, em.omega, t);
    if (delta <= 0.000001) delta = 0.000001; // Avoid division by zero
    return (MU_0 * em.N * em.N * I * I * em.S) / (2 * delta * delta);
}

int main() {
    std::ifstream inFile("input.txt");
    std::ofstream outFile("output.csv");

    if (!inFile.is_open()) {
        std::cerr << "Error: failed to open input.txt\n";
        return 1;
    }

    if (!outFile.is_open()) {
        std::cerr << "Error: failed to create output.csv\n";
        return 1;
    }

    int T, dt;
    if (!(inFile >> T >> dt)) {
        std::cerr << "Error: failed to read T and dt from input.txt\n";
        return 1;
    }

    std::vector<Electromagnet> electromagnets(3);
    for (int i = 0; i < 3; ++i) {
        if (!(inFile >> electromagnets[i].N >> electromagnets[i].S >> electromagnets[i].delta0
                    >> electromagnets[i].A >> electromagnets[i].omega >> electromagnets[i].I0)) {
            std::cerr << "Error: failed to read parameters for electromagnet #" << (i + 1) << "\n";
            return 1;
        }
    }

    outFile << "Time(s),F1(N),F2(N),F3(N)\n";
    for (int t = 0; t <= T; t += dt) {
        outFile << t;
        std::cout << "Time: " << t << " s\t";
        for (int i = 0; i < 3; ++i) {
            double F = tractionForce(electromagnets[i], t);
            outFile << "," << std::fixed << std::setprecision(6) << F;
            std::cout << "F" << (i + 1) << " = " << std::fixed << std::setprecision(2) << F << "\t";
        }
        outFile << "\n";
        std::cout << std::endl;
    }

    std::cout << "Calculation complete. Results saved to output.csv\n";
    return 0;
}
