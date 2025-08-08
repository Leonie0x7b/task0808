#include<stdio.h>
#include<string.h>

int main()
{
	float a,b;
	printf("请输入两个小数：(以空格分隔)");
	scanf("%f %f",&a,&b);
	char arr[8];
	
	//方法1：使用memcpy
	memcpy(arr,&a,4);
	memcpy(arr+4,&b,4);
	
	float a1,b1;
	memcpy(&a1,arr,4);
	memcpy(&b1,arr+4,4);
	
	//方法2,强制类型转换
	*(float*)(arr)=a;
	*(float*)(arr+4)=b;
	
	float a2,b2;
	a2=*(float*)(arr);
	b2=*(float*)(arr+4);
	
	//方法3，拆分
	unsigned char* p1=(unsigned char*)&a;
	unsigned char* p2=(unsigned char*)&b;
	for(int i=0;i<4;i++) arr[i]=p1[i];
	for(int i=0;i<4;i++) arr[i+4]=p2[i];
	
	float a3,b3;
	unsigned char *p3 = (unsigned char*)&a3;
	unsigned char *p4 = (unsigned char*)&b3;
	for (int i = 0; i < 4; i++) p3[i] = arr[i];     // 还原 a3
	for (int i = 0; i < 4; i++) p4[i] = arr[4 + i]; // 还原 b3

	// 输出结果
    printf("原始值: a = %.6f, b = %.6f\n", a, b);
    printf("方法1: a1 = %.6f, b1 = %.6f, 差 = %.8f, %.8f\n",
           a1, b1, a - a1, b - b1);
    printf("方法2: a2 = %.6f, b2 = %.6f, 差 = %.8f, %.8f\n",
           a2, b2, a - a2, b - b2);
    printf("方法3: a3 = %.6f, b3 = %.6f, 差 = %.8f, %.8f\n",
           a3, b3, a - a3, b - b3);

	
	return 0;
}