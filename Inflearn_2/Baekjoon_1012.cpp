#include <bits/stdc++.h>

using namespace std;

int TC, M, N, K, baechu[51][51], visitied[51][51];
int dy[4]={-1,0,1,0}, dx[4]={0,1,0,-1};
vector<int> answer_v;

void dfs(int y,int x){
	visitied[y][x]=1;
	for (int i=0;i<4;i++){
		int ny=y+dy[i];
		int nx=x+dx[i];
		if (ny<0||nx<0||ny>=N&&nx>=M) continue;
		if (visitied[ny][nx]||!baechu[ny][nx]) continue;
		dfs(ny,nx);
	}
}

int main()
{
	cin >> TC;

	for (int i=0;i<TC;i++){
		
		int cnt=0;
		cin >> M >> N >> K;
		fill(&baechu[0][0],&baechu[0][0]+51*51,0);
		fill(&visitied[0][0],&visitied[0][0]+51*51,0);
		
		for (int i=0;i<K;i++){
			int y, x;
			cin >> x >> y;	
			baechu[y][x]=1;
		}

		for (int i=0;i<N;i++){
			for (int j=0;j<M;j++){
				if (baechu[i][j]&&!visitied[i][j]){
					cnt++;
					dfs(i,j);
				}
			}
		}
		answer_v.push_back(cnt);
	}
	for (int i:answer_v){
		cout << i << " ";
	}
}