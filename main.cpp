#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<queue>
#include"http.h"
using namespace std;

//欢迎界面
void Welcome();

//开始抓取
bool StartCatch(string url);

int main()
{
    Welcome();
    cout << "请输入要抓取的URL的地址："<<endl;
    string url;
    cin >> url;
    StartCatch(url);
    system("pause");
    return EXIT_SUCCESS;
}

//欢迎界面
void Welcome()
{
    cout << endl;
    cout << endl;
    cout << "\t\t-----------------------------------------" << endl;
    cout << "\t\t-----------------------------------------" << endl;
    cout << "\t\t-\t\t\t\t\t-" << endl;
    cout << "\t\t-\t\t\t\t\t-" << endl;
    cout << "\t\t-\t\t\t\t\t-" << endl;
    cout << "\t\t-\t欢迎使用C++智能爬虫系统\t\t-" << endl;
    cout << "\t\t-\t\t\t\t\t-" << endl;
    cout << "\t\t-\t\t\t\t\t-" << endl;
    cout << "\t\t-\t\t\t\t\t-" << endl;
    cout << "\t\t-\t  某某大学某某实验室\t\t-" << endl;
    cout << "\t\t-\t\t\t\t\t-" << endl;
    cout << "\t\t-\t\t\t\t\t-" << endl;
    cout << "\t\t-----------------------------------------" << endl;
    cout << "\t\t-----------------------------------------" << endl;
}
//开始抓取
bool StartCatch(string url)
{
    queue<string> q;  //创建url队列   因为url是先获取到先处理，所以用queue的数据结构
    q.push(url);      //将获取到的url队列放入queue中

    while (!q.empty())  //判断队列是否为空，如果不为空，那么久一直采集
    {
        string currentUrl = q.front();   //将当前队列中的第一个url取出来
        q.pop();

        //解析URL   ----就是把协议、主机、资源路径给分割出来
        CHttp http;
        http.Init();
        http.AnalyseURL(currentUrl);
        cout << http.m_host << "\t\t" << http.m_object << endl;

        if (false == http.Connect())
            cout << "连接服务器失败" << endl;
        else
            cout << "连接服务器成功" << endl;

        //获取html信息
        string html;
        http.GetHtml(html);
        cout << html << endl;   //这一行可有可无，不过第一次跑的时候最好用上

    }
    return true;
}
