#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T,N,M;
    cin >> T;
    for (int i=0;i<T;i++){
        cin >> N >> M;
        vector<int> nv;
        for (int j=0;j<N;j++){
            int temp;
            cin >> temp;
            nv.push_back(temp);
        }
        sort(nv.begin(),nv.end());

        vector<int> mv;
        for (int j=0;j<M;j++){
            int temp;
            cin >> temp;
            mv.push_back(temp);
        }
        sort(mv.begin(),mv.end());
        
        int idx=0,ret=0;
        for (int j=0;j<nv.size();j++){
            int flag=0;
            while(idx<M&&mv[idx]<nv[j]){
                idx++;
                flag=1;
            }
            if (flag){
                
                ret+=idx;
                idx--;
            }
        }
        printf("%d\n",ret);
    }
}