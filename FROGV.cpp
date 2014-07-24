/*
  Ad-hoc
  Binary Search
*/

#include <bits/stdc++.h>
 
using namespace std;
 
long long int arr[1000005];
long long int sort_arr[1000005];
long long int breakpoint[1000005];
 
class Frogv {
	public:
		void calculate()
		{
			long long int n, p, i, j = 0;
			long long int k, pos = 0;
			scanf("%lld%lld%lld", &n, &k, &p);
			
			for (i = 0;i < n;i++) {
				scanf("%lld", &arr[i]);
				sort_arr[i] = arr[i];
			}
			
			sort(sort_arr, sort_arr + n);
			breakpoint[pos] = sort_arr[0];
			
			for (i = 1;i < n;i++) {
				if ((sort_arr[i] - sort_arr[i - 1]) > k) {
					pos++;
					breakpoint[pos] = sort_arr[i];
				}
			}
			
			/*for (i = 0;i <= pos;i++) {
				printf("%lld	", breakpoint[i]);
			}
			printf("\n");*/
			
			while (p--) {
				long long int x, y, level1, level2;
				scanf("%lld%lld", &x, &y);
				
				x--;
				y--;
				level1 = binarysearch(breakpoint, arr[x], pos);
				level2 = binarysearch(breakpoint, arr[y], pos);
				//printf("%lld	%lld\n", level1, level2);
				if (level1 == level2) {
					printf("Yes\n");
				} else {
					printf("No\n");
				}
			}
		}
		
		long long int binarysearch(long long int breakpoint[], long long int x, long long int size)
		{
			long long int lower = 0, upper = size, mid;
			int flag = 0;
			
			while (lower <= upper) {
				mid = (lower + upper) / 2;
				
				if (x == breakpoint[mid]) {
					flag = 1;
					break;
				} else if (x < breakpoint[mid]) {
					upper = mid - 1;
				} else {
					lower = mid + 1;
				}
			}
			
			if (flag == 0 && x <= breakpoint[mid]) {
				mid--;
			}
			return mid;
		}
};
 
int main()
{
	Frogv obj;
	obj.calculate();
	return 0;
} 
