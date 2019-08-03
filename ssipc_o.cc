/**  ssipc_o.cc  ***************************************************************


            Spread-Spectrum-IP

            A satircal internet protocol attempting to styme packet sniffers.


            Client



                           Copyright 2019  Daniel Huffman  All rights reserved.

*******************************************************************************/


#include "log_o" 
#include "rand_o"

#include "TheRaven_o.h"
#include "ssipc_o.h"
#include "ssip-packet_o.h"
#include "ssip-packetizer_o.h"


log_o   log;

ssipc_o::ssipc_o()  {
    State = 2;
}

ssipc_o::~ssipc_o()  {}

int ssipc_o::connect(const string_o& hostname)  {
    Host = hostname;

    return 0;
}

void ssipc_o::send(const string_o& message)  {
    list_o<ssip_packet_o> qp;
    ssip_packet_o*        ssip3;
    int         port;
    int         rc;
    string_o    ss;
    string_o    rs;
    string_o    ls;
    rand_o      rand;


    ssip_packetizer_o::packetize(message, qp);
    ssip_packetizer_o::disorder(qp);

    while(qp.cardinality() != 0)  {

        ssip3 = qp.get();
        port = rand.i(32)+2191;         // Pick a random port!

        ls = "";
        ls << "***************\n";
        ls << "p.Name(): " << ssip3->Name() << '\n';
        ls << "p.Sequence(): " << ssip3->Sequence() << '\n';
        ls << "p.RawData(): " << ssip3->RawData() << '\n';
        ls << "Connecting to host:" << Host << '\n';
        ls << "Sending on port: " << port << '\n';
        ls << "***************\n";
        log << ls;

        ss = "";
        ssip3->Serialize(ss);
        rc = client_o::connect(Host.string(), port);
        if(rc)  {
            log << "Connect error.";
            qp.put(ssip3);
            continue;
        }

        client_o::send(ss.string());

        yeild();

        rs = "";
        while(!rs.contains("\n\n"))  client_o::recv(rs);
        client_o::disconnect();
        ssip3->Deserialize(rs);
        Rqp.put(ssip3);

        yeild();
    }

}


int ssipc_o::receive(string_o& message)  {
    ssip_packet_o*  ssippp;
    int             dl = 0;

    ssip_packetizer_o::reorder(Rqp);
    

    while(Rqp.cardinality() != 0)  {
        ssippp = Rqp.get();
        message << ssippp->RawData();
        dl += ssippp->DataLength();
        message.cut(dl);
    }

    return  dl;
}


int main(int argc, char* argv[])  {
    string_o  rs;
    string_o  ls;
    string_o  host;
    ssipc_o   ssipc;
    string_o  theRaven = TheRaven;

    log << "ssipc start.";


    host = argv[1];
    if(host.length() < 2)  host = "localhost";

    ssipc.connect(host.string());

    ssipc.send(theRaven);

    ssipc.receive(rs);

    ssipc.disconnect();

    ls << "Received: " << rs.string() << '\n';
    log << ls;


    return 2;
}


/******************************************************************************/
