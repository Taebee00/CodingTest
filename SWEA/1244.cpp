#include<bits/stdc++.h>

using namespace std;

string temp_str;
vector<string> v;

void temp_swap(string &str,int a,int b){
    char temp=str[a];
    str[a]=str[b];
    str[b]=temp;
}

void dfs(int cnt,int sz,string &str){
    if (cnt==0){
        v.push_back(str);
        return;
    }
    for (int i=0;i<sz-1;i++){
        for (int j=i+1;j<sz;j++){
            temp_swap(str,i,j);
            dfs(cnt-1,sz,str);
            temp_swap(str,i,j);
        }
    }
}

bool cmp(const string a,const string b){
    return a>b;
}

int main(int argc, char** argv)
{
    int N;
    cin >> N;
    for (int i=0;i<N;i++){
        string str; int cnt;
        v.clear();
        cin >> str >> cnt;
        dfs(cnt,str.size(),str);
        sort(v.begin(),v.end(),cmp);
        printf("#%d %s\n",i+1,v[0].c_str());
    }
}