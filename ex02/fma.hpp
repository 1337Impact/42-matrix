#include <iostream>
#include <math.h>
#include <vector>
#include <assert.h>

typedef std::vector<float> V;
typedef std::vector<V *> M;

float lerp(float u, float v, float t);

V *lerp(V u, V v, float t);

M *lerp(M u, M v, float t);
