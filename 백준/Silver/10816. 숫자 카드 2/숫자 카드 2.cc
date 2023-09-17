#include <bits/stdc++.h>

using namespace std;

unordered_map<int,int> mp;

int main()
{
    int N, M;
    cin >> N;
    for (int i=0;i<N;i++){
        int temp;
        scanf("%d",&temp);
        mp[temp]++;
    }
    cin >> M;
    for (int i=0;i<M;i++){
        int temp;
        scanf("%d",&temp);
        
        printf("%d ",mp[temp]);
    }

}