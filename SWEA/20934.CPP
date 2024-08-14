#include <bits/stdc++.h>

using namespace std;

int T;

int main()
{
    cin >> T;
    for (int i=0;i<T;i++){
        string str; int cnt;
        cin >> str >> cnt;
        int idx=str.find('o');
        if (cnt==0){
            printf("#%d %d\n",i+1,idx);
        }
        else if (idx==1){
            if (cnt%2) printf("#%d 0\n",i+1);
            else printf("#%d 1\n",i+1);
        }
        else{
            if (cnt%2) printf("#%d 1\n",i+1);
            else printf("#%d 0\n",i+1);
        }
    }
}