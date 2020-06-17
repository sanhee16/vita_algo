#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<unordered_map>
using namespace std;


vector<vector<int>> m;
vector<vector<int>> vis;
int n;
queue<pair<int,int>> q;

int bfs() {
	vector<int> mov_x = { 1,-1,0,0 };
	vector<int> mov_y = { 0,0, 1,-1 };
	int ans = 0;
	while (true) {
		if (q.empty() == true)
			break;
		int dir = q.front().first;
		int cnt = q.front().second;
		ans = cnt;
		q.pop();
		int cur_x = dir / n;
		int cur_y = dir % n;
		vis[cur_x][cur_y] = 1;
		int x, y;
		for (int i = 0; i < 4; i++) {
			x = cur_x + mov_x[i];
			y = cur_y + mov_y[i];
			if (x < 0 || y < 0 || x >= n || y >= n)
				continue;
			if (m[x][y] == 1 && vis[x][y] == 0) {
				vis[x][y] = 1;
				m[x][y] = 0;
				q.push(make_pair(x * n + y, cnt+1));
			}
		}
	}
	return ans;
}

int main() {
	int ans = 0;
	cin >> n;
	vector<int> t;
	for (int i = 0; i < n; i++)
		t.push_back(0);
	for (int i = 0; i < n; i++) {
		m.push_back(t);
		vis.push_back(t);
	}
	int no = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> m[i][j];
			if (m[i][j] == 0) {
				no = 1;
				int first = i * n + j;
				q.push(make_pair(first,0));
			}

		}
	}
	if (no == 0)
		ans = -1;
	else
		ans = bfs();
	cout << ans << endl;
	return 0;
}


