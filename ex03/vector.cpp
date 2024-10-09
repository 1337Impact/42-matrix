#include "vector.hpp"

Vector::Vector(const std::vector<float>& vals) : values(vals) {}

Vector Vector::add(const Vector& v2) {
    std::vector<float> result;
    for (size_t i = 0; i < values.size(); i++) {
        result.push_back(values[i] + v2.values[i]);
    }
    return Vector(result);
}

Vector Vector::sub(const Vector& v2) {
    std::vector<float> result;
    for (size_t i = 0; i < values.size(); i++) {
        result.push_back(values[i] - v2.values[i]);
    }
    return Vector(result);
}

Vector Vector::scl(float scaler) {
    std::vector<float> result;
    for (size_t i = 0; i < values.size(); i++) {
        result.push_back(values[i] * scaler);
    }
    return Vector(result);
}

float Vector::dot(const Vector& v2) {
   int i = this->values.size();
    float sum = 0.0f;
   for (int i = 0; i < this->values.size() && i < v2.values.size(); i++){
        sum = fma(this->values[i], v2.values[i], sum);
   }
   return sum;
}

std::string Vector::toString() const {
    std::ostringstream os;
    os << "[";
    for (size_t i = 0; i < values.size(); ++i) {
        os << values[i];
        if (i != values.size() - 1) os << ", ";
    }
    os << "]";
    return os.str();
}

std::ostream& operator<<(std::ostream& os, const Vector& v) {
    os << v.toString();
    return os;
}
