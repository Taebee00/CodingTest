#include <bits/stdc++.h>

using namespace std;

int N, L, answer, arr[100][100], visitied[100][100]={0,};

int main()
{
    cin >> N >> L;

    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            cin >> arr[i][j];
        }
    }
    // 가로선 확인
    for (int i=0;i<N;i++){
        int flag=1;
        for (int j=0;j<N;j++){
            // 직전과 2 이상 차이나면 아웃
            if (j>0&&abs(arr[i][j]-arr[i][j-1])>1){
                flag=0;
                break;
            }
            // 직전과 같으면 통과
            if (j>0&&arr[i][j]==arr[i][j-1]) continue;
            // 직전이 1 클 때
            if (j>0&&arr[i][j-1]-1==arr[i][j]){
                for (int k=j;k<j+L;k++){
                    if (k>=N||arr[i][k]!=arr[i][j]){
                        flag=0;
                        break;
                    }
                    visitied[i][k]=1;
                }
                if (flag==0) break;
            }
            // 직전이 1 작을 때
            if (j>0&&arr[i][j-1]+1==arr[i][j]){
                for (int k=j-1;k>j-1-L;k--){
                    if (k<0||visitied[i][k]||arr[i][k]!=arr[i][j-1]){
                        flag=0;
                        break;
                    }
                }
                if (flag==0) break;
            }
        }
        if (flag){
            answer++;
        }   
    }
    fill(&visitied[0][0],&visitied[0][0]+100*100,0);
    // 세로선 확인
    for (int j=0;j<N;j++){
        int flag=1;
        for (int i=0;i<N;i++){
            // 직전과 2 이상 차이나면 아웃
            if (i>0&&abs(arr[i][j]-arr[i-1][j])>1){
                flag=0;
                break;
            }
            // 직전과 같으면 통과
            if (i>0&&arr[i][j]==arr[i-1][j]) continue;
            // 직전이 1 클 때
            if (i>0&&arr[i-1][j]-1==arr[i][j]){
                for (int k=i;k<i+L;k++){
                    if (k>=N||arr[k][j]!=arr[i][j]){
                        flag=0;
                        break;
                    }
                    visitied[k][j]=1;
                }
                if (flag==0) break;
            }
            // 직전이 1 작을 때
            if (i>0&&arr[i-1][j]+1==arr[i][j]){
                for (int k=i-1;k>i-1-L;k--){
                    if (k<0||visitied[k][j]||arr[k][j]!=arr[i-1][j]){
                        flag=0;
                        break;
                    }
                }
                if (flag==0) break;
            }
        }
        if (flag){
            answer++;
        }  
    }
    cout << answer;
}