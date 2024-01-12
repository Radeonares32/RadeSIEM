#include "header/network.h"
#include <iostream>
#include <pcapplusplus/PcapLiveDevice.h>
#include <pcapplusplus/PcapLiveDeviceList.h>
#include <pcapplusplus/SystemUtils.h>
#include <iostream>


int main() {
 NetworkAnalyzer network;
 auto dev = network.server("192.168.1.102");

 std::cout<< dev->getDefaultGateway() << std::endl;
  
 return 0; 
}
