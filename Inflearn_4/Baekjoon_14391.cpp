#include <bits/stdc++.h>

using namespace std;

int N, M, mx=0, visitied[4][4]={0,}, ver_hor[4][4];
int dy[4]={-1,0,1,0}, dx[4]={0,1,0,-1};
char arr[4][4];
vector<int> max_v;
int max_idx;

int main()
{
    cin >> N >> M;

    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            cin >> arr[i][j];
        }
    }

    for (int i=0;i<1<<N*M;i++){
        fill(&visitied[0][0],&visitied[0][0]+16,0);
        for (int j=0;j<N;j++){
            for (int k=0;k<M;k++){
                if (i&(1<<(M*j+k))) ver_hor[j][k]=1;
                else ver_hor[j][k]=0;
            }
        }
        vector<int> v;
        for (int j=0;j<N;j++){
            for (int k=0;k<M;k++){
                string str;
                int y=j,x=k;
                while (i&(1<<(y*M+k))&&x<M&&!visitied[y][x]){
                    visitied[y][x]=1;
                    str+=arr[y][x];
                    x++;
                }
                while ((i&(1<<(y*M+k)))==0&&y<N&&!visitied[y][x]){
                    visitied[y][x]=1;
                    str+=arr[y][x];
                    y++;
                }
                v.push_back(atoi(str.c_str()));
            }
        }
        int sum=0;
        for (int i:v) sum+=i;
        mx=max(mx,sum);
    }
    cout << mx;
}