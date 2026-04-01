#include <iostream>
#include <cmath> // Thêm thư viện để dùng hàm abs()
#include "PhanSo.h"
using namespace std;

// Input: Hai số nguyên a và b.
// Output: Số nguyên là ước chung lớn nhất của a và b.
// Giải quyết: Sử dụng thuật toán Euclid (đệ quy) để tìm UCLN.
int UCLN(int a, int b) {
    if (b == 0) return a;
    return UCLN(b, a % b);
}

// Input: Nhập từ bàn phím.
// Output: Gán giá trị cho tử số (iTu) và mẫu số (iMau).
// Giải quyết: Nhập tử số bình thường, riêng mẫu số dùng vòng lặp do-while để bắt buộc người dùng nhập khác 0.
void PhanSo::Nhap() {
    cout << "Nhap tu: ";
    cin >> iTu;
    do {
        cout << "Nhap mau (khac 0): ";
        cin >> iMau;
    } while (iMau == 0);
}

// Input: Không có.
// Output: Xuất phân số ra màn hình theo định dạng tu/mau.
// Giải quyết: Sử dụng cout để in giá trị iTu và iMau ngăn cách bởi dấu "/".
void PhanSo::Xuat() {
    cout << iTu << "/" << iMau;
}

// Input: Phân số hiện tại.
// Output: Phân số sau khi đã tối giản và chuẩn hóa dấu.
// Giải quyết: Tìm UCLN của tử và mẫu rồi chia cả hai cho UCLN đó. Nếu mẫu âm thì đảo dấu cả tử và mẫu.
void PhanSo::RutGon() {
    int ucln = UCLN(abs(iTu), abs(iMau));
    iTu /= ucln;
    iMau /= ucln;

    if (iMau < 0) {
        iTu = -iTu;
        iMau = -iMau;
    }
}

// Input: Một đối tượng phân số ps.
// Output: Đối tượng phân số mới là tổng của phân số hiện tại và ps.
// Giải quyết: Quy đồng mẫu số (a/b + c/d = (ad + bc)/(bd)) sau đó gọi hàm RutGon().
PhanSo PhanSo::Tong(PhanSo ps) {
    PhanSo kq;
    kq.iTu = iTu * ps.iMau + ps.iTu * iMau;
    kq.iMau = iMau * ps.iMau;
    kq.RutGon();
    return kq;
}

// Input: Một đối tượng phân số ps.
// Output: Đối tượng phân số mới là hiệu của phân số hiện tại và ps.
// Giải quyết: Quy đồng mẫu số (a/b - c/d = (ad - bc)/(bd)) sau đó gọi hàm RutGon().
PhanSo PhanSo::Hieu(PhanSo ps) {
    PhanSo kq;
    kq.iTu = iTu * ps.iMau - ps.iTu * iMau;
    kq.iMau = iMau * ps.iMau;
    kq.RutGon();
    return kq;
}

// Input: Một đối tượng phân số ps.
// Output: Đối tượng phân số mới là tích của phân số hiện tại và ps.
// Giải quyết: Nhân tử với tử, mẫu với mẫu (a/b * c/d = (ac)/(bd)) sau đó gọi hàm RutGon().
PhanSo PhanSo::Tich(PhanSo ps) {
    PhanSo kq;
    kq.iTu = iTu * ps.iTu;
    kq.iMau = iMau * ps.iMau;
    kq.RutGon();
    return kq;
}

// Input: Một đối tượng phân số ps.
// Output: Đối tượng phân số mới là thương của phân số hiện tại và ps.
// Giải quyết: Nhân nghịch đảo (a/b : c/d = (ad)/(bc)) sau đó gọi hàm RutGon().
PhanSo PhanSo::Thuong(PhanSo ps) {
    PhanSo kq;
    kq.iTu = iTu * ps.iMau;
    kq.iMau = iMau * ps.iTu;
    kq.RutGon();
    return kq;
}

// Input: Một đối tượng phân số ps.
// Output: Trả về 1 nếu lớn hơn, 0 nếu bằng, -1 nếu nhỏ hơn.
// Giải quyết: So sánh tích chéo (a/b và c/d so sánh ad với bc).
int PhanSo::SoSanh(PhanSo ps) {
    int left = iTu * ps.iMau;
    int right = ps.iTu * iMau;

    if (left > right) return 1;
    if (left == right) return 0;
    return -1;
}