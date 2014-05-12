#include <stdlib.h>
#define mod 1000000007
#include <cstring>
#include <cstdio>
#define get getchar_unlocked
 
using namespace std;
 
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
 
#define y putchar_unlocked
 
inline void output(int k)
{
	int n = k, i = 0;
	char ch[15];
	
	if (n <= 0) {
		if(n == 0) {
			y('0');
		} else {
			y('-');
		}
		n = n * -1;
	}
	
	while (n > 0) {
		ch[i] = (n % 10) + '0';
		n = n / 10;
		i++;
	}
	
	while (i > 0) {
		y(ch[i - 1]);
		i--;
	}
	
	y('\n');
}
 
unsigned long long modulo(unsigned long long a, unsigned long long b)
{
    unsigned long long product = a,ans = 1;
    while(b)
    {
        if((b&1)==1){
            ans *= product;
            ans %= mod;
        }
        b>>=1;
        product = (product * product) % mod;
    }
    return ans;
}
 
unsigned long long int binary(long long int n)
{
	unsigned long long int rem;
	unsigned long long x = 0, mediate = 1;
	char arr[25], c;
	int i = 0, j;
	
	while (n > 0) {
		rem = n % 2;
		c = rem + '0';
		arr[i] = c;
		n = n / 2;
		i++;
	}
	arr[i] = '\0';
	//printf("%s\n", arr)
	int k = 0;
	
	char arr1[25];
	
	for (j = i - 1;j >= 0;j--) {
		c = arr[j];
		arr1[k] = c;
		k++;
	}
	arr1[k] = '\0';
	
	for (j = 0;j < i;j++) {
		mediate = 1;
		if (j == i - 1) {
			if (arr1[j] == '1') {
				x++;
			}
		}
		
		
		else if (arr1[j] == '1' && j != i - 1) {
			for (k = j;k < i - 1;k++) {
				mediate *= 10; 
				//printf("med = %llu\n", mediate);
			}
			x += mediate;
		}
		
	}
	//printf("%llu\n", x);
	return x;
}
 
int main()
{
	int t;
	//scanf("%d", &t);
	t = input();
	while (t--) {
		unsigned long long int x, res;
		//scanf("%llu", &x);
		x = input();
		res = modulo(2, binary(x));
		res = modulo(res, 2);
		//printf("%llu\n", res);
		output(res);
	}		
	return 0;
}
