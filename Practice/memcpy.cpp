#include <bits/stdc++.h>

using namespace std;

int a[5], temp[5], a2[5][5], temp2[5][5], temp3[25];

int main()
{
    for (int i = 0; i < 5; i++) a[i] = i;
    memcpy(temp, a, sizeof(a));
    for (int i : temp) cout << i << ' ';
    cout << '\n';

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            a2[i][j] = i*j;
        }
    }
    memcpy(temp2, a2, sizeof(a2));
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            cout << temp2[i][j] << ' ';
        }
        cout << "\n";
    }
    memcpy(temp3, a2, sizeof(a2));
    for (int i = 0; i < 25; i++) cout << temp3[i] << ' '; 
}