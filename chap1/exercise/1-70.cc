#include <cmath>
#include <iostream>
#include <string>
using namespace std;

/*
	转换任意两个进制的数字可以用十进制来做中转
*/

bool is_valid(string num) {
	for (auto ch : num) if ((ch < '0' || ch > '9') && (ch < 'A' || ch > 'Z')) return false;
	return true;
}

int dig_to_dec(string num, int base) {
	int p = 0, ans = 0;
	for (int i = num.length() - 1; i >= 0; --i) {
		if (isdigit(num[i])) {
			ans += (int)(num[i] - '0')*pow(base, p++);
		}
		else {
			ans += (int)(num[i] - 'A' + 10)*pow(base, p++);
		}
	}
	return ans;
}

string dec_to_dig(int num, int base) {
	string ans;
	while (num > 0) {
		int tmp = num % base;
		num /= base;
		ans = (char)(tmp < 10 ? tmp + '0' : tmp + 'A' - 10) + ans;
	}
	return ans;
}

int main() {
	int b1, b2;
	string input;
	while (cin >> b1 >> b2 >> input) {
		if (b1 <= 1 || b2 <= 1 || input[0] == 'q' || input[0] == 'Q') break;
		if (!is_valid(input)) {
			cout << "input invalid!" << endl;
			continue;
		}
		int num = dig_to_dec(input, b1);
		cout << dec_to_dig(num, b2) << endl;
	}
	return 0;
}