
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <math.h>
#include <time.h>


/*函数*/
void message() {
	MessageBox(NULL, "我是弹出框", "消息", NULL);
}

int add(int num1, int num2) {
	
	return num1 + num2;
}

int minus(int num1, int num2) {
	
	return num1 - num2;
}

/*查找最小值*/
int * sreachLeast(int arr[] , int len) {

	int *p = &arr[0];
	int i = 0;
	for (; i < len ; i++)
	{
		if (arr[i] < *p)
		{
			*p = arr[i];
		}
	}

	return p;
}

/*模拟网络请求回调*/
void requestNet(char* url , void(*callBack)(char *)) {
	printf("请求地址：%s , 正在请求网络....\n",url);
	// 模拟网络请求耗时
	Sleep(2000);
	char* str = "我是请求的网络数据 ， 落花有意随流水 ， 流水无情恋落花\n";
	callBack(str);
}

/*回调函数*/
void netCallBack(char *str) {
	printf("网络请求回调\n");
	printf("请求到的数据：%s" ,str);
}

// 将函数指针字节定义到方法传入参数中 ， 类似java中的多态
void showMsg(int(*c)(int num1, int num2), int a, int b) {
		int r = c(a, b);
		printf("计算完成=%d\n", r);
}

/*
void main() {

	// 函数指针定义 , void 返回值(函数指针名称)(函数参数) = 函数名称
	//void(*func_p)() = message;
	//// 调用函数指针
	//func_p();
	//// 函数指针通过函数指针实行调用
	//printf("函数指针地址：%#x\n", message);
	//printf("函数指针地址：%#x\n", &func_p);

	showMsg(add, 10, 10);

	showMsg(minus, 30, 2);

	char* url = "www.zhuyongit.com";
	requestNet(url, netCallBack);

	//随机生成数组
	//int arr[10];
	//int i = 0;
	//int len = sizeof(arr) / sizeof(int);

	//printf("计算数组大小：%d\n", len);
	//srand(unsigned(time(NULL)));
	//for (; i < len ; i++)
	//{
	//	arr[i] = rand() % 100;

	//	printf("arr[%d] = %d\n", i,arr[i]);
	//}

	//int* p = sreachLeast(arr, len);

	//printf("最小值：%d\n", *p);
	//printf("最小值地址：%#x\n", p);

	getchar();
}*/