#include <stdio.h>
#include <stdlib.h>

int main() {
    int size = 8;  // size of the byte array
    char *bytes = malloc(size); 
    
    if (bytes == NULL) {  // check if successful
        printf("Allocation failed.\n exitting...\n");
        return 1;
    }
    
    free(bytes);  // free the memory after allocation
    return 0;
}
