#include <bits/stdc++.h>

using namespace std;

int dy[4]={0,-1,0,1}, dx[4]={1,0,-1,0}, mp[101][101]={0,};
pair<int,int> dim[4]={{1,0},{1,1},{0,1},{1,0}};

void dragon(vector<int> &v){
    vector<pair<int,int>> temp_v;
    temp_v.push_back({v[1],v[0]});
    temp_v.push_back({v[1]+dy[v[2]],v[0]+dx[v[2]]});
    while(v[3]--){
        int y,x;
        pair<int,int> s=temp_v.back();
        vector<pair<int,int>> temp_temp_v;
        for (int i=temp_v.size()-2;i>=0;i--){
            if (temp_v[i].first<s.first&&temp_v[i].second<=s.second){
                y=s.first-abs(temp_v[i].second-s.second);
                x=s.second+abs(temp_v[i].first-s.first);
            }
            else if (temp_v[i].first<=s.first&&temp_v[i].second>s.second){
                y=s.first+abs(temp_v[i].second-s.second);
                x=s.second+abs(temp_v[i].first-s.first);
            }
            else if (temp_v[i].first>s.first&&temp_v[i].second>=s.second){
                y=s.first+abs(temp_v[i].second-s.second);
                x=s.second-abs(temp_v[i].first-s.first);
            }
            else if (temp_v[i].first>=s.first&&temp_v[i].second<s.second){
                y=s.first-abs(temp_v[i].second-s.second);
                x=s.second-abs(temp_v[i].first-s.first);
            }      
            temp_temp_v.push_back({y,x});
        }
        for (auto&i:temp_temp_v){
            temp_v.push_back(i);
        }    
    }
    for (auto&i:temp_v){
        //printf("%d %d\n",i.first,i.second);
        mp[i.first][i.second]=1;
    }  
}

int main()
{
    int N,cnt=0;
    vector<vector<int>> v;
    cin >> N;
    for (int i=0;i<N;i++){
        int temp; vector<int> temp_v;
        for (int j=0;j<4;j++){         
            cin >> temp;
            temp_v.push_back(temp);
        }
        v.push_back(temp_v);
    }
    for (int i=0;i<N;i++){
        dragon(v[i]);
    }
    for (int i=0;i<100;i++){
        for (int j=0;j<100;j++){
            if (mp[i][j]&&mp[i+1][j]&&mp[i+1][j+1]&&mp[i][j+1]){
                cnt++;
            }
        }
    }
    cout << cnt;
}