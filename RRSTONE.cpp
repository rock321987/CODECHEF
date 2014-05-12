#include <cstdio>
#include <cstring>
 
#define get getchar_unlocked
 
inline int input()
{
    int n = 0, s = 1 ;
    char p = get();
    
	if (p == '-') {
        s = -1 ;
    }
    
    while ((p < '0' || p > '9') && p != EOF && p != '-') {
        p = get( ) ;
    }
    
    if (p == '-') {
        s = -1, p = get() ;
    }
    
    while (p >= '0' && p <= '9') {
        n = (n << 3) + (n << 1) + (p - '0') ;
        p = get() ;
    }
    
    return n * s ;
}
 
using namespace std;
 
int main()
{
	int n, i;
	long long int arr[100005], k, max = 0, min = 2 * 1e9 + 1;
	//scanf("%d%ld", &n, &k);
	n = input();
	k = input();
	
	for (i = 0;i < n;i++) {
		//scanf("%ld", &arr[i]);
		arr[i] = input();
		if (arr[i] > max) {
			max = arr[i];
		}
		if (arr[i] < min) {
			min = arr[i];
		}
	}
	
	if (k == 0) {
		for (i = 0;i < n;i++) {
			printf("%lld ", arr[i]);
		}
	} else if (k % 2 == 1) {
		for (i = 0;i < n;i++) {
			printf("%lld ", max - arr[i]);
		}
	} else {
		for (i = 0;i < n;i++) {
			printf("%lld ", arr[i] - min);
		}
	}
	printf("\n");
	return 0;
} 
