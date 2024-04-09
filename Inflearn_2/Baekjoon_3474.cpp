#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, T, two=0, five=0;
    vector<int> answer;

    cin >> T;

    for (int i=0;i<T;i++){
        cin >> N;
        for (int i=1;i<=N;i++){
            int temp=i;
            while (temp%2==0){
                temp/=2;
                two++;
            }
            while(temp%5==0){
                temp/=5;
                five++;
            }
        }
        answer.push_back(min(five,two));
    }
    for (int i:answer) cout << i << "\n";
}