#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T,N,M;
    cin >> T;
    for (int i=0;i<T;i++){
        cin >> N;
        vector<int> v1;
        for (int j=0;j<N;j++){
            int temp;
            cin >> temp;
            v1.push_back(temp);
        }
        cin >> M;
        vector<int> v2;
        for (int j=0;j<M;j++){
            int temp;
            cin >> temp;
            v2.push_back(temp);
        }
        sort(v1.begin(),v1.end());
        for (int&j:v2){
            int left=0;
            int right=v1.size()-1;
            int flag=0;
            while (left<=right){
                int mid=(left+right)/2;
                if (v1[mid]<j){
                    left=mid+1;
                }
                else if (v1[mid]>j){
                    right=mid-1;
                }
                else{
                    flag=1;
                    break;
                }
            }
            if (flag) printf("1\n");
            else printf("0\n");
        }   
    }
    
}