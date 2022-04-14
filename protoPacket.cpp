
#include <string>

class Packet {
public:
  int dest;
  int src;
  int port;
  bool malign;
  float evade;
  bool tcp;
  bool ip;
  bool cdp;
  std::string flags;

  Packet(int d, int s, int p, bool m, float e){
    dest = d;
    src = s;
    port = p;
    malign = m;
    evade = e;
  }
  Packet(int d, int s, int p, bool m, float e,
         bool t, bool i, bool c, std::string f){
    dest = d;
    src = s;
    port = p;
    malign = m;
    evade = e;
    tcp = t;
    ip = i;
    cdp = c;
    flags = f;
  }
};
