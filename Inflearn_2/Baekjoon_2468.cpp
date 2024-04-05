// #include <bits/stdc++.h>
// using namespace std;

// int n, _max = 0, answer = 0, arr[104][104], visitied[104][104] = { 0, };
// int dx[4] = { 0,1,0,-1 }, dy[4] = { -1,0,1,0 };

// void init() {
// 	for (int i = 0;i < 104;i++) {
// 		for (int j = 0;j < 104;j++) {
// 			visitied[i][j] = 0;
// 		}
// 	}
// }

// int dfs(int sx, int sy, int height) {
// 	if (visitied[sx][sy] == 1) {
// 		return 0;
// 	}
// 	visitied[sx][sy] = 1;
// 	for (int i = 0;i < 4;i++) {
// 		int x = sx + dx[i]; int y = sy + dy[i];
// 		if (x >= 0 && x < n && y >= 0 && y < n) {
// 			if (!visitied[x][y] && arr[x][y] > height) {
// 				dfs(x, y, height);
// 			}
// 		}
// 	}
// 	return 1;
// }

// int main() {
// 	cin >> n;
// 	for (int i = 0;i < n;i++) {
// 		for (int j = 0;j < n;j++) {
// 			cin >> arr[i][j];
// 			if (arr[i][j] > _max) {
// 				_max = arr[i][j];
// 			}
// 		}
// 	}
// 	for (int k = 0;k <= _max;k++) {
// 		int cnt = 0;
// 		for (int i = 0;i < n;i++) {
// 			for (int j = 0;j < n;j++) {
// 				if (arr[i][j] > k)
// 				{
// 					if (dfs(i, j, k)) {
// 						cnt++;
// 					}
// 				}
// 			}
// 		}
// 		if (cnt > answer) {
// 			answer = cnt;
// 		}
// 		init();
// 	}
// 	cout << answer;
// }
#include <bits/stdc++.h>

using namespace std;

int N, jido[100][100], visitied[100][100], max_height=0, answer=0;
int dy[4]={-1,0,1,0}, dx[4]={0,1,0,-1};

void dfs(int y,int x,int height){
	visitied[y][x]=1;
	for (int i=0;i<4;i++){
		int ny=y+dy[i]; 
		int nx=x+dx[i];
		if (ny<0||nx<0||ny>=N||nx>=N) continue;
		if (visitied[ny][nx]||jido[ny][nx]<=height) continue;
		dfs(ny,nx,height);
	}
}

int main()
{	
	cin >> N;

	for (int i=0;i<N;i++){
		for (int j=0;j<N;j++){
			cin >> jido[i][j];
			max_height=max(max_height,jido[i][j]);
		}
	}

	for (int height=0;height<=max_height;height++){

		int cnt=0;
		fill(&visitied[0][0],&visitied[0][0]+(100*100),0);

		for (int i=0;i<N;i++){
			for (int j=0;j<N;j++){
				if (jido[i][j]>height&&!visitied[i][j]){
					dfs(i,j,height);
					cnt++;
				}

			}
		}

		answer=max(answer,cnt);
	}
	cout << answer;
}