#include<bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
    int dx[4]={-1,-2,1,2};

	for(test_case = 1; test_case <= 10; ++test_case)
	{
        int l, arr[1001], answer=0;
        cin >> l;
        for (int i=0;i<l;i++){
            cin >> arr[i];
        }
        for (int i=2;i<l-2;i++){
            int cnt=INT_MAX;
            for (int j=0;j<4;j++){
                if (arr[i+dx[j]]>=arr[i]){
                    cnt=INT_MAX;
                    break;
                }
                cnt=min(cnt,arr[i]-arr[i+dx[j]]);
            }
            if (cnt==INT_MAX) cnt=0;
            answer+=cnt;
        }
        printf("#%d %d\n",test_case,answer);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}