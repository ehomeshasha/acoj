#include <bits/stdc++.h>


using namespace std;

/**
里斯本的绿荫的街道上每天都有熙熙攘攘的人群。这座座落在欧洲最西岸的城市的码头里。每天都有来自世界各国的航海家在这里起航。
金币..宝物，或者消失的古老文字。已知世界的边缘，香料源产地的争夺，征服者的野心，每个人都怀着这样或那样的目的，从大陆的这边，消失在远处的海平面上，或者就真的消失掉了，沉没在海底的黑暗里，再也回不来了。
不过在这所城市的其它地方，却充满着安静的气息。
生活在这里的人们不必为了食物和寒冷而整日的发愁，即便是在冬天。
每个人也都可以在这里，在一片属于自己的角落，分享着午后的温暖的阳光。
这一天下午，在学校的课堂里，一些低年级小学生在一起讨论一道困难的平面几何题。
可是因为这题的条件众多，想从纷繁复杂的条件里推出最后的结果。并不是一件容易的事情，
于是，如果可以根据现在的条件，把所有可以得到的结果都推出来。也许会很有帮助？
Task1: 统计平行直线总数。
Task2: 回答一些询问。
输入格式:
第一行依次是直线数n，条件数m，询问数q
紧接着是m个条件，p表示平行，v表示垂直。
直线用字母l加一个数字表示。
输出格式:
Task1统计平行直线总数。
Task2会询问两条直线间的关系
两条直线的关系会是下面三种情况之一..
'Parallel.' (平行)输出单引号内的内容
'Vertical.' (垂直)输出单引号内的内容
'No idea.' (不知道)输出单引号内的内容
如果输入样例不符合实际输出There must be something wrong!
限制:
0<=n,m,q<=200
样例 1 :
第一行依次是直线数n，条件数m，询问数q
输入:
6 5 2
l1 p l2
l2 v l4
l2 p l3
l4 p l5
l4 v l6
l1 l3
l2 l6
输出:
7
Parallel.
Parallel.
样例 2 :

输入:
2 2 0
l1 v l2
l1 p l2
输出:
There must be something wrong!
 */
int N,M,Q,fx[205],path[2],ans,cz[205][205];
struct Line {
    int a,b;
};
vector<Line> czv;

int ufind(int x)
{
    if (fx[x]==x) return x;
    fx[x]=ufind(fx[x]);
    return fx[x];
}

void trace(int p_idx)
{
    if (p_idx==2) {
        int a1=ufind(path[0]),a2=ufind(path[1]);
        if (a1==a2) {
//            printf("%d %d\n",path[0],path[1]);
            ans++;
        }
        return;
    }
    for (int i=1;i<=N;i++) {
        if (p_idx==1&&path[0]==i) continue; // 剪枝
        path[p_idx]=i;
        trace(p_idx+1);
        path[p_idx]=0;
    }
}

int main()
{
    scanf("%d %d %d\n",&N,&M,&Q);
    for (int i=1;i<=N;i++) fx[i]=i; // 初始化并查集
    for (int i=1;i<=M;i++) {
        int n1,n2;
        char type;
        scanf("l%d %c l%d\n",&n1,&type,&n2);
        if (type=='p'||type=='P') { // 平行的话可以合并
            int a1=ufind(n1), a2=ufind(n2);
            if (a1!=a2) fx[a1]=a2;
        } else if (type=='v'||type=='V') { // 垂直关系
            czv.push_back(Line{n1,n2});
        }
    }
    for (int i=0;i<czv.size();i++) {
        int a1=ufind(czv[i].a);
        int a2=ufind(czv[i].b);
        if (a1==a2) { // 存在即垂直又平行的关系，报错
            printf("There must be something wrong!\n");
            return 0;
        }
        cz[a1][a2]=1;
        cz[a2][a1]=1;
        czv[i].a=a1;
        czv[i].b=a2;
    }
    // 传递性实现
    // 实现顺序两两比较，如果存在a1==a2或a1==b2或b1==a2或b1==b2四种可能性
    // 就将剩余的另外两个数连接成并集
    if (czv.size()!=0) {
        for (int i=0;i<czv.size()-1;i++) {
            for (int j=i+1;j<czv.size();j++) {
                int a1=ufind(czv[i].a),a2=ufind(czv[j].a),b1=ufind(czv[i].b),b2=ufind(czv[j].b);
                if (a1==a2&&b1!=b2) fx[b1]=b2;
                else if (a1==b2&&b1!=a2) fx[b1]=a2;
                else if (b1==a2&&a1!=b2) fx[a1]=b2;
                else if (b1==b2&&a1!=a2) fx[a1]=a2;
            }
        }
    }
    // 求全排列
    // 任意选择2个不同的线段组合，然后判断是否平行
    // 求全组合，然后判断是否平行，用回溯算法，求N个里面取2个 CN2
    // 其实更简单是写2层循环也是ok的
    for (int i=1;i<=N-1;i++) {
        for (int j=i+1;j<=N;j++) {
            if (i==j) continue;
            int a1=ufind(i),a2=ufind(j);
            if (a1==a2) ans++;
        }
    }
//    trace(0);
    printf("%d\n",ans);
    // 查询
    for (int i=1;i<=Q;i++) {
        int n1,n2;
        scanf("l%d l%d\n",&n1,&n2);
        int a1=ufind(n1), a2=ufind(n2);
        if (a1==a2) printf("Parallel.");
        else if (cz[ufind(n1)][ufind(n2)]==1) printf("Vertical.");
        else printf("No idea.");
        printf("\n");
    }

    return 0;
}
