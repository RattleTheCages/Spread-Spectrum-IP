/**  ssipc_o.h  ****************************************************************

            Spread-Spectrum-IP

            A satirical internet protocol attempting to stymie packet sniffers.


            Client






                          Copyright  2019  Daniel Huffman  All rights reserved.

*******************************************************************************/

#ifndef SSIPClientOBJECT_API
#define SSIPClientOBJECT_API


#include "string_o"
#include "thread_o"
#include "client_o"
#include "list_o"

#include "ssip-packet_o.h"


class ssipc_o : public client_o, private thread_o  {
  protected:
    int                     State;
    string_o                Host;
    list_o<ssip_packet_o>   Rqp;

  public:
    ssipc_o();
    ssipc_o(const ssipc_o&);
    virtual   ~ssipc_o();
    ssipc_o&   operator = (const ssipc_o&);

    int        state() const;

    int        connect(const string_o&);
    void       send(const string_o&);
    long int   receive(string_o&);
};


/******************************************************************************/

inline int ssipc_o::state() const  {
    return  State;
}


#endif

/******************************************************************************/
