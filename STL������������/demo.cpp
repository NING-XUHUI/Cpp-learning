#include<vector>
#include<algorithm>
#include<functional>
#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
	{
		int ia[6] = {27,210,12,47,109,83};
		vector<int> vi(ia,ia+6);
		cout<<count_if(vi.begin(),vi.end(),not1(bind2nd(less<int>(),40)))<<endl;;

		auto ite = ::find(vi.begin(),vi.end(),109);

		cout<<*ite<<endl;
		return 0;
	}

	auto ite = ::find(vi.begin(),vi.end(),109);

	//count_if:	如果满足条件，则count加1
	//bind2nd:	需要第二参数
	//not1: 	否定