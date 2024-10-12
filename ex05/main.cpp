#include "vector.hpp"

int main() {
    Vector v1({1., 0.});
    Vector u1({1., 0.});

    const float cos = angle_cos(v1, u1);
    std::cout << "angle_cos: " << cos << std::endl;


    Vector v2({1., 0.});
    Vector u2({0., 1.});

    const float cos2 = angle_cos(v2, u2);
    std::cout << "angle_cos: " << cos2 << std::endl;

    Vector v3({-1., 1.});
    Vector u3({1., -1.});

    const float cos3 = angle_cos(v3, u3);
    std::cout << "angle_cos: " << cos3 << std::endl;

    Vector v4({2., 1.});
    Vector u4({4., 2.});

    const float cos4 = angle_cos(v4, u4);
    std::cout << "angle_cos: " << cos4 << std::endl;

    Vector v5({1., 2., 3.});
    Vector u5({4., 5., 6.});

    const float cos5 = angle_cos(v5, u5);
    std::cout << "angle_cos: " << cos5 << std::endl;
    return 0;
}