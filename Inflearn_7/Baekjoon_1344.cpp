#include <bits/stdc++.h>

using namespace std;

double A,B,ret;
// 1~18까지 소수가 아닌 수로 배열 선언
int arr[11]={1,4,6,8,9,10,12,14,15,16,18};

int main()
{
    cin >> A >> B;
    // 2차원 배열을 통해 18 combination n을 구현
    for (int i=0;i<11;i++){
        for (int j=0;j<11;j++){
            double A_com=1,B_com=1;
            double per=1,A_per=1,B_per=1;
            //A_com으로 A가 arr[i](소수가 아닌 수만큼) 번 득점했을 때의 경우의 수를 구함
            //A_per은 arr[i]만큼 득점했을 확률, 18-arr[i]만큼 득점 못했을 확률을 곱함
            for (int k=0;k<arr[i];k++){
                A_com*=(18-k);
                A_com/=(k+1);
                A_per*=(A/100);
            }
            for (int k=0;k<18-arr[i];k++){
                A_per*=(100-A)/100;
            }
            //B도 마찬가지
            for (int k=0;k<arr[j];k++){
                B_com*=(18-k);
                B_com/=(k+1);
                B_per*=(B/100);
            }
            for (int k=0;k<18-arr[j];k++){
                B_per*=(100-B)/100;
            }
            //A_com*A_per은 A가 arr[i]만큼 득점할 확률
            //B_com*B_per은 B가 arr[j]만큼 득점할 확률
            //모두 곱하면 A와 B 모두 소수가 아닌 숫자만큼 득점할 확률
            per*=A_com*A_per*B_com*B_per;
            ret+=per;
        }
        
    }
    // 1-(A와 B모두 소수가 아닌 숫자만큼 득점할 확률)=적어도 한 팀이 소수로 득점할 확룰
    printf("%f",1-ret);
}