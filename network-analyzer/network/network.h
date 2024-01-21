#pragma once

#include <nlohmann/json_fwd.hpp>
#include <pcapplusplus/PcapDevice.h>
#include <pcapplusplus/PcapLiveDevice.h>
#include <pcapplusplus/PcapLiveDeviceList.h>
#include <pcapplusplus/RawPacket.h>
#include <pcapplusplus/PcapFileDevice.h>
#include <pcapplusplus/SystemUtils.h>
#include <pcapplusplus/HttpLayer.h>
#include <iostream>
#include <string>
#include <sstream>


class NetworkAnalyzer {
  public:
    struct PacketStats;
    pcpp::PcapLiveDevice* server(std::string interface);
    static bool PacketHandler(pcpp::RawPacket* packet,pcpp::PcapLiveDevice* dev, void* cookie);
    void openServer(std::string interfaceDevice);
    static nlohmann::json Data();
};
