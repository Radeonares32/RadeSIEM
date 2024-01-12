#ifndef RADE_NETWORK_H
#define RADE_NETWORK_H

#include <pcapplusplus/PcapLiveDevice.h>
#include <pcapplusplus/PcapLiveDeviceList.h>
#include <pcapplusplus/SystemUtils.h>
#include <iostream>


pcpp::PcapLiveDevice* server(std::string interface);

#endif
