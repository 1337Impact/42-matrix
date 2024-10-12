#include "vector.hpp"


void test_norm_1() {
    Vector v1({1., 2., 3.});
    assert(v1.norm_1() == 6.0);
    
    Vector v2({-1., -2., -3.});
    assert(v2.norm_1() == 6.0);

    std::cout << "test_norm_1 passed!" << std::endl;
}

void test_norm() {
    Vector v1({3., 4.});
    assert(std::abs(v1.norm() - 5.0) < 1e-6);
    std::cout << v1.norm() << std::endl;

    Vector v2({1., 2., 2.});
    assert(std::abs(v2.norm() - 3.0) < 1e-6);

    std::cout << "test_norm passed!" << std::endl;
}

void test_norm_inf() {
    Vector v1({-1., 5., 3.});
    assert(v1.norm_inf() == 5.0);

    Vector v2({-7., -8., 4.});
    assert(v2.norm_inf() == 8.0);

    std::cout << "test_norm_inf passed!" << std::endl;
}

int main() {
    test_norm_1();
    test_norm();
    test_norm_inf();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}