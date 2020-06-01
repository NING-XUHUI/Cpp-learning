#include<stdio.h>
#include <math.h>


float getPercent(int bit,int tC,int ifO,int ifZ){
	float value;
	float Z = 1;
	float O = 1;

	if(ifZ == 0){
		Z = 1.5;
	}

	if(ifO == 1){
		O = 2;
	}

	value = ((float)tC / bit) * Z * O * 100;


	return value;
}


int main(){
	long long int number;
	int ifZ;
	scanf("%lld",&number);

	if (number>0)
	{
		ifZ = 1;
	}else{
		ifZ = 0;
	}

	long long int temp = (long long int)abs(number);
	number = temp;
	int count = 0;
	while(number != 0){
		number = number / 10;
		count++;
	}

	int bit[count];

	int twoCount = 0;
	for (int i = 0; i < count; ++i)
	{
		bit[i] = temp % 10;
		if (2 == bit[i])
		{
			twoCount++;
		}
		temp = temp / 10;
	}

	int ifo;
	if(bit[0] % 2 == 0){
		ifo = 1;
	}else{
		ifo = 0;
	}

	printf("%.2f%%\n",getPercent(count,twoCount,ifo,ifZ) );




	return 0;
}