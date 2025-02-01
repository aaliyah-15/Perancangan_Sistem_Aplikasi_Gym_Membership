#include <fstream>
#include "user.h"

class Member : public User {
  private:
    std::string id;
    std::string name;
    std::string joinedDate;
    std::string expiryDate;
  
  public:
  Member (std::string _id, std::string _name, std::string _joinedDate, std::string _expiryDate){
    Member::id = _id;
    Member::name = _name;
    Member::joinedDate = _joinedDate;
    Member::expiryDate = _expiryDate;
  }

  std::string getId(){
    return Member::id;
  }
  std::string getName(){
    return Member::name;
  }
  std::string getJoinedDate(){
    return Member::joinedDate;
  }
  std::string getExpiryDate(){
    return Member::expiryDate;
  }

  void createAppointment(int trainerID){
    std::ofstream ofs;
    ofs.open("appointments.csv", std::ios::app);
    ofs << Member::id << ",";
    ofs << Member::name << ",";
    ofs << trainerList[trainerID-1].name << ",";
    ofs << std::endl;
    ofs.close();
  }
};

struct MemberValidationResult
{
  bool isValid;
  Member member;
};

MemberValidationResult validateNIK(std::string _NIK)
{
  std::ifstream userI;
  userI.open("memberships.csv");
  std::string line;
  bool isNIKFound = false;
  Member m = Member("", "", "", "");

  while (!userI.eof())
  {
    getline(userI, line);
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
    m = Member(data[0], data[1], data[2], data[3]);

    if (data[0] == _NIK)
    {
      isNIKFound = true;
      break;
    }
  }
  userI.close();
  return MemberValidationResult{
    isNIKFound, m};
}