#include <iostream>
using namespace std;

unsigned int getCombinationCount(unsigned int n, unsigned int m) {
    if (n == 0)
        return 1;
    
    if (n == m)
        return 1;
    
    unsigned int x = 1, y = 1;
    
    for(unsigned int i = n; (i > m) && (i>n-m); i--)
        x *= i;
    
    for(unsigned int i = 1; (i <= n-m) && (i < m+1); i++)
        y *= i;
    
    return x/y;
}

unsigned int getCount(unsigned int number) {
    if ( number == 1 || number == 0)
        return 1;
    
    int count = 0;
    
    for (unsigned int i = 0; i < number; i++) {
        unsigned int a = getCombinationCount(number-1, i);
        unsigned int b = getCount(number-i-1);
        count += a*b;
    }
    
    return count;
}

int main(int argc, const char * argv[]) {
    int n = 0;
    while(cin >> n)
        cout << getCount(n) << endl;
    
    return 0;
}