#include <iostream>
#include <cstdlib>
#include <limits>
using namespace std;

class DiemTongKet {
    private:
        double DiemThanhPhan, DiemKetThucHocPhan;
    public:
        // Gia tri ban dau
        DiemTongKet();

        // Ham nhap xuat
        friend istream& operator>>(istream &is, DiemTongKet &a);
        friend ostream& operator<<(ostream &os, DiemTongKet a);

        // Cac toan tu
        float tinhDTK();
        bool operator == (DiemTongKet a);
		bool operator >= (DiemTongKet a);
		bool operator <= (DiemTongKet a);
		bool operator > (DiemTongKet a);
		bool operator < (DiemTongKet a);
		bool operator != (DiemTongKet a);
		DiemTongKet operator = (DiemTongKet a);
        DiemTongKet& operator++();
        DiemTongKet operator++(int);
        DiemTongKet& operator--();
        DiemTongKet operator--(int);

        // Kiem tra co hoc lai khong
        void KiemTraCoHocLai();
};

void choNhanEnter() {
    cout << "Nhan Enter de tiep tuc...";
    // Xoa toan bo ki tu
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // Cho nhan enter
    cin.get();
}

DiemTongKet::DiemTongKet() {
    DiemKetThucHocPhan = 0;
    DiemThanhPhan = 0;
}
float DiemTongKet::tinhDTK(){
	return DiemThanhPhan * 0.4 + DiemKetThucHocPhan * 0.6;
}
istream& operator>>(istream &is, DiemTongKet &a){
    
    // Nhap diem thanh phan
	cout << "Nhap vao diem TP: "; is >> a.DiemThanhPhan;
    while(a.DiemThanhPhan < 0 || a.DiemThanhPhan > 10) {
        cout << "Nhap lai diem TP: "; is >> a.DiemThanhPhan;
    }

    // Nhap diem ket thuc hoc phan
	cout << "Nhap vao diem KTHP: "; is >> a.DiemKetThucHocPhan;
    while(a.DiemKetThucHocPhan < 0 || a.DiemKetThucHocPhan > 10) {
        cout << "Nhap lai diem KTHP: "; is >> a.DiemKetThucHocPhan;
    }
	return is;
}
ostream& operator<<(ostream &os, DiemTongKet a){
    // In ra mang hinh diem
	os << "Diem TP: " << a.DiemThanhPhan << endl;
    os << "Diem KTHP: " << a.DiemKetThucHocPhan << endl;
    os << "Diem tong ket: " << a.tinhDTK() << endl;
    choNhanEnter();
    return os;
}
DiemTongKet& DiemTongKet::operator++() {
    this->DiemThanhPhan += 1;
    this->DiemKetThucHocPhan += 1;
    return *this;
}
DiemTongKet DiemTongKet::operator++(int) {
    DiemTongKet t = *this;
    this->DiemThanhPhan += 1;
    this->DiemKetThucHocPhan += 1;
    return t;
}
DiemTongKet& DiemTongKet::operator--() {
    this->DiemThanhPhan -= 1;
    this->DiemKetThucHocPhan -= 1;
    return *this;
}
DiemTongKet DiemTongKet::operator--(int) {
    DiemTongKet t = *this;
    this->DiemThanhPhan -= 1;
    this->DiemKetThucHocPhan -= 1;
    return t;
}
bool DiemTongKet::operator ==(DiemTongKet a){
	return tinhDTK() ==  a.tinhDTK();
}
bool DiemTongKet::operator >=(DiemTongKet a){
	return tinhDTK() >=  a.tinhDTK();
}
bool DiemTongKet::operator <=(DiemTongKet a){
	return tinhDTK() <=  a.tinhDTK();
}
bool DiemTongKet::operator >(DiemTongKet a){
	return tinhDTK() >  a.tinhDTK();
}
bool DiemTongKet::operator <(DiemTongKet a){
	return tinhDTK() <  a.tinhDTK();
}
bool DiemTongKet::operator !=(DiemTongKet a){
	return tinhDTK() !=  a.tinhDTK();
}
DiemTongKet DiemTongKet::operator =(DiemTongKet a){
	this->DiemThanhPhan = a.DiemThanhPhan;
	this->DiemKetThucHocPhan = a.DiemKetThucHocPhan;
	return *this;
}
void DiemTongKet::KiemTraCoHocLai() {
    // Neu diem ket thuc duoi 1 hoac diem tong ket duoi 5 thi hoc lai
    if(DiemKetThucHocPhan < 1) {
        cout << "\n\nDiem thi cua ban duoi 1, ban phai hoc lai!" << endl;
        return;
    } else if(DiemThanhPhan * 0.4 + DiemKetThucHocPhan * 0.6 < 5) {
        cout << "Diem tong ket cua ban duoc " << DiemThanhPhan * 0.4 + DiemKetThucHocPhan * 0.6 << " < 5. Vi vay ban phai hoc lai!" << endl;
    } else {
        cout << "Chuc mung ban khong phai hoc lai mon nay!!!!" << endl;
    }
    // nhan enter de tiep tuc
    choNhanEnter();
}

void menuSoSanh(){
	cout << "1. So sanh ==" << endl
		 << "2. So sanh >=" << endl
		 << "3. So sanh <=" << endl
		 << "4. So sanh >" << endl
		 << "5. So sanh <" << endl
		 << "6. So sanh !=" << endl << endl
         << "=> Lua chon: ";
}
void soSanh(DiemTongKet a, DiemTongKet b) {
    menuSoSanh();
    int choice;
    cin >> choice;
    switch(choice) {
        case 1:
            if(a == b) cout << a.tinhDTK() << " == " << b.tinhDTK();
            else cout << a.tinhDTK() << " != " << b.tinhDTK();
            break;
        case 2:
            if(a >= b) cout << a.tinhDTK() << " >= " << b.tinhDTK();
            else cout << a.tinhDTK() << " < " << b.tinhDTK();
            break;
        case 3:
            if(a <= b) cout << a.tinhDTK() << " <= " << b.tinhDTK();
            else cout << a.tinhDTK() << " > " << b.tinhDTK();
            break;
        case 4:
            if(a > b) cout << a.tinhDTK() << " > " << b.tinhDTK();
            else cout << a.tinhDTK() << " < " << b.tinhDTK();
            break;
        case 5:
            if(a < b) cout << a.tinhDTK() << " < " << b.tinhDTK();
            else cout << a.tinhDTK() << " > " << b.tinhDTK();
            break;
        case 6:
            if(a == b) cout << a.tinhDTK() << " != " << b.tinhDTK();
            else cout << a.tinhDTK() << " == " << b.tinhDTK();
            break;
        default:
            cout << "chon ngu the";
    }
}

int main() {
    int flat = 1, check = 1, choice;
    DiemTongKet poin1, poin2;
    while(flat == 1) {
        system("cls");
        cout << "1. Nhap diem" << endl
             << "2. Xem diem" << endl
             << "3. So sanh diem" << endl
             << "4. Kiem tra co hoc lai khong" << endl << endl
             << "=> Lua chon: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> poin1 >> poin2;
                check = 0;
                break;
            case 2:
                if(check == 0) {
                    cout << poin1 << poin2;
                } else {
                    cout << "Chua nhap diem!" << endl;
                    choNhanEnter();
                }
                break;
            case 3:
                if(check == 0) {

                }
            case 4:
                if(check == 0) {
                    poin1.KiemTraCoHocLai();
                } else {
                    cout << "Chua nhap diem!" << endl;
                    choNhanEnter();
                }
                break;
            default:
                cout << "Chon lai!" << endl;
                choNhanEnter();
                break;
        }
        
    }
}