#include <iostream>
#include <vector>

using namespace std;

int main() 
{
	char str[200];
	int num;	
	cin >> num;
    int idx=0;
    int mp[28]={0,};
    vector<char> ret;
	for (int i=0;i<num;i++){
        string queuestr;
        cin >> queuestr;
        int max=0,maxidx=0;
        for (int j=0;j<28;j++){
            if (mp[j]>max){
                max=mp[j];
                maxidx=j;
            }
        }
        if (queuestr=="enqueue"){
            char alphabet;
            cin >> alphabet;
            str[idx++]=alphabet;
            mp[int(alphabet)-'A']++;
        }      
        else{
            if (max==0){
                ret.push_back('*');
            }
            else{
                for (int j=0;j<200;j++){               
                    if (str[j]==char(maxidx+int('A'))){
                        //cout << char(maxidx+'A');
                        ret.push_back(char(maxidx+'A'));
                        mp[j]--;
                        str[j]='a';
                    }
                }
            }
        }               
    }
    for (int i=0;i<ret.size();i++){
        cout << ret[i] << " ";
    }
	return 0;
}