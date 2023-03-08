#include <bits/stdc++.h>
using namespace std;

int n, m, visitied[100][100] = { 0, };
int dx[4] = { 0,1,0,-1 }, dy[4] = { -1,0,1,0 };
char arr[100][100];

int bfs(int sx, int sy, int lx, int ly) {
	queue<pair<int, int>> q;
	visitied[sx][sy] = 1;
	q.push({ sx, sy });
	while (q.size()) {
		pair<int, int> num = q.front();
		q.pop();
		for (int i = 0;i < 4;i++) {
			int x = num.first + dx[i];
			int y = num.second + dy[i];
			if (x >= 0 && x < n && y >= 0 && y < m && visitied[x][y] == 0 && arr[x][y] == '1') {
				visitied[x][y] = visitied[num.first][num.second] + 1;
				if (x == lx && y == ly) {
					return visitied[lx][ly];
				}
				q.push({ x,y });
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			cin >> arr[i][j];
		}
	}
	cout << bfs(0, 0, n - 1, m - 1);
}