#include "SoPhuc.h"
#include <iostream>

using namespace std;

int main() {
    SoPhuc sp1, sp2, kq;

    cout << "--- Nhập số phức thứ nhất ---" << endl;
    sp1.Nhap();
    cout << "--- Nhập số phức thứ hai ---" << endl;
    sp2.Nhap();

    cout << "\nSố phức 1: "; sp1.Xuat();
    cout << "Số phức 2: "; sp2.Xuat();

    cout << "\n--- Kết quả các phép toán ---" << endl;

    kq = sp1.Tong(sp2);
    cout << "Tổng: "; kq.Xuat();

    kq = sp1.Hieu(sp2);
    cout << "Hiệu: "; kq.Xuat();

    kq = sp1.Tich(sp2);
    cout << "Tích: "; kq.Xuat();

    kq = sp1.Thuong(sp2);
    cout << "Thương: "; kq.Xuat();

    return 0;
}