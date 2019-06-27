#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <queue>
#include <climits>
#include <cmath>
#include <cstring>
#include <stdio.h>

using namespace std;

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto x = [](){ios_base::sync_with_stdio(false); cin.tie(NULL); return NULL;}();

class Solution {
public:
    int countPrimes(int n) {
      // n could be 0, boo!
      bool isPrime[n+1];
      memset(isPrime, true, sizeof(isPrime));
      for (int i = 2; i < sqrt(n); ++i) {
        if (isPrime[i]) {
          // cout << "prime: " << i << endl;
          // set all of its multiples to be divisible, i.e non-primes
          // start from square of prime number
          for (int j = i*i; j < n; j += i) {
            isPrime[j] = false;
          }
        }
      }
      int total{0};
      for (int i = 2; i < n; ++i) {
        if (isPrime[i])
          ++total;
      }
      // cout << "total = " << total << endl;
      return total;
    }
};

void test1() {
  Solution S;
  cout << "0? " << S.countPrimes(1) << endl;
  cout << "0? " << S.countPrimes(2) << endl;
  cout << "1? " << S.countPrimes(3) << endl;
  cout << "2? " << S.countPrimes(4) << endl;
  // 2, 3, 5, 7
  cout << "4? " << S.countPrimes(10) << endl;
  cout << "4? " << S.countPrimes(11) << endl;
  cout << "5? " << S.countPrimes(12) << endl;
  cout << "5? " << S.countPrimes(13) << endl;
  cout << "6? " << S.countPrimes(14) << endl;
}

void test2() {
  Solution S;
}

void test3() {
  Solution S;
}

int main() {
  test1();
  test2();
  test3();
  cout << "Done!" << endl;
  
  return 0;
}


