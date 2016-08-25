
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

/*联合体 ， 枚举 ， 文件IO*/

/*联合体*/
/*
	不同类型的变量共用一段内存（相互覆盖） ， 始终只有一个成员存在 ， 最后赋值的那个 ， 有利于节省内存
	联合体大小：成员中最大的成员所占的字节数
*/
union mValue
{
	int		i;
	short	s;
	long	l;
	float	f;

};

/*联合体示例*/
void useUnion() {
	union mValue m;
	m.f = 23.4f;
	m.i = 100;  // 最后一次赋值有效

	printf("联合体：\n%f - %d\n", m.f, m.i);
}

/*枚举*/
/*
	枚举（列举所有的情况）
	限定值，保证取值的安全性
*/
enum NetStatus {
	NET_SUCEESS,
	NET_ERROR,
	NOT_NET,
	NET_FAILURE
};

/*模拟网络请求*/
void requestHttp(char* url, void(*callBack)(enum NetStatus status,char* res)) {
	printf("请求地址：%s\n", url);
	printf("请求网络....\n");
	Sleep(2000);
	enum NetStatus status = NET_SUCEESS;
	char* res = "如果 爱情是一场花火 ,一闪即逝的花火,我也要去追求\n";
	callBack(status, res);
}

/*网络回调函数*/
void callBackHttp(enum NetStatus status, char* res) {
	switch (status)
	{
	case NET_SUCEESS:
		printf("网络数据：\n%s", res);
		break;
	case NET_ERROR:
		printf("网络错误：\n");
		break;
	case NOT_NET:
		printf("没有网络：\n");
		break;
	case NET_FAILURE:
		printf("请求网络错误：\n");
		break;
	default:
		printf("未知错误：\n");
		break;
	}
}

/*枚举示例*/
void useEnum() {
	enum NetStatus status = NET_FAILURE;

	printf("枚举中元素的值：%d\n", status);

	char* url = "http://www.zhuyongit.com";
	requestHttp(url, callBackHttp);
}


/*文件IO*/

/*读取文本文件*/
void readTextFile() {
	char* path = "C:\\Users\\Zeno\\Documents\\Visual Studio 2015\\Projects\\Hello_C\\Hello_C\\StructPointer.c";

	// 打开文件
	FILE* fp = fopen(path, "r");
	if (fp == NULL)
	{
		printf("打开文件失败\n");
		return;
	}
	// 字符缓冲区 ， 每次读一个字符串 ， 都会缓存到字符数组中
	char buffer[1024];
	while (fgets(buffer, 1024, fp)) {
		printf("%s", buffer);
	}

	// 关闭文件流
	fclose(fp);
}

/*写入文本文件*/
void writeTextFile() {
	char* path = "E:\\document\\write.txt";

	char* content = "如果 爱情是一场花火 ,一闪即逝的花火,我也要去追求\n如果 爱情是一场花火 ,一闪即逝的花火,我也要去追求\n";

	// 打开文件
	/*
		打开只写文件，若文件存在则文件长度清为0，即该文件内容会消失。若文件不存在则建立该文件。
	*/
	FILE* fp = fopen(path, "w");
	if (fp == NULL)
	{
		printf("打开文件失败\n");
		return;
	}
	// 写入文件
	fputs(content, fp);

	// 关闭文件流
	fclose(fp);
}

/*读写二进制文件 -- 复制文件*/
void fileCopy() {
	char* currentPath = "E:\\android_pdf\\研磨设计模式.pdf";
	char* destPath = "E:\\android_pdf\\研磨设计模式_new.pdf";

	// 打开文件
	FILE* currentFile_P = fopen(currentPath, "rb");
	FILE* destFile_P = fopen(destPath, "wb");

	// 先读取再写入
	int buffer[1024]; // 数据缓冲区
	int len; // 每次读取数据的长度
	while ((len = fread(buffer,sizeof(int),1024,currentFile_P)) != EOF)
	{
		// 将缓冲区里的内容写入到文件中
		fwrite(buffer, sizeof(int), len, destFile_P);
	}

	// 关闭流
	fclose(destFile_P);
	fclose(currentFile_P);
}

/*加密文件*/
void encryptFile() {

	// 待加密文件路径
	char* normal_path = "E:\\poto\\xj.jpg";
	// 加密后文件路径
	char* encrypt_path = "E:\\poto\\xj_encrypt.jpg";

	//打开文件
	FILE* normal_fp = fopen(normal_path, "rb");
	FILE* encrypt_fp = fopen(encrypt_path, "wb");
	// 读文件
	int buffer;
	while ((buffer = fgetc(normal_fp)) != EOF) {
		// 写入文件
		fputc(buffer ^ 8, encrypt_fp);
	}

	printf("文件加密成功\n");

	// 关闭流
	fclose(encrypt_fp);
	fclose(normal_fp);
}

/*文件解密*/
void decryptFile() {
	// 加密文件路径
	char* encrypt_path = "E:\\poto\\xj_encrypt.jpg";
	// 解密文件路径
	char* decrypt_path = "E:\\poto\\xj_deencrypt.jpg";

	// 打开文件
	FILE* encrypt_fp = fopen(encrypt_path, "rb");
	FILE* decrypt_fp = fopen(decrypt_path, "wb");

	// 读取文件
	int buffer;
	while ((buffer = fgetc(encrypt_fp)) != EOF) {
		// 写文件
		fputc(buffer ^ 8, decrypt_fp);
	}

	printf("文件解密成功\n");

	// 关闭流
	fclose(decrypt_fp);
	fclose(encrypt_fp);
}

/*带密码的文件加密*/
void passwordEncryptFile(char password[]) {
	// 待加密文件路径
	char* normal_path = "E:\\poto\\xj.jpg";
	// 加密文件路径
	char* encrypt_path = "E:\\poto\\xj_encrypt.jpg";

	// 打开文件
	FILE* normal_fp = fopen(normal_path,"rb");
	FILE* encrypt_fp = fopen(encrypt_path, "wb");

	// 读文件
	int buffer;
	int i = 0;
	int passwordCount = strlen(password);
	while ((buffer = fgetc(normal_fp)) != EOF)
	{
		// 写文件
		fputc(buffer ^ password[i % passwordCount], encrypt_fp);
		i++;
	}

	printf("文件加密成功\n");

	// 关闭流
	fclose(encrypt_fp);
	fclose(normal_fp);
}

void passwordDecryptFile(char password[]) {
	// 加密文件路径
	char* encrypt_path = "E:\\poto\\xj_encrypt.jpg";
	// 解密文件路径
	char* decrypt_path = "E:\\poto\\xj_decrypt.jpg";

	// 打开文件
	FILE* encrypt_fp = fopen(encrypt_path, "rb");
	FILE* decrypt_fp = fopen(decrypt_path, "wb");

	// 读文件
	int buffer;
	int i = 0; 
	int passwordCount = strlen(password);
	while ((buffer = fgetc(encrypt_fp)) != EOF) {
		// 写文件
		fputc(buffer ^ password[i % passwordCount], decrypt_fp);
		i++;
	}
	printf("文件解密成功\n");


	// 关闭流
	fclose(decrypt_fp);
	fclose(encrypt_fp);

}

/*获取文件大小*/
void getFileSize() {

	char* path = "E:\\android_pdf\\研磨设计模式.pdf";
	// 打开文件
	FILE* fp = fopen(path, "r");
	if (fp == NULL) {
		printf("打开文件失败\n");
		return;
	}

	// 重新定位文件指针 , SEEK_END文件末尾，0偏移量
	fseek(fp, 0l, SEEK_END);
	// 返回当前的文件指针，相对于文件开头的位移量
	long fileSize = ftell(fp);

	printf("文件大小：%ld M\n", fileSize / 1024 / 1024);

}

/*
void main() {

	// 联合体示例
	//useUnion();
	
	// 使用枚举
	useEnum();

	// 读取文本文件
	//readTextFile();

	// 写入文本文件
	//writeTextFile();

	// 二进制文件复制
	//fileCopy();

	// 获取文件大小
	//getFileSize();

	// 加密文件
	//encryptFile();

	// 解密文件
	//decryptFile();

	// 密码加密文件
	//passwordEncryptFile("my love");

	// 密码解密文件
	//passwordDecryptFile("my love");

	system("pause");
}*/