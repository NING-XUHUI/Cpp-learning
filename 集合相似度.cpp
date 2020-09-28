#include <iostream>
#include <set>

using namespace std;

set<int> sets[50];
int getJiaoji(int &s1, int &s2){
    int sum = 0;
    for(auto &item : sets[s1-1]){
        if(sets[s2-1].count(item))
            sum++;
    }
    return sum;
}

int main()
{
    int setCount;
    cin >> setCount;

    for(int i = 0;i<setCount; i++){
        int eleCount;
        cin >> eleCount;
        for(int j = 0;j<eleCount;j++){
            int ele;
            cin >> ele;
            sets[i].insert(ele);
        }
    }
    
    int wantCount;
    cin >> wantCount;
    for(int i = 0;i<wantCount;i++){
        int s1,s2;
        cin >> s1 >> s2;
        int jiaoji = getJiaoji(s1,s2);
        printf("%.2f%%\n", (double)(jiaoji) / ((double)(sets[s1].size() + sets[s2].size() - jiaoji)) * 100.0);
    }

    return 0;
}

