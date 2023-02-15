#include <stdio.h>
#include <stdlib.h>


void printBinary(unsigned int x) {
    for (int i = 3; i >= 0; i--) {
        if (x & (1 << i)){
        printf("1");
        } 
        else {
        printf("0");
        }
    }
    printf("\n");
  }


int magnitudeOrCompliment() {
    int sign = -6;
    unsigned char *bytes = (unsigned char *) &sign;

    // check for magnitude representation
    if ((bytes[0] & 0x80) == 0x80 && (bytes[1] == 0 && bytes[2] == 0 && bytes[3] == 0)) {
        printf("Magnitude representation\n");
        return 0;  // sign bit is set and all other bytes are 0
    }
    
    // check for two's complement representation
    if ((bytes[0] & 0x80) == 0x80 && bytes[1] == 0xFF && bytes[2] == 0xFF && bytes[3] == 0xFF) {
        printBinary(sign);
        printBinary(bytes[0]);
        printf("Two's compliment representation\n");
        return 1;  // sign bit is set and all other bytes are 1
    }
    return -1;
}


int main() {

// Task 1_1
int arr = 8; //byte size
char* ptr = (char*)malloc(arr*sizeof(char)); //allocate memory 

if(ptr == NULL) { //check if memory allocated successfully or not
    printf("Error");
}
printf("Succesfully allocated \n");

printf("test %d",(1 << 7));

// Task 1_2
int val = 0x04030201;
printf("%lu\n", sizeof(val));

int* p = (int*)ptr; 
*p = val; //pointing to value


if (ptr[0] == 0x01 && ptr[1] == 0x02 && ptr[2] == 0x03 && ptr[3] == 0x04) {
        printf("Integer stored in little endian order\n");
    } 
else if (ptr[3] == 0x01 && ptr[2] == 0x02 && ptr[1] == 0x03 && ptr[0] == 0x04) {
        printf("Integer stored in big endian order\n");
    } 
else {
        printf("Error: Unable to determine endianness\n");
    }


free (ptr);
magnitudeOrCompliment();
}



