#include "network.h"
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

          std::getline(lineStream,key, ',');
          std::getline(lineStream, value); 
          
          if(key.find("Packet length") != std::string::npos) {
            info.packetLength = value;
          }
          else if(key.find("Arrival time") != std::string::npos) {
            info.arrivalTime = value;
          }
          else if(key.find("Ethernet II Layer") != std::string::npos) {
            std::cout<<"Ethernet falan filan "<<value<<std::endl;
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

  std::cout<<parsedPacket.toString()<<std::endl;
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

