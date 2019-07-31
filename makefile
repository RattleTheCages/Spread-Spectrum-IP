################################################################################
################################################################################
##                                                                            ##
##12.31.1999  Performance Server Library v2.000  Daniel Huffman               ##
##                                                                            ##
##                                                                            ##
##  Multithreaded Performace Server Library Objects                           ##
##                                                                            ##
##                                                                            ##
##    Please note.  The header file dependences are not complete in this      ##
##    makefile.  If any changes are made to header files, please `make clean' ##
##    before executing `make all'.                                            ##
##                                                                            ##
################################################################################
################################################################################


# Use a complier that is POSIX threads enabled.
CC          = g++

SSERVER_DIR = ../Code-from-the-90s/projects/library/sserver/
PSERVER_DIR = ../Code-from-the-90s/projects/library/pserver/
PLIB_DIR    = ../Code-from-the-90s/projects/library/lib/

OBJFLAGS    = -g -I$(PLIB_DIR)/thread -I$(PLIB_DIR)/string -I$(PLIB_DIR)/log -I$(PLIB_DIR)/error -I$(PLIB_DIR)/memory -I$(PLIB_DIR)/other -I$(PLIB_DIR)/cron -I$(PSERVER_DIR) -I$(SSERVER_DIR)/telenet
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
## Perfromance Mulithreaded Server Objects.                                   ##
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
        $(SSERVER_DIR)client.o                                                 \
        $(SSERVER_DIR)sendrecv.o                                               \
        $(PLIB_DIR)*.o


ssips: ssips.o $(SSIP_OBJS)
	$(CC) $(LINKFLAGS) -o ssips ssips.o                                    \
        $(SSIP_OBJS)                                                           \
        $(SSERVER_DIR)input.o                                                  \
        $(SSERVER_DIR)output.o                                                 \
        $(SSERVER_DIR)server.o                                                 \
        $(SSERVER_DIR)sendrecv.o                                               \
        $(PSERVER_DIR)pserver.o                                                \
        $(PSERVER_DIR)queueDirector.o                                          \
        $(PSERVER_DIR)executionDirector.o                                      \
        $(PSERVER_DIR)threadDirector.o                                         \
        $(PSERVER_DIR)serverDirector.o                                         \
        $(PSERVER_DIR)inputgate.o                                              \
        $(PSERVER_DIR)outputgate.o                                             \
        $(PSERVER_DIR)workthread.o                                             \
        $(PSERVER_DIR)carapace.o                                               \
        $(PLIB_DIR)*.o




################################################################################
## Clean.                                                                     ##
################################################################################
clean:
	rm -f *.o $(EXECS)


################################################################################
################################################################################
