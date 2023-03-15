#include <bits/stdc++.h>
using namespace std;

typedef struct _info{
    int min;
    int sec;
    int team;
}info;

int main(){
    int num, team, min, sec, score=0, minsec, minsec_s;
    int minsec_1=0,minsec_2=0;
    string time;
    info info_arr[100];
    cin >> num;
    for (int i=0;i<num;i++){
        cin >> team >> time;
        min=atoi(time.substr(0,time.find(':')).c_str());
        sec=atoi(time.substr(time.find(':')+1,time.size()).c_str());
        minsec=min*60+sec;
        if (team==1&&score==0){
            minsec_s=minsec;
        } 
        else if (team==2&&score==0){
            minsec_s=minsec;    
        }
        else if (team==1&&score==-1){
            minsec_2+=minsec-minsec_s;
        }
        else if (team==2&&score==1){
            minsec_1+=minsec-minsec_s;
        }
        team==1?score++:score--;
        if (i==num-1&&score){
            if (score>0){
                minsec_1+=48*60-minsec_s;
            }
            else{
                minsec_2+=48*60-minsec_s;
            }
        }
    }
    printf("%02d:%02d\n", minsec_1/60, minsec_1%60);
    printf("%02d:%02d\n", minsec_2/60, minsec_2%60);
}