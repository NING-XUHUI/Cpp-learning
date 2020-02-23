#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[])
{
	ifstream file("integerss",ios_base::in|ios_base::binary);
	if (file)
	{
		while(file){//读到文件尾部file为0
			streampos here = file.tellg();
			int v;
			file.read(reinterpret_cast<char*>(&v),sizeof(int));
			if (file&&v==5)
			{
				cout<<"Position:"<<here<<" is 0"<<endl;
			}
		}
	}else{
		cout<<"ERROR"<<endl;
	}
	file.close();
	return 0;
}