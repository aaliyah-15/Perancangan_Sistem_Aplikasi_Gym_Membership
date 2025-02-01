#include <fstream>
#include <string>
#include "member.h"


class Admin : public User
{
private:
  std::string name;
  std::string password;

public:
  Admin() {} // default constructor
  Admin(std::string _name, std::string _password)
  {
    Admin::name = _name;
    Admin::password = _password;
  }

  std::string getName() { return Admin::name; }
  std::string getPassword() { return Admin::password; }

  void CreateMembership(Member *member)
  {
    system("cls");
    std::ofstream MembershipO;
    MembershipO.open("memberships.csv", std::ios::app);
    MembershipO << member->getId() << ",";
    MembershipO << member->getName() << ",";
    MembershipO << member->getJoinedDate() << ",";
    MembershipO << member->getExpiryDate() << ",";
    MembershipO << std::endl;
    MembershipO.close();
  }
  void EditMembership()
  {
    system("cls");
    std::ofstream tempOut;
    std::fstream file("memberships.csv");
    if (!file.is_open())
    {
      std::cerr << "Error to open file" << std::endl;
      return;
    }
    int selectedIndex;
    std::string line;
    int memberIndex = 1;
    std::cout << "INDEX | MEMBER NAME | EXPIRE DATE" << std::endl;
    std::cout << "------|-------------|------------" << std::endl;
    while (getline(file, line))
    {
      std::string data[4];
      std::string buff;
      int dataPos = 0;

      for (int i = 0; i < line.length(); i++)
      {
        if (line[i] == ',')
        {
          data[dataPos] = buff;
          dataPos++;
          buff = "";
          continue;
        }
        buff += line[i];
      }

      std::cout << "[" << memberIndex << "] ";
      std::cout << data[1] << " | ";
      std::cout << data[3];
      std::cout << "\n======\n";
      memberIndex++;
    }
    std::string updatedExpiryDate;
    std::cout << "Please enter index of member: ";
    std::cin >> selectedIndex;
    std::cout << "New membership expiry date [YYYY/MM/DD]: ";
    std::cin >> updatedExpiryDate;

    tempOut.open("temp.csv", std::ios::app);
    memberIndex = 1;
    std::ifstream file2temp("memberships.csv");
    if (!file2temp.is_open())
    {
      std::cerr << "Error to open file" << std::endl;
      return;
    }
    while (getline(file2temp, line))
    {
      std::string data[4];
      std::string buff;
      int dataPos = 0;

      for (int i = 0; i < line.length(); i++)
      {
        if (line[i] == ',')
        {
          data[dataPos] = buff;
          dataPos++;
          buff = "";
          continue;
        }
        buff += line[i];
      }

      tempOut << data[0] << ",";
      tempOut << data[1] << ",";
      tempOut << data[2] << ",";
      if(memberIndex == selectedIndex){
        tempOut << updatedExpiryDate << ",";
      }
      else {
        tempOut << data[3] << ",";
      }
      tempOut << std::endl;
      memberIndex++;
    }
    tempOut.close();
    file.close();
    file2temp.close();

    remove("memberships.csv");
    rename("temp.csv", "memberships.csv");
  }
  void DeleteMembership()
  {
    system("cls");
    std::ofstream tempOut;
    std::fstream file("memberships.csv");
    if (!file.is_open())
    {
      std::cerr << "Error to open file" << std::endl;
      return;
    }
    int selectedIndex;
    std::string line;
    int memberIndex = 1;
    std::cout << "INDEX | MEMBER NAME | NIK" << std::endl;
    std::cout << "------|-------------|------------" << std::endl;
    while (getline(file, line))
    {
      std::string data[4];
      std::string buff;
      int dataPos = 0;

      for (int i = 0; i < line.length(); i++)
      {
        if (line[i] == ',')
        {
          data[dataPos] = buff;
          dataPos++;
          buff = "";
          continue;
        }
        buff += line[i];
      }

      std::cout << "[" << memberIndex << "] ";
      std::cout << data[1] << " | ";
      std::cout << data[0];
      std::cout << "\n======\n";
      memberIndex++;
    }
    std::string updatedExpiryDate;
    std::cout << "Please enter index of member: ";
    std::cin >> selectedIndex;

    tempOut.open("temp.csv", std::ios::app);
    memberIndex = 1;
    std::ifstream file2temp("memberships.csv");
    if (!file2temp.is_open())
    {
      std::cerr << "Error to open file" << std::endl;
      return;
    }
    while (getline(file2temp, line))
    {
      if (memberIndex == selectedIndex)
      {
        memberIndex++;
        continue;
      }
      std::string data[4];
      std::string buff;
      int dataPos = 0;

      for (int i = 0; i < line.length(); i++)
      {
        if (line[i] == ',')
        {
          data[dataPos] = buff;
          dataPos++;
          buff = "";
          continue;
        }
        buff += line[i];
      }

      tempOut << data[0] << ",";
      tempOut << data[1] << ",";
      tempOut << data[2] << ",";
      tempOut << data[3] << ",";
      tempOut << std::endl;
      memberIndex++;
    }
    tempOut.close();
    file.close();
    file2temp.close();

    remove("memberships.csv");
    rename("temp.csv", "memberships.csv");
  }
  void ViewMemberships()
  {
    system("cls");
    std::fstream file("memberships.csv");
    if (!file.is_open())
    {
      std::cerr << "Error to open file" << std::endl;
      return;
    }
    std::string line;
    int memberIndex = 1;
    while (getline(file, line))
    {
      std::string data[4];
      std::string buff;
      int dataPos = 0;

      for (int i = 0; i < line.length(); i++)
      {
        if (line[i] == ',')
        {
          data[dataPos] = buff;
          dataPos++;
          buff = "";
          continue;
        }
        buff += line[i];
      }

      std::cout << "[" << memberIndex << "]" << std::endl;
      std::cout << "Nama: " << data[1] << std::endl;
      std::cout << "NIK: " << data[0] << std::endl;
      std::cout << "Member since: " << data[2] << std::endl;
      std::cout << "Expire at: " << data[3] << std::endl;
      std::cout << "\n======\n\n";
      memberIndex++;
    }
  }

  void ViewAppointments(){
    system("cls");
    std::fstream file("appointments.csv");
    if (!file.is_open())
    {
      std::cerr << "Error to open file" << std::endl;
      return;
    }
    std::string line;
    int appointmentIndex = 1;
    while (getline(file, line))
    {
      std::string data[3];
      std::string buff;
      int dataPos = 0;

      for (int i = 0; i < line.length(); i++)
      {
        if (line[i] == ',')
        {
          data[dataPos] = buff;
          dataPos++;
          buff = "";
          continue;
        }
        buff += line[i];
      }

      std::cout << "[" << appointmentIndex << "]" << std::endl;
      std::cout << "Name: " << data[1] << std::endl;
      std::cout << "Scheduled With: " << data[2] << std::endl;
      std::cout << "\n======\n\n";
      appointmentIndex++;
    }
  }
};

struct ValidationResult
{
  bool isSuccess;
  Admin admin;
};

ValidationResult validateLogin(LoginInfo &loginInfo)
{
  Admin arrAdmin[10] = {
      Admin("bitalxndr", "pw1234"),
      Admin("bittabitt", "pw1235"),
      Admin("asd", "asd"),
  };

  int indexFlag = -1;
  for (int i = 0; i < 10; i++)
  {
    if (loginInfo.username == arrAdmin[i].getName() && loginInfo.password == arrAdmin[i].getPassword())
    {
      indexFlag = i;
      break;
    }
  }
  if (indexFlag >= 0)
  {
    std::cout << "Login success." << std::endl;
    return ValidationResult{
        true,
        arrAdmin[indexFlag]};
  }
  std::cout << "Invalid username or password. Please try again." << std::endl;
  return ValidationResult{
      false,
      Admin("", ""),
  };
}
void UIAdmin(Admin *admin)
{
  const int VIEW_MEMBERS = 1;
  const int VIEW_APPOINTMENTS = 2;
  const int ADD_MEMBER = 3;
  const int RENEW_MEMBERSHIP = 4;
  const int CANCEL_MEMBERSHIP = 5;
  const int LOGOUT = 6;

  UIController c;
  bool shouldExit = false;
  std::string id, name, joinedDate, expiryDate;
  Member member = Member("", "", "", "");
  while (true)
  {
    if (shouldExit)
    {
      break;
    }
    int choice = c.getAdminInput();
    switch (choice)
    {
    case LOGOUT:
      shouldExit = true;
      break;
    case VIEW_MEMBERS:
      admin->ViewMemberships();
      std::cout << "\n----------------------" << std::endl;
      std::cout << "Tekan tombol Enter untuk kembali...";
      std::cin.ignore();
      std::cin.get();
      break;
    case VIEW_APPOINTMENTS:
      admin->ViewAppointments();
      std::cout << "\n----------------------" << std::endl;
      std::cout << "Tekan tombol Enter untuk kembali...";
      std::cin.ignore();
      std::cin.get();
      break;
    case ADD_MEMBER:
      system("cls");
      std::cout << "Add New Member" << std::endl;
      std::cout << "==============" << std::endl;
      
      std::cin.ignore(1, '\n');
      std::cout << "ID (NIK): ";
      getline(std::cin, id);

      std::cout << "Name: ";
      getline(std::cin, name);

      std::cout << "Joining Date [YYYY/MM/DD]: ";
      getline(std::cin, joinedDate);

      std::cout << "Expiry Date [YYYY/MM/DD]: ";
      getline(std::cin, expiryDate);

      member = Member(id, name, joinedDate, expiryDate);
      admin->CreateMembership(&member);
      std::cout << "Data created" << std::endl;
      std::cout << "\n----------------------" << std::endl;
      std::cout << "Tekan tombol Enter untuk kembali...";
      std::cin.get();
      break;
    case RENEW_MEMBERSHIP:
      admin->EditMembership();
      std::cout << "\n----------------------" << std::endl;
      std::cout << "Tekan tombol Enter untuk kembali...";
      std::cin.ignore();
      std::cin.get();
      break;
    case CANCEL_MEMBERSHIP:
      admin->DeleteMembership();
      std::cout << "\n----------------------" << std::endl;
      std::cout << "Tekan tombol Enter untuk kembali...";
      std::cin.ignore();
      std::cin.get();
      break;
    default:
      std::cout << "Pilihan yang anda masukkan salah." << std::endl;
      break;
    }
  }
}