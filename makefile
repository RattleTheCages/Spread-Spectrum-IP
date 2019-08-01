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

SSIP_HEADERS= ssip-packet_o.h ssip-packetizer_o.h
SSIP_OBJS   = ssip-packet_o.o ssip-packetizer_o.o


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

ssip-packet_o.o: ssip-packet_o.h ssip-packet_o.cc
	$(CC) $(OBJFLAGS) -c ssip-packet_o.cc

ssip-packetizer_o.o: ssip-packetizer_o.h ssip-packetizer_o.cc
	$(CC) $(OBJFLAGS) -c ssip-packetizer_o.cc

ssips_o.o: ssips_o.h ssips_o.cc $(SSIP_HEADERS)
	$(CC) $(OBJFLAGS) -c ssips_o.cc

ssipc_o.o: ssipc_o.h ssipc_o.cc $(SSIP_HEADERS)
	$(CC) $(OBJFLAGS) -c ssipc_o.cc

ssipc: ssipc_o.o $(SSIP_OBJS)
	$(CC) $(LINKFLAGS) -o ssipc ssipc_o.o                                  \
        $(SSIP_OBJS)                                                           \
        $(SSERVER_DIR)sserver_o.a                                              \
        $(PLIB_DIR)plib_o.a


ssips: ssips_o.o $(SSIP_OBJS)
	$(CC) $(LINKFLAGS) -o ssips ssips_o.o                                  \
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
