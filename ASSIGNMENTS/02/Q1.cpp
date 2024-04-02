#include<iostream>
#include<string>
using namespace std;

class SecurityTool{
private:
  string securityLevel;
  int cost, noOfDevices;
public:
  SecurityTool(string securityLevel, int cost, int noOfDevices) : securityLevel(securityLevel), cost(cost), noOfDevices(noOfDevices) {
    if(cost <= 0){
      cout << "Cost cannot be 0 or less than 0." << endl;
      exit(0);
    }
    if(securityLevel != "HIGH" && securityLevel != "MEDIUM" && securityLevel != "LOW"){
      cout << "Security level can only be High, Medium or Low." << endl;
      exit(0);
    }
  }

  string getSecurityLevel() { return securityLevel; }

  void print(){
    cout << "Firewall Tool Details: ";
    cout << "Security Level: " << securityLevel << endl;
    cout << "Cost: $" << cost << endl;
    cout << "Number of Devices: " << noOfDevices << endl;
}

  virtual void performScan(){
    cout << "Scanning for Viruses and Threats...\n" << "Your Security Level is: " << securityLevel << endl; 
  }
};


class FirewallTool : public SecurityTool{
private:
  int ports[23];
  string protocols[6];

  void generateList() {
    int startPort = 3; // Student ID: 23K-0073
    for (int i = 0; i < 23; ++i) {
        ports[i] = startPort + i;
    }
}

void generateProtocolList() {
    protocols[0] = "HTTPS";
    protocols[1] = "FTP";
    protocols[2] = "UDP";
    protocols[3] = "ICMP";
    protocols[4] = "SSH";
    protocols[5] = "SNMP";
}

public:
  FirewallTool(string securityLevel, int cost) : SecurityTool(securityLevel, cost, 10){
    generateList();
    generateProtocolList();
    }

void performScan() 
{
    cout << "\nPerforming SCAN FOR " << getSecurityLevel() << endl;
    int i;
    if (getSecurityLevel() == "HIGH") 
    {
        cout << "Allowed Protocols: " << endl;
        for (string protocol : protocols) 
            cout << protocol << endl;
        
        cout << "Allowed Ports: " << endl;
        for (int port : ports) 
            cout << port << endl;
    } 
    else if (getSecurityLevel() == "MEDIUM") 
    {
        cout << "Allowed Protocols: " << endl;
        for (string protocol : protocols) 
            cout << protocol << endl;
        
        cout << "Allowed Ports: " << endl;
        for (int port : ports) 
        {
            cout << port << endl;
            i = port;
        }
        cout << i + 1 << endl;
        cout << i + 2 << endl;
    } 
    else if (getSecurityLevel() == "LOW") 
    {
        cout << "Allowed Protocols: " << endl;
        for (string protocol : protocols) 
            cout << protocol << endl;
        
        cout << "TCP" << endl;
        cout << "DNS" << endl;
        cout << "\nAllowed Ports: " << endl;
        for (int port : ports) 
        {
            cout << port << endl;
            i = port;
        }
        cout << i + 1 << endl;
        cout << i + 2 << endl;
        cout << i + 3 << endl;
        cout << i + 4 << endl;
        cout << i + 5 << endl;
    }
}
};

int main(){
  cout << ("Rayyan Merchant\n23K-0073\n\n");
  FirewallTool firewall1("MEDIUM", 100);
  FirewallTool firewall2("HIGH", 200);
  FirewallTool firewall3("LOW", 50);
  firewall1.print();
  firewall2.print();
  firewall3.print();
  firewall1.performScan();
  firewall2.performScan();
  firewall3.performScan();
  return 0;
}


