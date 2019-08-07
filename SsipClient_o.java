/**  SsipClient_o.java  *******************************************************

            Spread-Spectrum-IP

            A satirical internet protocol attempting to stymie packet sniffers.


            Client



                           Copyright 2019  Daniel Huffman  All rights reserved.

*******************************************************************************/

import java.util.*;
import java.net.*;
import java.io.*;


public class SsipClient_o  {

    private Socket              socket;
    private OutputStream        output;
    private PrintWriter         writer;
    private InputStream         input;
    private InputStreamReader   reader;
    private Random              random;
    private List<SsipPacket_o>  receivedPackets;



    public SsipClient_o()  {
        random = new Random();
        receivedPackets = new LinkedList<>();
    }

    public List<SsipPacket_o> Packitize(String message)  {
        List<SsipPacket_o> lop = new LinkedList<>();
        Integer pick;
        Integer sleve = 0;
        Integer sequence = 0;
        SsipPacket_o ssipp;

        while(sleve < message.length())  {
            pick = random.nextInt(22) + 22;         // Cut the message into random sized pieces.
            if(pick+sleve >= message.length()) pick = message.length() - sleve;

            ssipp = new SsipPacket_o();

            ssipp.setName("SsipPacket_o");
            ssipp.setSequence(sequence++);
            ssipp.setRawData(message.substring(sleve, pick+sleve));
            ssipp.setDataLength(ssipp.RawData().length());
            lop.add(ssipp);

            sleve += pick;
        }

        return  lop;
    }

    public Integer SendMessage(String message)  {
        LinkedList<SsipPacket_o> lop = new LinkedList<>(Packitize(message));

        while(lop.size() > 0)  {
            SsipPacket_o ssipp = lop.pop();

            try  {
                Integer port = random.nextInt(32) + 2191;   // Pick a random port!
                socket = new Socket("localhost", port);
                output = socket.getOutputStream();
                writer = new PrintWriter(output, true);
                input = socket.getInputStream();
                reader = new InputStreamReader(input);

                writer.println(ssipp.Serialize());

                int ch;
                StringBuilder data = new StringBuilder();
              //while(!reader.ready());
                while((ch = reader.read()) != -1)  {
                    data.append((char)ch);
                }
                socket.close();

                ssipp = new SsipPacket_o();
                ssipp.Deserialize(data.toString());

                receivedPackets.add(ssipp);

                System.out.println("ssips: " + ssipp.Serialize() + "\n\n");

            }  catch(UnknownHostException uhex)  {
                System.out.printf("Hostname: " + uhex.getMessage());
            }  catch(IOException ioex)  {
                System.out.println("I/O error: " + ioex.getMessage());

                lop.add(ssipp);
            }
        }

        return  2;
    }

    public String ReceiveMessage()  {
        StringBuilder message = new StringBuilder();

        for(SsipPacket_o ssipp : receivedPackets)  {

            message.append(ssipp.RawData());

            System.out.println(ssipp.Sequence() + "  " + ssipp.RawData());

        }
        return  message.toString();
    }


    public static void main(String args[])  {
        System.out.println("SsipClient_o");

        SsipClient_o SsipClient = new SsipClient_o();

        String loveYou =
"How do I love thee? Let me count the ways. " +
"." +
"I love thee to the depth and breadth and height " +
"My soul can reach, when feeling out of sight " +
"For the ends of Being and ideal Grace. " +
"." +
"I love thee to the level of every day's " +
"Most quiet need, by sun and candlelight. " +
"." +
"I love thee freely, as men strive for Right; " +
"I love thee purely, as they turn from Praise. " +
"." +
"I love with a passion put to use " +
"In my old griefs, and with my childhood's faith. " +
"." +
"I love thee with a love I seemed to lose " +
"With my lost saints, I love thee with the breath, " +
"Smiles, tears, of all my life! and, if God choose, " +
"I shall but love thee better after death. ";


        SsipClient.SendMessage(loveYou);


        String received = SsipClient.ReceiveMessage();

        System.out.println("Received:\n" + received);

    }
}


