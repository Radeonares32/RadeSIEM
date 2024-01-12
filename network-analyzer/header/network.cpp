#include "network.h"
#include <pcapplusplus/PcapLiveDevice.h>
#include <pcapplusplus/PcapLiveDeviceList.h>
#include <pcapplusplus/SystemUtils.h>
#include <iostream>

pcpp::PcapLiveDevice* server(std::string interface) {
 pcpp::PcapLiveDevice* dev = pcpp::PcapLiveDeviceList::getInstance().getPcapLiveDeviceByIp(interface);
 if (dev == NULL) {
   std::cerr<<"Cannot find interface with IPv4 address of " << interface<< " " <<std::endl;
 }
 return  dev;
}
