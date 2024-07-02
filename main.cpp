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
        void updateData(Karyawan data){
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

        // fungsi untuk mencari data
        void src(string dataIn){
        string buffer;
        bool found = false;
        in.open(fileName);

        if(in.is_open()){

            // Print headers
            cout << left << setw(10) << "ID"
                << left << setw(20) << "Nama"
                << left << setw(15) << "Tanggal Lahir"
                << left << setw(15) << "Pekerjaan"
                << left << setw(20) << "Alamat"
                << left << setw(10) << "Jam Kerja" << endl;
            cout << string(90, '-') << endl; // separator line

            while (getline(in, buffer)){
                if(buffer.find(dataIn) != string::npos){
                    // cout << buffer << endl;

                    stringstream ss(buffer);
                    string idk, nama, tanggalLahir, pekerjaan, alamat, jamKerja;

                    getline(ss, idk, ',');
                    getline(ss, nama, ',');
                    getline(ss, tanggalLahir, ',');
                    getline(ss, pekerjaan, ',');
                    getline(ss, alamat, ',');
                    getline(ss, jamKerja, ',');

                    cout << left << setw(10) << idk
                        << left << setw(20) << nama
                        << left << setw(15) << tanggalLahir
                        << left << setw(15) << pekerjaan
                        << left << setw(20) << alamat
                        << left << setw(10) << jamKerja << "\n" << endl;

                    found = true;
                }
            }
            in.close();
            if(!found){
                cout << "404 not Found" << endl;
            }
        }else{
            cout << "File tidak ditemukan" << endl;
        }
    }


        // fungsi untuk delete file
        void deleteFile(){
            // code here
        }

        // fungsi untuk edit file
        void editData(){
            // code here
        }


};

// fungsi untuk add file bagian menu
void addData(){
    // code here
}

// fungsi unput user
string inputUser(){
    // code here 
}

// fungsi menu
void menu(){
    // code here
}

int main(){

    DBase database("dataKaryawan.txt");

    while (true){
        menu();
        int userChoice;
        cout << "Pilih Menu: ";
        cin >> userChoice;
        cin.ignore(); 

        if (userChoice == 1){
            Karyawan karyawan = inputUser();
            database.updateData(karyawan);
            cout << "Data Sudah Ditambah" << "\n" << endl;
        } else if (userChoice == 2){
            string idk;
            cout << "Masukan ID Karyawan yang Ingin Diedit: ";
            getline(cin, idk);

            Karyawan karyawan = inputUser();
 
            database.edit(idk, karyawan);
            cout << "Data Sudah Diedit" << endl;
        }
    return 0;
}
