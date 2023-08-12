#include <bits/stdc++.h>

using namespace std;

string str, str_2;
stack<int> stk;
vector<int> erase_v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> str >> str_2;
    
    for (int i=0;i<str.length();i++){
        if (stk.size()){
            //printf("%d %d %c %c\n",stk.top(),str_2.length(),str[i],str_2[stk.top()+1]);
        }
        if (str[i]==str_2[0]){
            //printf("1");
            stk.push(0);
            if (str_2.length()==1){
                str.erase(str.begin()+i);
            }
        }
        else if (stk.size()&&stk.top()+1<str_2.length()&&str[i]==str_2[stk.top()+1]){
            //printf("2");
            stk.push(stk.top()+1);
            if (stk.top()==str_2.length()-1){
                for (int j=0;j<str_2.length();j++){
                    str.erase(str.begin()+i-j);
                    stk.pop();
                }
                i-=str_2.length();
            }           
        }
        else{
            //printf("3");
            while(stk.size()){              
                stk.pop();
            }
        }
    }
    if (str.size()) cout << str;
    else cout << "FRULA";
}