#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N; double mx=0;
    vector<double> v;
    cin >> N;

    for (int i=0;i<N;i++){
        double num;
        cin >> num;
        v.push_back(num);
    }
    
    double sum=1;
    for (double i:v){
        if (sum<1) sum=1;
        sum*=i;
        if (sum>mx) mx=sum;
    }
    if (sum>mx) mx=sum;

    printf("%.3f",mx);
}