#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string str, str_2;
    cin >> str >> str_2;
    int i=0;
    while(1){
        int idx=str.find(str_2,i);
        if (idx!=string::npos){
            str.erase(idx,str_2.length());
            i=idx-str_2.length();
            if (i<0){
                i=0;
            }
            //cout << str << "\n";   
        }
        else{
            break;
        }
    }
    if (!str.size()){
        cout << "FRULA";
    }
    else{
        cout << str;
    }
}