#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<unordered_map>


using namespace std;
unordered_map<int, unsigned long long> d1;
unordered_map<int, unsigned long long> d2;

const long long mod = 1e9;

int n = 0;
int bfs() {
	long long total = 0;
	for (int j = 0; j < 10; j++) {
		int turn = n;
		unsigned long long cnt = 1;
		unsigned long long cnt_minus = 1;

		for (int i = 0; i < 10; i++)
			d1[i] = 0;
		for (int i = 0; i < 10; i++)
			d2[i] = 0;

		d1[j] = 1;
		while(true){


			if (turn == 1) {
				break;
			}

			for (int i = 0; i < 10; i++) {
				int tmp = d1[i] % mod;
				if (i == 0) {
					d2[i + 1] += tmp;
					d2[i + 1] %= mod;
				}
				else if (i == 9) {
					d2[i - 1] += tmp;
					d2[i - 1] %= mod;
				}
				else {
					d2[i - 1] += tmp;
					d2[i + 1] += tmp;

					d2[i + 1] %= mod;
					d2[i - 1] %= mod;
				}
			}

			for (int i = 0; i < 10; i++)
				d1[i] = 0;

			for (int i = 0; i < 10; i++)
				d1[i] = d2[i];

			for (int i = 0; i < 10; i++)
				d2[i] = 0;
			turn--;
		}
		for (int i = 0; i < 10; i++)
			total = (total + d1[i]) % mod;
		total = total % mod;
	}
	return total;
}

int main() {
	cin >> n;
	if (n == 1) {
		cout << 1 << endl;
		return 0;
	}
	cout << bfs() << endl;

	return 0;
}


