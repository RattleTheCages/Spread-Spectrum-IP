/**  ssip-packet_o.cc  ********************************************************

            Spread-Spectrum-IP


            Packet Object



                                                  Copyright Daniel Huffman 2019

*******************************************************************************/


#include "ssip-packet_o.h"

#include <strings.h> //bzero
#include </usr/include/string.h> //memcpy


ssip_packet_o::ssip_packet_o()  {
    name = "ssip-packet_o";
    sequence = 0;
    dataLength = 0;
    ::bzero(rawData, 2048);
}

ssip_packet_o::~ssip_packet_o()  {}

void ssip_packet_o::setRawData(const char* raw, const int dl)  {
    dataLength = dl;
    ::memcpy(rawData, raw, dataLength);
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

    ::bzero(rawData, 2048);
    ::memcpy(rawData, sin.string(), dataLength);
}



/******************************************************************************/
