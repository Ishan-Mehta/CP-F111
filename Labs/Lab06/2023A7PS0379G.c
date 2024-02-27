#include<stdio.h>

/**
 * @brief Returns the binary form of the decimal representation of an integer
 * 
 * - One of the methods to convert decimal to binary is by dividing the given decimal number 
 *   recursively by 2.
 * - The remainders are noted down till we get 0 as the final quotient. 
 * - After this step, these remainders are written in reverse order to get the binary value 
 *   of the given decimal number.
 * 
 * Example:
 * decimalToBinary(0) returns 0
 * decimalToBinary(1) returns 1
 * decimalToBinary(7) returns 111
 * decimalToBinary(200) returns 11001000  
 */
//Have required parameter(s)
int decimalToBinary(int number)
{
	if (number < 2)
		return number;

	return (number % 2) + decimalToBinary(number / 2) * 10;	
}


/**
 * @brief 
 * - Performs simple arithmetic operations on the parameter 'balance' depending on the options 
 *   entered by the user.
 * - The function begins by printing the 'balance' and then asks for an option from the user.
 * - The option entered by the user could be one of the following characters:
 *          '+', '-', 'e', 'c'
 * - On receiving an option 'e', the function does not ask as for any more 
 *   options to be entered and returns 'e', thereby exiting from the function.
 * - On receiving one of '+', '-' as an option, the function waits for the user 
 *   to enter an integer 'input' and performs the corresponding operation between 'balance' and 'input'.
 * - On receiving the option 'c', cancel the last operation and continue from there; 
 *   If there are no more operations to cancel, exit the program.
 * - If the user enters some other option other than the 4 allowed, the program exits.
 *  
 * Example: 
 *   - A possible run due to the function-call 'calculator(0)' is given below:
						Balance: 0
						+
						10
						Balance: 10
						+
						10
						Balance: 20
						+  
						10
						Balance: 30
						e
 *   - Another possible run due to the function-call 'calculator(0)' is given below:
						Balance: 0
						+
						10
						Balance: 10
						+
						10
						Balance: 20
						-
						5
						Balance: 15
						c
						Balance: 20
						+  
						10
						Balance: 30
						c
						Balance: 20
						c
						Balance: 10
						e
*    - Another possible run due to the function-call 'calculator(0)' is given below:
						Balance: 0
						+
						10
						Balance: 10
						-
						10
						Balance: 0
						c
						Balance: 10
						c
						Balance: 0
						c
*    - Another possible run due to the function-call 'calculator(0)' is given below:
						Balance: 0
						-
						10
						Balance: -10
						*
 */
char calculator(int balance)
{  
	printf("Balance: %d\n", balance);//This statement needs to be there in the function. You can however change the position of this statement.
	
	char operation;
	scanf(" %c", &operation);

	if (operation == '+' || operation == '-')
	{
		int update;
		scanf("%d", &update);

		if (operation == '-')
			update = -update;

		char output = calculator(balance + update);
		if (output == 'c')
			/* This also works!
			output = calculator(balance);
			return output; */
			return calculator(balance);
	}

	if (operation == 'c')
		return 'c';
	
	return 'e';
}

/**
 * @brief Checks whether a character is alphabet or digit
 * Returns 1 if character is an alphabet
 * Returns 2 if character is a digit
 * Returns 3 if character is neither alphabet nor digit
 * 
 * ASCII values:
 *  A - Z = 65 - 90
 *  a - z = 97 - 122
 *  0 - 9 = 48 - 57
 * 
 * Examples:
 * check_alphabet_digit('a') returns 1
 * check_alphabet_digit('0') returns 2
 * check_alphabet_digit('+') returns 3
*/
//Have required parameter(s) and return type
int check_alphabet_digit(char ch)
{
	if ((ch > 64 && ch < 91) || (ch > 96 && ch < 123))
		return 1;

	if (ch > 47 && ch < 58)
		return 2;

	return 3;	
}

int main()
{
	///*******DO NOT CHANGE main()********

	printf("1. decimal to binary  2. calculator(0) 3. check alphabet\n");
	printf("Which function do you want to test? Enter 1 or 2 or 3 accordingly.\n");

	int option;
	scanf(" %d", &option);

	if(option == 1)
	{
		int decimal;
		printf("Enter a number between 0 and 1000 (both inclusive): ");
		scanf("%d", &decimal);
		printf("Binary is: %d\n", decimalToBinary(decimal));
	}
	else if(option == 2)
	{
		calculator(0);
	}
	else if(option ==3)
	{
		char c;
		printf("Enter a character: ");
		scanf(" %c", &c);
		int check = check_alphabet_digit(c);
		if(check == 1)
			printf("You entered an alphabet.\n");
		else if(check == 2)
			printf("You entered a digit.\n");
		else
			printf("You entered neither an alphabet nor a digit.\n");
	}

	return 0;
}