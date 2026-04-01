#include <iostream>
#include "Day.h"
using namespace std;

int main()
{
    Day a;
    a.Nhap();
    Day NgayTiepTheo = a.NgayThangNamTiepTheo();
    NgayTiepTheo.Xuat();
}