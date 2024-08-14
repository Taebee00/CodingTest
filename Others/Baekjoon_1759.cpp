#include <bits/stdc++.h>

using namespace std;

int L, C, visitied[30]={0,}, vowl_sz=0, non_vowl_sz=0;
vector<char> v, chosen_v;
char vowl[5]={'a','e','i','o','u'};
vector<vector<char>> answer_v; 

bool IsVowl(char a){
    bool flag=false;
    for (int i=0;i<5;i++){
        if (vowl[i]==a){
            flag=true;
            break;
        }
    }
    return flag;
}

void dfs(int sz){
    if (sz==L){
        if (vowl_sz>=1&&non_vowl_sz>=2){
            answer_v.push_back(chosen_v);
        }
        return;
    }
    for (char i:v){
        if (sz==0||(!visitied[i-'a']&&sz>0&&chosen_v[sz-1]<i)){
            visitied[i-'a']=1;
            chosen_v.push_back(i);
            if (IsVowl(i)) vowl_sz++;
            else non_vowl_sz++;
            dfs(sz+1);
            visitied[i-'a']=0;
            chosen_v.pop_back();
            if (IsVowl(i)) vowl_sz--;
            else non_vowl_sz--;
        }
    }
}

int main()
{
    
    cin >> L >> C;

    for (int i=0;i<C;i++){
        char temp;
        cin >> temp;
        v.push_back(temp);
    }

    dfs(0);
    sort(answer_v.begin(),answer_v.end());
    
    for (auto i:answer_v){
        for (auto j:i) cout << j;
        cout << "\n";
    }
}