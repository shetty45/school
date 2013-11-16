all: UDPClient UDPServer TCPClient TCPServer

UDPClient: UDPClient.cpp
	g++ -o UDPClient UDPClient.cpp

UDPServer: UDPServer.cpp
	g++ -o UDPServer UDPServer.cpp

TCPServer: TCPServer.cpp 
	g++ -o TCPServer TCPServer.cpp

TCPClient: TCPClient.cpp 
	g++ -o TCPClient TCPClient.cpp

clean:
	rm UDPClient UDPServer TCPClient TCPServer
