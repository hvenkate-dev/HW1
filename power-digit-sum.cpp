 #include <iostream>
 #include <string>
 #include <cctype>
 #include <vector>
 #include <cmath>
 using namespace std;

 unsigned long long int power(unsigned int a, unsigned int b) {
	 unsigned long long int n = 1;
	 for (unsigned int i = 0; i < b; i++) {
		 n = n * a;
	 }
	 return n;
 }

 /* Explaining the Syntax: vector<int>: the function returns a vector containing integers
 vectorize_digits: the function name. unsigned long long n: the function receives one positive whole number.*/
 vector<int> vectorize_digits(unsigned long long n) {
	 vector<int> digits;
	 string number = to_string(n);
	 /*Characters representing numbers have character codes. Subtracting '0' converts a numeric character into its integer value*/
	 for (char digit : number) {
		 digits.push_back(digit - '0');
		 /* Example: '5' - '0' = 5 * '2' - '0' = 2*/
	 }
	 return digits;
 }

 // Converts a vector of integers into a readable format such as [8, 2, 3].
 string vec_to_string(vector<int> vec) {
	 string result = "[";
	 for (size_t i = 0; i < vec.size(); i++) {
		 result += to_string(vec[i]);
		 // Add separators only between values, so the result has no trailing comma.
		 if (i < vec.size() - 1) {
			 result += ", ";
		 }
	 }
	 result += "]";
	 return result;
 }

 int sum_vector(vector<int> v) {
	 int sum = 0;
	 for (int number : v) {
		 sum += number;
	 }
	 return sum;
 }

 int main(int argc, char* argv[]) {
	 //Checking If the input values are provided or not
	 if (argc != 3) {
		 cout << "Error: Please provide only two values." << endl;
		 cout << "Use: ./pds a b" << endl;
		 return 1;
	 }

	 string aInput = argv[1];
	 string bInput = argv[2];

	 //Checking If the input values are empty or not
	 if (aInput.empty() or bInput.empty()) {
		 cout << "Error: values cannot be empty." << endl;
		 return 1;
	 }

	 //Checking If the input values are negative or not
	 if (aInput[0] == '-' or bInput[0] == '-') {
		 cout << "No negative integers please" << endl;
		 return 1;
	 }

	 //Checking If the input values are integers or not
	 for (char c : aInput) {
		 if (!isdigit(c)) {
			 cout << "Error: String Input A contains non-integer values." << endl;
			 return 1;
		 }
	 }
	 for (char c : bInput) {
		 if (!isdigit(c)) {
			 cout << "Error: String Input B contains non-integer values." << endl;
			 return 1;
		 }
	 }

	 unsigned int a = stoul(aInput);
	 unsigned int b = stoul(bInput);

	 // Special Case for when a = 0, log(0) is undefined
	 if (a == 0) {
		 unsigned long long int n = power(a, b);
		 vector<int> digits = vectorize_digits(n);
		 int digitSum = sum_vector(digits);
		 cout << a << "^" << b << " = " << n << endl;
		 cout << "Sum Of Digits: " << digitSum << endl;
		 return 0;
	 }

	 //Checking if the given values will not overflow
	 double logResult = b * log10(a);
	 double logMax = 64 * log10(2);
	 if (logResult >= logMax) {
		 cout << "Error: The values are too large and would cause overflow." << endl;
		 return 1;
	 }

	 unsigned long long int n = power(a, b);
	 vector<int> digits = vectorize_digits(n);
	 string digitString = vec_to_string(digits);
	 int digitSum = sum_vector(digits);
	 cout << a << "^" << b << " = " << n << endl;
	 cout << "Digits: " << digitString << endl;
	 cout << "Sum Of Digits: " << digitSum << endl;
	 return 0;
 }
