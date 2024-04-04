#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n='z'-'a'+1;
	int arr[n]={0,};
	string str;
	cin >> str;
	for (int i=0;i<str.length();i++){
		arr[str[i]-'a']++;
	}
	for (int i:arr){
		cout << i << " ";
	}
}