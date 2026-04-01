#include <iostream>
#include "Time.h"
using namespace std;

// Input: Nhập iGio, iPhut, iGiay từ bàn phím.
// Output: Cập nhật giá trị cho thuộc tính đối tượng.
// Giải quyết: Dùng cin để đọc và gán dữ liệu, nhập lại nếu thông tin không hợp lệ.
void Time::Nhap()
{
    cout << "Nhap gio: "; cin >> iGio;
    cout << "Nhap phut: "; cin >> iPhut;
    cout << "Nhap giay: "; cin >> iGiay;
    if (iGio < 0 || iGio > 23 || iPhut < 0 || iPhut > 59 || 
        iGiay < 0 || iGiay > 59)
    {
        cout << "Thoi gian khong hop le! Vui long nhap lai!\n";
        Nhap();
    }
}

// Input: Thuộc tính iGio, iPhut, iGiay của đối tượng.
// Output: In chuỗi giờ phút giây ra màn hình.
// Giải quyết: Dùng cout để xuất dữ liệu thuộc tính
void Time::Xuat() {
    cout << iGio << " gio " << iPhut << " phut " << iGiay << " giay.\n";
}

// Input: iGio , iPhut, iGiay của đối tượng.
// Output: Đối tượng Time thời gian sau khi được cộng thêm một giây.
// Giải quyết: Tăng iGiay; nếu vượt quá giới hạn giây thì reset iGiay=0 và tăng iPhut; nếu iPhut > 59 thì reset iPhut=0 và tăng iGio.
// Tương tự nếu iGio quá giới hạn.
Time Time::TinhCongThemMotGiay()
{
    Time plus;
    plus.iGio = iGio;
    plus.iPhut = iPhut;
    plus.iGiay = iGiay;
    if (iGiay < 59)
        plus.iGiay++;
    else
    {
        plus.iGiay = 0;
        if (iPhut < 59)
            plus.iPhut++;
        else
        {
            plus.iPhut = 0;
            if (iGio < 23)
                plus.iGio++;
            else
                plus.iGio = 0;
        }
    }
    return plus;
}