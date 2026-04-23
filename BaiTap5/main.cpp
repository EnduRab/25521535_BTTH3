#include "cDaThuc.h"
#include <iostream>


using namespace std;

int main() {
    cDaThuc A;
    cDaThuc B;
    cout << "--- NHAP DA THUC A ---\n";
    NhapBacDaThuc(A);
    cin >> A;
    cout << "--- NHAP DA THUC B ---\n";
    NhapBacDaThuc(B);
    cin >> B;

    cout << "--- DA THUC DA NHAP ---\n";
    cout << A << endl;
    cout << B << endl;


    cout << "--- TINH GIA TRI ---";
    double x;
    cout << "\nNhap gia tri cua x trong da thuc: ";
    cin >> x;
    cout << "Gia tri cua da thuc A la: " << A.TinhGiaTri(x) << endl;
    cout << "Gia tri cua da thuc B la: " << B.TinhGiaTri(x) << endl;

    cout << "--- CAC PHEP TINH VOI DA THUC ---\n";
    cDaThuc Tong = A + B;
    cDaThuc Hieu = A - B;
    cout << "Tong 2 da thuc A + B = "; cout << Tong << endl;
    cout << "Hieu 2 da thuc A - B = "; cout << Hieu << endl;

    return 0;
}