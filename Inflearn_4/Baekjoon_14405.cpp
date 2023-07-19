#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    string str_arr[3]={"pi","ka","chu"};
    cin >> str;
    int idx=0;
    while(idx<str.length())
    {
        int flag=0;
        for (int i=0;i<3;i++){
            if (str.find(str_arr[i],idx)==idx){
                flag=str_arr[i].length();             
                break;
            }
        }
        if (flag){
            idx+=flag;
        }
        else{
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}