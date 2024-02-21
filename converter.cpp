#include <iostream>
#include <cmath>
using namespace std;
string decimalToBase(double num, int base);
double baseToDecimal(const string& num, int base);

int main() {

	
    double num;
    int sourceBase, targetBase;
    string inputNum, result;
    	int choice;
	cout << "1.Choose what you want to convert to:";
	cout << "2.Binary to Decimal" << endl;
	cout << "3.Decimal to Binary" << endl;
	cout << "4.Octal to Decimal" << endl;
	cout << "5.Decimal to Octal" << endl;
	cout << "6.Hexadecimal to Decimal" << endl;
	cout << "7.Decimal to Hexadecimal" << endl;
		cout << "8.binary to Hexadecimal" << endl;
			cout << "9.octal to binary" << endl;
				cout << "10.hexadecimal to binary" << endl;
	cin >> choice;
	

	if(choice == 2){
		cout<< "********Converting Binary to Decimal********";
	}
		else if(choice == 3)
		{
		cout << "********Decimal to Binary*******" << endl;	
		}
		
			else if(choice == 4)
		{
		cout << "********Octal to Decimal*******" << endl;	
		}
			else if(choice == 5)
		{
		cout << "********Decimal to Octal*******" << endl;	
		}
			else if(choice == 6)
		{
		cout << "********Hexadecimal to Decimal*******" << endl;	
		}
			else if(choice == 7)
		{
		cout << "********Decimal to Hexadecimal*******" << endl;	
		}
			else
		{
		cout << "********Invalid Input*******" << endl;	
	
		}

    cout << "Enter a number: ";
    cin >> inputNum;

    cout << "Enter the source base (2 for binary, 8 for octal, 10 for decimal, 16 for hexadecimal): ";
    cin >> sourceBase;

    cout << "Enter the target base (2 for binary, 8 for octal, 10 for decimal, 16 for hexadecimal): ";
    cin >> targetBase;

    num = baseToDecimal(inputNum, sourceBase);
    result = decimalToBase(num, targetBase);

    cout << "Result: " << result << std::endl;

    return 0;
}
// Function to convert a de6cimal number to another base
  	string decimalToBase(double num, int base) {
    string result = "";
    int intPart = static_cast<int>(num);//converts from double to int data 1type
    double fracPart = num - intPart;//: Calculate the fractional part of the decimal number by subtracting the integer part from the original number.

	//Start a loop that will continue until the integer part (intPart) becomes zero. This loop is used to convert the integer part of the decimal number into the target base.
    while (intPart > 0) {
        int remainder = intPart % base;
        result = (remainder < 10) ? char('0' + remainder) + result : char('A' + remainder - 10) + result;
        intPart /= base;
    }

    if (fracPart > 0) {
        result += ".";
        for (int i = 0; i < 5; i++) {  // Specify the number of decimal places to convert
            fracPart *= base; 
            int digit = static_cast<int>(fracPart);
            result += (digit < 10) ? char('0' + digit) : char('A' + digit - 10);
            fracPart -= digit;
        }
    }

    return result;
}

// Function to convert a number from any base to decimal
double baseToDecimal(const string& num, int base) {
    double result = 0.0;
    int intPart = 0;
    double fracPart = 0.0;
    int decimalPosition = num.find('.');

    for (size_t i = 0; i < num.length(); i++) {
        if (i < decimalPosition) {
            intPart = intPart * base + (isdigit(num[i]) ? (num[i] - '0') : (toupper(num[i]) - 'A' + 10));
        } else if (i > decimalPosition) {
            fracPart += (isdigit(num[i]) ? (num[i] - '0') : (toupper(num[i]) - 'A' + 10)) * std::pow(1.0 / base, i - decimalPosition);
        }
    }

    result = intPart + fracPart;
    return result;
}


