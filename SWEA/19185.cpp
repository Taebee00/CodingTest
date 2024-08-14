#include <bits/stdc++.h>

using namespace std;

int glb(int a,int b){
    if (b%a==0) return a;
    return glb(b%a,a);
}

int main()
{
    int T;
    cin >> T;
    for (int i=1;i<=T;i++){
        int a, b;
        string a_arr[21], b_arr[21];
        cin >> a >> b;
        for (int i=0;i<a;i++){
            cin >> a_arr[i];
        }
        for (int i=0;i<b;i++){
            cin >> b_arr[i];
        }
        int ldb=a*b/glb(a,b);
        int Q;
        cin >> Q;
        printf("#%d ",i);
        for (int j=0;j<Q;j++){
            int num;
            cin >> num;
            num=((num-1)%ldb);
            cout << a_arr[num%a] << b_arr[num%b] << " ";
        }
        cout << "\n";
    }
}