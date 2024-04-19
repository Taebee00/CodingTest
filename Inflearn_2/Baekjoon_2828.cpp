#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M, J;
    int box_left=1;
    int answer=0;

    cin >> N >> M >> J;

    for (int i=0;i<J;i++){
        int apple;
        cin >> apple;
        if (apple<box_left){
            answer+=(box_left-apple);
            box_left=apple;
        }
        else if (apple>box_left+M-1){
            answer+=(apple-(box_left+M-1));
            box_left=box_left+(apple-(box_left+M-1));
        }
        else continue;
    }

    cout << answer;
}