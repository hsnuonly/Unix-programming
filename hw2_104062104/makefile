CC:=g++
CPPFLAGS:= --std=c++14 -g

all: sandbox.o sandbox.so
	$(CC) sandbox.o -o sandbox $(CPPFLAGS) -ldl

sandbox.o: sandbox.cc
	$(CC) sandbox.cc -c $(CPPFLAGS)

sandbox.so: sandbox_shared.cc
	$(CC) $(CPPFLAGS) sandbox_shared.cc -fPIC -shared -ldl -o sandbox.so

clean:
	rm *.o *.so sandbox