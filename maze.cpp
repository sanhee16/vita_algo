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
int bfs() {
	int ans = 1000*1000;
	vector<int> mov_x = {1,-1,0,0};
	vector<int> mov_y = {0,0,1,-1};
	queue<pair<int, int>> q; //first : x,y - second : cnt
	q.push(make_pair(0, 1));

	/*
	x = q.first / n;
	y = q.first % n;
	*/

	while (true) {
		if (q.empty() == true)
			break;
		int dir = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (dir == n * n - 1) {
			if (ans > cnt)
				ans = cnt;
		}
		int cur_x = dir / n;
		int cur_y = dir % n;
		vis[cur_x][cur_y] == 1;
		int x, y;
		for (int k = 0; k < 4; k++) {
			x = cur_x + mov_x[k];
			y = cur_y + mov_y[k];
			if (x < 0 || y < 0 || x >= n || y >= n)
				continue;

			int num = m[x][y];
			if (num != 0 && num != 1) {
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						if (m[i][j] == num && vis[i][j]==0) {
							q.push(make_pair(i * n + j, cnt + 2));
							vis[i][j] = 1;
						}
					}
				}
			}
			else if (num == 0 && vis[x][y]== 0) {
				vis[x][y] = 1;
				q.push(make_pair(x * n + y, cnt + 1));
			}
			else if (num == 1) {
				continue;
			}
		}


	}
	if (ans == 1000 * 1000)
		ans = -1;
	return ans;


}
int main() {
	cin >> n;
	vector<int > t; 
	for (int i = 0; i < n; i++)
		t.push_back(0);
	for (int i = 0; i < n; i++) {
		m.push_back(t);
		vis.push_back(t);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <n; j++) {
			cin >> m[i][j];
		}
	}
	cout << bfs() << endl;
	return 0;
}


