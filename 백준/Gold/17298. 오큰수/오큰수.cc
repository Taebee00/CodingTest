#include <bits/stdc++.h>

using namespace std;

int N, answer[1000001];
stack<pair<int,int>> stk;

int main(){
    
    cin >> N;
    fill(answer,answer+N,-1);
    for (int i=0;i<N;i++){
        int temp;
        cin >> temp;
        while (stk.size()&&stk.top().second<temp){
            answer[stk.top().first]=temp;
            stk.pop();
        }
        stk.push({i,temp});
        
    }
    for (int i=0;i<N;i++){
        printf("%d ",answer[i]);
    }
}