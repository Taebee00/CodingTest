// #include <bits/stdc++.h>

// using namespace std;

// int N, mp[24][24],temp_mp[24][24],visitied[24][24]={0,}, mx=0;
// int dy[4]={-1,0,1,0}, dx[4]={1,0,-1,0};
// vector<int> v;

// void move(int i){
//     if (i==0){
//             for (int j=0;j<N;j++){
//                 for (int k=0;k<N;k++){
//                     int temp=k-1;
//                     if (temp_mp[j][k]){
//                         while(!temp_mp[j][temp]&&temp>=0&&temp<N){
//                             temp--;
//                         }
//                         if (temp_mp[j][temp]==temp_mp[j][k]&&!visitied[j][temp]){
//                             temp_mp[j][temp]*=2;
//                             visitied[j][temp]=1;
//                             temp_mp[j][k]=0;
//                         }
//                         else{
//                             temp_mp[j][temp+1]=temp_mp[j][k];
//                             if (k!=temp+1){
//                                 temp_mp[j][k]=0;
//                             }
//                         }
//                     }    
//                 }
//             }
//         }
//         else if (i==1){
//             for (int j=0;j<N;j++){
//                 for (int k=N;k>=0;k--){
//                     int temp=k+1;
//                     if (temp_mp[j][k]){
//                         while(!temp_mp[j][temp]&&temp>=0&&temp<N){
//                             temp++;
//                         }
//                         if (temp_mp[j][temp]==temp_mp[j][k]&&!visitied[j][temp]){
//                             temp_mp[j][temp]*=2;
//                             visitied[j][temp]=1;
//                             temp_mp[j][k]=0;
//                         }
//                         else{
//                             temp_mp[j][temp-1]=temp_mp[j][k];
//                             if (k!=temp-1){
//                                 temp_mp[j][k]=0;
//                             }
//                         }
//                     }    
//                 }
//             }
//         }
//         else if (i==2){
//             for (int j=0;j<N;j++){
//                 for (int k=1;k<N;k++){
//                     int temp=k-1;
//                     if (temp_mp[k][j]){
//                         while(!temp_mp[temp][j]&&temp>=0&&temp<N){
//                             temp--;
//                         }
//                         if (temp_mp[temp][j]==temp_mp[k][j]&&!visitied[j][temp]){
//                             temp_mp[temp][j]*=2;
//                             visitied[temp][j]=1;
//                             temp_mp[k][j]=0;
//                         }
//                         else{
//                             temp_mp[temp+1][j]=temp_mp[k][j];
//                             if (k!=temp+1){
//                                 temp_mp[k][j]=0;
//                             }
//                         }
//                     }    
//                 }
//             }
//         }
//         else{
//             for (int j=0;j<N;j++){
//                 for (int k=N-2;k>=0;k--){
//                     int temp=k+1;
//                     if (temp_mp[k][j]){
//                         while(!temp_mp[temp][j]&&temp>=0&&temp<N){
//                             temp++;
//                         }
//                         if (temp_mp[temp][j]==temp_mp[k][j]&&!visitied[j][temp]){
//                             temp_mp[temp][j]*=2;
//                             visitied[temp][j]=1;
//                             temp_mp[k][j]=0;
//                         }
//                         else{
//                             temp_mp[temp-1][j]=temp_mp[k][j];
//                             if (k!=temp-1){
//                                 temp_mp[k][j]=0;
//                             }
//                         }
//                     }    
//                 }
//             }
//         }
// }

// void cal(){
//     for (auto&i:v){
//         for (int j=0;j<N;j++){
//             for (int k=0;k<N;k++){
//                 visitied[j][k]=0;
//             }
//         }
//         if (i==0){
//             for (int j=0;j<N;j++){
//                 for (int k=0;k<N;k++){
//                     int temp=k-1;
//                     if (temp_mp[j][k]){
//                         while(!temp_mp[j][temp]&&temp>=0&&temp<N){
//                             temp--;
//                         }
//                         if (temp>=0&&temp<N&&temp_mp[j][temp]==temp_mp[j][k]&&!visitied[j][temp]){
//                             temp_mp[j][temp]*=2;
//                             visitied[j][temp]=1;
//                             temp_mp[j][k]=0;
//                         }
//                         else{
//                             temp_mp[j][temp+1]=temp_mp[j][k];
//                             if (k!=temp+1){
//                                 temp_mp[j][k]=0;
//                             }
//                         }
//                     }    
//                 }
//             }
//         }
//         else if (i==1){
//             for (int j=0;j<N;j++){
//                 for (int k=N-1;k>=0;k--){
//                     int temp=k+1;
//                     if (temp_mp[j][k]){
//                         while(!temp_mp[j][temp]&&temp>=0&&temp<N){
//                             temp++;
//                         }
//                         if (temp>=0&&temp<N&&temp_mp[j][temp]==temp_mp[j][k]&&!visitied[j][temp]){
//                             temp_mp[j][temp]*=2;
//                             visitied[j][temp]=1;
//                             temp_mp[j][k]=0;
//                         }
//                         else{
//                             temp_mp[j][temp-1]=temp_mp[j][k];
//                             if (k!=temp-1){
//                                 temp_mp[j][k]=0;
//                             }
//                         }
//                     }    
//                 }
//             }
//         }
//         else if (i==2){
//             for (int j=0;j<N;j++){
//                 for (int k=0;k<N;k++){
//                     int temp=k-1;
//                     if (temp_mp[k][j]){
//                         while(!temp_mp[temp][j]&&temp>=0&&temp<N){
//                             temp--;
//                         }
//                         if (temp>=0&&temp<N&&temp_mp[temp][j]==temp_mp[k][j]&&!visitied[temp][j]){
//                             temp_mp[temp][j]*=2;
//                             visitied[temp][j]=1;
//                             temp_mp[k][j]=0;
//                         }
//                         else{
//                             temp_mp[temp+1][j]=temp_mp[k][j];
//                             if (k!=temp+1){
//                                 temp_mp[k][j]=0;
//                             }
//                         }
//                     }    
//                 }
//             }
//         }
//         else{
//             for (int j=0;j<N;j++){
//                 for (int k=N-1;k>=0;k--){
//                     int temp=k+1;
//                     if (temp_mp[k][j]){
//                         while(!temp_mp[temp][j]&&temp>=0&&temp<N){
//                             temp++;
//                         }
//                         if (temp_mp[temp][j]==temp_mp[k][j]&&!visitied[temp][j]){
//                             temp_mp[temp][j]*=2;
//                             visitied[temp][j]=1;
//                             temp_mp[k][j]=0;
//                         }
//                         else{
//                             temp_mp[temp-1][j]=temp_mp[k][j];
//                             if (k!=temp-1){
//                                 temp_mp[k][j]=0;
//                             }
//                         }
//                     }    
//                 }
//             }
//         }
//     }
//     int temp_mx=0;
//     for (int i=0;i<N;i++){
//         for (int j=0;j<N;j++){
//             if (temp_mp[i][j]>temp_mx){
//                 temp_mx=temp_mp[i][j];
//             }
//         }
//     }
//     if (temp_mx>mx){
//         mx=temp_mx;
//     }
// }

// void choose(int sz,int choice){
//     if (sz==5){
//         for (int i=0;i<N;i++){
//             for (int j=0;j<N;j++){
//                 temp_mp[i][j]=mp[i][j];
//                 visitied[i][j]=0;
//             }
//         }
//         cal();
//         return;
//     }
//     for (int i=0;i<4;i++){
//         v.push_back(i);
//         choose(sz+1,i);
//         if (!v.empty()){
//             v.pop_back();
//         }
//     }
// }

// int main()
// {
//     cin >> N;
//     for (int i=0;i<N;i++){
//         for (int j=0;j<N;j++){
//             cin >> mp[i][j];
//             temp_mp[i][j]=mp[i][j];
//         }       
//     }
//     choose(0,0);
//     // while(1){
//     //     int temp;
//     //     cin >> temp;
//     //     move(temp);
//     //     for (int i=0;i<N;i++){
//     //         for (int j=0;j<N;j++){
//     //             printf("%d ",temp_mp[i][j]);
//     //         }
//     //         printf("\n");
//     //     }
//     // }
//     cout << mx;
// }
#include <bits/stdc++.h>

using namespace std;

int N, arr[20][20], visitied[20][20]={0,}, mx=0;
int dy[4]={-1,0,1,0}, dx[4]={0,1,0,-1};

void dfs(int cnt){
    if (cnt==5){
        for (int i=0;i<N;i++){
            for (int j=0;j<N;j++){
                mx=max(mx,arr[i][j]);
            }
        }
        return;
    }
    for (int i=0;i<4;i++){
        int temp_arr[20][20];
        fill(&visitied[0][0],&visitied[0][0]+N*N,0);
        memcpy(temp_arr,arr,sizeof(arr));
        if (i==0){
            for (int j=0;j<N-1;j++){
                for (int k=0;k<N;k++){
                    if (arr[j][k]&&arr[j][k]==arr[j+1][k]&&!visitied[j][k]){
                        arr[j][k]*=2;
                        visitied[j][k]=1;
                        arr[j+1][k]=0;
                    }
                    else if (!arr[j][k]){
                        arr[j][k]=arr[j+1][k];
                        arr[j+1][k]=0;
                    }
                }
            }
        }
        else if (i==1){
            for (int j=0;j<N;j++){
                for (int k=N-1;k>=1;k--){
                    if (arr[j][k]&&arr[j][k]==arr[j][k-1]&&!visitied[j][k]){
                        arr[j][k]*=2;
                        visitied[j][k]=1;
                        arr[j][k-1]=0;
                    }
                    else if (!arr[j][k]){
                        arr[j][k]=arr[j][k-1];
                        arr[j][k-1]=0;
                    }
                }
            }
        }
        else if (i==2){
            for (int j=N-1;j>=1;j--){
                for (int k=0;k<N;k++){
                    if (arr[j][k]&&arr[j][k]==arr[j-1][k]&&!visitied[j][k]){
                        arr[j][k]*=2;
                        visitied[j][k]=1;
                        arr[j-1][k]=0;
                    }
                    else if (!arr[j][k]){
                        arr[j][k]=arr[j-1][k];
                        arr[j-1][k]=0;
                    }
                }
            }
        }
        else if (i==3){
            for (int j=0;j<N;j++){
                for (int k=0;k<N-1;k++){
                    if (arr[j][k]&&arr[j][k]==arr[j][k+1]&&!visitied[j][k]){
                        arr[j][k]*=2;
                        visitied[j][k]=1;
                        arr[j][k+1]=0;
                    }
                    else if (!arr[j][k]){
                        arr[j][k]=arr[j][k+1];
                        arr[j][k+1]=0;
                    }
                }
            }
        }
        dfs(cnt+1);
        memcpy(arr,temp_arr,sizeof(arr));
    }
}

int main()
{
    cin >> N;
    
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            cin >> arr[i][j];
        }
    }

    dfs(0);

    // for (int i=0;i<N;i++){
    //     for (int j=0;j<N;j++){
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    cout << mx;
}