#include "iostream"

using namespace std;

string decimalToBinary(int number) {
    string result;

    while (number > 0) {
        const int reminder = number % 2;
        result += reminder ? '1' : '0';
        number = number / 2;
    }
    reverse(result.begin(), result.end());
    return result;
}

string decimalToOctal(int number) {
    string result;

    while (number > 0) {
        const int reminder = number % 8;
        result += '0' + reminder;
        number = number / 8;
    }
    reverse(result.begin(), result.end());
    return result;
}

string decimalToHex(int number) {
    string result;

    while (number > 0) {
        const int reminder = number % 16;

        if (reminder < 10)
            result += 48 + reminder;
        else
            result += 55 + reminder;
        number = number / 16;
    }
    reverse(result.begin(), result.end());
    return result;
}

// Binary -> all
int binaryToDecimal(string number) {
    int result = 0;
    int base = 1;

    for (int i = number.length() - 1; i >= 0; i--) {
        const int lastDigit = number[i] - '0';
        result += lastDigit * base;
        base *= 2;
    }
    return result;
}

int octalToDecimal(int number) {
    int result = 0;
    int base = 1;

    while (number > 0) {
        int last_digit = number % 10;
        result += last_digit * base;
        base *= 8;
        number /= 10;
    }
    return result;
}

int hexToDecimal(string number) {
    int result = 0;
    int base = 1;

    for (int i = number.length() - 1; i >= 0; i--) {
        const int lastDigit = number[i];

        if (lastDigit >= '0' && lastDigit <= '9')
            result += (lastDigit - 48) * base;
        else if (lastDigit >= 'A' && lastDigit <= 'F')
            result += (lastDigit - 55) * base;
        base *= 16;
    }
    return result;
}

int main() {
    cout<<'0' + 3<<endl;
    char val = '2';
    const int cur = val - '0';
    cout<<cur<<endl;
    char c = '0';
    int i = static_cast<int>(c);
    cout<<i<<endl;

    cout<<decimalToBinary(10)<<endl;
    cout<<decimalToOctal(10)<<endl;
    cout<<decimalToHex(10)<<endl;

    string binNumber = "1010";
    cout<<binaryToDecimal(binNumber)<<endl;
    cout<<decimalToOctal(binaryToDecimal(binNumber))<<endl;
    cout<<octalToDecimal(12)<<endl;
    cout<<hexToDecimal("A")<<endl;
}