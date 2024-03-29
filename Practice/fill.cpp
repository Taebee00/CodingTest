#include <bits/stdc++.h>

using namespace std;

const int max_n = 1004;
const int INF = 987654321;

vector<int> v[10];
vector<int> v2(10, 0); // 선언과 함께 초기화
vector<vector<int>> v3(10, vector<int>(10, 0)); // 선언과 함께 이차원 벡터 초기화
vector<vector<int>> v4;

int dp[10] = {0,};
int a[max_n];
int a2[max_n][max_n];

int main(){
    fill(v2.begin(), v2.end(), INF);
    fill(a, a+max_n, 10);
    for(int i = 0; i < max_n; i++) fill(a2[i], a2[i] + max_n, INF);
    fill(&a2[0][0], &a2[0][0] + max_n * max_n, INF);
    return 0;
}