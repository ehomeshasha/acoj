#include <iostream>

using namespace std;
int main()
{
    char s[6];
    int cnt = 0;
    scanf("%[^\n]", s);
    for (int i = 0; i < 5; i++) {
        if (s[i] == '\0') {
            break;
        }
        if (s[i] != '\n' && s[i] != ' ') {
            cnt++;
        }
    }
    cout << cnt << endl;

    return 0;
}
