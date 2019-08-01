/**  ssips_o.cc  ***************************************************************

            Spread-Spectrum-IP


            Server
k



                                                  Copyright Daniel Huffman 2019

*******************************************************************************/

#include "ssips_o.h"
#include "ssip-packet_o.h"

log_o       log;
sysinfo_o   sysinfo;
carapace_o  carapace;

ssips_o::ssips_o()  {
    State = 2;
}

ssips_o::~ssips_o()  {}


int carapace_o::process(input_o& input, output_o& output)  {
    string_o      out;
    ssip_packet_o ssipp;


    ssipp.Deserialize(input.message());

    ssipp.Serialize(out);
    output.setMessage(out.string());

    log << "int ssips_o::carapace_o::process() finished.";

    return  0;
}



int main(int argc, char* argv[])  {
    int     r = 0;
    ssips_o ssips;

        // In the future use random ports...  (And properly check error.)
    r += ssips.serveport(2201);
    r += ssips.serveport(2202);
    r += ssips.serveport(2203);
    r += ssips.serveport(2204);
    r += ssips.serveport(2205);
    r += ssips.serveport(2206);
    r += ssips.serveport(2207);
    r += ssips.serveport(2208);
    r += ssips.serveport(2209);
    r += ssips.serveport(2210);
    r += ssips.serveport(2211);
    r += ssips.serveport(2212);
    r += ssips.serveport(2213);
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
