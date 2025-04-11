#include "calculator.h"
#include <stdexcept>
#include <limits>

int Calculator::add(int a, int b) {
    // TODO
    int max_int = std::numeric_limits<int>::max();
    int min_int = std::numeric_limits<int>::min();
    
    if (b > 0 && a > max_int - b) {
        throw std::overflow_error("Addition overflow");
    }
    if (b < 0 && a < min_int - b) {
        throw std::overflow_error("Addition underflow");
    }
    return a + b;
}

int Calculator::sub(int a, int b) {
    int max_int = std::numeric_limits<int>::max();
    int min_int = std::numeric_limits<int>::min();

    if (b < 0 && a > max_int + b) {
        throw std::overflow_error("Subtraction overflow");
    }
    if (b > 0 && a < min_int + b) {
        throw std::overflow_error("Subtraction underflow");
    }
    return a - b;
}

int Calculator::mul(int a, int b) {
    int max_int = std::numeric_limits<int>::max();
    int min_int = std::numeric_limits<int>::min();

    if(a == 0 || b==0){
        return 0;
    }

    if (a > 0 && b > 0 && a > max_int / b){
        throw std::overflow_error("Multiplication overflow");
    } else if (a > 0 && b < 0) {
        if (b < min_int / a) throw std::overflow_error("Multiplication underflow");
    } else if (b > 0 && a < 0) {
        if (a < min_int / b) throw std::overflow_error("Multiplication underflow");
    }

    return a * b;
}

int Calculator::div(int a, int b) {
    if (b == 0) {
        throw std::invalid_argument("Division by zero");
    }

    // Special case: INT_MIN / -1 causes overflow
    if (a == std::numeric_limits<int>::min() && b == -1) {
        throw std::overflow_error("Division overflow");
    }
    return a / b;
}