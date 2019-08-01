/**  ssips_o.h  ****************************************************************

            Spread-Spectrum-IP


            Server



                                                  Copyright Daniel Huffman 2019

*******************************************************************************/

#ifndef SSIPServerOBJECT_API
#define SSIPServerOBJECT_API

#include "pserver_o.h"

class ssips_o : public pserver_o  {
  protected:
    int        State;

  public:
    ssips_o();
    ssips_o(const ssips_o&);
    virtual   ~ssips_o();
    ssips_o&   operator = (const ssips_o&);

    int        state() const;
};


/******************************************************************************/

inline int ssips_o::state() const  {
    return  State;
}



#endif

/******************************************************************************/
