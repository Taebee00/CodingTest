#include <string>
#include <vector>
#include <map>
#include <cstdlib>

using namespace std;

map<char,int> mp;
int dy[4]={-1,0,1,0}, dx[4]={0,1,0,-1};

vector<int> solution(vector<string> park, vector<string> routes) {
    mp['N']=0; mp['E']=1; mp['S']=2; mp['W']=3;
    vector<int> answer;
    int y, x;
    int Y_sz=park.size();
    int X_sz=park[0].size();
    for (int i=0;i<Y_sz;i++){
        for (int j=0;j<X_sz;j++){
            if (park[i][j]=='S'){
                y=i;
                x=j;   
            }
        }
    }
    for (auto &i:routes){
        int dir=mp[i[0]];
        int dis=atoi(i.substr(2,i.size()).c_str());
        int next_y=y; int next_x=x;
        int flag=0;
        for (int j=0;j<dis;j++){
            next_y+=dy[dir]; next_x+=dx[dir];
            if (next_y>=Y_sz||next_y<0||next_x>=X_sz||next_x<0||park[next_y][next_x]=='X'){
                flag=1;
                break;
            }
        }
        if (flag==0){
            y=next_y;
            x=next_x;
        }
    }
    answer.push_back(y);
    answer.push_back(x);
    return answer;
}