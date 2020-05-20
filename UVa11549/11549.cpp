#include <cstdio>
#include <cstdlib>
#include <set>
#include <sstream>
#include <iostream>

using namespace std;

int next(int n, int k)
{
    stringstream ss;
    ss << (long long) k * k;
    string s = ss.str();
    if(s.length() > n)
        s = s.substr(0, n);
    
    int ans;

    // initial stringstream constructor
    stringstream ss2(s);
    ss2 >> ans;
    return ans;
}

int main()
{

    //freopen("11549.in", "r", stdin);
    //freopen("11549.out", "w", stdout);

    int t, n, k;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &k);
        set <int> S;
        int ans = k;
        // 判斷數值 k 在不在 set 裡面（set 為集合，內部元素唯一），在就回傳 1，不在就回傳 0
        while(!S.count(k))
        {
            S.insert(k);
            if(k > ans) 
                ans = k;
            k = next(n, k);
        }
        printf("%d\n", ans);
    }
}