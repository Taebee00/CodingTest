#include <bits/stdc++.h>

using namespace std;

int main()
{
    int TC;
    cin >> TC;
    for (int i=1;i<=TC;i++){
        int N; string str;
        cin >> N >> str;
        if (str.size()%2==0&&str.substr(0,str.size()/2)==str.substr(str.size()/2,str.size())){
            printf("#%d Yes\n",i);
        }
        else printf("#%d No\n",i);
    }
}