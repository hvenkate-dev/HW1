// Thanks WILL for installing G++ and helping with the setup
// Thanks Huy'30(John) for helping with string to short method
// Atleast Half a dozen times I have thought what would be the sum of digits of a number

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Custom power function
unsigned int power(unsigned short a, unsigned short b)/* Returns a raised to the power of b using a for loop
unsigned meaning only postive integers as negative is not permitted
0 to 4,294,967,29 to 32,767 for a signed short and 0 to 65,535 for an unsigned short 
Short uses far less memory compared to int *
Unsigned int is used for return value because it can hold a larger range of values compared to unsigned short*/
{
    unsigned int n = 1;

    for (unsigned short i = 0; i < b; i++) // in each iteration, multiply n by a, iteration count is b using variable i
    {
        n = n * a; // n is multiplied by a in each iteration
        /* for example: a = 2 and b =3 
        i = 0, n = 1 * 2 = 2
        i = 1, n = 2 * 2 = 4
        i = 2, n = 4 * 2 = 8 */
    }

    return n;// returning final n value (n=8)
}

int main(int argc, char* argv[])// input of argument count to check is only 3 argc is provided and the values of argument are provided in argv array//
{
    // Checking if only two arguments are provided
    if (argc != 3) // If there are more than two arguments, ./pds a b it raises an error
    {
        cout << "Error: Please provide only two values." << endl;
        cout << "Use: ./pds a b" << endl;
        return 1;
    }

    string aInput = argv[1];//Taking String Input of Value a
    string bInput = argv[2];//Taking String Input of Value b

    // Checking if String Input A contains only integer values
    for (char c : aInput) // range based loop for checking each string value of a
    {
        if (!isdigit(c))// isdigit(c) function from cctype library, if char is not a digit, ! returns true therefore error is written in terminal
        {
            cout << "Error: String Input A contains non-integer values." << endl; // Raising Error
            return 1;
        }
    }

    // Checking if String Input B contains only integer values
    for (char c : bInput) // range based loop for checking each string value of b
    {
        if (!isdigit(c)) //isdigit(c) function from cctype library, if char is not a digit, ! returns true therefore error is written in terminal
        {
            cout << "Error: String Input B contains non-integer values." << endl; // Raising Error
            return 1;
        }
    }

    // Check for empty input
    if (aInput.empty() or bInput.empty()) // if either a or b input is empty, raise an error
    {
        cout << "Error: values cannot be empty." << endl; // Raising Error
        return 1;
    }

    // Convert strings to numbers
    /* stoi is a function that converts a string to an unsigned short integer is used to hold the converted values */

    unsigned short a = stoi(aInput);
    unsigned short b = stoi(bInput);

    // Compute a^b
    unsigned int n = power(a, b);

    // Calculate the sum of the digits
    unsigned int temp = n; // creating a temporary variable to hold the value of n for digit sum calculation
    unsigned int digitSum = 0; // initializing the digit sum variable to 0

    while (temp > 0)
    {
        digitSum += temp % 10; // adding the last digit of temp to digitSum
        temp /= 10; // removing the last digit from temp
    }

   
    cout << a << "^" << b << " = " << n << endl;// printing the result of a^b
    cout << "Sum Of Digits: " << digitSum << endl;// printing the sum of the digits of a^b

    return 0; // returning 0 to indicate successful execution
}

