#include <iostream>
#include <math.h>
#include <algorithm>
#include <map>

using namespace std;

/**
若一个数（首位不为零）从左向右读与从右向左读都一样，我们就将其称之为回文数。
例如：给定一个10进制数56，将56加56（即把56从右向左读），得到121是一个回文数。
又如：对于10进制数87：
STEP1：87+78  = 165                  STEP2：165+561 = 726
STEP3：726+627 = 1353                STEP4：1353+3531 = 4884
在这里的一步是指进行了一次N进制的加法，上例最少用了4步得到回文数4884。
写一个程序，给定一个N（2<=N<=10，N=16）进制数M，求最少经过几步可以得到回文数。如果在30步以内（包含30步）不可能得到回文数，则输出“Impossible！”
 */
map<char,int> m16;
map<int, char> m16_2;
void init_m16() {
    m16['0']=0;
    m16['1']=1;
    m16['2']=2;
    m16['3']=3;
    m16['4']=4;
    m16['5']=5;
    m16['6']=6;
    m16['7']=7;
    m16['8']=8;
    m16['9']=9;
    m16['A']=10;
    m16['B']=11;
    m16['C']=12;
    m16['D']=13;
    m16['E']=14;
    m16['F']=15;
}
void init_m16_2() {
    m16_2[0]='0';
    m16_2[1]='1';
    m16_2[2]='2';
    m16_2[3]='3';
    m16_2[4]='4';
    m16_2[5]='5';
    m16_2[6]='6';
    m16_2[7]='7';
    m16_2[8]='8';
    m16_2[9]='9';
    m16_2[10]='A';
    m16_2[11]='B';
    m16_2[12]='C';
    m16_2[13]='D';
    m16_2[14]='E';
    m16_2[15]='F';
}
// n进制加法
string add(string A, string B, int n) {
    int len=A.length();
    string C(len, 'x');
    int jinwei=0;
    for (int i=len-1;i>=0;i--) {
        int a=m16[A[i]];
        int b=m16[B[i]];
        // 和十进制比较
        // 1. 进位判断，
        int sum=a+b+jinwei;
        if (sum>=n) jinwei=1;// 需要进位
        else jinwei=0;
        // 2. 具体数字判断
        if (jinwei==1) sum-=n;
        // 3. 数字映射回字符
        C[i]=m16_2[sum];
    }
    if (jinwei==1) C="1"+C;
    return C;
}
// 反转字符串
string reverse(string A) {
    string B;
    for (int i=A.length()-1;i>=0;i--) {
        B.push_back(A.at(i));
    }
    return B;
}
// 判断字符串是否是回文数
bool is_huiwen(string A) {
    int len = A.length();
    int middle=len/2;
    for (int i=0;i<middle;i++) {
        if (A.at(i)!=A.at(len-i-1)) {
            return false;
        }
    }
    return true;
}


int main()
{
    init_m16();
    init_m16_2();
    int N;
    string M,B;
    cin >> N >> M;
    for (int i=1;i<=30;i++) {
        B=reverse(M);
        M=add(M,B,N);
        if(is_huiwen(M)) {
            printf("STEP=%d", i);
            return 0;
        }
    }
    printf("Impossible!");
    return 0;
}
