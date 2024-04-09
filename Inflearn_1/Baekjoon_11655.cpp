// // unique를 통해배열의 중복 제거하기

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
// 	string str;
// 	getline(cin, str);
// 	for (auto &i:str)
// 	{
// 		if (i >= 'a' && i <= 'z') {
// 			if (i > 'z' - 13) {
// 				i = char(12 + i - 'z' + 'a');
// 			}
// 			else {
// 				i = i + 13;
// 			}
// 		}
// 		if (i >= 'A' && i <= 'Z'){
// 			if (i > 'Z' - 13) {
// 				i = 'A' + i - 'Z' + 12;
// 			}
// 			else {
// 				i = i + 13;
// 			}
// 		}
// 	}
// 	cout << str;
// }
#include <bits/stdc++.h>

using namespace std;

int main()
{
	string str;
	getline(cin,str);
	for (char i : str){
		if (i>='A'&&i<='Z'){
			if (i+13<='Z'){
				i+=13;
			}
			else{
				i='A'+((i+13)%'Z')-1;
			}
		}
		if (i>='a'&&i<='z'){
			if (i+13<='z'){
				i+=13;
			}
			else{
				i='a'+((i+13)%'z')-1;
			}
		}
		cout << i;
	}
}