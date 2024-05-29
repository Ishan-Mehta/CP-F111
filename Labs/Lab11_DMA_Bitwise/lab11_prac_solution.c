#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal to binary
int* decimalToBinary(int n, int* size) {
    int* binary = NULL;
    int index = 0;
    *size = 0;
    
    // Handle special case when n is 0
    if (n == 0) {
        (*size)++;
        binary = (int*)malloc(sizeof(int));
        binary[index++] = 0;
        return binary;
    }

    // Find the number of bits needed
    int temp = n;
    while (temp > 0) {
        temp >>= 1;
        (*size)++;
    }

    // Allocate memory for binary representation
    binary = (int*)malloc(*size * sizeof(int));
    // Convert decimal to binary
    while (n > 0) {
        binary[index++] = n & 1;
        n >>= 1;
    }

    // Reverse the binary array
    for (int i = 0; i < *size / 2; i++) {
        int temp = binary[i];
        binary[i] = binary[*size - i - 1];
        binary[*size - i - 1] = temp;
    }
    return binary;
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
