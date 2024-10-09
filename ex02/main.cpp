#include <iostream>
#include <math.h>
#include <stdio.h>
#include <vector>
#include <assert.h>

typedef std::vector<float> V;
typedef std::vector<V *> M;

float lerp(float u, float v, float t) { return fma(t, v - u, u); }

V *lerp(V u, V v, float t) {
  V *res = new V();
  for (unsigned long i = 0; i < v.size(); i++) {
    res->push_back(lerp(u[i], v[i], t));
  }
  return res;
}

M *lerp(M u, M v, float t) {
  M *res = new M();
  for (unsigned long i = 0; i < u.size() && i < v.size(); i++) {
    res->push_back(lerp(*(u[i]), *(v[i]), t));
  }
  return res;
}

template <typename T> void print_vector(std::vector<T> v) {
  for (unsigned long i = 0; i < v.size(); i++) {
    std::cout << v[i] << " - ";
  }
  std::cout << std::endl;
}

void test_lerp_float() {
  assert(lerp(0.0f, 1.0f, 0.0f) == 0.0f);
  assert(lerp(0.0f, 1.0f, 1.0f) == 1.0f);
  assert(lerp(2.0f, 4.0f, 0.5f) == 3.0f);
  assert(lerp(10.0f, 20.0f, 0.25f) == 12.5f);
  std::cout << "lerp(float, float, float) tests passed." << std::endl;
}

void test_lerp_vector() {

  V u = {1.0f, 2.0f};
  V v = {3.0f, 4.0f};

  V *res = lerp(u, v, 0.5f);
  assert((*res)[0] == 2.0f);
  assert((*res)[1] == 3.0f);
  delete res;

  res = lerp(u, v, 0.0f);
  assert((*res)[0] == 1.0f);
  assert((*res)[1] == 2.0f);
  delete res;

  res = lerp(u, v, 1.0f);
  assert((*res)[0] == 3.0f);
  assert((*res)[1] == 4.0f);
  delete res;

  std::cout << "lerp(V, V, float) tests passed." << std::endl;
}

void test_lerp_matrix() {

  V u1 = {1.0f, 2.0f}, u2 = {3.0f, 4.0f};
  V v1 = {5.0f, 6.0f}, v2 = {7.0f, 8.0f};

  M u = {&u1, &u2};
  M v = {&v1, &v2};

  M *res = lerp(u, v, 0.5f);
  assert((*(*res)[0])[0] == 3.0f);
  assert((*(*res)[0])[1] == 4.0f);
  assert((*(*res)[1])[0] == 5.0f);
  assert((*(*res)[1])[1] == 6.0f);
  delete res;

  std::cout << "lerp(M, M, float) tests passed." << std::endl;
}

int main() {
  test_lerp_float();
  test_lerp_vector();
  test_lerp_matrix();

  return 0;
}
