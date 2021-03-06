#include <iostream>
#include <iomanip>
#include <cmath>
#include <functional>
using namespace std;
using uint = unsigned int;


template <typename domain>
domain ContinuousBinarySearch(
   const function<domain(domain)> &f, uint iterations, domain left, domain right, domain toFind) { 
    
    domain middle;

    while (iterations--) {
        middle = left + (right - left) / 2;

        if (f(middle) > toFind) left = middle;
        else right = middle;
    }

    return (left + right) / 2;
}


pair<bool, double> findSolution(double p, double q, double r, double s, double t, double u) {

    auto evaluate = [&](double x) -> double {
        return (p * exp(-1 * x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x*x + u);
    };

    if (evaluate(0) * evaluate(1) > 0) return {false, 0.0f};

    double left = ContinuousBinarySearch<double>(evaluate, 100, 0.0, 1.0, 0.0);

    return {true, left};
};


int main () {

    double p, q, r, s, t, u;

    while (cin >> p >> q >> r >> s >> t >> u) {

        auto solution = findSolution(p, q, r, s, t, u);
        if (solution.first) cout << setprecision(4) << fixed << solution.second << endl;
        else cout << "No solution" << endl;
    }

    return 0;
}
