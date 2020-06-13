#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> g[200001];
int vis[200001];
/*
memory 

vector<int> g[200001];
int vis[200001];
-> vaccine안에 하면 메모리용량 때문에 안됨(*너무 커서)
그래서 heap 메모리에 빼야한다.


*/
void vaccine() {
	int n,m;
	cin >> n >> m;
	queue<int> q;
	
	int ans_num = 0, ans_vertex = 0;
	
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		g[b].push_back(a);
		g[a].push_back(b);
	}
	
	
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		if (vis[i] == 0) {
			vis[i] = 1;
			q.push(i);
		}
		else
			continue;
		while (true) {
			if (q.empty() == true)
				break;
			int a = q.front();
			q.pop();
			cnt++;

			for (int b = 0; b < g[a].size(); b++) {
				if (vis[g[a][b]] == 0) {
					vis[g[a][b]] = 1;
					q.push(g[a][b]);
				}
			}
		}
		if (ans_num < cnt) {
			ans_num = cnt;
			ans_vertex = i;
		}
	}
	
	cout << ans_vertex << " " << ans_num << endl;
	return ;
}

int main() {
	vaccine();
	return 0;
}

