#include <iostream>
#include <iomanip>
#include <random>
#include <cmath>
using namespace std;
const int try_cnt_c = 100000; // 試行回数

// r=0 to t,a=0 to 2πを考える
void buffon1(double L, double t, int try_cnt) {
    int h = 0; // ヒットした回数
    double a; // 角度
    double r; // 平行線までの距離
    double pi = acos(-1); // 円周率
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dis(0.0, 1.0);

    for (int i = 1; i <= try_cnt; i++) {
        a = dis(gen)*(2*pi); // 0から2πまでの乱数
        r = dis(gen)*t; // 0からtまでの乱数
        if (sin(a) >= 0) {
            if (sin(a)*L >= r) h++;
        } else {
            if (-sin(a)*L >= 1 - r) h++;
        }
    }
    cout << (2.0*L*try_cnt / (t*h)) << endl; // 円周率の近似値
}

// r=0 to t/2,a=0 to π/2を考える
void buffon2(double L, double t, int try_cnt) {
    int h = 0; // ヒットした回数
    double a; // 角度
    double r; // 平行線までの距離
    double pi = acos(-1); // 円周率
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dis(0.0, 1.0);

    for (int i = 1; i <= try_cnt; i++) {
        a = dis(gen)*(pi/2);  // 0からπ/2までの乱数
        r = dis(gen)*(t/2); // 0からt/2までの乱数
        if (sin(a)*(L/2) >= r) h++;
    }
    cout << (2.0*L*try_cnt / (t*h)) << endl; // 円周率の近似値
}

// 三角関数ライブラリも円周率も使わない
// r=0 to t/2,a=0 to π/2を考える
void buffon3(double L, double t, int try_cnt) {
    int h = 0; // ヒットした回数
    double r; // 平行線までの距離
    double x; // sin値算出用座標
    double y; // sin値算出用座標
    double rs; // sin値算出用距離
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dis(0.0, 1.0);

    for (int i = 0; i < try_cnt; ) {
        x = dis(gen); // 0から1までの乱数
        y = dis(gen); // 0から1までの乱数
        r = dis(gen)*(t/2); // 0からt/2までの乱数
        rs = hypot(x, y);
        if (rs <= 1) { // 円内にあるか
            i++;
            // y/rs はsin値
            if ((y/rs)*(L/2) >= r) h++;
        }
    }
    cout << (2.0*L*try_cnt / (t*h)) << endl; // 円周率の近似値
}

int main() {
    buffon1(1, 1, try_cnt_c);
    buffon2(1, 1, try_cnt_c);
    buffon3(1, 1, try_cnt_c);
}
