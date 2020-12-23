CXXFLAGS=-MMD -MP -Wall
CC=$(CXX)

PROGRAMS=programm
OBJECTS=gebiet.o stadt.o strasse.o

ALLOBJECTS=$(OBJECTS) $(patsubst %,%.o,$(PROGRAMS))

default: $(PROGRAMS)

programm: $(OBJECTS)

clean:
	-rm -f $(ALLOBJECTS) $(ALLOBJECTS:%.o=%.d) $(PROGRAMS)

-include $(ALLOBJECTS:%.o=%.d)

