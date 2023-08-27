#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef struct _node{
    int who;
    ll ATK;
    ll HP;
}node;

int N, M;
ll ret=LONG_LONG_MAX;
node mp[123456];

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N >> M;
    for (int i=0;i<N;i++){
        cin >> mp[i].who >> mp[i].ATK >> mp[i].HP;
    }
    ll low=1; ll high=123456*1000000;
    while(low<=high){
        ll mid=(low+high)/2;
        node temp={0,M,mid};
        for (int i=0;i<N;i++){
            node temp_mp=mp[i];
            if (temp_mp.who==1){
                int cnt=temp_mp.HP/temp.ATK+(temp_mp.HP%temp.ATK?1:0);
                temp.HP-=(cnt-1)*temp_mp.ATK;
                if (temp.HP<=0){
                    low=mid+1;
                    break;
                }
            }
            else{
                temp.HP+=temp_mp.HP;
                if (temp.HP>mid){
                    temp.HP=mid;
                }
                temp.ATK+=temp_mp.ATK;
            }
            if (i==N-1){
                high=mid-1;
                ret=min(mid,ret);
            }
        }
    }
    cout << ret;
}