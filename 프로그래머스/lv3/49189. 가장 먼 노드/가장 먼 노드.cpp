#include <string>
#include <vector>
#include <queue>

using namespace std;

queue<int> q;
int visitied[20001];

int solution(int n, vector<vector<int>> edge) {
    int answer = 0,mx=0;
    q.push(1);
    visitied[1]=1;
    while(q.size()){
        int node=q.front();
        for (int i=0;i<edge.size();i++){
            if (edge[i][0]==node&&!visitied[edge[i][1]]){
                q.push(edge[i][1]);
                visitied[edge[i][1]]=visitied[node]+1;
                if (visitied[edge[i][1]]>mx){
                    answer=0;
                    mx=visitied[edge[i][1]];
                }
                if (visitied[edge[i][1]]==mx){
                    answer++;
                }
            }
            if (edge[i][1]==node&&!visitied[edge[i][0]]){
                q.push(edge[i][0]);
                visitied[edge[i][0]]=visitied[node]+1;
                if (visitied[edge[i][0]]>mx){
                    answer=0;
                    mx=visitied[edge[i][0]];
                }
                if (visitied[edge[i][0]]==mx){
                    answer++;
                }
            }
        }
        q.pop();
    }
    return answer;
}