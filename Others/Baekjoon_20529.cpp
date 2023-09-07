#include <bits/stdc++.h>

using namespace std;

int T,N,mn=INT_MAX;
char mbti_arr[4]={'E','S','T','J'};
int mp[32];
vector<int> v;

// void bin(int n){
//     vector<int> bin_v;
//     while(n){
//         bin_v.push_back(n%2);
//         n/=2;
//     }
//     for (int i=bin_v.size()-1;i>=0;i--){
//         printf("%d",bin_v[i]);
//     }
//     printf(" ");
// }

int cal(int i,int j){
    int sum=0;
    int dist=i^j;
    //bin(dist);
    for (int i=0;i<4;i++){
        if (dist&(1<<i)) sum++;
    }
    return sum;
}




int main()
{
    cin >> T;
    for (int i=0;i<T;i++){
        v.clear();
        cin >> N; 
        for (int j=0;j<N;j++){
            string str;
            int temp=0;
            cin >> str;
            for (int i=0;i<4;i++){
                if (str[i]==mbti_arr[i]){
                    temp|=1<<3-i;
                }
            }
            if (mp[temp]<3){
                mp[temp]++;
                v.push_back(temp);
            }           
        }
        int ret=INT_MAX;
        for (int j=0;j<v.size();j++){
            for (int k=j+1;k<v.size();k++){
                for (int l=k+1;l<v.size();l++){
                    ret=min(ret,cal(v[j],v[k])+cal(v[k],v[l])+cal(v[j],v[l]));
                }
            }
        }
        printf("%d\n",ret);
    }
}