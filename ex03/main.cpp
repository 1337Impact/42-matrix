#include "vector.hpp"

int main() {
    Vector v1({-1., 6.});
    Vector v2({3., 2.});

    std::cout << "v1: " << v1 << std::endl;
    std::cout << "v2: " << v2 << std::endl;

    Vector result = v1.add(v2);
    std::cout << "v1 + v2: " << result << std::endl;

    result = v1.sub(v2);
    std::cout << "v1 - v2: " << result << std::endl;

    result = v1.scl(2.0f);
    std::cout << "v1 * 2: " << result << std::endl;

    const int dot = v1.dot(v2);
    std::cout << "v1 . v2: " << dot << std::endl;

    return 0;
}