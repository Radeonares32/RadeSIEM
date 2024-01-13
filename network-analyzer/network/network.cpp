#include "network.h"
#include <cstddef>
#include <nlohmann/json_fwd.hpp>
#include <pcapplusplus/Packet.h>
#include <pcapplusplus/PcapDevice.h>
#include <pcapplusplus/PcapLiveDevice.h>
#include <pcapplusplus/PcapLiveDeviceList.h>
#include <pcapplusplus/PcapFileDevice.h>
#include <pcapplusplus/RawPacket.h>
#include <pcapplusplus/SystemUtils.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

json data = {};

struct NetworkAnalyzer::PacketInfo {
  std::string packetLength;
  std::string arrivalTime;
  std::string ethernetSrc;
  std::string ethernetDst;
  std::string ipv4Src;
  std::string ipv4Dst;
  std::string tFlags;
  std::string tSrcPort;
  std::string tDstPort;
};


std::vector<std::string> splitString(const std::string& input, char delimiter) {
    std::vector<std::string> result;

    size_t start = 0, end = input.find(delimiter);

    while (end != std::string::npos) {
        std::string token = input.substr(start, end - start);

        size_t firstNonSpace = token.find_first_not_of(" \t\n\v\f\r");
        size_t lastNonSpace = token.find_last_not_of(" \t\n\v\f\r");

        if (firstNonSpace != std::string::npos && lastNonSpace != std::string::npos) {
            size_t prefixPos = token.find("Dst:");
            if (prefixPos != std::string::npos) {
                token.erase(prefixPos, 4);            }

            size_t firstNonSpace = token.find_first_not_of(" \t\n\v\f\r");
            size_t lastNonSpace = token.find_last_not_of(" \t\n\v\f\r");

            result.push_back(token.substr(firstNonSpace, lastNonSpace - firstNonSpace + 1));
        }

        start = end + 1;
        end = input.find(delimiter, start);
    }

    std::string lastToken = input.substr(start);

    size_t firstNonSpace = lastToken.find_first_not_of(" \t\n\v\f\r");
    size_t lastNonSpace = lastToken.find_last_not_of(" \t\n\v\f\r");

    if (firstNonSpace != std::string::npos && lastNonSpace != std::string::npos) {
        size_t prefixPos = lastToken.find("Dst:");
        if (prefixPos != std::string::npos) {
            lastToken.erase(prefixPos, 4); 
        }

        size_t firstNonSpace = lastToken.find_first_not_of(" \t\n\v\f\r");
        size_t lastNonSpace = lastToken.find_last_not_of(" \t\n\v\f\r");

        result.push_back(lastToken.substr(firstNonSpace, lastNonSpace - firstNonSpace + 1));
    }

    return result;
}


struct NetworkAnalyzer::PacketStats {
    int ethPacketCount;
    int ipv4PacketCount;
    int ipv6PacketCount;
    int tcpPacketCount;
    int udpPacketCount;
    int dnsPacketCount;
    int httpPacketCount;
    int sslPacketCount;
    

    void clear() { ethPacketCount = 0; ipv4PacketCount = 0; ipv6PacketCount = 0; tcpPacketCount = 0; udpPacketCount = 0; tcpPacketCount = 0; dnsPacketCount = 0; httpPacketCount = 0; sslPacketCount = 0; }

    PacketStats() { clear(); }

    void consumePacket(pcpp::Packet& packet)
      {

        pcpp::Packet parsedPacket(packet);
 
        std::istringstream iss(parsedPacket.toString());
  
        NetworkAnalyzer::PacketInfo info;

        std::string line;

        while(std::getline(iss,line)) {
          std::istringstream lineStream(line);

          std::string key, value;

          std::getline(lineStream,key, ':');
          std::getline(lineStream, value); 
         
          std::cout<<key<<std::endl;
          
          if(key.find("Packet length") != std::string::npos) {
              std::cout<<"Here1"<<std::endl;
              std::cout<<value<<std::endl;
          }
          else if(key.find("Arrival time") != std::string::npos) {
            std::cout<<"here1"<<std::endl; 
            std::cout<<value<<std::endl;
          }
          else if(key.find("Ethernet II Layer") != std::string::npos) {
            std::vector<std::string> splitData = splitString(value,',');
            data["srcMac"] = splitData[0];
            data["destMac"] = splitData[1];
            
            
          }

        }

        if (packet.isPacketOfType(pcpp::Ethernet))
            ethPacketCount++;
        if (packet.isPacketOfType(pcpp::IPv4))
            ipv4PacketCount++;
        if (packet.isPacketOfType(pcpp::IPv6))
            ipv6PacketCount++;
        if (packet.isPacketOfType(pcpp::TCP))
            tcpPacketCount++;
        if (packet.isPacketOfType(pcpp::UDP))
            udpPacketCount++;
        if (packet.isPacketOfType(pcpp::DNS))
            dnsPacketCount++;
        if (packet.isPacketOfType(pcpp::HTTP))
            httpPacketCount++;
        if (packet.isPacketOfType(pcpp::SSL))
            sslPacketCount++;
 
 }  
};

pcpp::PcapLiveDevice* NetworkAnalyzer::server(std::string interface) {
  pcpp::PcapLiveDevice* dev = pcpp::PcapLiveDeviceList::getInstance().getPcapLiveDeviceByIpOrName(interface);
  if (dev == nullptr) {
   std::cerr<<"Cannot find interface card " << interface<< " " <<std::endl;
  }
  return  dev;
}
bool NetworkAnalyzer::PacketHandler(pcpp::RawPacket* rawPacket,pcpp::PcapLiveDevice* dev,void* cookie) {
  NetworkAnalyzer::PacketStats* stats = (PacketStats*)cookie;

  pcpp::Packet parsedPacket(rawPacket);

  stats->consumePacket(parsedPacket);

 
  //std::cout<<parsedPacket.toString()<<std::endl;
  //std::cout<<data.dump(4)<<std::endl;
  return false;
}

void NetworkAnalyzer::openServer(std::string interfaceDevice) {
 PacketStats stats;

 pcpp::PcapLiveDevice* pcapDevice = server(interfaceDevice);
 pcapDevice->open();

 pcapDevice->startCaptureBlockingMode(PacketHandler,&stats,-1);

 pcpp::multiPlatformSleep(10);
 
 pcapDevice->close();
 
}
