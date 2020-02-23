#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[])
{
	int values[] = {3,7,0,5,4};
	ofstream os("integerss",ios_base::out|ios_base::binary);
	os.write(reinterpret_cast<char*>(values),sizeof(values));
	os.close();

	ifstream is("integerss",ios_base::in|ios_base::binary);
	if (is)
	{
		is.seekg(4*sizeof(int));//移动读取位置
		int v;
		is.read(reinterpret_cast<char*>(&v),sizeof(int));
		cout<<"The 4th integer in the file is :"<<v<<endl;
	}else{
		cout<<"ERROR"<<endl;
	}
	is.close();
	return 0;
}