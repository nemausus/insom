/*#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int T, n, a[100005], c4[100005], c7[100005];
long long ans;

int count(int x, int z) {
    int ret = 0;
    while (x) {
        ret += x%10 == z;
        x /= 10;
    }
    return ret;
}

long long solve47() {
    long long ret = 0; int r4=n-1, w4=n-1, r7=n-1, w7=-1, R, W;
    for (int i=n; i>0; --i) {
        r4 = min(r4, i-1);
        w4 = min(w4, r4);
        while (w4 >= 0 && c4[w4]-c4[i] <= 1) w4--;
        r7 = min(r7, i-1);
        while (r7 >= 0 && c7[r7]-c7[i] < 3) r7--;
        if (r7 < 0) break;
        w7 = min(w7, r7);
        R = min(r4, r7);
        W = max(w4, w7);
        ret += max(0, R-W);
    }
    return ret;
}

long long solve7_0() {
    long long ret = 0; int r7=n-1, w7=n-1;
    for (int i=n; i>0; --i) {
        r7 = min(r7, i-1);
        w7 = min(w7, r7);
        while (w7 >= 0 && c7[w7]-c7[i] == 0) w7--;
        ret += r7-w7;
    }
    return ret;
}

int t[100005];
int bs(int x, int y, int z) {
    int mi = x, mid, ma = y;
    if (t[mi] > z) return 0;
    while (mi < ma) {
        mid = (mi + ma + 1) >> 1;
        if (t[mid] <= z) mi = mid;
        else ma = mid - 1;
    }
    return mi - x + 1;
}
long long solve7_1() {
    for (int i=0; i<=n; ++i) t[i] = c4[i] + i;
    long long ret = 0; int r7=n-1, w7=n-1;
    for (int i=n; i>0; --i) {
        r7 = min(r7, i-1);
        while (r7 >= 0 && c7[r7]-c7[i] < 1) r7--;
        if (r7 < 0) break;
        w7 = min(w7, r7);
        while (w7 >= 0 && c7[w7]-c7[i] <= 1) w7--;
        if (w7 < r7) {
            if (i == n || c7[i] != c7[i+1]) {
                sort(t+w7+1, t+r7+1);
            }
            ret += bs(w7+1, r7, t[i]);
        }
    }
    return ret;
}

long long solve(int I, int J, int K) {
    long long ret = 0; int r4=n-1, w4=n-1, r7=n-1, w7=n-1, R, W;
    for (int i=n; i>0; --i) {
        r4 = min(r4, i-K);
        while (r4 >= 0 && c4[r4]-c4[i] < I) r4--;
        if (r4 < 0) break;
        w4 = min(w4, r4);
        while (w4 >= 0 && c4[w4]-c4[i] <= I) w4--;
        r7 = min(r7, i-K);
        while (r7 >= 0 && c7[r7]-c7[i] < J) r7--;
        if (r7 < 0) break;
        w7 = min(w7, r7);
        while (w7 >= 0 && c7[w7]-c7[i] <= J) w7--;
        R = min(r4, r7);
        W = max(w4, w7);
        ret += max(0, R-W);
    }
    return ret;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i=0; i<n; ++i) {
            scanf("%d", &a[i]);
        }
        c4[n] = c7[n] = 0;
        for (int i=n-1; i>=0; --i) {
            c4[i] = c4[i+1] + count(a[i], 4);
            c7[i] = c7[i+1] + count(a[i], 7);
        }
        ans = 0;
        ans += solve47();
        ans += solve7_0();
        ans -= solve(2, 0, 1);
        ans += solve7_1();
        ans -= solve(2, 1, 2);
        for (int i=3; i*i*i<=n; ++i) {
            for (int j=3, k=i*i*i; k<=n; ++j, k*=i) {
                ans += solve(i, j, k);
            }
        }
        cout << ans << endl;
    }
    return 0;
}*/