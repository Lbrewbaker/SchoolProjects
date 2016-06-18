#**********************************
# Author: Luke Brewbaker
# Date: 4/24/16
# Modified:4/29/16
# File: chatserve.java
# OSU CS372
# Overview:
#

# Additional sources: 
# http://www.bogotobogo.com/python/python_network_programming_tcp_server_client_chat_server_chat_client_select.php

#***********************************
  


#Socket module import allows for creation of sockets within program
from socket import socket, AF_INET, SOCK_STREAM
import sys

#Check for the correct number of arguments (3).  Print usage if incorrect
if len(sys.argv) != 3:
    print " usage: { python chatclient.py <server_hostname> <port_number> }"
    sys.exit(1)

#get servername and port from command line
serverName = sys.argv[1]
serverPort = int(sys.argv[2])

#chat variables
quit = "\quit"
message = " "

# create the client socket
clientSocket = socket(AF_INET, SOCK_STREAM) #IPv4, TCP Socket

# Initiate the TCP connection and perform handshake.  If connection refused, end program.
try:
    clientSocket.connect((serverName,serverPort))
except Exception as error:
    print error.strerror + "."
    sys.exit(1)

#Inform user of chatclient that connection is established
print '\nWelcome to Chat Server of Awesomeness.'
print 'Connection with server established.'
print 'Use \quit or CTRL + C to end connection.'

#Prompt to enter clientName
clientName = raw_input('\nEnter a chat handle: ')

#10 character maximum for chatclient handle
while((len(clientName) > 10) or (" " in clientName)):
    clientName = raw_input('\nNotice: 10 character maximum and no whitespace allowed. Try again.\nEnter a chat handle: ')

#format the client name
clientName = clientName+"> "
print ' '

#Infinite loop, until /quit or SIGINT
while(1):
    #message continues to collect characters until user inputs a carriage return
    message = raw_input(clientName)

    #Input validation for less than 500 chars
    while (len(message) > 500):
        print '\nError: Messages must be 500 characters or less. Try again.\n'
        message = raw_input(clientName)

    #If /quit entered by used, exit program
    if (message == quit):
        #Send command for the Server side to end also
        clientSocket.send("\quit")
        print 'Connection ended by client.'
        # Closes socket and TCP connection
        clientSocket.close()
        sys.exit(0)

    # send message to server
    message = clientName+message+"\n"
    clientSocket.send(message)

    # retrieve and display message sent from server
    replyMessage = clientSocket.recv(1024)
    print(replyMessage),

    #If \quit command sent from Server, end program
    if quit in replyMessage:
        print 'Connection ended by server.'
        clientSocket.close()
        sys.exit(0)
