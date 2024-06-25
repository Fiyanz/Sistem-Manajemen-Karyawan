# Sistem Manajemen Karyawan

## Algoritma 


```js
// kelas karyawan
// fian
class Karyawan:
    // Atribut karyawan
    id: int
    nama: string
    tanggalLahir: string
    alamat: string
    pekerjaan: string
    jamKerja: int

    // Konstruktor untuk inisialisasi objek Jadwal
    constructor(id, nama, tanggalLaahir, alamat, pekerjaan, jamKerja):
        self.id = id
        self.nama = nama
        self.tanggalLahir = tanggalLahir
        self.almat = alamat
        self.pekerjaan = perkerjaan
        self.jamKerja = jamKerja

    // fungi untuk mengembalikan data kaeyawan
    function getKaryawan() -> string:
        return idk + "," + nama + "," + tanggalLahir + "," + alamat + "\n"
        


// kelas untuk database

// khari
class Dbase:
    // atribut database
    ofstream out // objek dari liblary fstream
    ifstream in // objek dari liblary fstream
    namaFile: string

    // konstuktor selakigus untuk memberi nama file
    constructor(namaFile):
        self.namaFile = namaFile

    // meifa
    // fungsi untuk update data dari kelas karyawan
    function update(karyawan data):
        out.open(fileName, append) // mode append
        save(data.getDataKaryawan())
        out.close();

    // putri
    // fungsi untuk mengahapus file
    function delete(id | nama):
            in.open(fileName)
            while getline(fileName):
                // jika menemukan data sesuai input
                if output.find(dataIn):
                    in.delete()
                    print("data sudah dihapus")
                    in.close()
            
            in.close()
            print("404 not Found")

    // novi
    // fungsi untuk membaca semua file file
    function readAllData(karyawan data):
        output, buffer string
            in.open(fileName);

            while !in.eof() // fungsi bawaan liblary untuk mendeteksi line dari file
                if nameFile = None:
                    print("file kosong")
                    in.close()
                getline(in, buffer);
                output.append("\n" + buffer);
            
            print(output)

    // zijah
    // fungsi untuk mencari data keryawan
    function search(id | nama):
        in.open(fileName)
        while getline(fileName):
            // jika menemukan data sesuai input
            if output.find(dataIn):
                return output
                in.close()

    // nizar
    // fungsi untuk edit karyawan
    function edit(id, kaaryawan data):
        in.open(fileName)
        while getline(fileName):
            // jika menemukan data sesuai input
            ifoutput.find(dataIn):
                in.delete()
                save(data.getDataKaryawan)
                in.close()
            
        
        in.close()
        print("404 not Found")



function menu():
    print("Menu Utama:")
    print("1. Tambah Karyawan")
    print("2. Hapus Karyawan")
    print("3. Cari karyawan")
    print("4. Edit Karyawan")
    print("5. Tampilkan Daftar Karyawan")
    print("6. Keluar")

//anom
//fungsi untuk menerima input dari user
function inputDataKaryawan() -> str:
    id = input("Masukan ID: ")
    nama = input("Masukan Nama: ")
    tangglLahir = input("Masukan tanggal Lahir: ")
    alamat = input("Masukan Alamat: ")
    perkajaan = input("Masukan Pekerjaan: ")
    jamKerja = input("Masukan Jam Kerja: ")

    return id, nama, tanggalLahir, alamat, pekerjaan, jamKerja

// main fungsi
function main():



    while True:
        // menampilkan menu
        menu()

        // memilih menu
        userChoice = int(input("Masukan Angka:"))

        // switch case
        switch userChoice:
            case 1:
                // menambahkan data karyawan
                karyawan.add(inputDataKaryawan)
            case 2:
                // delete data kryawan
                deleteData = input("Masukan id/nama yang akan dihapus: )
                karyawan.delete(deleteData)
            case 3:
                // mencari data
                searchData = input("Masukan id/nama yang akan di cari: ")
                karyawan.search(searchData)
            case 4:
                // edit data karyawan
                editData = input("Masukan id/nama data yang akan di edit: )
                karyawan.edit(editData)
            case 5: 
                // menampulkan data karyawan
                karyawan.readAllData()
            case 6:
                // keluar program
                print("Program Selesai")
                break

```

## Keterangan
