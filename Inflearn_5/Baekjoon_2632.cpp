#include <bits/stdc++.h>

using namespace std;

int main()
{
    int sz,A_sz,B_sz;
    int A[1000],B[1000],sum_A[1000],sum_B[1000];
    cin >> sz >> A_sz >> B_sz;
    sum_A[0]=A[0];
    sum_B[0]=B[0];   
    for (int i=0;i<A_sz;i++){
        cin >> A[i];
        if (i>0){
            sum_A[i]=sum_A[i-1]+A[i];
        }
    }
    for (int i=0;i<B_sz;i++){
        cin >> B[i];
        if (i>0){
            sum_B[i]=sum_B[i-1]+B[i];
        }
    }
    for (int i=0;i<=sz;i++){
        for (int j=0;j<A_sz;j++){
            for (int k=)
        }
    }
}