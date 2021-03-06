/*
Computer类
类的组合
*/

#include <iostream>

using namespace std;

enum CPU_Rank { P1 = 1, P2, P3, P4, P5, P6, P7 };

class CPU {
private:
  CPU_Rank rank;
  int frequency;
  float voltage;

public:
  CPU(CPU_Rank r, int f, float v) {
    rank = r;
    frequency = f;
    voltage = v;
    cout << "构造类一个CPU！" << endl;
  }
  ~CPU() { cout << "析构了一个CPU！" << endl; }
  CPU_Rank getRank() const { return rank; }
  int getFrequency() const { return frequency; }
  float getVoltage() const { return voltage; }

  void setRank(CPU_Rank r) { rank = r; }
  void setFrequency(int f) { frequency = f; }
  void setVoltage(float v) { voltage = v; }

  void Run() { cout << "CPU开始运行！" << endl; }
  void Stop() { cout << "CPU停止运行！" << endl; }
};

enum RAM_Type { DDR2 = 2, DDR3, DDR4 };

class RAM {
private:
  RAM_Type type;
  unsigned int frequency; // MHz
  unsigned int size;      // GB

public:
  RAM(RAM_Type t, int f, int s) {
    type = t;
    frequency = f;
    size = s;
    cout << "构造了一个RAM！" << endl;
  }
  ~RAM() { cout << "析构类一个RAM！" << endl; }

  RAM_Type getType() const { return type; }
  unsigned int getFrequency() const { return frequency; }
  unsigned int getSize() const { return size; }

  void setType(RAM_Type t) { type = t; }
  void setFrequency(unsigned int f) { frequency = f; }
  void setSize(unsigned int s) { size = s; }

  void Run() { cout << "RAM开始运行！" << endl; }
  void Stop() { cout << "RAM停止运行！" << endl; }
};

enum CDROM_Interface { SATA, USB };
enum CDROM_Install_type { external, built_in };

class CD_ROM {
private:
  CDROM_Interface interface_type;
  unsigned int cache_size; // MB
  CDROM_Install_type install_type;

public:
  CD_ROM(CDROM_Interface i, unsigned int s, CDROM_Install_type it) {
    interface_type = i;
    cache_size = s;
    install_type = it;
    cout << "构造了一个CDROM!" << endl;
  }

  ~CD_ROM() { cout << "析构了一个CDROM!" << endl; }

  CDROM_Interface getInterfaceType() const { return interface_type; }
  unsigned int getSize() const { return cache_size; }
  CDROM_Install_type getInstallType() const { return install_type; }

  void setInterfaceType(CDROM_Interface i) { interface_type = i; }
  void setSize(unsigned int s) { cache_size = s; }
  void setInstallType(CDROM_Install_type it) { install_type = it; }

  void Run() { cout << "CD_ROM开始运行！" << endl; }
  void Stop() { cout << "CD_ROM停止运行！" << endl; }

};
class COMPUTER {
private:
  CPU my_cpu;
  RAM my_ram;
  CD_ROM my_cdrom;
  unsigned int storage_size; // GB
  unsigned int bandwidth;    // MB
  //unsigned int bandwidth;
  

public:
  COMPUTER(CPU c, RAM r, CD_ROM cd, unsigned int s, unsigned int b);

  ~COMPUTER() { cout << "析构了一个COMPYUTER！" << endl; }

  void Run() {
    my_cpu.Run();
    my_ram.Run();
    my_cdrom.Run();
    cout << "COMPUTER开始运行！" << endl;
  }

  void Stop() {
    my_cpu.Stop();
    my_ram.Stop();
    my_cdrom.Stop();
    cout << "COMPUTER停止运行！" << endl;
  }
};

COMPUTER::COMPUTER(CPU c, RAM r, CD_ROM cd, unsigned int s, unsigned int b)
    : my_cpu(c), my_ram(r), my_cdrom(cd) {
  storage_size = s;
  bandwidth = b;

  cout << "构造了一个COMPUTER！" << endl;
}
int main() {
  CPU a(P6, 300, 2.8);
  a.Run();
  a.Stop();
  a.Run();
  a.Stop();
  cout << "*****************" << endl;
  RAM b(DDR3, 1600, 8);
  b.Run();
  b.Stop();
  cout << "*****************" << endl;
  CD_ROM c(SATA, 2, built_in);
  c.Run();
  c.Stop();
  cout << "*****************" << endl;
  COMPUTER my_computer(a, b, c, 128, 10);
  cout << "*****************" << endl;
  my_computer.Run();
  my_computer.Stop();
  a.Stop();
   
  return 0;
}
