/**  ssip-packetizer.h  ********************************************************

            Spread-Spectrum-IP


            Packetizer Object



                                                  Copyright Daniel Huffman 2019

*******************************************************************************/


#ifndef SSIPPacketizerOBJECT_API
#define SSIPPacketizerOBJECT_API

#include "string.h"
#include "queue.h"
#include "ssip-packet.h"


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

    void  packetize(const string_o&, queue_o<ssip_packet_o>&);

};


/******************************************************************************/



#endif

/******************************************************************************/
