#include <bits/stdc++.h>

using namespace std;

int N, arr[100001]={0,}; 
long long answer=0;
deque<int> deq;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i=0;i<N;i++){
        int num;
        cin >> num;
        if (arr[num])
        arr[num]=i;
        for (auto j=deq.end()-2;j>=deq.begin()&&deq.size()>1;j--){
            if (*j==num){
                deq.erase(deq.begin(),j+1);
                break;
            }
        }
        answer+=deq.end()-deq.begin();
    }
    cout << answer;
}