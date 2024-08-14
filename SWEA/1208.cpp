#include <bits/stdc++.h>

using namespace std;

int main()
{
    for (int i=1;i<=10;i++){
        int num, answer; vector<int> v;
        cin >> num;
        for (int j=0;j<100;j++){
            int height;
            cin >> height;
            v.push_back(height);
        }
        sort(v.begin(),v.end());
        for (int j=0;j<num;j++){
            int mx=*(v.end()-1);
            int mn=*(v.begin());
            *v.begin()=mn+1;
            *(v.end()-1)=mx-1;
            sort(v.begin(),v.end());
            if (mx-mn<=1) break;
        }
        if (answer>1) answer=*(v.end()-1)-*v.begin();
        printf("#%d %d\n",i,answer);
    }
}