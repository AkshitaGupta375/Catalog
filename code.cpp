#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

// Function to decode Y values
int decodeY(const std::string& value, int base) {
    int y = 0;
    int power = 0;
    for (int i = value.length() - 1; i >= 0; --i) {
        y += (value[i] - '0') * pow(base, power);
        power++;
    }
    return y;
}

// Function to find the coefficients using Lagrange interpolation
double lagrangeInterpolation(const std::map<int, int>& roots, int x) {
    double result = 0;
    for (const auto& root : roots) {
        double numerator = 1;
        double denominator = 1;
        for (const auto& otherRoot : roots) {
            if (root.first != otherRoot.first) {
                numerator *= (x - otherRoot.first);
                denominator *= (root.first - otherRoot.first);
            }
        }
        result += root.second * numerator / denominator;
    }
    return result;
}

int main() {
    // Input JSON data
    json data = R"({
        "keys": { "n": 4, "k": 3 },
        "1": { "base": "10", "value": "4" },
        "2": { "base": "2", "value": "111" },
        "3": { "base": "10", "value": "12" },
        "6": { "base": "4", "value": "213" }
    })"_json;

    // Extract values
    int n = data["keys"]["n"];
    int k = data["keys"]["k"];

    // Process roots
    std::map<int, int> roots;
    for (const auto& root : data.items()) {
        if (root.key() != "keys") {
            int x = std::stoi(root.key());
            int base = root.value()["base"];
            int value = decodeY(root.value()["value"].get<std::string>(), base);
            roots[x] = value;
        }
    }

    // Find constant term (c)
    double c = lagrangeInterpolation(roots, 0);
    std::cout << "Constant term (c): " << c << std::endl;

    return 0;
}