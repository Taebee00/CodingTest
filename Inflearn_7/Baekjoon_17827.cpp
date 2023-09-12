#include <bits/stdc++.h>

using namespace std;

struct horse{
    int num;
    int y;
    int x;
    int dir;
};

int N,K,dy[4]={0,0,-1,1},dx[4]={1,-1,0,0};
pair<int,vector<struct horse>> mp[13][13];
struct horse arr[11];

int main()
{
    cin >> N >> K;
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            cin >> mp[i][j].first;
        }
    }
    for (int i=0;i<K;i++){
        int y,x,dir;
        cin >> y >> x >> dir;
        struct horse temp={i,y-1,x-1,dir-1};
        arr[i]=temp;
        mp[y-1][x-1].second.push_back(temp);
    }
    int tm=1;
    while(tm<=1000){
        // 0부터 k까지 반복
        for (int i=0;i<K;i++){
            // next에 이동할 좌표 저장
            int y=arr[i].y;
            int x=arr[i].x;
            int next_y=arr[i].y+dy[arr[i].dir];
            int next_x=arr[i].x+dx[arr[i].dir];
            printf("loc: %d %d\n",arr[i].y+1,arr[i].x+1);
            
            // 이동할 좌표가 파란색이거나 범위를 벗어나면 방향만 일단 반대로 바꿔줌
            if (mp[next_y][next_x].first==2||(next_y<0||next_y>=N||next_x<0||next_x>=N)){
                arr[i].dir=arr[i].dir%2==0?arr[i].dir+1:arr[i].dir-1;
                next_y=arr[i].y+dy[arr[i].dir];
                next_x=arr[i].x+dx[arr[i].dir];
            }
            printf("next_loc: %d %d\n",next_y+1,next_x+1);
            // 이동할 좌표가 흰색
            if (mp[next_y][next_x].first==0){
                // mp의 이전좌표 요소들을 mp의 next 좌표 요소에 push
                // 이동 좌표 요소들 위치 및 방향 업데이트
                for (auto &j:mp[arr[i].y][arr[i].x].second){
                    j.y=next_y;
                    j.x=next_x;
                    mp[next_y][next_x].second.push_back(j);
                    arr[j.num]={j.num,next_y,next_x,j.dir};
                }
                // 이전좌표 요소들 제거
                mp[y][x].second.clear();
            }
            else if (mp[next_y][next_x].first==1){
                reverse(mp[arr[i].y][arr[i].x].second.begin(),mp[arr[i].y][arr[i].x].second.end());
                for (auto &j:mp[arr[i].y][arr[i].x].second){
                    mp[next_y][next_x].second.push_back(j);
                    arr[j.num]={j.num,next_y,next_x,j.dir};
                }
                mp[y][x].second.clear();
            }
            else if (mp[next_y][next_x].first==2||(next_y<0||next_y>=N||next_x<0||next_x>=N)){
                next_y=arr[i].y;
                next_x=arr[i].x;
                for (auto &j:mp[arr[i].y][arr[i].x].second){
                    arr[j.num]={j.num,next_y,next_x,j.dir};
                }
            }      
            if (mp[next_y][next_x].second.size()==4){
                cout << tm;
                return 0;
            }
            for (int j=0;j<N;j++){
                for (int k=0;k<N;k++){
                    printf("%d ",mp[j][k].second.size());
                }
                printf("\n");
            }
        }
        tm++;
    }
    cout << -1;

}