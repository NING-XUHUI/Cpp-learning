#include <stdio.h>

int Count_Digit ( const int N, const int D );

int main()
{
    int N, D;
	
    scanf("%d %d", &N, &D);
    printf("%d\n", Count_Digit(N, D));
    return 0;
}

/* 你的代码将被嵌在这里 */

int getBit(int n){
	
	int i = 0;

	do{
		i++;
		n = n / 10;
	}while(n != 0);

	return i;
}

int Count_Digit (const int N,const int D){

	int count = 0;
	int n = N;
	if (n < 0)
	{
		n = -n;
	}

	for (int i = 0; i < getBit(N); ++i)
	{
		int a = (n % 10);
		if (a == D)
		{
			count++;
		}
		n = n / 10;
	}
		return count;
}