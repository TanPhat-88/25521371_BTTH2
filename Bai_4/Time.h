#ifndef TIME_H
#define TIME_H
class Time {
private:
    int iGio, iPhut, iGiay;
public:
    void Nhap();
    void Xuat();
    Time TinhCongThemMotGiay(); 
};

#endif