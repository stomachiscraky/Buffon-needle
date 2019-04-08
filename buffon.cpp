#include <iostream>
#include <iomanip>
#include <random>
#include <cmath>
using namespace std;
const int try_cnt = 100000; // 試行回数

// 0から2πまで考える
void buf_pi1() {
    int h = 0; // ヒットした回数
    double a; // 角度
    double r; // 上側距離
    double pi = acos(-1); // 円周率
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dis(0.0, 1.0);

    for (int i = 1; i <= try_cnt; i++) {
        a = dis(gen) * 2 * pi; // 0から2πまでの乱数
        r = dis(gen); // 0から１までの乱数
        if (sin(a) >= 0) {
            if (sin(a) >= r) h++;
        } else {
            if (-sin(a) >= 1 - r) h++;
        }
    }
    cout << (2.0*try_cnt / h) << endl; // 円周率の近似値
}
// 0からπまで考える
void buf_pi2() {
    int h = 0; // ヒットした回数
    double a; // 角度
    double r; // 上側距離
    double pi = acos(-1); // 円周率
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dis(0.0, 1.0);

    for (int i = 1; i <= try_cnt; i++) {
        a = dis(gen) * pi;  // 0からπまでの乱数
        r = dis(gen); // 0から１までの乱数
        if (sin(a) >= r) h++;
    }
    cout << (2.0*try_cnt / h) << endl; // 円周率の近似値
}
// 三角関数ライブラリも円周率も使わない
void buf_pi3() {
    int h = 0; // ヒットした回数
    double r; // 上側距離
    double x; // sin値算出用座標
    double y; // sin値算出用座標
    double rs; // sin値算出用距離
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dis(0.0, 1.0);

    for (int i = 0; i < try_cnt; ) {
        x = dis(gen); // 0から１までの乱数
        y = dis(gen); // 0から１までの乱数
        r = dis(gen); // 0から１までの乱数
        rs = hypot(x, y);
        if (rs <= 1) { // 円内にあるか
            i++;
            // y / rs はsin値
            if (y / rs >= r) h++;
        }
    }
    cout << (2.0*try_cnt / h) << endl; // 円周率の近似値
}
int main() {
    buf_pi1();
    buf_pi2();
    buf_pi3();
}
