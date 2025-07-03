#include <iostream>
using namespace std;

// Husnul Fikri Averus
// A11.2024.15776

class List {
private:
    int data[100];
    int size;

public:
    List() { size = 0; }

    void inputAwal(int jumlah) {
        cout << "Masukkan nilai:\n";
        for (int i = 0; i < jumlah; i++) {
            cin >> data[i];
        }
        size = jumlah;
    }

    void tampil() {
        cout << "List: ";
        for (int i = 0; i < size; i++) {
            cout << data[i];
            if (i != size - 1) cout << ", ";
        }
        cout << endl;
    }

    void sortAsc() {
        int temp[100];
        for (int i = 0; i < size; i++) temp[i] = data[i];
        for (int i = 0; i < size - 1; i++)
            for (int j = 0; j < size - i - 1; j++)
                if (temp[j] > temp[j + 1])
                    swap(temp[j], temp[j + 1]);
        cout << "Ascending: ";
        for (int i = 0; i < size; i++) {
            cout << temp[i];
            if (i != size - 1) cout << ", ";
        }
        cout << endl;
    }

    void sortDesc() {
        int temp[100];
        for (int i = 0; i < size; i++) temp[i] = data[i];
        for (int i = 0; i < size - 1; i++)
            for (int j = 0; j < size - i - 1; j++)
                if (temp[j] < temp[j + 1])
                    swap(temp[j], temp[j + 1]);
        cout << "Descending: ";
        for (int i = 0; i < size; i++) {
            cout << temp[i];
            if (i != size - 1) cout << ", ";
        }
        cout << endl;
    }

    void filter() {
        cout << "Filter Nilai: ";
        for (int i = 0; i < size; i++)
            if (data[i] % 2 == 0) cout << data[i] << ", ";
        for (int i = 0; i < size; i++)
            if (data[i] % 2 != 0)
                cout << data[i] << (i == size - 1 ? "" : ", ");
        cout << endl;
    }

    bool hapus(int nilai) {
        for (int i = 0; i < size; i++) {
            if (data[i] == nilai) {
                for (int j = i; j < size - 1; j++)
                    data[j] = data[j + 1];
                size--;
                return true;
            }
        }
        return false;
    }

    bool tambah(int nilai, int posisi) {
	int index = posisi - 1;
        if (size >= 100 || index < 0 || index > size) return false;
        for (int i = size; i > index; i--)
            data[i] = data[i - 1];
        data[index] = nilai;
        size++;
        return true;
    }

    int getSize() { return size; }

    void tambahDataDenganValidasi() {
        char lanjut;
        cout << "\nIngin menambahkan nilai baru? (y/n): ";
        cin >> lanjut;

        if (lanjut == 'y' || lanjut == 'Y') {
            while (size >= 5) {
                cout << "Jumlah List = " << size << endl;
                cout << "Hapus nilai? (y/n): ";
                char hapusInput;
                cin >> hapusInput;
                if (hapusInput == 'y' || hapusInput == 'Y') {
                    int target;
                    cout << "Input Nilai yang akan dihapus: ";
                    cin >> target;
                    if (!hapus(target)) {
                        cout << "Nilai tidak ditemukan.\n";
                    } else {
                        cout << "Nilai berhasil dihapus.\n";
                    }
                } else {
                    cout << "Aksi dibatalkan.\n";
                    return;
                }
            }

            if (size < 5) {
                int val, pos;
                cout << "Input Nilai baru: ";
                cin >> val;
                cout << "Posisi: ";
                cin >> pos;
                if (!tambah(val, pos)) {
                    cout << "Posisi tidak valid atau array penuh.\n";
                }
		cout << endl;
            }
        }
    }
};

int main() {
    List list;
    int n;
    cout << "Masukkan jumlah nilai awal: ";
    cin >> n;
    list.inputAwal(n);

    char ulang;
    do {
        list.tampil();
        cout << "Jumlah List: " << list.getSize() << endl;
        list.sortAsc();
        list.sortDesc();
        list.filter();

        list.tambahDataDenganValidasi();
	
	list.tampil();

        cout << "\nUlangi proses? (y/n): ";
        cin >> ulang;
    } while (ulang == 'y' || ulang == 'Y');

    cout << "\nProgram selesai.\n";
    return 0;
}
