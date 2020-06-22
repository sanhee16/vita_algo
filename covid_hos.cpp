#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<stdio.h>
#include<queue>
#include<deque>
#include<unordered_map>
#include<cstdio>

using namespace std;

/*
dp = time out
-> binary search! O(nlogn)
*/

vector<int> t;
int main() {
	long long n, k;
	cin >> n >> k;
	int big = 0;
	for (int i = 0; i < k; i++) {
		int inp = 0;
		cin >> inp;
		t.push_back(inp);
	}
	long long res;
	long long start=0, end=1e9;

	int idx; 
	sort(t.begin(), t.end());
	int ans = 0;
	while (start <= end) {
		int done = 0;
		idx = (start + end) / 2;
		res = 0;
		for (int i = 0; i<k; i++) {
			res += idx / t[i];
		}

		if (res < n)
			start = idx+1;
		else if (res >= n) {
			end = idx-1;
			ans = idx;
		}
	}

	cout << ans << endl;

	return 0;
}
