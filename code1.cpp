#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int decodeY(const std::string& value, int base) {
    int y = 0;
    int power = 0;
    for (int i = value.length() - 1; i >= 0; --i) {
        int digit = (base == 16) ? (value[i] >= 'A' ? value[i] - 'A' + 10 : value[i] - '0') : (value[i] - '0');
        y += digit * pow(base, power);
        power++;
    }
    return y;
}

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
    json data = R"({
        "keys": { "n": 9, "k": 6 },
        "1": { "base": "10", "value": "28735619723837" },
        "2": { "base": "16", "value": "1A228867F0CA" },
        "3": { "base": "12", "value": "32811A4AA0B7B" },
        "4": { "base": "11", "value": "917978721331A" },
        "5": { "base": "16", "value": "1A22886782E1" },
        "6": { "base": "10", "value": "28735619654702" },
        "7": { "base": "14", "value": "71AB5070CC4B" },
        "8": { "base": "9", "value": "122662581541670" },
        "9": { "base": "8", "value": "642121030037605" }
    })"_json;

    int n = data["keys"]["n"];
    int k = data["keys"]["k"];

    std::map<int, int> roots;
    for (const auto& root : data.items()) {
        if (root.key() != "keys") {
            int x = std::stoi(root.key());
            int base = std::stoi(root.value()["base"]);
            int value = decodeY(root.value()["value"].get<std::string>(), base);
            roots[x] = value;
        }
    }

    double c = lagrangeInterpolation(roots, 0);
    std::cout << "Constant term (c): " << c << std::endl;

    return 0;
}
