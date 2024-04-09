#include <bits/stdc++.h>

using namespace std;

int main()
{
    int H, W;
    char jido[100][100];
    int answer[100][100];

    fill(&answer[0][0],&answer[0][0]+100*100,-1);

    cin >> H >> W;

    for (int i=0;i<H;i++){
        for (int j=0;j<W;j++){
            cin >> jido[i][j];
        }
    }

    for (int i=0;i<H;i++){
        for (int j=0;j<W;j++){
            if (jido[i][j]=='c'){
                answer[i][j]=0;
            }
            else if (j>0&&answer[i][j-1]>=0){
                answer[i][j]=answer[i][j-1]+1;
            }
        }
    }

    for (int i=0;i<H;i++){
        for (int j=0;j<W;j++){
            cout << answer[i][j] << " ";
        }
        cout << "\n";
    }
}