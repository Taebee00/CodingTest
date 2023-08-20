#include <bits/stdc++.h>

using namespace std;

typedef struct _shark{
    int y;
    int x;
    bool exist=0;
    int speed;
    int dir;
    int sz;
}shark;

int dy[4]={-1,1,0,0},dx[4]={0,0,1,-1};
int R,C,M,sum=0;
shark mp[101][101];
vector <shark> shark_v;

void fishing(int i){
    for (int j=1;j<=R;j++){
        if (mp[j][i].exist){
            sum+=mp[j][i].sz;
            mp[j][i].exist=0;
            shark_v.erase(find_if(shark_v.begin(),shark_v.end(),mp[j][i]));
            printf("%d fishing - sz: %d sum: %d\n", i,mp[j][i].sz,sum);
            return;
        }
    }
}

void move(){
    vector<shark> temp_v;
    for (auto&i:shark_v){
        printf("%d %d move\n",i.y,i.x);
        pair<int,int> temp;
        temp.first=i.y; temp.second=i.x;
        int cnt=i.speed;
        while(cnt--){
            if (temp.first+dy[i.dir]==0||temp.first+dy[i.dir]==R+1){
                i.dir=i.dir==0?1:0;
            }
            else if (temp.second+dx[i.dir]==0||temp.second+dx[i.dir]==C+1){
                i.dir=i.dir==2?3:2;
            }
            temp.first+=dy[i.dir];
            temp.second+=dx[i.dir];
            printf("%d %d -> ",temp.first,temp.second);
        }
        i.y=temp.first;
        i.x=temp.second;
        temp_v.push_back(i);
        printf("\n");
    }
    printf("\n");
    for (int i=1;i<=R;i++){
        for (int j=1;j<=C;j++){
            mp[i][j].exist=0;
        }
    }
    shark_v.clear();
    for (auto&i:temp_v){
        if (mp[i.y][i.x].exist&&mp[i.y][i.x].sz>i.sz){
            continue;
        }
        mp[i.y][i.x]=i;
        shark_v.push_back(i);
    }
}

int main(){
    
    cin >> R >> C >> M;

    for (int i=0;i<M;i++){
        int r,c,s,d,z;
        cin >> r >> c >> s >> d >> z;
        mp[r][c]={r,c,1,s,d-1,z};
        shark_v.push_back(mp[r][c]);
    }

    for (int j=1;j<=R;j++){
        for (int k=1;k<=C;k++){
            if (mp[j][k].exist){
                printf("%d ",mp[j][k].sz);
            }
            else{
                printf("0 ");
            }
        }
        printf("\n");
    }
    printf("\n");

    for (int i=1;i<=C;i++){
        fishing(i);
        move();

        for (int j=1;j<=R;j++){
            for (int k=1;k<=C;k++){
                if (mp[j][k].exist){
                    printf("%d ",mp[j][k].sz);
                }
                else{
                    printf("0 ");
                }
            }
            printf("\n");
        }
        printf("\n");
    }
    cout << sum;
}