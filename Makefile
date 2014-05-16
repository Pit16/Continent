CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		Kontynent.cpp Panstwo.cpp Pasmo_gorskie.cpp

LIBS =

TARGET = Continent

$(TARGET):	$(OBJS) main.cpp
	$(CXX) -o $(TARGET) $(OBJS) main.cpp $(LIBS)

all:	$(TARGET)

clean:
	rm -f *.o $(TARGET)

test: $(OBJS) testy.cpp
	$(CXX) -o Testuj $(OBJS) testy.cpp 
	./Testuj
