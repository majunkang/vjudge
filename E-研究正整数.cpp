#include <iostream>

using namespace std;

int getCount(int n, int max) {
    if (n == 0) {
        return 1;
    }
    
    int totalCount = 0;
    // 求当前第1位分别为max, max-1, ..., 1 时
    // 递归剩余的(n-i)数值可能的组合数
    // 为了避免重复的组合，限定递归时max值不能大于当前这一位(i)的大小
    for (int i = max; i > 0; i--) {
        if (n-i < 0) {
            continue;
        }
        
        totalCount += getCount(n-i, i);
    }
    
    return totalCount;
}

int main(int argc, const char * argv[]) {
    int n = 0;
    
    while(cin >> n) {
        cout << getCount(n, n) << endl;
    }
    
    return 0;
}
