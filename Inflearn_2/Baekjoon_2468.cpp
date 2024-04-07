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