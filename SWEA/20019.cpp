#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int i=0;i<T;i++){
        int flag=1;
        string str;
        cin >> str;
        string a=str.substr(0,str.size()/2);
        string b=str.substr(str.size()/2+1,str.size()-1);
        string temp=a;
        reverse(a.begin(),a.end());
        if (a!=temp){
            flag=0;
        }
        temp=b;
        reverse(b.begin(),b.end());
        if (b!=temp){
            flag=0;
        }
        temp=str;
        reverse(str.begin(),str.end());
        if (str!=temp){
            flag=0;
        }
        if (flag) printf("#%d YES\n",i+1);
        else printf("#%d NO\n",i+1);
    }
}