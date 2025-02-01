#include <iostream>
#include "admin.h"
using namespace std;

int main() {
    const int JADWAL = 1;
    const int PELATIH = 2;
    const int BUAT_JANJI = 3;
    const int LOGIN = 4;
    const int KELUAR = 99;

    UIController c;
    User user;
    Admin admin;
    LoginInfo loginInfo;
    ValidationResult result;
    MemberValidationResult mvr = MemberValidationResult{false, Member("", "", "", "")};
    std::string NIK;

    bool shouldExit = false;
    while (true) {
        if (shouldExit) {
            break;
        }
        int choice = c.getUserInput();
        switch (choice) {
            case KELUAR:
                cout << "Terima kasih sudah menggunakan layanan kami." << endl;
                shouldExit = true;
                break;
            case JADWAL:
                user.ViewJadwal();
                break;
            case PELATIH:
                user.ViewPelatih();
                break;
            case BUAT_JANJI:
                system("cls");
                c.trainerSchedule();
                std::cout << "\n----------------------------------------" << std::endl;
                std::cout << "Please enter your NIK: ";
                std::cin >> NIK;
                mvr = validateNIK(NIK);
                if(!mvr.isValid){
                    std::cout << "Maaf, anda belum menjadi member." << std::endl;
                    std::cout << "Silakan melakukan registrasi member" << std::endl;
                    cout << "\n----------------------------------------" << endl;
                    cout << "Tekan tombol Enter untuk kembali...";
                    std::cin.ignore();
                    std::cin.get();
                    break;
                }
                int trainerId;
                std::cout << "\n----------------------------------------" << std::endl;
                std::cout << "Please select your trainer [1-6]: ";
                cin >> trainerId;
                mvr.member.createAppointment(trainerId);
                cout << "\nAppointment created" << endl;
                cout << "\n----------------------------------------" << endl;
                cout << "Tekan tombol Enter untuk kembali...";
                std::cin.ignore();
                std::cin.get();
                break;
            case LOGIN:
                loginInfo = c.getLoginInput();
                result = validateLogin(loginInfo);
                if (!result.isSuccess) {
                    cout << "\n----------------------------------------" << endl;
                    cout << "Tekan tombol Enter untuk kembali...";
                    cin.ignore();
                    cin.get();
                    break;
                }
                UIAdmin(&result.admin);
                break;
            default:
                cout << "Pilihan yang anda masukkan salah." << endl;
                break;
        }
    }
    return 0;
}