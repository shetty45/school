#UDPclient.py
import socket

UDP_IP = "127.0.0.1"
RPORT = 12000
MESSAGE = "ping"

print "UDP target IP: ", UDP_IP
print "UDP target port: ", RPORT
print "message sent: ", MESSAGE

client = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

i=0
while True:
	try:
		if(i<10):
			client.sendto(MESSAGE.encode('utf_8'),(UDP_IP, RPORT))
			print "sending message: ", MESSAGE
			print i
			i=i+1
			client.settimeout(1)

			data, addr = client.recvfrom(1024)
			print "received echo: ", data
			print "received at: ", addr

	finally:
		print "Closing socket..."
client.close()

#remaining to be done: calculate RTT for each datagram