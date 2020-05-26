#include <iostream>
#include <memory>
#include <string>
using namespace std;


struct Person:enable_shared_from_this<Person>
{
	void show(){
		cout << "Person" << endl;
	}

	shared_ptr<Person> getShared(){
		return shared_from_this();
	}
};


int main(int argc, char const *argv[])
{
	// shared_ptr<string> stingPointer(new string("heo"));

	// cout << stingPointer.use_count() << endl;
	// cout << *stingPointer << endl;


	// shared_ptr<string> stingPointer2 = stingPointer;

	// cout << stingPointer.use_count() << endl;

	shared_ptr<Person> ptr2;


	{
		shared_ptr<Person> ptr(new Person);
		ptr2 = ptr->getShared();
		cout << ptr.use_count() << endl;

	}

	ptr2->show();

	return 0;
}