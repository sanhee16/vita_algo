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

int bot1, bot2;
pair<int, int> ans;
int vis[1001][1001];

void go(){
	int done = 0;
	queue<pair<int, int>> q1;
	queue<pair<int, int>> q2;
	q1.push({ 0,1 });
	q2.push({ 0,1 });
	int cur1, cur1_cnt, cur2, cur2_cnt;
	while (true) {
		if (q1.empty() == true) {
			done = 1;
			break;
		}
		cur1 = q1.front().first;
		cur1_cnt = q1.front().second;
		cur2 = q2.front().first;
		cur2_cnt = q2.front().second;
		q1.pop();
		q2.pop();

		if (cur1 == ans.first && cur2 == ans.second)
			break;

		for (int i = 0; i < 3; i++) {
			if (i == 0) {
				// 버리기
				if (cur1 != 0 && vis[0][cur2] == 0) {
					vis[0][cur2] = 1;
					q1.push({ 0, cur1_cnt + 1 });
					q2.push({ cur2, cur2_cnt + 1 });
				}
				if (cur2 != 0 && vis[cur1][0]==0) {
					vis[cur1][0] = 1;
					q1.push({ cur1, cur1_cnt + 1 });
					q2.push({ 0, cur2_cnt + 1 });
				}
			}
			else if (i == 1) {
				// 가득 채우기
				if (cur1 != bot1 && vis[bot1][cur2]==0) {
					vis[bot1][cur2] = 1;
					q1.push({ bot1, cur1_cnt + 1 });
					q2.push({ cur2, cur2_cnt + 1 });
				}
				if (cur2 != bot2 && vis[cur1][bot2]==0) {
					vis[cur1][bot2] = 1;
					q1.push({ cur1, cur1_cnt + 1 });
					q2.push({ bot2, cur2_cnt + 1 });
				}
			}
			else {
				// 옮기기
				if (cur1 != bot1 && cur2 != 0) {
					// cur2 -> cur1
					if (cur1 + cur2 > bot1 && vis[bot1][cur1 + cur2 - bot1] == 0) {
						vis[bot1][cur1+cur2-bot1] = 1;
						q1.push({ bot1, cur1_cnt + 1 });
						q2.push({ cur2 - (bot1-cur1) ,cur2_cnt + 1 });
					}
					else if (cur1 + cur2 <= bot1 && vis[cur1 + cur2][0]==0){
						vis[cur1 + cur2][0] = 1;
						q1.push({ cur1+cur2 ,cur1_cnt + 1 });
						q2.push({ 0 ,cur2_cnt + 1 });
					}
				}
				if (cur1 != 0 && cur2 != bot2) {
					// cur1 -> cur2
					if (cur1 + cur2 > bot2 && vis[cur1 + cur2 - bot2][bot2]==0) {
						vis[cur1 + cur2 - bot2][bot2] = 1;
						q1.push({ cur1 - (bot2-cur2) ,cur1_cnt + 1 });
						q2.push({ bot2 ,cur2_cnt + 1 });
					}
					else if(cur1 + cur2 <= bot2 && vis[0][cur1 + cur2] == 0){
						vis[0][cur1 + cur2] = 1;
						q1.push({ 0 ,cur1_cnt + 1 });
						q2.push({ cur1 + cur2 ,cur2_cnt + 1 });
					}
				}
			}
		}

	}
	if (done == 1)
		cout << -1 << endl;
	else
		cout << cur1_cnt << endl;
	return;
}

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	bot1 = a;
	bot2 = b;
	ans = { c,d };
	go();

	return 0;
}
