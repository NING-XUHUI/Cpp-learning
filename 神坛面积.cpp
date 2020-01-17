#include<iostream>
#include<iomanip>
#include<math.h>
class Point{
public:
	void setPoint();
	float getArea(Point p1,Point p2);
private:
	float xPoint;
	float yPoint;
};


void Point::setPoint(){
	float x,y;
	scanf("%f %f",&x,&y);
	xPoint = x;
	yPoint = y;
}

float Point::getArea(Point p1,Point p2){
	float Area = (this->xPoint*p1.yPoint - this->xPoint*p2.yPoint + p1.xPoint*p2.yPoint - p1.xPoint*this->yPoint + p2.xPoint*this->yPoint - p2.xPoint*p1.yPoint)/2.0;
	return Area;
}

int main(int argc, char const *argv[])
{
		
	int number;
	scanf("%d",&number);

	Point ps[number];

	for (int i = 0; i < number; ++i)
	{
		ps[i].setPoint();
	}
	float min = abs(ps[0].getArea(ps[1],ps[2]));
	float a = 0;
	for (int i = 0; i < number; i++)
	{
		for (int j = 0; j < number; j++)
		{
			for (int k = 0; k < number; k++)
			{
				if(i != j && j != k && i != k){
					a = abs(ps[i].getArea(ps[j],ps[k]));
					if (a <= min && a > 0)
					{
						min = a;
					}
					
				}
			}
			
		}
		
	}
	
	std::cout<<min<<std::setprecision(2);


	return 0;
}