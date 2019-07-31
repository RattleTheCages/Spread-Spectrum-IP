/**  ssipc.h  ******************************************************************

            Spread-Spectrum-IP


            Client


                                                  Copyright Daniel Huffman 2019

*******************************************************************************/

#ifndef SSIPClientOBJECT_API
#define SSIPClientOBJECT_API


#include "string.h"
#include "thread.h"
#include "client.h"
#include "queue.h"
#include "ssip-packet.h"


class ssipc_o : public client_o, private thread_o  {
  protected:
    int                     State;
    string_o                Host;
    queue_o<ssip_packet_o>  Rqp;

  public:
    ssipc_o();                                      // Default constructor.
    ssipc_o(const ssipc_o&);                        // Copy constructor.
    virtual   ~ssipc_o();                           // Default destructor.
    ssipc_o&   operator = (const ssipc_o&);         // Assignment operator.

    int        state() const;

    int        connect(const string_o&);
    void       send(const string_o&);
    int        receive(string_o&);
};


/******************************************************************************/

inline int ssipc_o::state() const  {
    return  State;
}


#endif

/******************************************************************************/
