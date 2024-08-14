#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;

    cin >> tc;

    for (int i=0;i<tc;i++){
        deque<int> deq;
        string cmd, num;
        char input;
        int sz;
        cin >> cmd >> sz;

        while(1){
            cin >> input;
            if (input>='0'&&input<='9'){
                num+=input;
            }
            else if (num.size()){
                deq.push_back(stoi(num));
                num="";
            }
            if (input==']') break; 
        }

        int r=0;
        int flag=1;
        for (char j:cmd){
            if (j=='R') r^=1;
            else if (!deq.size()){
                flag=0;
                break;
            }
            else if (r==0){
                deq.pop_front();
            }
            else if (r==1){
                deq.pop_back();
            }
        }
        if (!flag) cout << "error\n";
        else{
            if (r) reverse(deq.begin(),deq.end());
            cout << "[";
            for (int i=0;i<deq.size();i++){
                cout << deq[i];
                if (i!=deq.size()-1) cout << ",";
            }
            cout << "]\n";
        }
    }
}