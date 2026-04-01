#include <iostream>
#include "Day.h"
using namespace std;

// Input: Số nguyên y (năm).
// Output: true nếu là năm nhuận, false nếu không.
// Giải quyết: Kiểm tra (y chia hết cho 400) hoặc (chia hết cho 4 và không chia hết cho 100).
bool LaNamNhuan(int y)
{
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

// Input: Tháng m, năm y.
// Output: Số ngày tối đa trong tháng đó (28, 29, 30 hoặc 31).
// Giải quyết: Dùng switch-case phân loại tháng;
int SoNgayTrongThang(int m, int y)
{
    switch (m)
    {
    case 4 : case 6 : case 9 : case 11:
        return 30;
    case 2:
        return (LaNamNhuan(y) ? 29 : 28); 
    default:
        return 31;
    }
}

// Input: Nhập d, m, y từ bàn phím.
// Output: Cập nhật giá trị cho thuộc tính đối tượng.
// Giải quyết: Dùng cin để đọc và gán dữ liệu.
void Day::Nhap()
{
    cout << "Nhap ngay: "; cin >> iNgay;
    cout << "Nhap thang: "; cin >> iThang;
    cout << "Nhap nam: "; cin >> iNam;
    if (iThang > 12 || iThang < 1 || iNam < 0 || iNgay < 0 ||
        iNgay >SoNgayTrongThang(iThang,iNam))
    {
        cout << "Ngay thang nam khong hop le! Vui long nhap lại: \n";
        Nhap();
    }
};

// Input: Thuộc tính d, m, y của đối tượng.
// Output: In chuỗi định dạng "Ngay d thang m nam y" ra màn hình.
// Giải quyết: Dùng cout để xuất dữ liệu thuộc tính
void Day::Xuat()
{
    cout << "Ngay" << " " << iNgay << " " << "thang" << " " << iThang << " " << "nam" << " " << iNam << "\n"; 
}

// Input: Ngày, tháng, năm hiện tại (d, m, y).
// Output: Đối tượng Day chứa ngày kế tiếp.
// Giải quyết: Tăng d; nếu vượt quá giới hạn tháng thì reset d=1 và tăng m; nếu m > 12 thì reset m=1 và tăng y.
Day Day::NgayThangNamTiepTheo()
{
    Day tiepTheo;
    tiepTheo.iNgay = iNgay;
    tiepTheo.iThang = iThang;
    tiepTheo.iNam = iNam;
    int soNgayTrongThang = SoNgayTrongThang(iThang,iNam);

    if (iNgay < soNgayTrongThang) {
        tiepTheo.iNgay++;
    } else {
        tiepTheo.iNgay = 1;
        if (iThang < 12) {
            tiepTheo.iThang++;
        } else {
            tiepTheo.iThang = 1;
            tiepTheo.iNam++;
        }
    }
    return tiepTheo;
}
