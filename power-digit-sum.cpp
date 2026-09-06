// Thanks WILL for installing G++ and helping with the setup
// Thanks Huy'30(John) for helping with verification of the code

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Custom power function
unsigned int power(unsigned short a, unsigned short b)/* Returns a raised to the power of b using a for loop
unsigned meaning only postive integers as negative is not permitted */
{
    unsigned int n = 1;

    for (unsigned short i = 0; i < b; i++) // in each iteration, multiply n by a, iteration count is b using variable i
    {
        n = n * a; // n is multiplied by a in each iteration
    }

    return n;// returning final n value
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

