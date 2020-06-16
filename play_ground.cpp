#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include<cstring> //memset
/*
bit-mask
DP
완전탐색
*/
using namespace std;

int n;
vector<vector<int>> adj;
const int inf = 1e9;
vector<vector<int>> d;
//int d[1 << 16][16];
int recur(int cur, int mask) {
	// vertex 방문
	if (mask == (1<<n)-1) {
		if (adj[cur][0] != 0)
			return adj[cur][0];
		else
			return inf;
	}
	// mask에 대해 이미 조사 끝
	int& res = d[mask][cur];
	if (res != -1)
		return res;

	// mask 조사
	res = inf;
	for (int i = 0; i < n; i++) {
		if (adj[cur][i] && ((mask&(1<<i))==0)) {
			res = min(res, recur(i, mask | (1 << i)) + adj[cur][i]);
		}
	}
	return res;
}


int main() {
	cin >> n;
	//memset(d, -1, sizeof(d));
	vector<int> vis;
	vector<int> t;
	
	for (int i = 0; i < 17; i++)
		t.push_back(-1);
	for (int i = 0; i < pow(2,16); i++)
		d.push_back(t);
	

	for (int i = 0; i < n; i++) 
		vis.push_back(0);
	
	for (int i = 0; i < n; i++) 
		adj.push_back(vis);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> adj[i][j];
		}
	}

	cout << recur(0,1) << endl;

	return 0;
}


