/**  SsipPacket_o.java  *******************************************************

            Spread-Spectrum-IP

            A satirical internet protocol attempting to stymie packet sniffers.


            Packet Object




                           Copyright 2019  Daniel Huffman  All rights reserved.

*******************************************************************************/

public class SsipPacket_o  {

    private String      name;
    private Integer     sequence;
    private Integer     dataLength;
    private String      rawData;


    public SsipPacket_o()  {
        sequence = 0;
        dataLength = 0;
        rawData = new String("\n");
    }

    public void setName(String n)  {
        name = n;
    }

    public void setSequence(Integer seq)  {
        sequence = seq;
    }

    public void setDataLength(Integer lng)  {
        dataLength = lng;
    }

    public void setRawData(String raw)  {
        dataLength = raw.length();
        rawData = raw;
    }

    public String RawData()  {
        return  rawData;
    }

    public Integer Sequence()  {
        return  sequence;
    }

    public String Serialize()  {
        StringBuilder out = new StringBuilder("ssip_packet_o:\n");

        out.append("name=").append(name).append('\n');
        out.append("sequence=").append(sequence.toString()).append('\n');
        out.append("dataLength=").append(dataLength.toString()).append('\n');
        out.append("rawData=").append(rawData).append('\n');
        out.append('\n');

        return  out.toString();
    }

    public void Deserialize(String in)  {
        String[] s = in.split("\n");

        name = s[1].split("=")[1].toString();
        sequence =  Integer.parseInt(s[2].split("=")[1]);
        dataLength =  Integer.parseInt(s[3].split("=")[1]);

        rawData = s[4].substring(s[4].lastIndexOf("=") + 1, s[4].length());
    }


}



