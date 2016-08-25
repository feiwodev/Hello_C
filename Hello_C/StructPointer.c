
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*结构体*/

/*
	结构体是一种构造数据类型
	把不同的数据类型整合起来成为一个自定义的数据类型
*/

// 定义一个结构体
// 一个结构体相当于一个java中的类 ， 结构体中只有声明 ， 函数没有实现 ， 属性也不能初始化 ， 一般定义在头文件中
struct Person
{
	char* name;
	int age;
};

struct News {
	// 使用字符数组 ， 在赋值的时候和字符指针略有不同
	char title[128];
	char* content;
};

/*结构体的几种写法*/
// 在声明结构体的时候 ， 定义结构体变量和指针
struct Product {
	char* productName;
	char* productDesc;
}product , *productP;

// 匿名结构 , 没有结构体名称 ， 可以定义多个结构体变量， 可作为单例使用
struct {
	char * name;
	int age;
}person;


/*结构体嵌套 ， 两种嵌套方式*/

// one
struct GoodsBean {
	int total;
	int status;

	struct Goods {
		char* goodsName;
		char* goodsDesc;
	};
};

// two
struct ProductBean
{
	int total;
	int status;

	struct Product product;
};

/*结构嵌套示例*/
void nestingStruct() {
	// one
	printf("\n\n\n\n结构嵌套示例\n\n");
	// 使用字面量的形式赋值
	struct GoodsBean goodsBean = { 10,0,{ "全新Iphone6s","金色全新Iphone6s ， 能与Android手机媲美的Iphone6s" } };
	printf("商品总数：%d\n商品状态：%d\n商品名称：%s\n商品描述：%s\n", goodsBean.total, goodsBean.status, goodsBean.goodsName, goodsBean.goodsDesc);

	// two
	printf("\n\n");
	struct ProductBean productBean;
	productBean.total = 100;
	productBean.status = 0;
	productBean.product.productName = "金色经典 ， 小米5 ， 你值得拥有";
	productBean.product.productDesc = "全新金色小米5 ， 刚买没几个月";

	printf("商品总数：%d\n商品状态：%d\n商品名称：%s\n商品描述：%s\n", productBean.total, productBean.status, productBean.product.productName, productBean.product.productDesc);
}

/*结构体与函数指针*/
struct Dog {
	char* name;
	int age;

	void(*dogWow)(char* wow);
};

void dogWow(char* wow) {
	printf("狗是：%s 叫\n", wow);
}

/*结构体与函数指针的使用*/
void useStructAndFunction() {
	printf("\n\n\n\n");
	printf("结构体中，函数没有实现 ， 在创建结构体时 ， 将函数名称赋值给函数指针即可\n");
	struct Dog dog = { "小黄",3,dogWow };
	dog.dogWow("汪汪。。。");
}

/*结构体数组*/
void useStructArray() {
	printf("\n\n\n\n结构体数组示例\n\n");
	// 结构体数组
	struct Person persons[] = { {"zeno",20},{"非我",24}, {"逝我",23} };
	struct Person *p = &persons;
	int personArrSize = sizeof(persons) / sizeof(struct Person);
	printf("遍历结构体数组：\n");
	// 遍历
	for (; p < persons + personArrSize; p++)
	{
		printf("姓名：%s \t 年龄：%d\n", p->name, p->age);
	}
}

/*结构体与动态内存分配*/
void structAndMalloc() {
	printf("\n\n\n\n结构体与动态内存分配\n\n");
	// 申请堆内存空间 ， 空间地址是连续的
	struct Person* person = (struct Person*)malloc(sizeof(struct Person) * 10);
	struct Person* p = person;
	p->name = "小九";
	p->age = 20;
	p++;
	p->name = "非我";
	p->age = 24;

	printf("遍历结构体动态内存：\n");
	struct Person* loop_p = person;
	// 遍历
	for (; loop_p < person + 2; loop_p++)
	{
		printf("姓名：%s \t 年龄：%d\n", loop_p->name, loop_p->age);
	}
}



/*结构体多种写法的使用*/
void defineMultiStruct() {
	// 在声明结构体的时候定义结构变量 ， 操作方便 ， 不用再定义一遍
	product.productName = "全新X系列宝马 ， X5";
	product.productDesc = "无刮痕 ， 全新X系列宝马 ， 享受驾驶愉悦 ， 就开宝马轿车";

	printf("\n\n\n\n");
	printf("产品信息：\n产品名称：%s\n产品描述：%s\n",product.productName,product.productDesc);


	printf("\n\n\n使用结构体指针 , 使用结构体指针不用.符号 ， 使用->符号来操作结构体成员 , ->操作符是(*p).的简写 \n\n");
	productP = &product;
	printf("产品信息：\n产品名称：%s\n产品描述：%s\n", productP->productName, productP->productDesc);

	/*使用匿名结构体 ， 始终只有一个结构体实例 , 可以作为单例来使用*/
	person.name = "逝我";
	person.age = 23;
	printf("\n\n");
	printf("用户信息：\n用户姓名：%s\n用户年龄：%d\n", person.name, person.age);
}

/*简单使用结构体*/
void makeSimpleStruct() {

	// 使用结构体 ， 使用字面量的形式创建一个结构体
	struct Person person = { "zeno",21 };
	// 打印
	printf("输出：姓名 - %s ; 年龄 - %d\n", person.name, person.age);


	//另一种创建结构体的方式
	struct Person person2;
	person2.name = "非我";
	person2.age = 23;

	printf("\n输出：姓名 - %s ; 年龄 - %d\n", person2.name, person2.age);

	struct News news;
	//news.title 是字符数组 ， 不能直接 news.title = "xxx" ， 需要使用strcpy()函数
	strcpy(news.title, "我是新闻标题");
	news.content = " 我是新闻正文";

	printf("\n\n输出：\n标题 \n %s \n正文：\n  %s\n", news.title, news.content);
}

/*类型别名 关键字：typedef*/
/*
	1.不同名称代表在干不同的事情typedef int jint;
	2.不同情况下，使用不同的别名
	3.书写简洁
*/
// 简单别名

typedef char* Name;

// 结构体别名
typedef struct ImageInfo {
	char* name;
	int size;
	char* path;
}ImageInfo , *ImageInfo_P;

/*修改文件名称*/
void reFileName(ImageInfo_P imgeInfo_p, char* reName) {
	imgeInfo_p->name = reName;
}

/*类型别名示例*/
void useTypedef() {
	// 普通变量别名使用
	printf("\n\n\n\n类型别名示例\n\n");
	Name name = "zeno";
	printf("类型别名：Name = %s\n", name);

	/*结构体别名使用 , 和使用java对象类似*/
	ImageInfo imageInfo;
	char pathStr[120] = {"D://imag//"};
	imageInfo.name = "美丽风景.jpg";
	// 修改文件名称
	reFileName(&imageInfo, "大中国.jpg");

	imageInfo.size = 2333;
	// 拼接字符串
	strcat(pathStr, imageInfo.name);
	imageInfo.path = pathStr;


	printf("\n\n文件信息：\n文件名：%s\n文件大小：%d kb\n文件路径：%s\n", imageInfo.name, imageInfo.size, imageInfo.path);

}



//void main() {
//	
//	/*简单使用结构体*/
//	makeSimpleStruct();
//
//	/*结构体多种写法的使用*/
//	defineMultiStruct();
//
//	/*结构嵌套示例*/
//	nestingStruct();
//
//	/*结构体数组*/
//	useStructArray();
//
//	/*结构体与动态内存分配*/
//	structAndMalloc();
//
//	/*结构体与函数指针的使用*/
//	useStructAndFunction();
//
//	/*类型别名示例*/
//	useTypedef();
//
//	system("pause");
//}

