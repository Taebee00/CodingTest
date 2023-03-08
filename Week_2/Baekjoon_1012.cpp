#include <bits/stdc++.h>
using namespace std;

int n, m, num, arr[50][50], visitied[50][50] = { 0, }, cnt = 0;
int dx[4] = { 0,1,0,-1 }, dy[4] = { -1,0,1,0 };

void init() {
	cnt = 0;
	for (int i = 0;i < 50;i++) {
		for (int j = 0;j < 50;j++) {
			arr[i][j] = 0; visitied[i][j] = 0;
		}
	}
}

int dfs(int fx, int fy) {
	if (visitied[fx][fy]) return 0;
	visitied[fx][fy] = 1;
	for (int i = 0;i < 4;i++) {
		int x = fx + dx[i], y = fy + dy[i];
		if (x >= 0 && x < n && y >= 0 && y < m) {
			if (!visitied[x][y] && arr[x][y]) {
				dfs(x, y);
			}
		}
	}
	return 1;
}

int main() {
	int tc;
	cin >> tc;
	for (int j = 0;j < tc;j++){
		cin >> m >> n >> num;
		pair<int, int> loc[2500] = { {0,0}, };
		for (int i = 0;i < num;i++) {
			cin >> loc[i].second >> loc[i].first;
			arr[loc[i].first][loc[i].second] = 1;
		}
		for (int i = 0;i < num;i++) {
			if (dfs(loc[i].first, loc[i].second)) {
				cnt++;
			}
		}
		cout << cnt << "\n";
		init();
	}
}