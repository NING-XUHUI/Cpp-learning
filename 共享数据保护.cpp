//const常类型

class A{
private:
  int x,y;
public:
  A(int i,int j){x = i;y = j;}
  
};

class R{
public:
  R(int r1,int r2):r1(r1),r2(r2){}
  void print();
  void print()const;
private:
  int r1,r2;
};
void R::print(){
  cout<<r1<<":"<<r2<<endl;
}
void R::print()const{
  cout<<r1<<";"<<r2<<endl;
}


int main(){
  //A const a(3,4);

  R a(3,4);
  a.print();//调用print()
  const R b(20,52);
  b.print();//调用print()const
  
  return 0;
}

//常引用：

class Point{
private:
  int x,y;
public:
  Point(int x = 0,int y = 0):x(x),y(y){}
  int getX(){return x;}
  int getY(){return y;}

  friend float dist(const Point &p1,const Point &p2);//只读，不可修改
  
};

float dist(const Point &p1,const Point &p2){
  double x = p1.x - p2.x;
  double y = p1.y - p2.y;

  return static_cast<float>(sqrt(x*x + y*y));
}

