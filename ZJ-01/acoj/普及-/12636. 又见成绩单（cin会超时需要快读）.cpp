#include <bits/stdc++.h>


using namespace std;

/**
n名同学参加了c++期末考试，他们的成绩单如下，请按照分数从高到低排序，如果成绩相同，则按照名字的字典序从小到大进行排序。
输入格式:
第一行一个整数n（n<=200000）表示有n个人参加了考试，接下来n组数据，每组数据包含两行，
第一行为学生姓名（只包含英文小写字母和空格，且不超过200个字符），第二行为这个学生得到的分数（int范围以内）。
输出格式:
输出n行。排序之后的结果。
样例 1 :
输入:
3
Aha World
99
Tom Wang
100
Ahaa
99
输出:
Tom Wang
Aha World
Ahaa
 */


struct Stu {
    int score;
    char* name;
};

bool mysort(Stu a,Stu b)
{
    if (a.score!=b.score) return a.score>b.score;
    // 比较字母序
    return strcmp(a.name,b.name)<0;
}

int main()
{
    int n,score;
    scanf("%d\n", &n);
    Stu data[200005];
    for (int i=1;i<=n;i++) {
        char* name=new char[205];
        gets(name);
        scanf("%d\n",&score);
        data[i]=Stu{score,name};
    }
    sort(data+1,data+1+n, mysort);
    for (int i=1;i<=n;i++)
        cout << data[i].name << '\n';
    return 0;
}

