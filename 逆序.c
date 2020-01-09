#include<stdio.h>
int getBit(int n);
int main(int argc, char const *argv[])
{
	
	int a;
	scanf("%d",&a);

	int b = getBit(a);

	int c[b];
	for (int i = 0; i < b; ++i)
	{
		c[i] = (a % 10);
		a = a / 10;
	}

	int d = 0;
	for (int i = 0; i < b; ++i)
	{
		if (c[i] == 0 && d == 0)
		{
			continue;
		}


		if(c[i] != 0){
			d = 1;
			printf("%d",c[i] );
		}else{
		printf("%d",c[i] );
	}
}


	
	printf("\n");
	return 0;

}
int getBit(int n){
	
	int i = 0;

	do{
		i++;
		n = n / 10;
	}while(n != 0);

	return i;
}