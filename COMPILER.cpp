#include <cstdio>
#include <algorithm>
#include <string>
#include <stack>
#include <iostream>
 
using namespace std;
 
int main()
{
	int t;
	scanf("%d", &t);
	
	while (t--) {
		string arr;
		cin >> arr;
		stack<char> st;
		int i, cnt = 0;
		
		for (i = 0;i < arr.size();i++) {
			if (arr[i] == '<') {
				st.push('<');
			} else {
				if (! st.empty()) {
					st.pop();
					if (st.empty()) {
						cnt = i + 1;
					}
				} else {
					break;
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
} 
