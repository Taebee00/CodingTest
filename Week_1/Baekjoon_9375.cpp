#include <bits/stdc++.h>
using namespace std;

int main()
{
	int num,clothes;
	cin >> num;
	for (int i = 0;i < num;i++) {
		cin >> clothes; cin.ignore();
		map<string, int> arr; 
		string str;;
		for (int j = 0;j < clothes;j++){
			getline(cin,str);
			arr[str.substr(str.find(' ') + 1, str.length())]++;
		}
		int options=1;
		for (auto& j : arr) {
			options *= j.second + 1;
		}
		cout << options - 1<< endl;
	}
}
