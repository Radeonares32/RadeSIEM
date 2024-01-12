#include "header/network.h"
#include <iostream>
#include <pcapplusplus/PcapLiveDevice.h>
#include <pcapplusplus/PcapLiveDeviceList.h>
#include <pcapplusplus/SystemUtils.h>
#include <iostream>


int main() {
 pcpp::PcapLiveDevice* srv = server("192.168.1.102"); 

 std::cout<< srv->getName() << std::endl;

 return 0; 
}
