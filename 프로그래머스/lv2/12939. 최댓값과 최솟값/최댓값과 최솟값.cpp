#include <string>
#include <vector>

using namespace std;

string casting(int num){
    string str;
    int pos=1;
    if (num<0){
        pos=0;
        num*=-1;
    }
    while(num!=0){
        str+=(num%10)+'0';
        num/=10;
    }
    string answer;
    if (!pos) answer+='-';
    for (int i=str.size()-1;i>=0;i--){
        answer+=str[i];
    }
    return answer;
}

string solution(string s) {
    string answer = "";
    int idx=0,num=0,mx=-1e8,mn=1e8;
    while(idx<s.size()){
        if (s[idx]=='-'){
            idx++;
            num=-1*(s[idx]-'0');
        }
        else if (s[idx]!=' '){
            num=num>=0?num*10+s[idx]-'0':num*10-(s[idx]-'0');
        }
        if (s[idx]==' '||idx==s.size()-1){
            mx=max(mx,num);
            mn=min(mn,num);
            num=0;
        }
        idx++;
    }
    answer+=casting(mn)+" "+casting(mx);
    return answer;
}