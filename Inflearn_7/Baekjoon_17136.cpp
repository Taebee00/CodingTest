#include <bits/stdc++.h>

using namespace std;

int mp[10][10], paper[6], visitied[10][10], num,ret=INT_MAX;
vector<pair<int,int>> v;

void recur(int n,int sz,int cnt){
    // 모두 가렸으면 paper 몇개 썼는지 ret에 저장
    if (cnt==num){
        int sum=0;
        for (int i=1;i<=5;i++){
            sum+=paper[i];
        }
        ret=min(ret,sum);
    }
    // n이 v.size 보다 크면 리턴
    if (n>=v.size()) return;
    // 선택된 종이를 이미 5개보다 많이 썼으면 리턴
    if (paper[sz]>=5) return;

    int y=v[n].first;
    int x=v[n].second;
    // 이미 (y,x) 방문했으면 리턴
    if (visitied[y][x]){
        recur(n+1,sz,cnt);
    }

    // sz*sz 정사각형에 맞지 않으면 리턴
    int sum=0;
    for (int i=0;i<sz;i++){
        for (int j=0;j<sz;j++){
            sum+=mp[y+i][x+j];
        }
    }
    if (sum!=sz*sz) return;

    // sz*sz 만큼 visitied 처리, 가린 종이 cnt++, 
    // paper++를 통해 종이 사용 표시
    if (y+sz-1>=10&&x+sz-1>=10) return;

    //printf("y:%d x:%d sz:%d cnt:%d\n",v[n].first,v[n].second,sz,cnt);
    for (int i=0;i<sz;i++){
        for (int j=0;j<sz;j++){
            visitied[y+i][x+j]=1;
            cnt++;
        }
    }
    paper[sz]++;

    // 다음 칸 재귀함수 호출
    for (int i=1;i<=5;i++){
        recur(n+1,i,cnt);
    }
    
    // 원상복구
    paper[sz]--;
    for (int i=0;i<sz;i++){
        for (int j=0;j<sz;j++){
            visitied[y+i][x+j]=0;
            cnt--;
        }
    }
}

int main()
{
    for (int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            cin >> mp[i][j];
            if (mp[i][j]){
                num++;
                v.push_back({i,j});
            }
        }
    }
    for (int i=1;i<=5;i++){
        recur(0,i,0);
    }
    cout << ret;
}