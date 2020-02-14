#include<iostream>

using namespace std;

int main(){
	unsigned aCnt = 0,eCnt = 0,iCnt = 0,oCnt = 0,uCnt = 0;
	char ch;
	while(cin>>ch){
		switch (ch){
			case 'a':
				++aCnt;
				break;
			case 'e':
				++eCnt;
				break;
			case 'i':
				++iCnt;
				break;
			case 'o':
				++oCnt;
			case 'u':
				++uCnt;
		}
	}
	cout<<"The number of a:"<<aCnt<<endl;
	cout<<"The number of e:"<<eCnt<<endl;
	cout<<"The number of i:"<<iCnt<<endl;
	cout<<"The number of o:"<<oCnt<<endl;
	cout<<"The number of u:"<<uCnt<<endl;

	return 0;
}