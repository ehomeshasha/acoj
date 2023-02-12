#include <bits/stdc++.h>


using namespace std;

/**
n名同学参加了c++期末考试，他们的成绩单如下，但是有的人成绩单分数错了，会出现多次分数，如果出现了多次分数，按照较高的一个。
请按照分数从高到低排序，如果成绩相同，则按照名字的字典序从小到大进行排序。
输入格式:
第一行一个整数n（n<=200000）表示有n个人参加了考试，接下来n组数据，每组数据包含两行，
 第一行为学生姓名（只包含引文小写字母和空格，且不超过200个字符），第二行为这个学生得到的分数（int范围以内）。
输出格式:
输出n行。排序之后的结果。
样例 1 :
输入:
4
Aha World
99
Tom Wang
80
Ahaa
99
Tom Wang
100
输出:
Tom Wang
Aha World
Ahaa
 */
struct Stu {
    string name;
    int score;
};

bool mysort(Stu a,Stu b)
{
    if (a.score!=b.score) return a.score>b.score;
    return a.name<b.name;
}

int main()
{
    int n,score,idx=0;
    char t[205];
    map<string,int> m;
    Stu stu[200005];
    cin >> n;
    gets(t);
    // O(n)
    for (int i=0;i<n;i++) {
        char* name=new char[205];
        gets(name);
        string names=name;
        scanf("%d\n",&score);
        if (m.count(names)==0) m[names]=score;
        else if (m[names]<score) m[names]=score;
    }
    // O(n)
    map<string,int>::iterator iter;
    for (iter=m.begin();iter!=m.end();iter++) {
        stu[idx++]=Stu{iter->first,iter->second};
    }
    // O(n)
    sort(stu,stu+idx,mysort);
    // O(n)
    for (int i=0;i<idx;i++)
        cout << stu[i].name << '\n';

    return 0;
}
