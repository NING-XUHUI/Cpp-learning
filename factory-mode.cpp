#include <iostream>
#include <string>
#include <map>
using namespace std;

class RoleOperation {
public:
  virtual std::string Op() = 0;
  virtual ~RoleOperation() {}
};

class RootAdminRole : public RoleOperation {
public:
  RootAdminRole(const std::string &roleName) : m_RoleName(roleName) {}
  std::string Op() { return m_RoleName + "has A permission"; }

private:
  std::string m_RoleName;
};

class OrderAdminRole : public RoleOperation {
public:
  OrderAdminRole(const std::string &roleName) : m_RoleName(roleName) {}
  std::string Op() { return m_RoleName + "has B permission"; }
private:
  std::string m_RoleName;
};

class NormalAdminRole : public RoleOperation {
public:
  NormalAdminRole(const std::string &roleName) : m_RoleName(roleName) {}
  std::string Op() { return m_RoleName + "has C permission"; }
private:
  std::string m_RoleName;
};

class RoleFactory{
  static RoleFactory& Instance(){
    static RoleFactory instance;
    return instance;
  }
  void RegisterRole(const std::string& name,RoleOperation* register){
    m_RoleRegister[name] = register;
  }
  RoleOperation* GetRole(const std::string& name){
  }
}

int main() { return 0; }
