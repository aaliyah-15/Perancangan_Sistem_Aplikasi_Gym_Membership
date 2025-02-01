#include <iostream>

struct LoginInfo
{
  std::string username;
  std::string password;
};

struct Trainer{
  std::string name;
  std::string days;
};

Trainer trainerList[6] = {
    {"Rizky Pratama", "Senin, Jumat"},
    {"Raditya Putra", "Rabu, Kamis"},
    {"Daniel Aditya", "Selasa, Jumat"},
    {"Kevin Permana", "Rabu, Sabtu"},
    {"Satria Wijaya", "Kamis, Sabtu"},
    {"Andreas Dimas", "Senin, Selasa"},
};

class UIController
{
public:
  void gymSchedule()
  {
    std::cout << "Jadwal Buka" << std::endl;
    std::cout << "----------------------" << std::endl;
    std::cout << "Senin" << "  | " << "04.30 - 22.00" << std::endl;
    std::cout << "Selasa" << " | " << "04.30 - 22.00" << std::endl;
    std::cout << "Rabu" << "   | " << "04.30 - 22.00" << std::endl;
    std::cout << "Kamis" << "  | " << "04.30 - 22.00" << std::endl;
    std::cout << "Jumat" << "  | " << "04.30 - 22.00" << std::endl;
    std::cout << "Sabtu" << "  | " << "04.30 - 22.00" << std::endl;
    std::cout << "Minggu" << " | " << "04.30 - 22.00" << std::endl;
  }

  void trainerSchedule()
  {
    std::cout << "Jadwal Pelatih" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    for (int i = 0; i < 6; i++) {
      std::cout << "Pelatih " << i+1 << ": " << trainerList[i].name << " | " << trainerList[i].days << std::endl;
    }
  }

  int getUserInput()
  {
    int choice;
    system("cls");
    std::cout << "Pilih menu:" << std::endl;
    std::cout << "1. Lihat jadwal buka" << std::endl;
    std::cout << "2. Lihat jadwal pelatih" << std::endl;
    std::cout << "3. Buat janji" << std::endl;
    std::cout << "4. Login admin" << std::endl;
    std::cout << "99. Keluar" << std::endl;
    std::cout << "-----------------------" << std::endl;
    std::cout << "Masukkan pilihan: ";
    std::cin >> choice;
    return choice;
  }

  LoginInfo getLoginInput()
  {
    system("cls");
    std::string name, password;
    std::cout << "LOGIN" << std::endl;
    std::cout << "-----------" << std::endl;
    std::cout << "username: ";
    std::cin >> name;
    std::cout << "password: ";
    std::cin >> password;
    return LoginInfo{name, password};
  }

  int getAdminInput()
  {
    int choice;
    system("cls");
    std::cout << "Pilih menu:" << std::endl;
    std::cout << "1. View Membership" << std::endl;
    std::cout << "2. View Appointment Schedule" << std::endl;
    std::cout << "3. Create Membership" << std::endl;
    std::cout << "4. Renew Membership" << std::endl;
    std::cout << "5. Cancel Membership" << std::endl;
    std::cout << "6. Logout" << std::endl;
    std::cout << "--------------------" << std::endl;
    std::cout << "Masukkan Pilihan: ";
    std::cin >> choice;
    return choice;
  }
};