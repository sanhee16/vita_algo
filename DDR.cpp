#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<unordered_map>
using namespace std;



int main() {
	int n;
	int ans = 1;
	cin >> n;
	unordered_map<int, long long> play;
	int btn = 0;
	int time = 0;
	for (int i = 0; i < n*2; i++) {
		if (i % 2 == 0) {
			// button
			cin >> btn;
		}
		else {
			// time
			cin >> time;
			play[time]++;
			if (play[time] > 2) {
				ans = 0;
				break;
			}
		}
	}
	cout << ans << endl;

	return 0;
}


