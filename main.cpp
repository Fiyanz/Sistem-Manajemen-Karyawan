#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

// class karyawan
class Karyawan{
private:
    
public:
    string nama;
    string idk;
    string tanggalLahir;
    string alamat;

    Karyawan(string idk, string nama, string tanggalLahir, string alamat){
        Karyawan::idk = idk;
        Karyawan::nama = nama;
        Karyawan::tanggalLahir = tanggalLahir;
        Karyawan::alamat = alamat;
    }

    // fungsi untuk mengembalikan artibut karyawa / data karyawan
    string getDataKaryawan(){
        return idk + "," + nama + "," + tanggalLahir + "," + alamat + "\n";
    }
};

// class database / read and write file
class DBase{
    public:
        ofstream out;
        ifstream in;
        string fileName;

        // fungsi default krtika pertama di panggil
        DBase(const char* fileName){
            DBase::fileName = fileName;
        }

        // fungsi untuk save file
        void save(Karyawan data){
            DBase::out.open(DBase::fileName, ios::app);
            DBase::out << data.getDataKaryawan();
            out.close();
        }

        // fungsi untuk membaca seluruh data
        void readAll(){
            string output, buffer;
            DBase::in.open(DBase::fileName);

            while (!DBase::in.eof()){
                getline(DBase::in, buffer);
                output.append("\n" + buffer);
            }
            cout << output << endl;
        }

        // fungsi untuk membaca single line of file
        string readOne(string dataIn){
            // code here
            string output, buffer;
            DBase::in.open(DBase::fileName);

            while (getline(DBase::in, output)){
                
                if(output.find(dataIn, 0) != string::npos){
                    DBase::in.close();
                    return output;
                }
            }
            DBase::in.close();
            return "404 not Found";
        }

};

int main(){

    // user input
    string idk;
    cout << "Masukan ID: "; 
    getline(cin, idk);
    string nama;
    cout << "Masukan Nama: "; 
    getline(cin, nama);
    string tanggalLahir;
    cout << "Masukan Tanggal Lahir: "; 
    getline(cin, tanggalLahir);
    string alamat;
    cout << "Masukan Alamat: ";
    getline(cin, alamat);
    // buat objek karyawan
    Karyawan karyawan(idk, nama, tanggalLahir, alamat);

    string dataKaryawan = karyawan.getDataKaryawan();
    cout << dataKaryawan << endl;
    return 0;
}