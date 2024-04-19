#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, T, five=0;
    vector<int> answer;

    cin >> T;

    for (int i=0;i<T;i++){
        cin >> N;
        five=0;
        for (int j=1;j<=N;j++){
            int temp=j;
            while(temp%5==0){
                temp/=5;
                five++;
            }
        }
        answer.push_back(five);
    }
    for (int i:answer) cout << i << "\n";
}