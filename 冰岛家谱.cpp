#include <iostream>
using namespace std;

#define MAXSIZE (10000000)

int arr[MAXSIZE];
void Union(int x, int y);
int Judge(int x);

int main(){
    for(int i = 0;i < MAXSIZE;i++){
        arr[i] = i;
    }

    int count;
    cin >> count;
    for(int i = 0;i<count;i++){
        int a,b,c;
        cin >> a >> b >> c;
        if(a == 1){
            Union(b,c);
        }else{
            if(Judge(b) == Judge(c)){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}

int Judge(int x){
    if(arr[x] == x){
        return x;
    }else{
        return Judge(arr[x]);
    }
}

void Union(int x, int y){
    int p = Judge(x);
    int q = Judge(y);
    if(p == q){
        return;
    }
    if(q > p){
        arr[q] = p;
    }else{
        arr[p] = q;
    }
}
