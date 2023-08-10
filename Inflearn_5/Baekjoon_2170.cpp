#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, start, end, endend=INT_MIN, sum=0;
    vector<pair<int,int>> line_v;

    cin >> N;

    for (int i=0;i<N;i++){
        scanf("%d %d",&start,&end);
        line_v.push_back({start,end});
        if (end>endend){
            endend=end;
        }
    }
    sort(line_v.begin(),line_v.end());
    int idx=0,start_idx=0;
    for (int i=0;i<line_v.size();i++){
        if (line_v[idx].second>line_v[i].first){
            idx=line_v[idx].second>line_v[i].second?idx:i;
        }
        else{
            sum+=line_v[idx].second-line_v[start_idx].first;
            idx=i;
            start_idx=i;
        }
        if (i==line_v.size()-1){
            sum+=endend-line_v[start_idx].first;
        }

    }
    printf("%d",sum);
}