#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal to binary
int* decimalToBinary(int n, int* size) {    
    //Declare the varibles to store the size of the answer, the starting index of the answer and the binary answer
    //TODO:

    
    // Handle special case when n is 0
    //TODO: 


    // Find the number of bits needed
    //TODO: 



    // Allocate memory for binary representation
    //TODO: 


    // Convert decimal to binary
    //TODO:



    // Reverse the binary array
    //TODO:


}

// DO NOT MAKE ANY CHANGES TO THE MAIN func!
int main() {
    int decimal;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);
    int size;
    int* binary = decimalToBinary(decimal, &size);
    printf("Binary representation: ");
    for (int i = 0; i < size; i++) {
        printf("%d", binary[i]);
    }
    printf("\n");
    // Free dynamically allocated memory
    free(binary);
    return 0;
}
