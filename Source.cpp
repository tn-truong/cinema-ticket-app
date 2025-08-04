#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct SuatChieu {
    int id;
    string phim;
    string gioChieu;
    int soGheConLai;
};

vector<SuatChieu> dsSuat = {
    {1, "Avengers", "14:00", 200},
    {2, "Spiderman", "16:00", 200},
    {3, "Batman", "18:00", 200},
};

void hienThiSuat() {
    cout << "\n--- DANH SACH SUAT CHIEU ---\n";
    for (const auto& s : dsSuat) {
        cout << s.id << ". " << s.phim << " | " << s.gioChieu
            << " | Ghe con lai: " << s.soGheConLai << "\n";
    }
}

void datVe() {
    int id, soGhe;
    hienThiSuat();
    cout << "\nNhap ID suat chieu muon dat: ";
    cin >> id;

    bool timThay = false;
    for (auto& s : dsSuat) {
        if (s.id == id) {
            timThay = true;
            if (s.soGheConLai == 0) {
                cout << "Het ghe cho suat nay!\n";
                return;
            }
            cout << "Nhap so ghe muon dat: ";
            cin >> soGhe;
            if (soGhe <= s.soGheConLai && soGhe > 0) {
                s.soGheConLai -= soGhe;
                cout << "✅ Dat ve thanh cong! Con lai " << s.soGheConLai << " ghe.\n";
            }
            else {
                cout << "❌ So ghe khong hop le!\n";
            }
            break;
        }
    }

    if (!timThay) {
        cout << "❌ Khong tim thay suat chieu!\n";
    }
}

int main() {
    int chon;
    do {
        cout << "\n========= MENU =========\n";
        cout << "1. Xem danh sach suat chieu\n";
        cout << "2. Dat ve\n";
        cout << "0. Thoat\n";
        cout << "Chon chuc nang: ";
        cin >> chon;

        switch (chon) {
        case 1: hienThiSuat(); break;
        case 2: datVe(); break;
        case 0: cout << "👋 Tam biet!\n"; break;
        default: cout << "❌ Lua chon khong hop le!\n"; break;
        }
    } while (chon != 0);

    return 0;
}
