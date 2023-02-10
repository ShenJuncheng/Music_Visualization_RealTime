//
// Created by 23194 on 2023/2/10.
//

#ifndef HTTP_H     //目的是为了防止头文件重复包含
#define HTTP_H
#include<WinSock2.h>
#include <string>

class CHttp
{
public:
    std::string m_host;   //域名
    std::string m_object; //资源路径
    bool m_bHttps;
    SOCKET m_socket;   //套接字
public:
    CHttp();     //构造函数
    ~CHttp();    //析构函数

    //初始化网络
    bool Init();
    //解析URL
    bool AnalyseURL(std::string url);
    //连接服务器
    bool CHttp::Connect();
    //下载网页及保存
    bool GetHtml(std::string& html);  //引用类型的变量
};
#endif
#ifndef HTTP_H     //目的是为了防止头文件重复包含
#define HTTP_H
#include<WinSock2.h>
class CHttp
{
public:
	std::string m_host;   //域名
	std::string m_object; //资源路径
	bool m_bHttps;
	SOCKET m_socket;   //套接字
public:
	CHttp();     //构造函数
	~CHttp();    //析构函数

	//初始化网络
	bool Init();
	//解析URL
	bool AnalyseURL(std::string url);
	//连接服务器
	bool CHttp::Connect();
	//下载网页及保存
	bool GetHtml(std::string& html);  //引用类型的变量
};
#endif

