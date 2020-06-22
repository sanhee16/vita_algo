/*
// 너무 많은 조건문, 불필요한 변환
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<stdio.h>
#include<queue>
#include<deque>
#include<unordered_map>

using namespace std;



int main() {
	pair<int, int> a;
	pair<int, int> b;

	string str,tmp; 
	int h = 0, m = 0;

	
	cin >> str;
	tmp = str.substr(0, 2);
	h = stoi(tmp.c_str());
	tmp.clear();
	tmp = str.substr(3, 2);
	m = stoi(tmp.c_str());
	a = { h,m };


	cin >> str;
	tmp = str.substr(0, 2);
	h = stoi(tmp.c_str());
	tmp.clear();
	tmp = str.substr(3, 2);
	m = stoi(tmp.c_str());
	b = { h,m };
	
	int ans = 0;

	if (a.first == 23 && b.first == 0) {
		/*
		23:59
		0:02
		*/
		if (a.second > b.second && (b.second + 60 - a.second <= 10))
			ans = 1;

	}
	else{
		if (a.first == b.first) {
			if (a.second <= b.second && (b.second - a.second <= 10))
				ans = 1;
		}
		/*
		11:59
		12:02
		*/
		if (a.first + 1 == b.first) {
			if (a.second > b.second && (b.second + 60 - a.second <= 10))
				ans = 1;
		}
	}
	cout << ans << endl;


	return 0;
}

*/

#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<stdio.h>
#include<queue>
#include<deque>
#include<unordered_map>

using namespace std;

/*
23:59
00:02 
일 때 0 출력됨 -> 맞는건지?
*/

int main() {
	
  int h, m;
	int a, b, ans=1;

	scanf("%d:%d", &h, &m);
	a = h * 60 + m;
	scanf("%d:%d", &h, &m);
	b = h * 60 + m;

	if (a > b || b-a > 10)
		ans = 0;
	
	
	cout << ans;
	return 0;
}
