/**  ssip-packet_o.cc  ********************************************************

            Spread-Spectrum-IP

            A satircal internet protocol attempting to styme packet sniffers.


            Packet Object




                           Copyright 2019  Daniel Huffman  All rights reserved.

*******************************************************************************/


#include "succession_o"
#include "ssip-packet_o.h"


ssip_packet_o::ssip_packet_o()  {
    name = "ssip-packet_o";
    sequence = 0;
    dataLength = 0;
    succession_o::bzero(rawData, 2048);
}

ssip_packet_o::ssip_packet_o(const ssip_packet_o& sp)  {
    name = sp.name;
    sequence = sp.sequence;
    dataLength = sp.dataLength;
    succession_o::memcpy(rawData, sp.rawData, 2048);
}

ssip_packet_o::~ssip_packet_o()  {}

void ssip_packet_o::setRawData(const char* raw, const int dl)  {
    dataLength = dl;
    succession_o::memcpy(rawData, raw, dataLength);
    succession_o::bzero(rawData+dataLength, 2048-dataLength);
}

void ssip_packet_o::Serialize(string_o& sout)  {

    sout << "ssip_packet_o:\n";
    sout << "name=" << name.string() << '\n';
    sout << "sequence=" << sequence << '\n';
    sout << "dataLength=" << dataLength << '\n';
    sout << "rawData=" << rawData << '\n';
    sout << "\n";

}

void ssip_packet_o::Deserialize(string_o& sin)  {
    sin.upcut("ssip_packet_o:");
    sin.upcut("name=");
    name = sin;
    name.cut('\n');
    sin.upcut("sequence=");
    sequence = sin.stoi();
    sin.upcut("dataLength=");
    dataLength = sin.stoi();
    sin.upcut("rawData=");

    succession_o::memcpy(rawData, sin.string(), dataLength);
    succession_o::bzero(rawData+dataLength, 2048-dataLength);
}



/******************************************************************************/
