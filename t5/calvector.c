#include "calvector.h"

vector3f vadd(vector3f v1,vector3f v2){//向量相加
	vector3f res;
	res.x=v1.x+v2.x;
	res.y=v1.y+v2.y;
	res.z=v1.z+v2.z;
	return res;
} 

vector3f vsub(vector3f v1,vector3f v2){//向量相减
	vector3f res;
	res.x=v1.x-v2.x;
	res.y=v1.y-v2.y;
	res.z=v1.z-v2.z;
	return res;
}

float vdot(vector3f v1,vector3f v2){//向量点乘
	return v1.x*v2.x+v1.y*v2.y+v1.z*v2.z;
}

float vlength(vector3f v){//向量的模
	return sqrtf(v.x*v.x+v.y*v.y+v.z*v.z);
}

vector3f vnorm(vector3f v){//向量单位化
	vector3f res;
	float len=vlength(v);
	if(len==0.0f){
		return v;
	}
	res.x=v.x/len;
	res.y=v.y/len;
	res.z=v.z/len;
	return res;
}

vector3f vcross(vector3f v1,vector3f v2){//向量叉乘
	vector3f res;
	res.x=v1.y * v2.z - v1.z * v2.y;
	res.y=v1.z * v2.x - v1.x * v2.z;
	res.z=v1.x * v2.y - v1.y * v2.x;
	return res;
}
