#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <math.h>

class Vector {
public:    
    Vector(const std::vector<float>& vals);
    
    Vector add(const Vector& v2);
    
    Vector sub(const Vector& v2);
    
    Vector scl(float scaler);

    float dot(const Vector& v2);
    
    friend std::ostream& operator<<(std::ostream& os, const Vector& v);

    std::vector<float> values;

private:
    std::string toString() const;
};

#endif 
 