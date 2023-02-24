#include <bits/stdc++.h>


using namespace std;

/**
昨天，360非法截取了用户的QQ聊天信息……但是由于QQ的隐私保护措施，聊天记录的顺序被打乱了。
360想请你帮他将聊天记录按发送信息的时间升序排列，并输出所有给定的账号发送的信息内容，每行一条。
聊天记录的格式为：
YYYY-MM-DD hh:mm:ss <user> <message>
其中：
YYYY-MM-DD hh:mm:ss为发送信息的时间。
<user> 为发送信息的账号，且只包含大小写英文字母及标点符号；
<message> 为信息的内容。

输入格式:

第一行为一个只包含大小写英文字母及标点符号的字符串，为给定的账号。（日期、时间、姓名和消息之间用空格隔开）
第二行一直到文件结束，每行包含一条聊天记录，格式如题目描述。
输出格式:
有若干行，为按发送时间升序排列的所有给定账号发送的信息内容。
限制:
行数小于1000，字符串长度小于500
样例 1 :
输入:
Ahalei
2010-11-02 22:01:55 Ahalei 886.
2010-08-03 09:10:45 BigL What?
2010-11-02 21:45:09 Ahalei How are you?
2010-11-02 21:44:32 PGDN I am OK!
2010-11-02 21:45:19 Ahalei what do you want to do?
2009-10-25 06:00:35 PGDN O my God!
输出:
How are you?
what do you want to do?
886.
 */
struct node{
    string y,d,u,mes;
}a[1005];
bool cmp(node i,node j)
{
    if(i.y!=j.y) return i.y<j.y;
    return i.d<j.d;
}
int main()
{
    string user;
    cin>>user;
    int cnt=0;
    while(cin>>a[cnt].y)
    {
        cin>>a[cnt].d>>a[cnt].u;
        getchar();
        getline(cin,a[cnt].mes);
        cnt++;
    }
    sort(a,a+cnt,cmp);
    for(int i=0;i<cnt;i++)
    {
        if(user==a[i].u)
            cout<<a[i].mes<<endl;
    }
    return 0;
}
