#include <bits/stdc++.h>


using namespace std;

/**
班级中有n个学生，每个学生都有自己的积分和成绩
先按积分从高到低排序，如果积分相同，按成绩从高到低，如果积分和成绩相同，则按姓名字典序从小到大进行排序。
输入格式:
输入共n+1行，第一行输入一个正整数n，第2行到第n行，每行3个数据，依次是学生姓名，积分和成绩，
姓名为长度不超过20的字符串，积分和成绩为不超过100的整数。
输出格式:
输出n行，每行3个信息，依次是学生姓名，积分和成绩，中间用空格隔开。
限制:
n<=100000
样例 1 :
输入:
3
Aha  20 90
Code 30 89
Com 20 90
输出:
Code 30 89
Aha  20 90
Com 20 90
 */
struct Stu {
    string name;
    int point;
    int score;
};

bool mysort(Stu a,Stu b)
{
    if (a.point!=b.point) return a.point>b.point;
    if (a.score!=b.score) return a.score>b.score;
    return a.name<b.name;
}

int main()
{
    int n,point,score;
    string name;
    Stu stu[100005];
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> name >> point >> score;
        stu[i]=Stu{name,point,score};
    }
    sort(stu,stu+n,mysort);
    for (int i=0;i<n;i++) {
        cout << stu[i].name << " " << stu[i].point << " " << stu[i].score << "\n";
    }
    return 0;
}
