#include <bits/stdc++.h>


using namespace std;

/**
又考试了，这次考试的人数特别多，考试结束后，成绩统计是一件很重要的事情。
老师们都很关心学生的成绩，于是他们把学生的成绩按学生的姓名进行排列（字典顺序，姓名全为小写字母，从小到大排列），
 并统计各个分数段的人数，以及满分的同学。
输入格式:
第一行：一个数 n （n<=130000人）
以下n行：每行两个信息，分别为学生姓名（30个字符以内），分数（1~150分）
输出格式: // 判断15次比较耗时，最好直接算出来然后统计 21/10=2 8/10=0 11/10=1 149/10=14, 直接除以10可以简化，存入计数数组
第一行为1~9 10~19 20~29 30~39 40~49 50~59 60~69 70~79 80~89 90~99 100~109 110~119 120~129 130~139 140~149各个分数段的人数（空格隔开，没有则输出0 ）
接下来的n 行，分别为按照字典序排好的n个学生的姓名和成绩（空格隔开）
再接下来的一行为满分的人的人数x（如果没有则为0）（保证x不超过10000）
接下来的x行为满分人的姓名（如果x为0则为一行‘No’）（按字典序从小到大排序）
注意：一行若有多个数据，每一个数据之间用空格隔开。分数段中没有0分的。
样例 1 :
输入:
3
abc 50
ab 85
bc 55
输出:
0 0 0 0 0 2 0 0 1 0 0 0 0 0 0
ab 85
abc 50
bc 55
0
No
 */
struct Student {
    int score;
    char* name;
} stu_list[130000], manfen[10000];
int n,tongji[16]={0},mf_idx=0; // 下标0~14,对应15档分数，最后一个15下标为满分人数

bool msort(Student a, Student b)
{
    return strcmp(a.name,b.name)<0;
}

int main()
{
    // scanf输入printf输出，提升效率
    // 排序优化
    scanf("%d\n",&n);
    for (int i=0;i<n;i++) {
        char *t=new char[30];
        scanf("%s %d\n",t,&stu_list[i].score);
        stu_list[i].name=t;
        // 计算15档分数
        tongji[stu_list[i].score/10]++;
        if (stu_list[i].score==150) {
            manfen[mf_idx++]=stu_list[i];
        }
    }
    // 排序
    sort(stu_list,stu_list+n,msort);
    sort(manfen,manfen+mf_idx,msort);
    for (int i=0;i<15;i++) {
        printf("%d",tongji[i]);
        if (i<14) printf(" ");
    }
    printf("\n");
    for (int i=0;i<n;i++) {
        printf("%s %d\n",stu_list[i].name,stu_list[i].score);
    }
    printf("%d\n", mf_idx);
    if (mf_idx==0) {
        printf("No");
    } else {
        for (int i=0;i<mf_idx;i++) {
            printf("%s\n",manfen[i].name);
        }
    }
    return 0;
}
