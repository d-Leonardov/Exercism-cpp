#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>

namespace hexadecimal {
	int convert(std::string number) {
		int length = number.length();
		std::transform(number.begin(), number.end(), number.begin(), ::tolower);
		int hex{ 16 };
		int power{ 0 };
		int newNumber{ 0 };

        for (int i = length - 1; i >= 0; i--) {
			if (number[i] == 102) {
				newNumber += 15 * std::pow(hex, power);
				power++;
				continue;
			}
			if (number[i] == 101) {
				newNumber += 14 * std::pow(hex, power);
				power++;
				continue;
			}
			if (number[i] == 100) {
				newNumber += 13 * std::pow(hex, power);
				power++;
				continue;
			}
			if (number[i] == 99) {
				newNumber += 12 * std::pow(hex, power);
				power++;
				continue;
			}
			if (number[i] == 98) {
				newNumber += 11 * std::pow(hex, power);
				power++;
				continue;
			}
			if (number[i] == 97) {
				newNumber += 10 * std::pow(hex, power);
				power++;
				continue;
			}
			if (!(number[i] >= 48 && number[i] <= 57)) {
				return 0;
			} else newNumber += int(number[i] - '0') * std::pow(hex, power); power++;
        }

		std::cout << newNumber;
		return newNumber;
	}
}  // namespace hexadecimal

//int main() {
//	hexadecimal::convert("f1");
//}