#! /usr/bin/python

#Author: Luke Brewbaker
#Date:  5/20/16
#Modified: 5/28/16
#File:  ftclient.py
#Overview: file transfer client written in python.  Will connect to ftserver.cpp on flip server.
#Sources: https://docs.python.org/2/library/socket.html; http://www.bogotobogo.com/python/python_network_programming_server_client_file_transfer.php; https://www.youtube.com/watch?v=LJTaPaFGmM4


import socket, sys, threading, os

def initiateContact(host, port):

    s = None
    # Try to connect to all addresses returned as a result of the name resolution
    for res in socket.getaddrinfo(host, port, socket.AF_UNSPEC, socket.SOCK_STREAM):
        af, socktype, proto, canonname, sa = res
        try:
            #Socket call
            s = socket.socket(af, socktype, proto)
        except socket.error as msg:
            s = None
            continue
        try:
            #Connect call
            s.connect(sa)
        except socket.error as msg:
            s.close()
            s = None
            continue
        break
    if s is None:
        print "Error: Could not open socket on port " + port
        sys.exit(1)

    #return socket
    return s

def makeRequest():

     #Send command
    control.sendall(COMMAND)

    #send confirmation
    response = control.recv(1024)

    #Send command
    if response == COMMAND:
        if COMMAND == "-l":
            control.sendall(HOST + " " + COMMAND + " " + DATA_PORT)
        if COMMAND == "-g":
            control.sendall(HOST + " " + COMMAND + " " + FILENAME + " " + DATA_PORT)


#get arguments from command line.  First with the -l command
if len(sys.argv) == 5:
    HOST = sys.argv[1]
    CONTROL_PORT = sys.argv[2]
    COMMAND = sys.argv[3]
    DATA_PORT = sys.argv[4]
elif len(sys.argv) == 6: #get arguments from command line with the -g command.
    HOST = sys.argv[1]
    CONTROL_PORT = sys.argv[2]
    COMMAND = sys.argv[3]
    FILENAME = sys.argv[4]
    DATA_PORT = sys.argv[5]
else:
    print "Usage: python " + sys.argv[0] + " <server host> <server port> <commands: -l | -g filename <data port>" #print usage information if program called incorrectly.
    exit(1)

#start connection
control = initiateContact(HOST, CONTROL_PORT)

#make request to the server
makeRequest()

#indicates on which connection to receive
response = control.recv(1024)

if response == "DATA":
    #Connect to data connection
    data = initiateContact(HOST, DATA_PORT)
    
    #list command
    if COMMAND == "-l":
        listing = data.recv(1024)
        print "Receiving directory structure from " + HOST + ":" + DATA_PORT
        print listing

    #get command
    if COMMAND == "-g":
        #file size
        filesize = control.recv(1024)
        #file contents
        filecontents = data.recv(int(filesize))
        #file name
        fo = open(FILENAME, 'wb')

        print 'Receiving "' + FILENAME + '" from ' + HOST + ":" + DATA_PORT
        
        #write file contents to new file
        fo.write(filecontents)

        print "File transfer complete"

#close the connection when finished.
control.close()
exit(0)