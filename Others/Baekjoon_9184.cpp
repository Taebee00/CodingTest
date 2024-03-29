#include <bits/stdc++.h>

using namespace std;

int dp[51][51][51];

int w(int a,int b,int c){
    //printf("%d %d %d\n",a,b,c);
    if (a<=0||b<=0||c<=0){
        return 1;
    }
    if (dp[a][b][c]){
        return dp[a][b][c];
    }
    else if (a>20||b>20||c>20){
        return dp[a][b][c]=w(20,20,20);
    }
    else if (a<b&&b<c){
        return dp[a][b][c]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
    }
    else{
        return dp[a][b][c]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
    }

}

int main()
{
    while(true){
        int a,b,c;
        cin >> a >> b >> c;
        if (a==-1&&b==-1&&c==-1){
            return 0;
        }
        printf("w(%d, %d, %d) = %d\n",a,b,c,w(a,b,c));
    }
}