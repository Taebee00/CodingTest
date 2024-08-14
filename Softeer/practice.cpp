#include <bits/stdc++.h>
using namespace std;

int N, arr[10][10], visitied[10][10]={0,}, cnt=0;
int dy[4]={-1,0,1,0}, dx[4]={0,1,0,-1};
vector<int> v;

int dfs(int y,int x){
	int sum=1;
	visitied[y][x]=1;
	for (int i=0;i<4;i++){
		int ny=y+dy[i];
		int nx=x+dx[i];
        if (ny<0||nx<0||ny>=N||nx>=N||visitied[ny][nx]||!arr[ny][nx]) continue;
		sum+=dfs(ny,nx);
	}
	return sum;
}

int main() {

	cin >> N;

	for (int i=0;i<N;i++){
		for (int j=0;j<N;j++){
			cin >> arr[i][j];
		}
	}
	for (int i=0;i<N;i++){
		for (int j=0;j<N;j++){
			if (arr[i][j]&&!visitied[i][j]){
				cnt++;
				v.push_back(dfs(i,j));
			}
		}
	}
    sort(v.begin(),v.end());
	cout << cnt << "\n";
	for (int i:v) cout << i << " ";
}