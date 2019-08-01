/**  ssip-packetizer.cc  *******************************************************

            Spread-Spectrum-IP


            Packetizer Object



                                                  Copyright Daniel Huffman 2019


*******************************************************************************/


#include <strings.h>
#include </usr/include/string.h>
#include "ssip-packetizer.h"
#include "rand_o.h"


ssip_packetizer_o::ssip_packetizer_o()  {}

ssip_packetizer_o::~ssip_packetizer_o()  {}

void ssip_packetizer_o::packetize(const string_o& message, queue_o<ssip_packet_o>& listOfPackets)  {

    rand_o    rand;
    ssip_packet_o* ssip3;
    string_o  msg;
    string_o  msc;
    int       seq = 0;
    int       cut = 0;

    msg = message;

    while(msg.length() > 0)  {
        seq++;

        cut = rand.i(22) + 22;

        ssip3 = new ssip_packet_o();
        ssip3->setSequence(seq);
        msc = msg;
        msc.cut(msg.length() < cut ? msg.length() : cut);
        ssip3->setRawData(msc.string(), msc.length());
        listOfPackets.put(ssip3);

        msg.upcut(msg.length() < cut ? msg.length() : cut);

    }

}



/******************************************************************************/
