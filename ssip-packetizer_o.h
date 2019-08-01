/**  ssip-packetizer_o.h  ******************************************************

            Spread-Spectrum-IP


            Packetizer Object



                                                  Copyright Daniel Huffman 2019

*******************************************************************************/


#ifndef SSIPPacketizerOBJECT_API
#define SSIPPacketizerOBJECT_API

#include "string_o.h"
#include "queue_o.h"
#include "ssip-packet_o.h"


class ssip_packetizer_o  {
  protected:
    string_o            name;
    int                 sequence;
    char                rawData[2048];

  public:
    ssip_packetizer_o();
    ssip_packetizer_o(const ssip_packetizer_o&);
    virtual             ~ssip_packetizer_o();
    ssip_packetizer_o&   operator = (const ssip_packetizer_o&);


    static  void  packetize(const string_o&, queue_o<ssip_packet_o>&);
};


/******************************************************************************/



#endif

/******************************************************************************/