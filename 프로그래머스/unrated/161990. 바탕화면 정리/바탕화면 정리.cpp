#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int ldx=60, ldy=60, rdx=-1, rdy=-1;
    for (int i=0;i<wallpaper.size();i++){
        for (int j=0;j<wallpaper[0].size();j++){
            if (wallpaper[i][j]=='#'){
                if (i<ldx) ldx=i;
                if (j<ldy) ldy=j;
                if (i+1>rdx) rdx=i+1;
                if (j+1>rdy) rdy=j+1;
            }
        }
    }
    answer.push_back(ldx);
    answer.push_back(ldy);
    answer.push_back(rdx);
    answer.push_back(rdy);
    return answer;
}