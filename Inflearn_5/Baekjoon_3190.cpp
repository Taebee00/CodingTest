#include <bits/stdc++.h>

using namespace std;

int N,K,L,second=0,dir_idx=0;
int mp[101][101]={0,};
vector<pair<int,char>> dir;
int dy[4]={0,1,0,-1}, dx[4]={1,0,-1,0};
queue<tuple<int,int,char>> tail_q;

int main()
{
    cin >> N >> K;
    for (int i=0;i<K;i++){
        int apple_y,apple_x;
        cin >> apple_y >> apple_x;
        mp[apple_y][apple_x]=2;
    }
    cin >> L;
    for (int i=0;i<L;i++){
        int temp_sec;
        char temp_dir;
        cin >> temp_sec >> temp_dir;
        dir.push_back({temp_sec,temp_dir});
    }
    int y=0,x=0,tail_y=0,tail_x=0,tail_dir=0,rotate_idx=0;
    mp[0][0]=1;
    while(1){
        //printf("%d,%d\n",y,x);
        second++;
        y+=dy[dir_idx];
        x+=dx[dir_idx];
        if (y<0||y>=N||x<0||x>=N||mp[y][x]==1){
            cout << second;
            break;
        }
        else if (!mp[y][x]){
            mp[y][x]=1;
            mp[tail_y][tail_x]=0;
            tail_y+=dy[tail_dir];
            tail_x+=dx[tail_dir];
        }
        else if (mp[y][x]==2){
            mp[y][x]=1;
        }
        if (rotate_idx<L&&dir[rotate_idx].first==second){
            if (dir[rotate_idx].second=='L'){
                dir_idx=(dir_idx-1)%4;
            }
            else{
                dir_idx=(dir_idx+1)%4;
            }
            tail_q.push(make_tuple(y,x,dir[rotate_idx].second));
            rotate_idx++;        
        }
        if (!tail_q.empty()&&get<0>(tail_q.front())==tail_y&&get<1>(tail_q.front())==tail_x){
            if (get<2>(tail_q.front())=='L'){
                tail_dir=(tail_dir-1)%4;
            }
            else{
                tail_dir=(tail_dir+1)%4;
            }
            tail_q.pop();
        }
    }
}