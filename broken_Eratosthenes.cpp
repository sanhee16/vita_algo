#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<math.h>
#include<unordered_map>
using namespace std;


int main() {
	long long n;
	cin >> n;
	/*
	37 * 2 = 74

	*/
	for (long long i = 2; i < sqrt(n); i++) {
		if (n % i == 0) {
			long long find = n / i;
			for (long long j = 2; j < sqrt(find); j++) {
				if (find % j == 0) {
					cout << "0" << endl;
					return 0;
				}
			}
		}
	}

	cout << "1" << endl;
	return 0;
}


