#include <bits/stdc++.h>
using namespace std;

int n,m,apple_num,apple,arr[11],cnt=0;

int main(){
    cin >> n >> m;
    cin >> apple_num;
    int left=1, right=m;
    for (int i=0;i<apple_num;i++){
        cin >> apple;
        if (apple>=left&&apple<=right){
            continue;
        }
        else if (apple<left){
            while(apple<left){
                left--; right--;
                cnt++;
            }
        }
        else if (apple>right){
            while(apple>right){
                left++; right++;
                cnt++;
            }
        }
    }
    cout << cnt;
}