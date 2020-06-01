#include<stdio.h>
#include<math.h>
int max(int a,int b){

	return a > b ? a : b;
}

int diffNum(int year){
	if (year < 10)
	{
		return 3;
	}
	else if (year < 100)
	{
		return 2;
	}else {
	int bit[4];
	for (int i = 0; i < 4; ++i)
	{
		bit[i] = year % 10;
		year = year / 10;
	}

	int count[3] = {0,0,0};

	for (int i = 0; i < 3; ++i)
	{
		for (int j = i; j < 4; ++j)
		{
			if (bit[i] == bit[j])
			{
				count[i]++;
			}
		}
	}

	int m1 = max(count[0],count[1]);

	int m2 = max(m1,count[2]);


	return m2;
}
}
int main(){


	int year = ;

	printf("%d\n",diffNum(year) );


	return 0;
}