/**  ssips_o.cc  ***************************************************************

            Spread-Spectrum-IP

            A satirical internet protocol attempting to stymie packet sniffers.


            Server
x




                           Copyright 2019  Daniel Huffman  All rights reserved.

*******************************************************************************/

#include "ssips_o.h"
#include "ssip-packet_o.h"

log_o       log;
sysinfo_o   sysinfo;
carapace_o  carapace;


ssips_o::ssips_o() : State(2) {}

ssips_o::~ssips_o()  {}


int carapace_o::process(input_o& input, output_o& output)  {
    string_o      out;
    string_o      ls;
    ssip_packet_o ssipp;


    ssipp.Deserialize(input.message());


    ssipp.setName("The mark of ssips_o.");
    ssipp.Serialize(out);
    output.setMessage(out.string());

    ls << "ssips_o::carapace_o::process( socket(" << input.socket() << "), sequence(";
    ls << ssipp.Sequence() << ") ) finished.";
    log << ls;

    return  0;
}



int main(int argc, char* argv[])  {
    int     r = 0;
    ssips_o ssips;


        // In the future use random ports...  (And properly check error.)
    r += ssips.serveport(2191);
    r += ssips.serveport(2192);
    r += ssips.serveport(2193);
    r += ssips.serveport(2194);
    r += ssips.serveport(2195);             // S
    r += ssips.serveport(2196);             //  p
    r += ssips.serveport(2197);             //   r
    r += ssips.serveport(2198);             //    e
    r += ssips.serveport(2199);             //     a
    r += ssips.serveport(2200);             //      d

    r += ssips.serveport(2201);
    r += ssips.serveport(2202);             // S
    r += ssips.serveport(2203);             //  p
    r += ssips.serveport(2204);             //   e
    r += ssips.serveport(2205);             //    c
    r += ssips.serveport(2206);             //     t
    r += ssips.serveport(2207);             //      r
    r += ssips.serveport(2208);             //       u
    r += ssips.serveport(2209);             //        m
    r += ssips.serveport(2210);
    r += ssips.serveport(2211);
    r += ssips.serveport(2212);             // I
    r += ssips.serveport(2213);             //  P
    r += ssips.serveport(2214);
    r += ssips.serveport(2215);
    r += ssips.serveport(2216);
    r += ssips.serveport(2217);
    r += ssips.serveport(2218);
    r += ssips.serveport(2219);
    r += ssips.serveport(2220);
    r += ssips.serveport(2221);
    r += ssips.serveport(2222);
    if(r)  return  r;


    ssips.persist();

    return 2;
}

/******************************************************************************/
