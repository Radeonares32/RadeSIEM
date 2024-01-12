#pragma once

#include <pcapplusplus/PcapLiveDevice.h>
#include <pcapplusplus/PcapLiveDeviceList.h>
#include <pcapplusplus/RawPacket.h>
#include <pcapplusplus/SystemUtils.h>
#include <iostream>

class NetworkAnalyzer {
  public:
    pcpp::PcapLiveDevice* server(std::string interface);
    void onPacket(pcpp::RawPacket* packet,pcpp::PcapLiveDevice* dev, void* cookie);
};
