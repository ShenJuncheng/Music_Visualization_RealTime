////
//// Created by 23194 on 2023/2/10.
////
//
//#include<iostream>
//#include"http.h"
//#include<WinSock2.h>  //使用套接字的头文件
//#include <fstream>    //包含文件流的头文件
//#define _CRT_SECURE_NO_WARNINGS
//#pragma comment(lib,"ws2_32.lib")
//
////构造函数
//CHttp::CHttp()
//{
//    m_bHttps = false;   //默认一开始不是https协议
//    m_socket = NULL;
//}
////析构函数
//CHttp::~CHttp()
//{
//
//}
////解析URL函数
//bool CHttp::AnalyseURL(std::string url)
//{
//    //https://www.microsoft.com/zh-cn/download/confirmation.aspx?id=40770  示例 https
//    //http://www.163.com/     示例 http
//
//    //将字符串分别转化为大、小写的函数
//    //toupper(); tolower();  因为有些网站用的是大写的HTTPS\HTTP
//    std::string str = url.substr(0, 8); //substr(string, start<,length>):从string的start位置开始提取字符串,length:要提取字符串的长度
//    if ("https://" == str)
//    {
//        m_bHttps = true;
//    }
//    else if (str.find("http://") !=std::string::npos)
//    {
//        m_bHttps = false;
//    }
//    else
//        return false;
//
//    //找主机网址的反斜杠位置
//    int nPos = url.find('/', m_bHttps ? 8 : 7);  //如果m_bHttps为真，那么从第8个之后的位置开始找，否则从第七个位置之后开始找
//    if (nPos == std::string::npos)  //这句话的意思就是说如果把最后一个位置都找完了，还没找到。   npos表示string的结束位置，
//    {
//        //http://www.163.com
//        m_host=url.substr(m_bHttps ? 8 : 7);  //例如上面这种，如果主机后面没有/，那么直接从http://开始截取，截到最后
//        m_object = "/";  //像上面这种没有资源路径，那我们就给他们一个斜杠
//    }
//    else
//    {
//        //如果是这种情况https://www.microsoft.com/zh-cn/download/confirmation.aspx?id=40770
//        m_host = url.substr(m_bHttps ? 8 : 7, nPos - (m_bHttps ? 8 : 7));
//        m_object = url.substr(nPos);
//    }
//
//    if (m_host.empty())  //如果主机内容为空，意味着截取不到
//        return false;
//
//    return true;
//}
////初始化网络
//bool CHttp::Init()
//{
//    WSADATA wd;
//    if (0 != WSAStartup(MAKEWORD(2, 2), &wd))
//        return false;
//    if (LOBYTE(wd.wVersion) != 2 || HIBYTE(wd.wVersion) != 2)  //判断请求的是不是2.2版本
//        return false;
//
//    //创建套接字
//    m_socket=socket(AF_INET, SOCK_STREAM, 0);
//}
////连接服务器
//bool CHttp::Connect()
//{
//    //将域名解析成对应的IP地址
//    HOSTENT * p=gethostbyname(m_host.c_str());  //P存放的内容就是由主机域名解析好后的ip地址，
//    if (p == NULL)
//        return false;   //解析失败
//    //连接服务器
//    sockaddr_in sa;
//    sa.sin_family = AF_INET;
//    sa.sin_port = htons(80);
//    memcpy(&sa.sin_addr, p->h_addr, 4);
//
//    if (SOCKET_ERROR == connect(m_socket, (sockaddr*)&sa, sizeof(sockaddr)))
//        return false;
//    return true;
//}
//
//bool CHttp::GetHtml(std::string& html)
//{
//    std::string get;
//    get += "GET " + m_object + " HTTP/1.1\r\n";
//    get += "Host: " + m_host + "\r\n";
//    get += "User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.77 Safari/537.36 Edg/91.0.864.37";
//    get += "Connection: Close\r\n";
//    get += "\r\n";
//
//    //发送GET请求
//    if(SOCKET_ERROR==send(m_socket, get.c_str(), get.length(), 0));  //套接字、发送的内容、发送多长、flag
//    std::cout << "GET请求发送失败" << std::endl;
//
//    //接收数据
//    char ch = 0;
//    std::fstream dataFile;   //创建一个文件，用于存放html的内容dataFile.open("D:\\html.txt", std::ios::out);
//    dataFile.open("D:\\html.txt", std::ios::out);
//    if (!dataFile)
//    {
//        printf("文件打开失败!\n");
//        return false;
//    }
//    while (recv(m_socket, &ch, sizeof(ch), 0))
//    {
//        html += ch;
//        dataFile << ch;
//    }
//    dataFile.close();
//    return true;
//}
