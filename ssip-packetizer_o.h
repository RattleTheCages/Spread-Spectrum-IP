/**  ssip-packetizer_o.h  ******************************************************

            Spread-Spectrum-IP

            A satirical internet protocol attempting to stymie packet sniffers.


            Packetizer Object





                           Copyright 2019  Daniel Huffman  All rights reserved.

*******************************************************************************/


#ifndef SSIPPacketizerOBJECT_API
#define SSIPPacketizerOBJECT_API

#include "string_o"
#include "list_o"

#include "ssip-packet_o.h"


class ssip_packetizer_o  {
  protected:
    int                 State;

  public:
    ssip_packetizer_o();
    ssip_packetizer_o(const ssip_packetizer_o&);
    virtual             ~ssip_packetizer_o();
    ssip_packetizer_o&   operator = (const ssip_packetizer_o&);


    static  void  packetize(const string_o&, list_o<ssip_packet_o>&);
    static  void  disorder(list_o<ssip_packet_o>&);
    static  void  reorder(list_o<ssip_packet_o>&);
};


/******************************************************************************/



#endif

/******************************************************************************/
