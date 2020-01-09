#include <stdio.h>
#include <math.h>

int IsTheNumber ( const int N );
int main()
{
    int n1, n2, i, cnt;
	
    scanf("%d %d", &n1, &n2);
    cnt = 0;
    for ( i=n1; i<=n2; i++ ) {
        if ( IsTheNumber(i) )
            cnt++;
    }
    printf("cnt = %d\n", cnt);

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

int IsTheNumber( const int N){

	if (sqrt(N) == (int)sqrt(N))
	{
		int n = N;
		int b = getBit(n);
		int a[getBit(n)];

		for (int i = 0; i < b ; i++)
		{
			a[i] = (n % 10);
			n = n / 10;
		}


		for (int k = 0; k < getBit(N) - 1; k++)
		{
			for (int j = k + 1; j < getBit(N); j++)
			{
				if (a[k] == a[j])
				{
					return 1;
				}else
				continue;
			}
		}
		return 0;
	}else 
	return 0;
}