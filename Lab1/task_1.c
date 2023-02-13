//#include <stdio.h>
//#include <stdlib.h>


void printBinary(unsigned int x) {
    for (int i = 7; i >= 0; i--) {
        if (x & (1 << i)) printf("1");
        else printf("0");
    }

    unsigned char* bytearr = (unsigned char*)(&x);
    
            
  }


int magnitudeOrCompliment() {
    int sign = -4;
    
    printBinary(sign);

    return 1;

}


int main() {
/*int arr = 8; //byte size
char* ptr = (char*)malloc(arr*sizeof(char)); //allocate memory 

if(ptr == NULL) { //check if memory allocated successfully or not
    printf("Error");
}
printf("Succesfully allocated \n");

int val = 0x04030201;

printf("%d\n", sizeof(val));

int* p = (int*)ptr; 
*p = val; //pointing to value


if (ptr[0] == 0x01 && ptr[1] == 0x02 && ptr[2] == 0x03 && ptr[3] == 0x04) {
        printf("Integer stored in little endian order\n");
    } else if (ptr[3] == 0x01 && ptr[2] == 0x02 && ptr[1] == 0x03 && ptr[0] == 0x04) {
        printf("Integer stored in big endian order\n");
    } else {
        printf("Error: Unable to determine endianness\n");
    }


free (ptr);
*/
magnitudeOrCompliment();

}



