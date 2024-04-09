#include <bits/stdc++.h>

using namespace std;

int dy[4]={-1,0,1,0}, dx[4]={0,1,0,-1};

int N, M, visitied[101][101]={0,};
char miro[101][101];

void bfs(int y, int x){
	queue<pair<int,int>> que;

	visitied[y][x]=1;
	que.push({y,x});

	while(que.size()){
		int qy, qx, ny, nx;
		tie(qy,qx)=que.front();
		que.pop();

		for (int i=0;i<4;i++){
			ny=qy+dy[i];
			nx=qx+dx[i];
			if (miro[ny][nx]=='0') continue;
			if (ny<1||nx<1||ny>N||nx>M) continue;
			if (visitied[ny][nx]) continue;
			visitied[ny][nx]=visitied[qy][qx]+1;
			que.push({ny,nx});
		}
	}
}

int main()
{
	cin >> N >> M;
	
	for (int i=1;i<=N;i++){
		for (int j=1;j<=M;j++){
			cin >> miro[i][j];
		}
	}

	bfs(1,1);

	cout << visitied[N][M];
}