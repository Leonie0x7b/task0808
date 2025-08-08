#include <stdio.h>
#include "calvector.h"

int main(){
	//第一问
	vector3f D1A={1.f,0.f,1.f};
	vector3f D1C1={0.f,1.f,0.f};
	vector3f AC1=vsub(D1C1,D1A);//直线方向向量
	vector3f D1B={1.f,1.f,0.f};
	vector3f C1B=vsub(D1B,D1C1);
	float ans1;
	ans1=vlength(vcross(C1B,AC1))/vlength(AC1);
	printf("点B到直线AC1的距离是%.4f\n",ans1);
	
	//第二问
	vector3f D1E={1.f,0.5f,0.f};
	vector3f AE=vsub(D1E,D1A);
	vector3f n=vcross(AE,AC1);//平面法向量
	vector3f D1F={1.f,0.5f,1.f};
	//由几何关系易得直线与平面平行
	float ans2;
	ans2=fabs(vdot(n,D1F)-vdot(n,D1E))/vlength(n);
	printf("直线FC到平面AEC1的距离是%.4f\n",ans2);
	
	return 0;
}