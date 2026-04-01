#include <iostream>
#include "Time.h"
using namespace std;

int main()
{
    Time t;
    t.Nhap();
    Time congThemMotGiay = t.TinhCongThemMotGiay();
    congThemMotGiay.Xuat();
}