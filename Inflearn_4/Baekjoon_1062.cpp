// #include <bits/stdc++.h>

// using namespace std;

// int N,K,mx=0;
// string str[50];
// int bin=(1<<'a'-'a')|(1<<'n'-'a')|(1<<'t'-'a')|(1<<'i'-'a')|(1<<'c'-'a');

// void find(int num,int left,int choice)
// {   
//     if (left==0){
//         int cnt=0;
//         for (int i=0;i<N;i++){
//             int flag=0;
//             for (int j=0;j<str[i].length();j++){
//                 if (!(bin&(1<<(str[i][j]-'a')))){
//                     flag=1;
//                     break;
//                 }
//             }
//             if (!flag){
//                 cnt++;
//             }
//         }
//         if (cnt>mx){
//             mx=cnt;
//         }
//     }
//     for (int i=choice+1;i<num;i++){
//         if (i+'a'=='a'||i+'a'=='n'||i+'a'=='t'||i+'a'=='c'||i+'a'=='i'){
//             continue;
//         }
//         bin|=1<<i;
//         find(num,left-1,i);
//     }
//     bin&=~(1<<choice);
//     return;
// }

// int main()
// {  
//     cin >> N >> K;
//     for(int i=0;i<N;i++){
//         cin >> str[i];
//     }
//     if (K<5){
//         cout << '0';
//         return 0;
//     }
//     find(26,K-5,-1);
//     cout << mx;
// }d
#include <bits/stdc++.h>

using namespace std;

int N, K, choose_arr[26]={0,}, chosen_arr[26], mx=0;
vector<string> str_v;

int cal(){
    int ret=0;
    for (int i=0;i<N;i++){
        int flag=1;
        for (char j:str_v[i]){
            if (!chosen_arr[j-'a']){
                flag=0;
                break;
            }
        }
        if (flag) ret++;
    }
    return ret;
}

int main()
{
    cin >> N >> K;

    for (int i=0;i<N;i++){
        string str;
        cin >> str;
        str_v.push_back(str);
    }

    choose_arr['a'-'a']=1;
    choose_arr['n'-'a']=1;
    choose_arr['t'-'a']=1;
    choose_arr['i'-'a']=1;
    choose_arr['c'-'a']=1;
    
    for (int i=1;i<(1<<26)-1;i++){
        int cnt=0;
        memcpy(chosen_arr,choose_arr,sizeof(choose_arr));
        for (int j=0;j<26;j++){
            if (i&(1<<j)&&!chosen_arr[j]){
                cnt++;
                chosen_arr[j]=1;
            }
        }
        if (cnt==K-5){
            //printf("%X\n",i);
            //cout << cal() << "\n";
            mx=max(mx,cal());
        }
    }

    cout << mx;
}