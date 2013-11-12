all: UDPClient UDPServer TCPClient TCPServer

UDPClient: UDPClient.c
	gcc -o UDPClient UDPClient.c

UDPServer: UDPServer.c
	gcc -o UDPServer UDPServer.c

TCPServer: TCPServer.cpp 
	g++ -o TCPServer TCPServer.cpp

TCPClient: TCPClient.cpp 
	g++ -o TCPClient TCPClient.cpp

clean:
	rm TCPClient TCPServer
