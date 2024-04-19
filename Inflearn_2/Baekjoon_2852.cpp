#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, win_time[3]={0,}, score[3]={0,};

    struct info{
        int team;
        int time;
    };

    struct info info_arr[101];

    cin >> N;

    for (int i=1;i<=N;i++){
        int time,minute;
        scanf("%d %02d:%02d",&info_arr[i].team,&time,&minute);
        info_arr[i].time=time*60+minute;
    }

    for (int i=1;i<=N;i++){
        if (score[1]>score[2]){
            win_time[1]+=(info_arr[i].time-info_arr[i-1].time);
        }
        else if (score[1]<score[2]){
            win_time[2]+=(info_arr[i].time-info_arr[i-1].time);
        }
        score[info_arr[i].team]++;
    }
    if (score[1]>score[2]){
        win_time[1]+=(48*60-info_arr[N].time);
    }
    else if (score[1]<score[2]){
        win_time[2]+=(48*60-info_arr[N].time);
    }

    printf("%02d:%02d\n%02d:%02d",win_time[1]/60,win_time[1]%60,win_time[2]/60,win_time[2]%60);
}