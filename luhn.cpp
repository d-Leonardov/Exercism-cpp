#include <cmath>
#include <string>
#include <iostream>
#include <string>

namespace luhn {
    bool valid(std::string number) {
        int numberLength = number.length();
        int value{ 0 };
        std::string newNumber;

        for (int j{ 0 }; j < numberLength; j++) {
            if ((number[j] >= 48 && number[j] <= 57) && (number[j] != 32)) newNumber += number[j];
            if (number[j] == 32) continue;
            if (!(number[j] >= 48 && number[j] <= 57)) return 0;
        }

        numberLength = newNumber.length();

        if (numberLength > 1) {
            for (int i = numberLength - 1; i >= 0; i--) {
                int digit = newNumber[i] - '0';
                if (numberLength % 2 == 0) {
                    if ((i % 2 == 0 || (numberLength == 2 && i == 0))) {
                        int n = digit * 2;
                        if (n > 9) {
                            value += n - 9;
                        } else value += n;
                    } else value += digit;
                } else if (numberLength % 2 != 0) {
                    if ((i % 2 != 0 || (numberLength == 2 && i == 0))) {
                        int n = digit * 2;
                        if (n > 9) {
                            value += n - 9;
                        } else value += n;
                    } else value += digit;
                }
            }
        } else return false;

        std::cout << value;

        if (value % 10 == 0) {
            return true;
        } else return false;
    }
}  // namespace luhnn

int main() {
    luhn::valid("19");
}