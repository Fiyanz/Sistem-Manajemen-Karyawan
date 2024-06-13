#include <iostream>

using namespace std;

// klas karyawan
class Kawyawan{
    public:
        int32_t id;
        string nama;
        string alamat;
};

int main(){

    Kawyawan karyawan1;
    karyawan1.nama = "kazu";

    cout << "Nama Karyawan " << karyawan1.nama << endl;
    return 0;
}