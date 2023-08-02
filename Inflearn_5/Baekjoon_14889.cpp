#include <bits/stdc++.h>

using namespace std;

int N, s[20][20], team[20], mn=INT_MAX;
vector<int> v;

int cal(){
    int team_1=0, team_2=0;
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            if (team[i]==0&&team[j]==0){
                team_1+=s[i][j];
            }
            else if (team[i]==1&&team[j]==1){
                team_2+=s[i][j];
            }  
        }
    }
    return abs(team_1-team_2);
}

void choose(int cnt, int choice)
{
    if (cnt==N/2){
        // for (auto&i:v){
        //     printf("%d ",i);
        // }
        // printf("\n");
        int temp=cal();
        if (temp<mn){
            mn=temp;
        }
        return;
    }
    for (int i=choice+1;i<N;i++){
        team[i]=1;
        choose(cnt+1,i);
        team[i]=0;
    }
}

int main()
{
    cin >> N;
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            cin >> s[i][j];
        }
    }
    choose(0,-1);
    cout << mn;
}