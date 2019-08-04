/**  ssip-packetizer_o.cc  *****************************************************

            Spread-Spectrum-IP

            A satircal internet protocol attempting to styme packet sniffers.



            Packetizer Object





                           Copyright 2019  Daniel Huffman  All rights reserved.

*******************************************************************************/


#include "rand_o"
#include "bstree_o"
#include "log_o"

#include "ssip-packetizer_o.h"

extern log_o log;

ssip_packetizer_o::ssip_packetizer_o():State(2)  {}

ssip_packetizer_o::~ssip_packetizer_o()  {}

void ssip_packetizer_o::packetize(const string_o& message, list_o<ssip_packet_o>& listOfPackets)  {

    rand_o          rand;
    ssip_packet_o*  ssip3;
    string_o        msg;
    string_o        msc;
    int             seq = 0;
    int             cut = 0;

    msg = message;

    while(msg.length() > 0)  {

        cut = rand.i(22) + 22;      // Cut the message into random sized pieces.

        ssip3 = new ssip_packet_o();
        ssip3->setSequence(seq++);
        msc = msg;
        msc.cut(msg.length() < cut ? msg.length() : cut);
        ssip3->setRawData(msc.string(), msc.length());
        listOfPackets.put(ssip3);

        msg.upcut(msg.length() < cut ? msg.length() : cut);

    }
}


void ssip_packetizer_o::reorder(list_o<ssip_packet_o>& lop)  {
    bstree_o<ssip_packet_o> pbst;
    ssip_packet_o*          ssip3;

    while(ssip3 = lop++)  pbst.insert(ssip3->Sequence(), ssip3);

    bstreeSearch_o<ssip_packet_o> ts(&pbst);
    ssip3 = ts.sortedList();
    lop.put(new ssip_packet_o(*ssip3));
    while(ssip3 = ts++)  lop.put(new ssip_packet_o(*ssip3));
}


void ssip_packetizer_o::disorder(list_o<ssip_packet_o>& lop)  {
    ssip_packet_o*          ssip3;
    rand_o                  rand;
    int                     monte;
    list_o<ssip_packet_o>   carlo;

    while(lop.cardinality() > 0)  {

        monte = rand.i(22);
        while(monte-- > 0)  {
            ssip3 = lop.get();     // Spin the Wheel Of Fortune!
            lop.put(ssip3);
        }

        ssip3 = lop.get();
        carlo.put(ssip3);
    }

    while(carlo.cardinality() > 0)  {
        ssip3 = carlo.get();
        lop.put(ssip3);
    }

}




/******************************************************************************/
