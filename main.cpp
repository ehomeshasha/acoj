#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;


int main()
{

    char s;
    int ans=0;
// 	freopen("title.in","r",stdin);
// 	freopen("title.out","w",stdout);
    for(int i=0;;i++)//可以从i=1到i<=5   因为最多只有5个字符
    {
        s='\0';
        scanf("%c",&s); //每次读入一个字符
        if (s=='\0') break;
        if ((s>='0'&&s<='9')||(s>='a'&&s<='z')||(s>='A'&&s<='Z')) {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}