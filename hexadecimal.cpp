#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>

namespace hexadecimal {
	int convert(std::string number) {
		int length = number.length();
		std::transform(number.begin(), number.end(), number.begin(), ::tolower);
		int hex = 16;
		int power = 0;
		int newNumber = 0;

		for (int i = length - 1; i >= 0; i--) {
			int digitValue;
			if (number[i] >= 'a' && number[i] <= 'f') {
				digitValue = 10 + (number[i] - 'a');
			}
			else if (number[i] >= '0' && number[i] <= '9') {
				digitValue = number[i] - '0';
			}
			else {
				return 0; // Invalid character
			}

			newNumber += digitValue * std::pow(hex, power);
			power++;
		}

		std::cout << newNumber;
		return newNumber;
	}
}  // namespace hexadecimal

int main() {
	hexadecimal::convert("f1");
}