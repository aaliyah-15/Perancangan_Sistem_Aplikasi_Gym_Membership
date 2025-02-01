#include <string>
#include "controller.h"

class User
{
  public:
  void ViewJadwal()
  {
    UIController c;
    system("cls");
    c.gymSchedule();
    std::cout << "\n----------------------" << std::endl;
    std::cout << "Tekan tombol Enter untuk kembali...";
    std::cin.ignore();
    std::cin.get();
  }
  void ViewPelatih()
  {
    UIController c;
    system("cls");
    c.trainerSchedule();
    std::cout << "\n----------------------------------------" << std::endl;
    std::cout << "Tekan tombol Enter untuk kembali...";
    std::cin.ignore();
    std::cin.get();
  }
};
