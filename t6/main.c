#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

int main(){
	uint32_t res=0;
	
	//初始化随机种子
	srand((unsigned int)time(NULL));

	 for(int i=0;i<32;i++){
	 	int randomnum=rand()%101;//随机数控制在0-100之间
	 	
	 	printf("这是第%d个随机数：%d\n",i+1,randomnum);
	 	if(randomnum>50){
	 		res |=1U<<i; //1U是无符号整数，向右移动i位，使得第i位为1，其余为0，res取位或操作，第i位变为1，其余不变
		 }
	 }

     printf("\n最终结果: 十进制 = %u, 十六进制 = 0x%X\n", res, res);

	// 输出二进制
    printf("二进制表示: ");
    for (int i = 31; i >= 0; i--) {
        printf("%d", (res >> i) & 1);//打印操作，将res右移，将关注的第i位移到最低位，与1取按位与，打印出最后1位
        if (i % 8 == 0) printf(" ");  // 每8位分割
    }
    printf("\n");
    
    return 0;
}
