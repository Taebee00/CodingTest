#include <bits/stdc++.h>

using namespace std;

int N, scv[3]={0,}, visitied[61][61][61]={0,};
int arr[6][3]={{1,3,9},{1,9,3},{3,1,9},{3,9,1},{9,1,3},{9,3,1}};
struct scv_struct{
    int a;
    int b;
    int c;
};

int bfs(int a,int b,int c){
    queue<scv_struct> que;
    visitied[a][b][c]=1;
    que.push({a,b,c});
    while(que.size()){
        scv_struct temp;
        temp=que.front();
        que.pop();
        //printf("%d %d %d\n",temp.a,temp.b,temp.c);
        for (int i=0;i<6;i++){
            int na=max(0,temp.a-arr[i][0]);
            int nb=max(0,temp.b-arr[i][1]);
            int nc=max(0,temp.c-arr[i][2]);
            if (visitied[na][nb][nc]) continue;
            visitied[na][nb][nc]=visitied[temp.a][temp.b][temp.c]+1;
            if (!na&&!nb&&!nc){
                return visitied[na][nb][nc]-1;
            }
            que.push({na,nb,nc});
        }
    }
}

int main()
{
    cin >> N;
    
    for (int i=0;i<N;i++){
        cin >> scv[i];
    }

    cout << bfs(scv[0],scv[1],scv[2]);
}