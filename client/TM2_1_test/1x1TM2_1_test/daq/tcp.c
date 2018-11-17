//////////////////////////////////////////////////////// tcp setup
tcp mytcp;
mytcp.IP="192.168.2.3";
mytcp.port="1024";

mytcp.setup();
int sockfd=mytcp.sockfd;
sockfd=mytcp.sockfd;

/******** send data to main control ******************/
tcp_client ts;
ts.setup((char*)"192.168.3.201",1234);
