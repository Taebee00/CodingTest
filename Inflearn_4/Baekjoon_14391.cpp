#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M, h_mp[4][4],v_mp[4][4],mx=0;
    char num;
    cin >> N >> M;
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            cin >> num;
            h_mp[i][j]=num-'0';
            v_mp[j][i]=num-'0';
        }
    }
    for (int i=0;i<(1<<N*M);i++){
        int sum_sum=0;
        //cout << "i: " << i <<"\n";
        //cout << "horizontal\n";
        for (int j=0;j<N;j++){
            int sum=0;
            for (int k=0;k<M;k++){
                if (i&(1<<(j*M+k))){
                    sum=sum*10+h_mp[j][k];
                }
                else{
                    sum_sum+=sum;
                    sum=0;              
                }
            }
            sum_sum+=sum;
            //cout << sum_sum << "\n";
        }
        //cout << "vertical\n";
        for (int j=0;j<M;j++){
            int sum=0;
            for (int k=0;k<N;k++){
                if (!(i&(1<<(k*M+j)))){
                    sum=sum*10+v_mp[j][k];
                }
                else{
                    sum_sum+=sum;
                    sum=0;
                }
            }
            sum_sum+=sum;
            //cout << sum_sum << "\n";     
        }    
        if (sum_sum>mx){
            mx=sum_sum;
        }
    }
    cout << mx;
}