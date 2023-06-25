#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <string>

using namespace std;

int mp[16][16]={
    {0,0,0,0,0,0,17,17,17,17,0,0,0,0,0,0},
    {0,0,0,0,0,4,17,17,17,17,1,0,0,0,0,0},
    {0,0,0,7,7,4,4,12,12,1,1,5,5,0,0,0},
    {0,0,7,7,7,4,4,12,12,1,1,5,5,5,0,0},
    {0,0,7,7,7,4,4,12,12,1,1,5,5,5,0,0},
    {0,16,16,16,16,4,4,12,12,1,1,13,13,13,13,0},
    {19,19,16,16,16,16,4,12,12,1,13,13,13,13,20,20},
    {19,19,10,10,10,10,10,25,25,9,9,9,9,9,20,20},
    {19,19,10,10,10,10,10,25,25,9,9,9,9,9,20,20},
    {19,19,15,15,15,15,3,11,11,2,14,14,14,14,20,20},
    {0,15,15,15,15,3,3,11,11,2,2,14,14,14,14,0},
    {0,0,6,6,6,3,3,11,11,2,2,8,8,8,0,0},
    {0,0,6,6,6,3,3,11,11,2,2,8,8,8,0,0},
    {0,0,0,6,6,3,3,11,11,2,2,8,8,0,0,0},
    {0,0,0,0,0,3,18,18,18,18,2,0,0,0,0,0},
    {0,0,0,0,0,0,18,18,18,18,0,0,0,0,0,0}
};

int main()
{   
    string str;
    cin >> str;

    string strarr[200];
    int v_idx=0;
    for(auto&i:str){
        if (i!=',')
        {
            strarr[v_idx]+=i;
        }
        else{
            v_idx++;
        }
    }
    int intarr[200];

    for (int i=0;i<=v_idx;i++){
        intarr[i]=stoi(strarr[i]);
    }

    int ret=40;

    int flag[9]={0,},sum[9]={0,};
    for (int i=0;i<=v_idx;i=i+2){        
        if (i/6==0){            
            if (mp[i][i+1]==5){
                flag[0]++;
                ret+=5;               
            }
            if (i==4&&!flag[0]){
                ret/=2;
            }
        }
        else if (i/6==1){
            if (mp[i][i+1]==6){
                flag[1]++;
                ret+=6;               
            }
            if (i==10&&!flag[1]){
                ret/=2;
            }
        }
        else if (i/6==2){
            if (mp[i][i+1]==7){
                flag[2]++;
                ret+=7;               
            }
            if (i==16&&!flag[2]){
                ret/=2;
            }
        }
        else if (i/6==3){
            if (mp[i][i+1]==8){
                flag[3]++;
                ret+=8;               
            }
            if (i==22&&!flag[3]){
                ret/=2;
            }
        }
        else if (i/6==4){
            if (mp[i][i+1]==17){
                flag[4]++; 
                ret+=17;             
            }
            else if (mp[i][i+1]==18){
                flag[4]++; 
                ret+=18;   
            }
            if (i==28&&!flag[4]){
                ret/=2;
            }
            sum[4]+=mp[i][i+1];
        }
        else if (i/6==5){
            if (mp[i][i+1]==9){
                flag[5]++;
                ret+=9;               
            }
            else if (mp[i][i+1]==10){
                flag[5]++;
                ret+=10;
            }
            if (i==34&&!flag[5]){
                ret/=2;
            }
        }
        else if (i/6==6){
            if (mp[i][i+1]==11){
                flag[6]++;
                ret+=11;               
            }
            else if (mp[i][i+1]==12){
                flag[6]++;
                ret+=12;
            }
            if (i==40&&!flag[6]){
                ret/=2;
            }
        }
        else if (i/6==7){
            if (mp[i][i+1]==19){
                flag[7]++;
                ret+=19;               
            }
            else if (mp[i][i+1]==20)
            {
                flag[7]++;
                ret+=20;
            }
            if (i==46&&!flag[7]){
                ret/=2;
            }
        }
        else if (i/6==8){
            if (mp[i][i+1]==25){
                flag[8]++;
                ret+=25;               
            }
            if (i==52&&!flag[8]){
                ret/=2;
            }
        }
    }

    cout << ret;
}