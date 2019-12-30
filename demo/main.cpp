#include <fstream>
#include <iostream>
using  namespace std;

void open(char str[]){
    int i = 0;
    ifstream f;
    f.open("ok.txt");
    if(!f){
        cout<<"not open"<<endl;
        return;;
    }
    while (f){
        f.get(str[i]);
        i++;
    }
    str[i] = '\0';
    f.close();
    cout<<str<<endl;
}

int len(char str[]){
    for (int i = 0,temp = 0; str[i] != '\0' ; i++) {
        temp++;

        return temp;
    }
}
int index(char a[],char b[]){
    int i,j,temp;
    for (int i = 0; i < len(a) - len(b) ; i++) {
        temp = i;
        j = 0;
        while (j<=len(b) && a[temp]==b[j]){
            temp++;
            j++;
        }
        if (j==len(b))
            return i;
    }
    return  -1;
}

int count(char str[]){
    int i,c = 0;
    for (i = 0; i < len(str) ; i++)
        if (str[i] == ' ')
            c++;

    return  c+1;

}

void output(char a[]){
    for (int i = 0; i < len(a); ++i) {
        cout<<a[i];

        cout<<endl;
    }
}

void  output(char str[],int){
    for (int i = 0; i < len(str); ++i)
        if (str[i]==' ')
            break;
        else
            cout<<str[i];

        cout<<endl;

}

int main() {
    //创建文件
//    ofstream SaveFile("file_test.txt");
//    SaveFile<<"Hello!";


/*/文件的打开
    ofstream  ou("file_create.txt");
    ifstream  in;
    ou<<"Hello!";
    in.open("file_create.txt");

    if (in.fail())
        cout<<"文件不存在"<<endl;
    else
        cout<<"文件已经打开"<<endl;

    in.close();
    */

/*  文件的关闭
    ifstream  in;
    in.open("file_create.txt");
    if (in.fail()){
        cout<<"文件不存在"<<endl;
    } else
        cout<<"文件已打开"<<endl;

    in.close();
    cout<<"文件已关闭"<<endl;

*/

/*读写文本文件
    ofstream  fout("test.txt");
    if (!fout){
        cout<<"无法打开文件"<<endl;
        return 1;
    }

    fout<<"hello ! world !"<<endl;
    fout<<10<<endl;
    fout<<hex<<11<<endl;
    fout.close();
    ifstream fin("test.txt");
    if (!fin){
        cout<<"无法打开"<<endl;
        return 1;
    }

    int i;
    char ch;
    char c[20];
    fin>>c;
    fin>>i;
    fin>>ch;
    cout<<c<<endl;
    cout<<i<<endl;
    cout<<ch<<endl;
    fin.close();

 */

    char m[100];
    char n[]="ok";
    open(m);
    cout<<"单词长度："<<len(m) - 1<<endl;
    cout<<"目标单词数："<<index(m,n)<<endl;
    cout<<"单词数"<<count(m)<<endl;
    output(m);
    output(m,1);



    return 0;
}
