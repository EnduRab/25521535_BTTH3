#ifndef CPHANSO_H
#define CPHANSO_H

class cPhanSo {
private:
    int Tu, Mau;
public:
    cPhanSo(int, int);
    cPhanSo();

    void RutGon();
    void Xuat();

    double GetGiaTri() const;

    cPhanSo operator+(const cPhanSo& other);
    bool operator>(const cPhanSo& other);

    friend class cDSPhanSo;
};

#endif // !CPHANSO_H
