#include <stdio.h>
#include <stdint.h>

uint32_t trans(uint32_t value){//大小端转换函数
    return ((value & 0x000000FF) << 24) |  // 最低字节移到最高位
           ((value & 0x0000FF00) << 8)  |  // 次低字节移到次高位
           ((value & 0x00FF0000) >> 8)  |  // 次高字节移到次低位
           ((value & 0xFF000000) >> 24);   // 最高字节移到最低位
}

void check_endian() {
    uint32_t test = 0x00000001;
    uint8_t *ptr = (uint8_t *)&test;
    
    if (*ptr == 1) {
        printf("本机为小端模式(Little-endian)\n");
    } else {
        printf("本机为大端模式(Big-endian)\n");
    }
}

// 打印32位整数的字节存储情况
void print_bytes(uint32_t value, const char *desc) {
    uint8_t *bytes = (uint8_t *)&value;
    printf("%s: 0x%08X\n", desc, value);
    printf("字节存储顺序: 0x%02X 0x%02X 0x%02X 0x%02X\n\n",
           bytes[0], bytes[1], bytes[2], bytes[3]);
}

int main()
{
	uint32_t original = 0x12253647;
    
    // 检测并打印本机字节序
    check_endian();
    
    // 打印本机字节序下的存储方式
    print_bytes(original, "本机字节序下的0x12253647");
    
    // 转换为另一端模式并打印
    uint32_t swapped = trans(original);
    print_bytes(swapped, "转换后(另一端模式)的0x12253647");
    
    return 0;
}