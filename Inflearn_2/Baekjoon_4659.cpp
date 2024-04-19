#include <bits/stdc++.h>

using namespace std;

int bowl_arr[26]={0,};

bool isbowl(char chr){
    return bowl_arr[chr-'a'];
}

int main()
{
    bowl_arr['a'-'a']=1;
    bowl_arr['e'-'a']=1;
    bowl_arr['i'-'a']=1;
    bowl_arr['o'-'a']=1;
    bowl_arr['u'-'a']=1;

    string str;
    while(1){
        int flag=0;
        cin >> str;
        if (str=="end"){
            break;
        }
        for (int i=0;i<str.length();i++){
            if (isbowl(str[i])==true){
                flag=1;
            }   
            if (i>=2&&isbowl(str[i])&&isbowl(str[i-1])&&isbowl(str[i-2])){
                flag=0;
                break;
            }
            if (i>=2&&!isbowl(str[i])&&!isbowl(str[i-1])&&!isbowl(str[i-2])){
                flag=0;
                break;
            }
            if ((i>=1&&str[i]==str[i-1])&&(str[i]!='e'&&str[i]!='o')){
                flag=0;
                break;
            }
        }
        if (flag){
            printf("<%s> is acceptable.\n",str.c_str());
        }
        else printf("<%s> is not acceptable.\n",str.c_str());
    }
}