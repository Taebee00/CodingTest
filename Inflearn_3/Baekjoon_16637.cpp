#include <bits/stdc++.h>

using namespace std;

int N, answer=0;
char str[20];
vector<char> num_v;
vector<char> cal_v;
vector<int> choose_v;

int cal_2(int n,int m,char how){
    if (how=='+') return n+m;
    if (how=='-') return n-m;
    if (how=='*') return n*m;
    else return 0;
}

int cal(){
    vector<int> temp_num_v;
    vector<char> temp_cal_v;
    for (int i=0;i<num_v.size();i++){
        if (find(num_v.begin(),num_v.end(),i)==num_v.end()){
            temp_num_v.push_back(num_v[i]);
            if (i<num_v.size()-1) temp_cal_v.push_back(cal_v[i]);
        }
        else{
            temp_num_v.push_back(cal_2(num_v[i],num_v[i+1],cal_v[i]));
            i++;
            temp_cal_v.push_back(cal_v[i]);
        }
    }
    int ret=temp_num_v[0];
    for (int i=1;i<temp_num_v.size();i++){
        ret=cal_2(ret,temp_num_v[i],temp_cal_v[i-1]);
    }
    return ret;
}

void recur(int first, int second,int start){
    if (start>num_v.size()){
        for (int i:choose_v) cout << i << " ";
        cout << "\n";
        answer=max(answer,cal());
        return;
    }
    if (first>=0) choose_v.push_back(num_v[first]);
    recur(start,start+1,start+2);
    recur(first,second,start+1);
    if (first>=0) choose_v.pop_back(); 
}

int main()
{   
    cin >> N;
    for (int i=0;i<N;i++){
        cin >> str[i];
        if (!(i%2)) num_v.push_back(str[i]-'0');
        else cal_v.push_back(str[i]);
    }

    recur(-2,-1,0);
    cout << answer;
}