#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    priority_queue<float,vector<float>,greater<float>> pq;
    cin >> N;
    for (int i=0;i<N;i++){
        float temp;
        cin >> temp;
        pq.push(temp);
    }
    for (int i=0;i<7;i++){
        printf("%.3f\n",pq.top());
        pq.pop();
    }
}