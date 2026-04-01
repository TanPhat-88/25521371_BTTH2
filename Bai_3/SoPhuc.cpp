#include "SoPhuc.h"
#include <iostream>

using namespace std;

// Input: Không có (Nhập từ bàn phím).
// Output: Gán giá trị cho thuộc tính iThuc và iAo của đối tượng.
// Giải quyết: Sử dụng đối tượng cin để nhận giá trị từ người dùng.
void SoPhuc::Nhap() {
    cout << "Nhập phần thực: ";
    cin >> iThuc;
    cout << "Nhập phần ảo: ";
    cin >> iAo;
}

// Input: Không có.
// Output: In ra màn hình định dạng số phức (a + bi) hoặc (a - bi).
// Giải quyết: Kiểm tra dấu của iAo để in ra ký tự '+' hoặc '-' cho phù hợp thẩm mỹ.
void SoPhuc::Xuat() const {
    if (iAo >= 0)
        cout << iThuc << " + " << iAo << "i";
    else
        cout << iThuc << " - " << -iAo << "i";
    cout << endl;
}

// Input: Một đối tượng số phức sp2.
// Output: Một đối tượng số phức mới là tổng của đối tượng hiện tại và sp2.
// Giải quyết: Cộng phần thực với phần thực, phần ảo với phần ảo.
SoPhuc SoPhuc::Tong(SoPhuc sp2) {
    SoPhuc kq;
    kq.iThuc = this->iThuc + sp2.iThuc;
    kq.iAo = this->iAo + sp2.iAo;
    return kq;
}

// Input: Một đối tượng số phức sp2.
// Output: Một đối tượng số phức mới là hiệu của đối tượng hiện tại và sp2.
// Giải quyết: Lấy phần thực hiện tại trừ phần thực sp2, phần ảo hiện tại trừ phần ảo sp2.
SoPhuc SoPhuc::Hieu(SoPhuc sp2) {
    SoPhuc kq;
    kq.iThuc = this->iThuc - sp2.iThuc;
    kq.iAo = this->iAo - sp2.iAo;
    return kq;
}

// Input: Một đối tượng số phức sp2 (c + di).
// Output: Một đối tượng số phức mới là tích của (a + bi) * (c + di).
// Giải quyết: Sử dụng công thức (ac - bd) + (ad + bc)i.
SoPhuc SoPhuc::Tich(SoPhuc sp2) {
    SoPhuc kq;
    kq.iThuc = this->iThuc * sp2.iThuc - this->iAo * sp2.iAo;
    kq.iAo = this->iThuc * sp2.iAo + this->iAo * sp2.iThuc;
    return kq;
}

// Input: Một đối tượng số phức sp2 (c + di).
// Output: Một đối tượng số phức mới là thương của (a + bi) / (c + di).
// Giải quyết: Nhân cả tử và mẫu với số phức liên hợp của mẫu. 
// Phần thực = (ac + bd) / (c^2 + d^2), Phần ảo = (bc - ad) / (c^2 + d^2).
SoPhuc SoPhuc::Thuong(SoPhuc sp2) {
    SoPhuc kq;
    float mauSo = sp2.iThuc * sp2.iThuc + sp2.iAo * sp2.iAo;
    if (mauSo == 0) {
        cout << "Lỗi: Mẫu số bằng 0, không thể chia!" << endl;
        kq.iThuc = 0; kq.iAo = 0;
        return kq;
    }
    kq.iThuc = (this->iThuc * sp2.iThuc + this->iAo * sp2.iAo) / mauSo;
    kq.iAo = (this->iAo * sp2.iThuc - this->iThuc * sp2.iAo) / mauSo;
    return kq;
}