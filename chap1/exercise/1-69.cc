#include <cmath>
#include <iostream>
#include <string>
using namespace std;

bool is_binary_valid(string bin) {
	for (auto ch : bin) if (ch < '0' || ch > '1') return false;
	return true;
}

int bin_to_dec(string bin) {
	int ans = 0, base = 0;
	for (int i = bin.length() - 1; i >= 0; --i) {
		ans += (int)(bin[i] - '0')*pow(2, base++);
	}
	return ans;
}

int main() {
	string input;
	while (cin >> input) {
		if (input[0] == 'q' || input[0] == 'Q') break;
		if (!is_binary_valid(input)) {
			cout << "input invalid!" << endl;
			continue;
		}
		cout << bin_to_dec(input) << endl;
	}
	return 0;
}