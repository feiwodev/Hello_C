
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

/*
	C语言内存分配：
	1.栈区（stack） win 1~2M（是一个确定的常数） 超出会提示stackoverflow
		自动分配 ， 自动释放
	2.堆区（heap）
		手动分配和释放 ， 80%内存
	3.全局区或静态区
	4.字符常量区
	5.程序代码区
	
*/

/*栈内存分配*/
void stackFunc() {
	int arr[1024];
}

/*动态内存分配*/
void heapFunc() {
	// 动态内存分配 ， 使用malloc函数在对内存中开辟连续的内存空间 , 单位是：字节
	// 申请一块40M的堆内存
	int* p = (int*)malloc(1024 *1024 * 10 * sizeof(int));

	// 回收内存
	//free(p);
}


/* 动态内存分配 */
/*
void main() {

	while (1)
	{
		Sleep(1000);
		heapFunc();
	}

	getchar();

}*/

/*动态指定内存大小*/
/*
	静态内存分配，分配内存大小的是固定，问题：1.很容易超出栈内存的最大值 2.为了防止内存不够用会开辟更多的内存，容易浪费内存
	动态内存分配，在程序运行过程中，动态指定需要使用的内存大小，手动释放，释放之后这些内存还可以被重新使用（活水）
*/
/*
void main() {

	int len;
	printf("请输入首次分配内存大小：");
	scanf("%d", &len);
	// 动态分配内存 ， 内存空间是连续的
	int* p = (int*)malloc(len * sizeof(int));
	// 给申请的内存空间赋值
	int i = 0;
	for (; i < len ; i++)
	{
		p[i] = rand() % 100;

		printf("array[%d] = %d , %#x\n", i, p[i], p);
	}

	// 在原有内存上面，重新分配内存大小
	printf("请输入增加的内存大小");
	int add;
	scanf("%d", &add);
	// 重新申请内存大小 ， 传入申请的内存指针 ， 申请内存总大小
	int* p2 = (int*)realloc(p, (len + add) * sizeof(int));
	// 给新申请的内存空间赋值
	int j = len;
	for (; j < len + add ; j++)
	{
		p2[j] = rand() % 200;
	
	}

	// 打印
	j = 0;
	for (; j < len + add; j++)
	{
		printf("array[%d] = %d , %#x\n", j, p2[j], &p2[j]);
	}
	
	// 回收申请的动态内存
	if (p2 != NULL)
	{
		free(p2);
		p2 = NULL;
	}
		
	system("pause");
}*/


/*
	内存分配的几个注意细节：
	1.不能多次释放
	2.释放完之后 ， 给指针置NULL，标志释放完成
	3.内存泄漏 （p重新赋值之后 ， 再free ， 并没有真正释放 ， 要在赋值之前释放前一个内存空间）
*/