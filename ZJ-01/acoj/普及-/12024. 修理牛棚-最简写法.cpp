#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
    int M,S,C,sum=0,maxn=210;
    int a[maxn],cha[maxn];
    scanf("%d%d%d",&M,&S,&C);
    for(int i=1;i<=C;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+C+1);
    for(int i=2;i<=C;i++)
        cha[i-1]=a[i]-a[i-1]-1;
    sort(cha+1,cha+C);
    for(int i=1;i<=C-M;i++)
        sum+=cha[i];
    printf("%d\n",sum+C);
    return 0;
}
