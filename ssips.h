/**  ssips.h  ******************************************************************

            Spread-Spectrum-IP


            Server



                                                  Copyright Daniel Huffman 2019

*******************************************************************************/

#ifndef SSIPServerOBJECT_API
#define SSIPServerOBJECT_API

#include "pserver.h"

class ssips_o : public pserver_o  {
  protected:
    int        State;

  public:
    ssips_o();                                      // Default constructor.
    ssips_o(const ssips_o&);                        // Copy constructor.
    virtual   ~ssips_o();                           // Default destructor.
    ssips_o&   operator = (const ssips_o&);         // Assignment operator.

    int        state() const;
};


/******************************************************************************/

inline int ssips_o::state() const  {
    return  State;
}



#endif

/******************************************************************************/
