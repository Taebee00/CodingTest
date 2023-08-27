#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<double> v;
    double mx=0;
    double multi=1;
    for (int i=0;i<N;i++){
        double temp;
        cin >> temp;
        v.push_back(temp);
        if (multi*temp>=1){
            multi*=temp;
            mx=max(mx,multi);
        }
        else{
            mx=max(mx,temp);
            multi=1;
        }
    }
    printf("%.3f",mx);
}