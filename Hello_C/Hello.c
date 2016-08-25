
#define _CRT_SECURE_NO_WARNINGS // 宏定义

/*头文件里面只有函数的声明 ， 编译的时候会找到函数的实现*/
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

/* C语言中主函数 ， 只有函数名称是强制的 ， 函数的返回值可以有也可以是void ， 函数的参数
   也可以是多个 。
*/

/*
int main() {

	printf("Hello World");
	MessageBox(NULL, "dd", "dd", NULL);
	getchar();

	return 0;
}*/

/*C 语言的基本数据类型 , 输出占位符

	int - %d 
	short - %d 
	long - %ld 
	float - %f 
	double - %lf 
	char - %c
	字符串 - %s
	八进制 - %o
	十六进制 - %x

*/

/*
void main() {
	
	int i = 90;
	printf("int 所占字节：%d\n", sizeof(int));
	printf(" i 的值：%d\n", i);
	
	short sh = 32;
	printf("short 所占字节数：%d\n", sizeof(short));
	printf("sh 的值：%d\n", sh);

	long l = 12312;
	printf("long 所占字节数：%d\n", sizeof(long));
	printf("l 的值：%ld\n", l);

	float f = 12.3;
	printf("float 所占字节数：%d\n", sizeof(float));
	printf("f 的值：%f\n", f);

	double d = 234.345;
	printf("double 所占字节数：%d\n", sizeof(double));
	printf("d 的值：%lf\n", d);

	char c = 'c';
	printf("char 所占字节数：%d\n", sizeof(char));
	printf("c 的值：%c\n", c);

	// 输出字符串
	printf("输出字符串：%s\n", "我是输出的字符串");

	// 输出八进制
	printf("输出八进制：%#o\n", 023);

	// 输出十六进制
	printf("输出十六进制：%#x\n", 0x23443);

	system("pause");

}*/

/*
void main() {

	int i;
	printf("请输入一个整数"); 
	// 从控制台输入 ， 使用&取地址符 ， 来接收输入的值
	scanf("%d", &i);
	
	printf("你输入的是：%d\n", i);

	system("pause");

}*/

/* 想要修改传入变量的值 ， 则需要使用指针通过变量的地址 ， 来修改变量的值
void changeNum(int* i) {
	 printf("函数中i的地址：%#x\n", i);
	*i = 300;
} */

/*没有使用指针的函数
void changeNum(int i) {

	printf("函数中i的地址：%#d\n", i);
	i = 300;
}*/


// 指针存储的是变量的内存地址 , 只能存储内存地址 ， 直接赋值整数值也会转化成内存地址
// 内存地址是系统给数据分配的编号
/*
void main() {

	int i = 100;

	int *p = &i;

	//printf("i 的地址：%#x\n", &i);
	//printf("i 的地址：%#x\n", p);
	//printf("i 的值: %d\n", *p);
	printf("传入函数的 i 的地址：%#x\n",&i);
	// 将变量i传入到函数中 , 不对变量去区地址
	changeNum(&i);

	printf("修改后的值：%d\n", i);

	system("pause");

}*/


/*简单外挂注入*/
/*
void main() {

	int time = 500;
	printf("time 内存地址：%#x\n", &time);

	while (time > 0) {
		time--;
		printf("游戏运行中...%d\n", time);
		// 睡一秒钟
		Sleep(1000);
	}

	system("pause");

}*/

/*指针类型*/
/*
void main() {
	// 指针为什么要有类型 ？
	// 地址是开始读取的位置 ， 类型是读取的长度
	// 此处有待商讨 ， int and float 都是4字节数 ， 却还是取不到。

	int i = 100;
	int* p = &i;

	float j = 98.4;

	p = &j;

	printf("i 的地址：%#x\n", p);
	printf("int size : %d\n", sizeof(int));
	printf("float size:%d\n", sizeof(float));
	printf("p 读取的值：%f\n", *p);

	getchar();
}
*/
/*
void main() {
	int i = 10;
	// p指针变量存储的是i的内存地址
	int* p = &i;
	// p1指针变量存储的是p的内存地址
	int** p1 = &p;

	int *p2 = 100;

	printf("指针作为普通变量：%d\n", p2);

	printf("i 的地址：%#x\n", &i);

	printf("p 地址：%#x\n", &p);

	printf("通过p1取得p的地址：%#x\n", p1);
	printf("通过p1取得i的地址：%#x\n", *p1);
	printf("通过p1取得i的值：%d\n", **p1);

	// 通过p1修改i的值
	**p1 = 100;

	printf("通过p1修改过的i的值：%d\n", i);

	getchar();
}
*/

/*指针运算*/
/*
void main() {
	
	int arr[] = { 89,20,13,45,68 };

	// 数组地址 ， 默认是首个元素的内存地址
	printf("输出数组arr地址：%#x\n", &arr);
	printf("这样也可以获取到数组的地址：%#x\n", arr);
	printf("第一个元素的地址: %#x\n", &arr[0]);

	//int* p = &arr;
	float *p = &arr;

	printf("指针变量存储的值：%#x -- 取值:%d\n", p,*p);

	int i = 0;
	for (; i < 5; i++)
	{
		printf("数组元素：%d == 数组元素地址：%#x\n", arr[i],&arr[i]);
	}

	printf("\n");

	
	int j = 0; 
	for (; j < 5; j++)
	{
		printf("数组元素的值 ： %d == 指针存储的地址：%#x\n", *p,p);
		p++;
	}
	
	int k = 0;
	for (; p < arr + 5; p++) {
		
		*p = k;
		k++;

		printf("*p value : %d\n", *p);
	}

	printf("\n");

	int j = 0;
	for (; j < 5; j++)
	{
		printf("数组元素：%d\n", arr[j]);
	}

	getchar();
}
*/