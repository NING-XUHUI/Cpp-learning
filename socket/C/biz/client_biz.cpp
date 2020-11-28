/*************************************************************************
    > File Name: client_biz.cpp
    > Author: Leoning
    > Mail: 1998ok4nxh@gmail.com 
    > Created Time: 2020年11月28日 星期六 13时38分18秒
 ************************************************************************/

#include "../freeplus/freecplus/_freecplus.h"

CTcpClient TcpClient;		// 创建客户端对象

bool biz001();

int main(int argc, char *argv[])
{
	if (TcpClient.ConnectToServer("127.0.0.1", 5000) == false) // 发起请求
	{
		printf("TcpClient.ConnectToServer failed\n");
		return -1;
	}
	
	// 身份验证
	if (biz001() == false) 
	{
		printf("biz001() failed\n");
		return -1;
	}
	// 程序直接退出，析构函数释放资源
}

bool biz001()
{
	char strbuffer[1024];		// 存放数据的缓冲区
	memset(strbuffer, 0, sizeof(strbuffer));
	snprintf(strbuffer, 1000, "<bizcode>1</bizcode><username>wucf</username><password>p@ssw0rd</password>");
	printf("发送：%s\n", strbuffer);
	if (TcpClient.Write(strbuffer) == false) return false;

	memset(strbuffer, 0, sizeof(strbuffer));
	if (TcpClient.Read(strbuffer, 20) == false) return false;
	printf("接收：%s\n", strbuffer);
	int iretcode = -1;
	GetXMLBuffer(strbuffer, "retcode", &iretcode);

	if (iretcode == 0) {
		printf("身份验证成功\n");
		return true;
	}
	printf("身份验证失败\n");
	return false;
}
