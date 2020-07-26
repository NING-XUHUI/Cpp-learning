#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

using namespace std;

int main(){
  /**
     vector:container
     alloccator<int>:allocator
     iterator:vi.begin(),vi.end()
     algorithm:count_if()
     function_adapter(negator):not1
     function_adapter(binder):bind2nd
     function_object:less<int>
   */



  int ia[6] = {27,210,12,47,109,83};
  vector<int,allocator<int>> vi(ia,ia+6);
  cout << count_if(vi.begin(),vi.end(),not1(bind2nd(less<int>(),10)));

  return 0;
}
