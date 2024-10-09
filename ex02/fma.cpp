#include "fma.hpp"

float lerp(float u, float v, float t) { return fma(t, v - u, u); }

V *lerp(V u, V v, float t) {
  V *res = new V();
  for (unsigned long i = 0; i < u.size() && i < v.size(); i++) {
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