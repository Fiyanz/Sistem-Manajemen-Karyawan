#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

#include <vector>
#include <sstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

// class karyawan
class Karyawan{
private:
    
public:
    string nama;
    string idk;
    string tanggalLahir;
    string pekerjaan;
    string alamat;
    string jamKerja;

    Karyawan(string idk, string nama, string tanggalLahir,string pekerjaan, string alamat, string jamKerja){
        Karyawan::idk = idk;
        Karyawan::nama = nama;
        Karyawan::tanggalLahir = tanggalLahir;
        Karyawan::pekerjaan = pekerjaan; 
        Karyawan::alamat = alamat;
        Karyawan::jamKerja = jamKerja;
    }

    // fungsi untuk mengembalikan artibut karyawa / data karyawan
    string getDataKaryawan(){
        return idk + "," + nama + "," + tanggalLahir + "," + pekerjaan + "," + alamat + "," + jamKerja + "\n";
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
            out.open(fileName, ios::app);
            out << data.getDataKaryawan();
            out.close();
        }

        // fungsi untuk membaca seluruh data
        void readAll(){
        string line;
        in.open(fileName);

        if (!in.is_open()) {
            cout << "File tidak ditemukan" << endl;
            return;
        }

        // Print headers
        cout << left << setw(10) << "ID"
             << left << setw(20) << "Nama"
             << left << setw(15) << "Tanggal Lahir"
             << left << setw(15) << "Pekerjaan"
             << left << setw(20) << "Alamat"
             << left << setw(10) << "Jam Kerja" << endl;
        cout << string(90, '-') << endl; // separator line

            // Print data
            while (getline(in, line)){
                stringstream ss(line);
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
                    << left << setw(10) << jamKerja << endl;
            }
            in.close();
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
    // fungsi untuk edit file
    void edit(string idk, Karyawan newData){
        ifstream infile(fileName);
        ofstream temp("temp.txt");
        string line;
        if(idk != ""){
            while (getline(infile, line)){
                if (line.find(idk) != string::npos){
                    line = newData.getDataKaryawan();
                }
                temp << line << endl;
            }

            infile.close();
            temp.close();
            remove(fileName.c_str());
            rename("temp.txt", fileName.c_str());
        }else{
            cout << "Input Tidak Falid!!" << endl;
        }
    }



    // fungsi untuk delete file
    void deleteFile(string dataIn){
        ifstream infile(fileName);
        ofstream temp("temp.txt");
        string line;

        while (getline(infile, line)){
            if (line.find(dataIn) == string::npos){
                temp << line << endl;
            }
        }

        infile.close();
        temp.close();
        remove(fileName.c_str());
        rename("temp.txt", fileName.c_str());
    }

};


// fungsi input user
Karyawan inputUser(){
Karyawan inputUser(){
    string idk, nama, tanggalLahir, pekerjaan, alamat, jamKerja, dump;

    cout << "Masukan ID: "; 
    getline(cin, idk);
    cout << "Masukan Nama: "; 
    getline(cin, nama);
    cout << "Masukan Tanggal Lahir: "; 
    getline(cin, tanggalLahir);
    cout << "Masukan Pekerjaan: ";
    getline(cin, pekerjaan);
    cout << "Masukan Alamat: ";
    getline(cin, alamat);
    cout << "Masukan Jam Kerja: ";
    getline(cin, jamKerja);

    return Karyawan(idk, nama, tanggalLahir, pekerjaan, alamat, jamKerja);
}

// fungsi menu
void menu(){
    // code here
}

void clear(){

}

// main fungsi
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
        }else if (userChoice == 3){
            string searchData;
            cout << "Masukan Data yang Dicari: ";
            getline(cin, searchData);
            database.src(searchData);
        } else if (userChoice == 4){
            string deleteData;
            cout << "Masukan Data yang Dihapus: ";
            getline(cin, deleteData);
            database.deleteFile(deleteData);
            cout << "Data Sudah Dihapus" << endl;
        } else if (userChoice == 5){
            clear();
            database.readAll();
            // cout << "\n" << endl;
        } else if (userChoice == 6){
            clear();
            break;
        } else {
            clear();
            cout << "Pilihan tidak valid" << "\n" << endl;
        }
    }
    return 0;
}
