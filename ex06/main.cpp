#include "vector.hpp"

int main() {
    Vector v1({1., 0., 1.});
    Vector u1({1., 0., 0.});

    const Vector *cos = cross_product(v1, u1);
    std::cout << "cross_product: " << *cos << std::endl;


    Vector v2({1., 2., 3.});
    Vector u2({4., 5., 6.});

    const Vector *cos2 = cross_product(v2, u2);
    std::cout << "cross_product: " << *cos2 << std::endl;

    Vector v3({4., 2., -3.});
    Vector u3({-2., -5., 16.});

    const Vector *cos3 = cross_product(v3, u3);
    std::cout << "cross_product: " << *cos3 << std::endl;

    return 0;
}