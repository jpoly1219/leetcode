using namespace std;

class Solution {
public:
    int fib(int n) {
        // fibonacci
        // 0 + 1 + 1 + 2 + 3 + 5 + ...
        // F(n) = F(n-1) + F(n-2)
        // F(3) = F(2) + F(1) = F(1) + F(0) + 1 = 1 + 0 + 1 = 2
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        return fib(n-1) + fib(n-2);
    }
};