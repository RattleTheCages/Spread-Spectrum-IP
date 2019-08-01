################################################################################
################################################################################
##                                                                            ##
##    Spread-Spectrum-IP                                                      ##
##                                                                            ##
##    A satircal internet protocol attempting to styme packet sniffers.       ##
##                                                                            ##
##                                                                            ##
##                                                                            ##
##    Please note.  The header file dependences are not complete in this      ##
##    makefile.  If any changes are made to header files, please `make clean' ##
##    before executing `make all'.                                            ##
##                                                                            ##
################################################################################
################################################################################


CC          = g++

SSERVER_DIR = ../Code-from-the-90s/projects/library/sserver/
PSERVER_DIR = ../Code-from-the-90s/projects/library/pserver/
PLIB_DIR    = ../Code-from-the-90s/projects/library/lib/

OBJFLAGS    = -g -I$(PLIB_DIR)/thread -I$(PLIB_DIR)/string -I$(PLIB_DIR)/log -I$(PLIB_DIR)/error -I$(PLIB_DIR)/memory -I$(PLIB_DIR)/other -I$(PLIB_DIR)/cron -I$(PSERVER_DIR) -I$(SSERVER_DIR)/telenet -I$(SSERVER_DIR)/dataObjects -I$(PSERVER_DIR)/directors -I$(PSERVER_DIR)/gate -I$(PSERVER_DIR)/carapace
LINKFLAGS   = -pthread -L$(PLIB_DIR)



EXECS       = ssips ssipc

SSIP_HEADERS= ssip-packet.h ssip-packetizer.h
SSIP_OBJS   = ssip-packet.o ssip-packetizer.o


################################################################################
## All.                                                                       ##
################################################################################

all:
	@echo "Spread Spectrum IP  v1.000     07.31.2019  Daniel Huffman"
	@echo `date`
	make $(SSIP_OBJS)
	make $(EXECS)
	@echo `date`


################################################################################
##                                                                            ##
################################################################################

ssip-packet.o: ssip-packet.h ssip-packet.cc
	$(CC) $(OBJFLAGS) -c ssip-packet.cc

ssip-packetizer.o: ssip-packetizer.h ssip-packetizer.cc
	$(CC) $(OBJFLAGS) -c ssip-packetizer.cc

ssips.o: ssips.h ssips.cc $(SSIP_HEADERS)
	$(CC) $(OBJFLAGS) -c ssips.cc

ssipc.o: ssipc.h ssipc.cc $(SSIP_HEADERS)
	$(CC) $(OBJFLAGS) -c ssipc.cc

ssipc: ssipc.o $(SSIP_OBJS)
	$(CC) $(LINKFLAGS) -o ssipc ssipc.o                                    \
        $(SSIP_OBJS)                                                           \
        $(SSERVER_DIR)sserver_o.a                                              \
        $(PLIB_DIR)plib_o.a


ssips: ssips.o $(SSIP_OBJS)
	$(CC) $(LINKFLAGS) -o ssips ssips.o                                    \
        $(SSIP_OBJS)                                                           \
        $(PSERVER_DIR)pserver_o.a                                              \
        $(SSERVER_DIR)sserver_o.a                                              \
        $(PLIB_DIR)plib_o.a



################################################################################
## Clean.                                                                     ##
################################################################################
clean:
	rm -f *.o $(EXECS)


################################################################################
################################################################################
