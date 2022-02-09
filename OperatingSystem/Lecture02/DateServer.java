import java.net.*;
import java.io.*;

public class DateServer { // public class DateServer
    public static void main(String[] args) throws Exception{
        ServerSocket server = new ServerSocket(6013); // port number 6013

        // Now listen for connections
        while (true) {
            System.out.println("Listening...");
            Socket client = server.accept(); // request listening... return client socket(e.g. 7078 port)
            PrintWriter pout = new PrintWriter(client.getOutputStream(), true);
            System.out.println("New Client is Connected.");
            // write the Date to the socket
            pout.println(new java.util.Date().toString());

            // close the socket and resume listening for connections
            client.close();
            System.out.println("Client is Disconnected");
        }
    }
}