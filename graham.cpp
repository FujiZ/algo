#include<iostream>
#include<cmath>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

struct Point{
	Point(int a,int b):x(a),y(b){}
	int x;
	int y;
};

Point *point0=NULL;

double distance(const Point& a,const Point& b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

//返回(p1-p0)*(p2-p0)的叉积(x1y2-x2y1)
//>0: <p0,p1>在<p0,p2>顺时针方向
//=0: <p0,p1>与<p0,p2>共线
//<0: <p0,p1>在<p0,p2>逆时针方向
int multi(const Point& p1,const Point& p2,const Point& p0){
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}

bool cmp(Point* a,Point* b){	//当false时交换
	//按极角大小进行排序
	int k=multi(*a,*b,*point0);
	if(k>0) return true;
	//若极角相同则按距离
	else if(k==0) return distance(*a,*point0)<distance(*b,*point0);
	else return false;
}

void print(vector<Point*>& pointSta){
	for(Point* p:pointSta)
		cout<<p->x<<','<<p->y<<endl;
}

void graham(vector<Point*>& pointVec,int n){
	//找到y最小的点
	point0=pointVec.front();
	for(Point* p:pointVec)
		if(p->y<point0->y||(p->y==point0->y&&p->x<point0->x))
			point0=p;
	//按照极角大小排序
	sort(pointVec.begin(),pointVec.end(),cmp);
	vector<Point*> pointSta;
	for(int i=0;i<3;++i)
		pointSta.push_back(pointVec[i]);
	for(int i=3;i<n;++i){
		while(multi(*pointVec[i],**pointSta.rbegin(),**(pointSta.rbegin()+1))>=0)
			pointSta.pop_back();
		pointSta.push_back(pointVec[i]);
	}
	print(pointSta);
}

int main(void){
	int n;
	cin>>n;
	vector<Point*> pointVec;
	for(int i=0;i<n;++i){
		int x,y;
		cin>>x>>y;
		pointVec.push_back(new Point(x,y));
	}
	graham(pointVec,n);
	return 0;
}
