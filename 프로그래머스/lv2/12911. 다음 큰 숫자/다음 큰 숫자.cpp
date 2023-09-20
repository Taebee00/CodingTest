#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer, cnt_1=0;
    for (int i=0;i<20;i++){      
        if (n&(1<<i)){
            cnt_1++;
        }
    }
    
    while(true){
        n++;
        int cnt_2=0;
        for (int i=0;i<20;i++){
            if (n&(1<<i)){
                cnt_2++;
            }
        }
        if (cnt_2==cnt_1){
            return n;
        }
    }
}