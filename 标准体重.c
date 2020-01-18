#include<stdio.h>
#include <math.h>
void getTheCon(int h,int w){
	int value = (h - 100)*0.9*2;
	int s = abs(w - value);
	if (s < value*0.1)
	{
		printf("You are wan mei!\n");
	}else
	if (w < value)
	{
		printf("You are tai shou le!\n");
	}else
		printf("You are tai pang le!\n");

}

int main(){

	int number;
	scanf("%d",&number);
	int H[number],W[number];

	for (int i = 0; i < number; ++i)
	{
		scanf("%d %d",&H[i],&W[i]);
	}

	for (int i = 0; i < number; ++i)
	{
		getTheCon(H[i],W[i]);
	}

	return 0;
}