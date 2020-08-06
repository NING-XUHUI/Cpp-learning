#include <iostream>

using namespace std;

//struct与class的区别
typedef struct point3d
{
    float x;
    float y;
    float z;
}Point3d;

//若想打印一个Point3d就要定义一个函数如下
void
point3d_print(const Point3d *pd)
{
    printf("(%g, %g, %g)",pd->x,pd->y,pd->z);
}

// 或使用一个宏来打印
#define Point3d_print(pd) \
    printf("(%g, %g, %g)",pd->x,pd->y,pd->z);


/****************************************************/

//使用class实现
class Point3d{
public:
    Point3d(float x=0.0,float y=0.0,float z=0.0):_x(x),_y(y),_z(z){}
    float x(){return _x};
    float y(){return _y};
    float z(){return _z};
    
    void x(float xval){_x = xval;}
    //etc
private:
    float _x;
    float _y;
    float _z;
};

inline ostream& operator << (ostream& os,const Point3d& pt)
{
    os << "(" << pt.x << "," << pt.y << "," << pt.z << ")" << endl;
    return os;
}


// 或者使用多层class层次实现
class Point{
public:
  Point(float x = 0.0):_x(x){}
  float x() {return _x;}
  void x(float xval) {_x = xval;}
  //...
protected:
  float _x;
};

class Point2d:Point{
public:
  Point2d(float x=0.0,float y=0.0):Point(x),_y(y){}
  float y() {return _y;}
  void y(float yval) {_y = yval;}
  //...
private:
  float _y;
};

class Point3d:Point2d{
public:
  Point3d(float x=0.0,Point y=0.0,Point z=0.0):Point2d(x,y),_z(z){}
  float z() {return _z;}
  void z(float zval){ _z = zval; }
private:
  float _z;
};

// 坐标类型参数化的class
template<class type>
class Point3d{
public:
    Point3d(type x = 0.0,type y = 0.0,type z = 0.0):_x(x),_y(y),_z(z){}
    type x() {return _x;}
    void x(type xval){_x = xval;}
    //etc
private:
    float _x;
    float _y;
    float _z;
};

//  坐标类型与坐标数量都参数化

template<class type, int dim>
class Point{
public:
    Point();
//    Point(type coords[dim]){
//        for(int index = 0;index < dim;index++){
//            _coords[index]=*coords;
//            coords++;
//        }
//    }
    Point(type coords[dim]){
        for(int index = 0;index < dim;index++){
            _coords[index]=coords[index];
        }
    }
    type& operator[](int index){
        assert(index<dim && index>=0);
        return _coords[index];
    }
    type operator[](int index)const{
        assert(index<dim && index>=0);
        return _coords[index];
    }
private:
    type _coords[dim];
};

template<class type,int dim>
ostream&
operator<<(ostream &os,const Point<type,dim>& pt)
{
    os << "(";
    for(int ix = 0;ix < dim-1;ix++)
        os << pt[ix] << ",";
    os << pt[dim-1];
    os << ")";
    return os;
}

/**
 * 从struct到class，布局成本是否增加？增加了多少？
 * 答：没有增加，成员函数虽然出现在class内，但是不出现在object中，每一个非内联函数只会诞生一个函数实例。而内联函数则会在每一个使用者（模块）产生一个函数实例。
 * 而c++在布局以及存取时间上面主要的额外负担是有virtual引起的包括：
 * 1.virtual function 用以支持一个有效率的“执行期绑定”(runtime binding)
 * 2.virtual base class 用以实现“多次出现在继承体系中的base class,有一个单一而被共享的实例”
 */ 

int main()
{
    int a[3] = {1,2,3};
    Point<int,3> p1(a);
    cout << p1 << endl;

    return 0;
}

