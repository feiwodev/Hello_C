
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

/*预编译*/

/*
	C语言执行流程
	1.编译 - 生成目标代码(.obj)
	2.连接 - 将目标代码与C函数库连接合并 ， 生成最终可执行文件
	3.执行

	预编译（预处理）：为编译做准备 ， 完成代码文本替换工作。
*/

//#define 预编译指令 ， 宏定义 ， 宏替换
// 核心就是替换
// 定义一个常数
#define MAX 100 

// 宏函数
void _jni_define_func_read() {
	printf("read\n");
}

void _jni_define_func_write() {
	printf("write\n");
}

// 定义宏函数
#define jni(NAME) _jni_define_func_##NAME() ;

// 模拟Android日志输出 , 核心就是替换
#define LOG(LEVE,FORMAT,...) printf(##LEVE); printf(##FORMAT,__VA_ARGS__) ;
#define LOGI(FORMAT,...) LOG("INFO:",##FORMAT,__VA_ARGS__) ;
#define LOGE(FORMAT,...) LOG("ERROR:",##FORMAT,__VA_ARGS__) ;
#define LOGW(FORMAT,...) LOG("WARN:",##FORMAT,__VA_ARGS__) ;

/**/
void main() {

	int i = 99;
	if (i < MAX) // 在编译时期， 会将MAX替换成100
	{
		printf("i 小于 MAX\n");
	}


	// 宏函数
	//jni(read); 可以简化函数名称

	LOGI("%s", "自定义日志。。。。\n");
	LOGE("%s", "我是错误日志...\n");

	system("pause");
}