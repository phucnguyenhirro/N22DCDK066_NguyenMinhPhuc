#include <iostream>

class Sap {
protected:
    int _stt;
    float _dt;
    long _doanhThu;

public:
    static long DON_GIA_THUE;
    virtual long tinhTienThue() {
        return DON_GIA_THUE * this->_dt;
    }

    virtual long tinhThueDoanhThu() = 0;
    virtual long tinhTongTien() = 0;

    virtual void nhapThongTin() {
        std::cout << "Nhap STT: ";
        std::cin >> this->_stt;
        std::cout << "Nhap Dien tich: ";
        std::cin >> this->_dt;
        std::cout << "Nhap Doanh thu: ";
        std::cin >> this->_doanhThu;
    }

    virtual ~Sap() {
        this->_stt = 0;
        this->_dt = 0;
        this->_doanhThu = 0;
    }
};

long Sap::DON_GIA_THUE = 40000000;

class SapThucPham : public Sap {
private:
    long phiDongLanh;
    static float PHAN_TRAM_THUE_SAP_THUC_PHAM;

public:
    long tinhThueDoanhThu() override {
        return static_cast<long>(PHAN_TRAM_THUE_SAP_THUC_PHAM * this->_doanhThu);
    }

    long tinhTongTien() override {
        return this->phiDongLanh + this->tinhThueDoanhThu() + this->tinhTienThue();
    }

    void nhapThongTin() override {
        Sap::nhapThongTin();
        std::cout << "Nhap Phi dong lanh: ";
        std::cin >> this->phiDongLanh;
    }
};

float SapThucPham::PHAN_TRAM_THUE_SAP_THUC_PHAM = 0.1;

class SapQuanAo : public Sap {
public:
    static float PHAN_TRAM_THUE_SAP_QUAN_AO;

    long tinhThueDoanhThu() override {
        return static_cast<long>(PHAN_TRAM_THUE_SAP_QUAN_AO * this->_doanhThu);
    }

    long tinhTongTien() override {
        return this->tinhThueDoanhThu() + this->tinhTienThue();
    }
};

float SapQuanAo::PHAN_TRAM_THUE_SAP_QUAN_AO = 0.1;

class SapTrangSuc : public Sap {
public:
    static long GIOI_HAN_DOANH_THU;
    static float PHAN_TRAM_THUE_DUOI_GIOI_HAN;
    static float PHAN_TRAM_THUE_TREN_GIOI_HAN;

    long tinhThueDoanhThu() override {
        if (this->_doanhThu <= GIOI_HAN_DOANH_THU) {
            return static_cast<long>(PHAN_TRAM_THUE_DUOI_GIOI_HAN * this->_doanhThu);
        } else {
            return static_cast<long>(PHAN_TRAM_THUE_TREN_GIOI_HAN * this->_doanhThu);
        }
    }

    long tinhTongTien() override {
        return this->tinhThueDoanhThu() + this->tinhTienThue();
    }
};

long SapTrangSuc::GIOI_HAN_DOANH_THU = 199000009;
float SapTrangSuc::PHAN_TRAM_THUE_DUOI_GIOI_HAN = 0.2;
float SapTrangSuc::PHAN_TRAM_THUE_TREN_GIOI_HAN = 0.3;

class QuanlyDanhSach {
private:
    Sap* danhSachSap[100];
    int soLuongSap;

public:
    QuanlyDanhSach() : soLuongSap(0) {}

    void themSap(Sap* sap) {
        if (soLuongSap < 100) {
            danhSachSap[soLuongSap++] = sap;
        } else {
            std::cout << "Danh sach sap da day!" << std::endl;
        }
    }

    void tinhTongTienTuongCa() {
        long tongTien = 0;
        for (int i = 0; i < soLuongSap; ++i) {
            tongTien += danhSachSap[i]->tinhTongTien();
        }
        std::cout << "Tong tien tuong ca: " << tongTien << std::endl;
    }

    void nhapDanhSachSap() {
        std::cout << "Nhap so luong sap: ";
        std::cin >> soLuongSap;

        for (int i = 0; i < soLuongSap; ++i) {
            int loaiSap;
            std::cout << "Chon loai sap (1: ThucPham, 2: QuanAo, 3: TrangSuc): ";
            std::cin >> loaiSap;

            switch (loaiSap) {
                case 1: {
                    SapThucPham* sap = new SapThucPham();
                    sap->nhapThongTin();
                    themSap(sap);
                    break;
                }
                case 2: {
                    SapQuanAo* sap = new SapQuanAo();
                    sap->nhapThongTin();
                    themSap(sap);
                    break;
                }
                case 3: {
                    SapTrangSuc* sap = new SapTrangSuc();
                    sap->nhapThongTin();
                    themSap(sap);
                    break;
                }
                default:
                    std::cout << "Loai sap khong hop le!" << std::endl;
                    break;
            }
        }
    }
};

int main() {
    QuanlyDanhSach quanly;
    quanly.nhapDanhSachSap();
    quanly.tinhTongTienTuongCa();

    return 0;
}

                   
