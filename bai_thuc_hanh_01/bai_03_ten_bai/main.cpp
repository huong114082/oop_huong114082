
#include <iostream>
#include <string>
#include <limits>
using namespace std;

////////// Khach Hang ///////////
class KhachHang {
private:
    string tenKH;
    string sdt;
    string diaChi;

public:
    KhachHang() {
        tenKH = "";
        sdt = "";
        diaChi = "";
    }

    KhachHang(string tenKH, string sdt, string diaChi) {
        this->tenKH = tenKH;
        this->sdt = sdt;
        this->diaChi = diaChi;
    }

    friend class HoaDon;

    void nhap() {
        cout << "Ten khach hang: ";
        getline(cin, tenKH);

        cout << "So dien thoai: ";
        getline(cin, sdt);

        cout << "Dia chi: ";
        getline(cin, diaChi);
    }
};

////////// Hang Hoa ///////////
class HangHoa {
private:
    string tenHH;
    string DVT;
    int soLuong;
    int donGia;

public:
    HangHoa() {
        tenHH = "";
        DVT = "";
        soLuong = 0;
        donGia = 0;
    }

    HangHoa(string tenHH, string DVT,
            int soLuong, int donGia) {
        this->tenHH = tenHH;
        this->DVT = DVT;
        this->soLuong = soLuong;
        this->donGia = donGia;
    }

    friend class HoaDon;

    void nhap() {
        cout << "Ten hang hoa: ";
        getline(cin, tenHH);

        cout << "Don vi tinh: ";
        getline(cin, DVT);

        cout << "So luong: ";
        cin >> soLuong;

        cout << "Don gia: ";
        cin >> donGia;

        cin.ignore();
    }

    long long thanhTien() const {
        return soLuong * donGia;
    }
};

////////// Hoa Don ///////////
class HoaDon {
private:
    string soHD;
    string ngay;
    KhachHang KH;
    HangHoa HH[15];
    int n;

public:
    HoaDon() {
        soHD = "";
        ngay = "";
        n = 0;
    }

    HoaDon(string soHD, string ngay) {
        this->soHD = soHD;
        this->ngay = ngay;
        n = 0;
    }

    void nhap() {
        cout << "So hoa don: ";
        getline(cin, soHD);

        cout << "Ngay: ";
        getline(cin, ngay);

        cout << "\n--- Nhap thong tin khach hang ---\n";
        KH.nhap();

        do {
            cout << "So mat hang (1-15): ";
            cin >> n;
            cin.ignore();

            if (n < 1 || n > 15) {
                cout << "So mat hang khong hop le!\n";
            }
        } while (n < 1 || n > 15);

        for (int i = 0; i < n; i++) {
            cout << "\nMat hang " << i + 1 << "\n";
            HH[i].nhap();
        }
    }

    long long tongTien() const {
        long long tong = 0;

        for (int i = 0; i < n; i++) {
            tong += HH[i].thanhTien();
        }

        return tong;
    }

    void xuat() const {
        cout << "\n----- HOA DON BAN HANG -----\n";

        cout << "So HD: " << soHD << "\n";
        cout << "Ngay: " << ngay << "\n";

        cout << "Ten khach hang: " << KH.tenKH << "\n";
        cout << "So dien thoai: " << KH.sdt << "\n";
        cout << "Dia chi: " << KH.diaChi << "\n";

        cout << "\nSTT\tTen hang\tDVT\tSL\tDon gia\tThanh tien\n";

        for (int i = 0; i < n; i++) {
            cout << i + 1 << "\t"
                 << HH[i].tenHH << "\t"
                 << HH[i].DVT << "\t"
                 << HH[i].soLuong << "\t"
                 << HH[i].donGia << "\t"
                 << HH[i].thanhTien() << "\n";
        }

        cout << "\nTONG TIEN: " << tongTien() << "\n";
    }
};

int main() {
    HoaDon hd;
    hd.nhap();
    hd.xuat();
    return 0;
}
