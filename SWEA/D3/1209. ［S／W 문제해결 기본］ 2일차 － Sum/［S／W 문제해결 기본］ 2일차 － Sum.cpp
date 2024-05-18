#include <bits/stdc++.h>

using namespace std;

int main()
{
    int TC;
    for (int tc=1;tc<=10;tc++){
        cin >> TC;
        int answer=0;
        int arr[100][100];
        int horizontal_sum[100]={0,};
        int vertical_sum[100]={0,};
        int daegak=0;
        int r_daegak=0;
        for (int i=0;i<100;i++){
            for (int j=0;j<100;j++){
                cin >> arr[i][j];
            }
        }
        for (int i=0;i<100;i++){
            for (int j=0;j<100;j++){
                horizontal_sum[i]+=arr[i][j];
                vertical_sum[j]+=arr[i][j];
                if (i==j) daegak+=arr[i][j];
                if (i==99-j) r_daegak+=arr[i][j];
            }
        }
        int temp_mx;
        sort(horizontal_sum,horizontal_sum+100);
        sort(vertical_sum,vertical_sum+100);
        temp_mx=max(horizontal_sum[99],vertical_sum[99]);
        temp_mx=max(temp_mx,daegak);
        temp_mx=max(temp_mx,r_daegak);
        printf("#%d %d\n",TC,temp_mx);
    }
}