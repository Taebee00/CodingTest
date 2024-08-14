#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int D, K;

bool query(int lev,int prev_num,int num){
    //cout << lev << " " << prev_num << " " << num << "\n";
    // 종료조건
    if (num>K) return false;
    if (lev==D){
        if (num==K) return true; 
        return false;
    }
    // 재귀함수
    return query(lev+1,num,prev_num+num);
}

int main()
{

    cin >> D >> K;

    for (int i=1;i<K-1;i++){
        for (int j=i+1;j<K;j++){
            // cout << i << ", " << j << "-----------\n"; 
            if (query(2,i,j)){
                cout << i << "\n" << j;
                exit(0);
            }
        }
    }
}