#include <bits/stdc++.h>


using namespace std;

/**
最近CSP考试NOI公布了n个学生的成绩，但是官网上只给了学生的考号k和成绩s，
 我们现在想知道啊哈编程m个学生的学生成绩，我们直接查看官网上的学号不能分辨出是哪位学生，但是我们知道所有学生的姓名name和考号k，
 现在需要匹配学生的考号，输出啊哈编程所有的学生的姓名和成绩，输出时按成绩从高到低输出，如果成绩相同，则按姓名从小到大输出。
输入格式:
第一行输入两个正整数n和m。
接下来输入n行，每行两个正整数k和s。
接下来输入m行，每行依次输入学生姓名name和考号k，name为长度不超过30且只含小写字母的字符串，k为正整数。
输出格式:
输出m行，依次输出排序好的姓名和成绩。
提示:
注意：官网给出的名单可能有重复信息，如果考号k这个学生输入多次成绩，取最小的成绩
限制:
10≤n≤100000
5≤m≤10000
0<=s<=100
考号中数字范围从0到99999
样例 1 :

输入:
5 2
HB-00001 79
HB-00005 45
HB-00101 90
HB-00023 80
HB-00054 60
infinite HB-00001
ahaword HB-00101
输出:
ahaword 90
infinite 79
说明:
ahaword考号为101，根据前面的数据，考号为101学生的成绩为90，infinite考号为1，考号为1的学生成绩为79，ahaword成绩比infinite成绩高，所以先输出ahaword的信息，再输出infinite的成绩。
 */
struct Stu {
    string k;
    int score;
    string name;
};

bool mysort(Stu a, Stu b)
{
    if (a.score!=b.score) return a.score>b.score;
    return a.name<b.name;
}

int main()
{
    int n,m,s,stu_idx=0;
    map<string,int> ks;
    map<string,string> kname;
    Stu stu[10005];
    cin >> n >> m;
    // 去重
    for (int i=0;i<n;i++) {
        string k;
        cin >> k >> s;
        if(ks.count(k)==0) ks[k]=s;
        else if (s<ks[k]) ks[k]=s;
    }
    // 映射名字
    for (int i=0;i<m;i++) {
        string name,k;
        cin >> name >> k;
        kname[k]=name;
    }
    // 数组
    map<string,string>::iterator iter;
    for (iter=kname.begin();iter!=kname.end();iter++) {
        if (ks.count(iter->first)==0) continue;
        stu[stu_idx++]=Stu{iter->first,ks[iter->first],iter->second};
    }
    // 排序
    sort(stu,stu+stu_idx,mysort);
    for (int i=0;i<stu_idx;i++) {
        cout << stu[i].name << " " << stu[i].score << "\n";
    }
    return 0;
}
