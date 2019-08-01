/**  ssip-packet_o.h  **********************************************************

            Spread-Spectrum-IP


            Packet Object



                                                  Copyright Daniel Huffman 2019

*******************************************************************************/

#ifndef SSIPPacketOBJECT_API
#define SSIPPacketOBJECT_API


#include "string_o.h"


class ssip_packet_o  {
  protected:
    string_o            name;
    int                 sequence;
    int                 dataLength;
    char                rawData[2048];

  public:
    ssip_packet_o();
    ssip_packet_o(const ssip_packet_o&);
    virtual         ~ssip_packet_o();
    ssip_packet_o&   operator = (const ssip_packet_o&);

    const char*      RawData() const;
    const char*      Name() const;
    int              Sequence() const;
    int              DataLength() const;

    void             setSequence(const int);
    void             setDataLength(const int);
    void             setName(const string_o);
    void             setRawData(const char*, const int);

    void             Serialize(string_o&);
    void             Deserialize(string_o&);

};


/******************************************************************************/

inline const char* ssip_packet_o::RawData() const  {
    return  rawData;
}

inline const char* ssip_packet_o::Name() const  {
    return  name.string();
}

inline int ssip_packet_o::Sequence() const  {
    return  sequence;
}

inline int ssip_packet_o::DataLength() const  {
    return  dataLength;
}

inline void ssip_packet_o::setSequence(const int seq)  {
    sequence = seq;
}

inline void ssip_packet_o::setDataLength(const int dl)  {
    dataLength = dl;
}

inline void ssip_packet_o::setName(const string_o n)  {
    name = n;
}


#endif

/******************************************************************************/
