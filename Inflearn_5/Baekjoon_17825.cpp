#include <bits/stdc++.h>

using namespace std;

typedef struct _horse{
    int val;
    int dir;
    int finish=0;
}horse;

int cnt=0;
int one[9]={10,13,16,19,25,30,35,40,41};
int two[9]={30,28,27,26,25,30,35,40,41};
int three[8]={20,22,24,25,30,35,40,41};
int dice[10];
int sum,ret=0;
vector<int> choose_v;
vector<int> ret_v;
vector<int> temp_v;
horse horses[4];

int go(horse& a,int speed){
    if (a.finish){
        return 0;
    }
    if (a.val==10){
        a.dir=1;
    }
    else if (a.val==30&&a.dir==0){
        a.dir=2;
    }
    else if (a.val==20){
        a.dir=3;
    }
    if (a.dir==0){
        for (int i=0;i<4;i++){
            if (a.val+2*speed==horses[i].val&&a.dir==horses[i].dir&&a.val+2*speed<=40){
                return 0;
            }
        }
        a.val+=2*speed;
        if (a.val>40){
            a.finish=1;
        }
    }
    if (a.dir==1){
        if (find(one,one+8,a.val)-one+speed<9){
            for (int i=0;i<4;i++){
                if (one[find(one,one+8,a.val)-one+speed]==horses[i].val&&a.dir==horses[i].dir){
                    return 0;
                }
            }
            a.val=one[find(one,one+8,a.val)-one+speed];
        }
        else{
            a.val=41;
            a.finish=1;
        }
    }
    else if (a.dir==2){
        if (find(two,two+8,a.val)-two+speed<9){
            for (int i=0;i<4;i++){
                if (two[find(two,two+8,a.val)-two+speed]==horses[i].val&&a.dir==horses[i].dir){
                    return 0;
                }
            }
            a.val=two[find(two,two+8,a.val)-two+speed];
        }
        else{
            a.val=41;
            a.finish=1;
        }
    }
    else if (a.dir==3){
        if (find(three,three+7,a.val)-three+speed<8){
            for (int i=0;i<4;i++){
                if (three[find(three,three+7,a.val)-three+speed]==horses[i].val&&a.dir==horses[i].dir){
                    return 0;
                }
            }
            a.val=three[find(three,three+8,a.val)-three+speed];
        }
        else{
            a.val=41;
            a.finish=1;
        }
    }
    if (a.val<=40){
        sum+=a.val;
        temp_v.push_back(a.val);
    }
    return 1;
}

void choose(int sz)
{
    // if (cnt%100==0){
    //     cout << cnt << "\n";
    // }
    if (sz==10){
        for (int i=0;i<4;i++){
            horses[i].val=0;
            horses[i].dir=0;
            horses[i].finish=0;
        }
        sum=0;
        temp_v.clear();
        for (int i=0;i<10;i++){
            int temp=go(horses[choose_v[i]],dice[i]);
            if (!temp){
                break;
            }          //printf("horse:%d, dice:%d location: %d\n",choose_v[i],dice[i],horses[choose_v[i]].val);
        }
        //printf("-----------------\n");
        //cout << sum << "\n";
        
        if (sum>ret){
            ret=sum;
            ret_v.clear();
            ret_v=choose_v;
        }
        //ret=max(sum,ret);
        return;
    }
    for (int i=0;i<4;i++){
        choose_v.push_back(i);
        choose(sz+1);
        choose_v.pop_back();
    }
}

int main()
{
    for (int i=0;i<10;i++){
        cin >> dice[i];
    }
    choose(0);
    cout << ret;
    cout << "\n";
    for (auto&i:ret_v){
        printf("%d ",i);
    }
}