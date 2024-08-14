#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int M, S=0;
    cin >> M;
    vector<char> v;

    for (int i=0;i<M;i++){
        string str;
        int num;
        cin >> str;
        if (str=="all"){
            S=(1<<20)-1;
            continue;
        }
        else if (str=="empty"){
            S=0;
            continue;
        }
        cin >> num;
        if (str=="add"){
            S|=(1<<num-1);
        }
        else if (str=="remove"){
            S&=~(1<<num-1);
        }
        else if (str=="check"){
            if (S&(1<<num-1)) cout << "1\n";
            else cout << "0\n";
        }
        else if (str=="toggle"){
            S^=(1<<num-1);
        }   
        
    }
    for (int i:v) cout << i << "\n";
}