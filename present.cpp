#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;


int main() {
	int n, m;
	vector<int> a;
	vector<int> b;
	vector<int> ans;

	unordered_map<int, int> d;

	// 1 < n,m < 1000000
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		a.push_back(0);
	for (int i = 0; i < m; i++){
		b.push_back(0);
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		d[a[i]]++;
	}
	for (int i = 0; i < m; i++)
		cin >> b[i];

	sort(a.begin(), a.end());
	unique(a.begin(), a.end());
for (int i = 0; i < b.size(); i++) {
		//tree->find(b[i]);
		ans.push_back(d[b[i]]);
		//cnt = 0;
	}

	for (int i = 0; i < b.size(); i++)
		cout << ans[i] << " ";
	cout << endl;

	return 0;
}
