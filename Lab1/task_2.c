#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Task 2_1
struct float_bytes {
    char buffer[sizeof(float)];
};

// Task 2_3
void set_float(struct float_bytes *f, float value) {
    // Enforce limits, setting value to the closest value within the range 
    if (value < -7.875f) {
        value = -7.875f;
    } else if (value > 7.875f) {
        value = 7.875f;
    }
    
    // Extract sign, mantissa, and exponent from value
    int sign = (value < 0.0f) ? 1 : 0; // 1 if negative, 0 if positive
    value = fabsf(value); // absolute value
    int whole = (int) value; // integer part
    float fractional = value - whole; 
    int exponent = 0; 
    while (whole >= 2 && exponent < 7) { 
        whole /= 2;
        exponent++;
    }
    int mantissa = (int) (whole - 1); 
    for (int i = 0; i < 4; i++) {
        mantissa *= 2;
        if (fractional >= 0.5f) {
            mantissa++;
        }
        fractional *= 2;
            printf("mantissa: %d\n", mantissa);
        if (mantissa > 15) {
        printf("whole: %d, exponent: %d\n", whole, exponent);
            mantissa /= 2;
            exponent++;
            if (exponent > 7) {
                exponent = 7;
                mantissa = 15;
                break;
            }
        }
    }
    
    // Write sign, mantissa, and exponent to buffer
    f->buffer[0] = (sign << 7) | (exponent << 4) | mantissa;
}

// Task 2_4
void print_float(struct float_bytes *f) {
    for (int i = sizeof(float) - 1; i >= 0; i--) {
        for (int j = 7; j >= 0; j--) {
            printf("%d", (f->buffer[i] >> j) & 1);
        }
    }
    printf("\n");
}

int main() {
    struct float_bytes f;
    
    set_float(&f, 123.456f);
    printf("123.456: ");
    print_float(&f);
    
    set_float(&f, -1.5f);
    printf("-1.5:    ");
    print_float(&f);
    
    set_float(&f, 0.125f);
    printf("0.125:   ");
    print_float(&f);
    
    set_float(&f, 1000000.0f);
    printf("1000000: ");
    print_float(&f);
    
    return 0;
}


