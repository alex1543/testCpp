gcc server.cpp -o server
./server &
netstat -anp --tcp | grep server
telnet localhost 5000
