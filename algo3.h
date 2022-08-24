#include <bits/stdc++.h>

template <typename T>
using matrix = std::vector<std::vector<T>>;

template <typename T>
std::istream& operator>>(std::istream& is, matrix<T>& m) {
    for (int i = 0; i < m.size(); ++i) {
        for (int j = 0; j < m.size(); ++j) {
            m[i].resize(m.size());
            std::cin >> m[i][j];
        }
    }
    return is;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
    auto it = v.cbegin();
    while (it != --v.cend()) {
        std::cout << *it;
        std::cout << ", ";
        it++;
    }
    std::cout << *it;
    return os;
}