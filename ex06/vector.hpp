#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <math.h>

class Vector {
public:    
    std::vector<float> values;

    Vector();
    Vector(const std::vector<float>& vals);
    
    Vector add(const Vector& v2);
    
    Vector sub(const Vector& v2);
    
    Vector scl(float scaler);

    float dot(const Vector& v2);

    float norm_1(void) const;
    float norm(void) const;
    float norm_inf(void) const;
    
    float operator[](unsigned int index);
    const float operator[](unsigned int index) const;
    friend std::ostream& operator<<(std::ostream& os, const Vector& v);


private:
    std::string toString() const;
    double abs(double n) const;
    double calcSqrt(double n) const;
};

Vector *cross_product(Vector &u, Vector &v);

#endif 
 