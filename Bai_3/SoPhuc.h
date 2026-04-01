#ifndef SOPHUC_H
#define SOPHUC_H

#include <iostream>

class SoPhuc {
private:
    int iThuc;
    int iAo;

public:
    // Phương thức nhập, xuất
    void Nhap();
    void Xuat() const;

    // Các phương thức tính toán
    SoPhuc Tong(SoPhuc sp2);
    SoPhuc Hieu(SoPhuc sp2);
    SoPhuc Tich(SoPhuc sp2);
    SoPhuc Thuong(SoPhuc sp2);
};

#endif