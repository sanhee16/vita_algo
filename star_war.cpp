#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<unordered_map>
using namespace std;

/*
***** a,k의 범위 잘 생각하기


*/


int inf = 1e9;
vector<int> a;
vector<int> d;

int main() {
	int n, k;
	cin >> n >> k;
	int big = 0;
	for (int i = 0; i < k+1; i++) {
		d.push_back(inf);
	}
	for (int i = 0; i < n; i++) {
		int tmp = 0;
		cin >> tmp;
		if (tmp < 10001) {
			a.push_back(tmp);
			if (big < tmp)
				big = tmp;
			d[tmp] = 1;
		}
	}
	unique(a.begin(), a.end());
	sort(a.begin(), a.end());
	int ans = 0;
	for (int i = 1; i < k+1; i++) {
		for (int j = 0; j < a.size() && a[j] < i; j++) {
			d[i] = min(d[i - a[j]] + 1, d[i]);
		}
	}

	if (d[k] == inf)
		cout << -1 << endl;
	else
		cout << d[k] << endl;


	return 0;
}

