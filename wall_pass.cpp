#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<deque>
#include<unordered_map>
/*
가중치가 0,1 이 있음 = deque 사용 (가중치에 따라 서로 다른 queue를 사용해도 되지만 deque가 편함)
(그동안은 가중치가 1만 있어서 queue)

vis에서 1,0만 체크할 게 아니고 vis자체에 count값을 넣으면 
deque 에 pair(xy좌표, cnt)를 넣는 것보다 메모리를 줄일 수 있다.
pair로 넣으면 runtime error발생
*/
using namespace std;
int d[1001][1001];
int vis[1001][1001];
deque<int> q;

int n;

int go() {
	int cnt = 1;
	vector<int> mov_x = { -1,1,0,0 };
	vector<int> mov_y = { 0,0,1,-1 };
	int ans = 1e9;

	q.push_front(0);
	vis[0][0] = 1;

	while (true) {
		if (q.empty() == true)
			break;
		int dir = q.front();
		int cur_x = dir / n;
		int cur_y = dir % n;
		int cur_cnt = vis[cur_x][cur_y];
		q.pop_front();
		//vis[cur_x][cur_y] = 1;
		for (int i = 0; i < 4; i++) {
			int x = cur_x + mov_x[i];
			int y = cur_y + mov_y[i];

			if (x < 0 || y < 0 || x > n-1 || y > n-1)
				continue;
			if (x == n - 1 && y == n - 1) {
				if (ans > cur_cnt)
					ans = cur_cnt;
				continue;
			}
			if (vis[x][y] == 0) {
				if (d[x][y] == 1) {
					vis[x][y] = vis[cur_x][cur_y];
					q.push_front(x * n + y);
				}
				else if (d[x][y] == 0){
					vis[x][y] = vis[cur_x][cur_y]+1;
					q.push_back(x*n+y);
				}
			}
		}
	}
	return ans;
		
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			vis[i][j] = 0;
			int inp = 0;
			cin >> inp;
			d[i][j] = inp;
		}
	}


	cout << go() << endl;

	return 0;
}
