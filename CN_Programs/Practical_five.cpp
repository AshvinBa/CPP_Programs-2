/*
#include <iostream>
#include <string>
#include <cstring> // for memset
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h> // for close

// TCP server class
class TCPServer {
public:
    static const int PORT = 1222; // Server port

    void start() {
        // Create a socket
        int server_fd = socket(AF_INET, SOCK_STREAM, 0);
        
        // Define the server address structure
        struct sockaddr_in address;
        int addrlen = sizeof(address);
        memset(&address, 0, sizeof(address));
        address.sin_family = AF_INET;
        address.sin_addr.s_addr = INADDR_ANY;
        address.sin_port = htons(PORT);
        
        // Bind the socket to the server address
        bind(server_fd, (struct sockaddr *)&address, sizeof(address));
        
        // Listen for connections
        listen(server_fd, 3);
        std::cout << "Server Started" << std::endl;
        
        // Accept a connection
        int new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
        std::cout << "Connection accepted" << std::endl;
        
        // Communication loop
        char buffer[1024] = {0};
        std::string send;
        while (true) {
            // Clear the buffer
            memset(buffer, 0, sizeof(buffer));
            // Read data from the client
            read(new_socket, buffer, 1024);
            std::string str(buffer);
            send = "Echo:" + str;
            // Send the echoed message back to the client
            sendto(new_socket, send.c_str(), send.length(), 0, (struct sockaddr *)&address, addrlen);
            std::cout << "Echoing: " << str << std::endl;
            // Break the loop if the client sends "END"
            if (str == "END") {
                break;
            }
        }
        std::cout << "Closing server" << std::endl;
        // Close the connection
        close(new_socket);
        // Close the server socket
        close(server_fd);
    }
};

int main() {
    // Start the TCP server
    TCPServer server;
    server.start();
    return 0;
}
*/



import java.io.*;
import java.net.*;
class TCPServer
{
 public static final int PORT=1222;
 public static void main(String a[])throws Exception
 {
 ServerSocket s=new ServerSocket(PORT);
 System.out.println("Server Started");
 Socket c = s.accept();
 System.out.println("Connection acepted:"+c);
 BufferedReader in = new BufferedReader(new InputStreamReader(c.getInputStream()));
 PrintWriter out= new PrintWriter(new BufferedWriter(new
OutputStreamWriter(c.getOutputStream())),true);
 String send;
 while(true)
 {
 String str=in.readLine();
 send=("Echo:"+str);
 out.println(send);
 System.out.println("Echoing: "+str);
 if(str.equals("END"))
 break;
 }
 System.out.println("Closing server");
 c.close();
 s.close();
 }
}


// 2 .Client Server:-
import java.io.*;
import java.net.*;
class TCPClient
{
 public static void main(String a[])throws Exception
 {
 Socket cp=new Socket("localhost",1222);
 System.out.println("Client connected"+cp);
 String s1;
 BufferedReader abc = new BufferedReader(new InputStreamReader(cp.getInputStream()));
 BufferedReader in =new BufferedReader(new InputStreamReader(System.in));
 PrintWriter out =new PrintWriter(new BufferedWriter(new
OutputStreamWriter(cp.getOutputStream())),true);
 while(true)
 {
 System.out.println("Enter the string to sent to server");
 s1=in.readLine();
 out.println(s1);
 String str =abc.readLine();
 System.out.println("From server:"+str);
 if(str.equals("END"))
 break;
 }
 System.out.println("Closing client");
 cp.close();
 }
}
