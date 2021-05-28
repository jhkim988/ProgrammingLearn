import java.net.*;
import java.io.*;

public class DateServer {
    public static void main(String[] args) throws Exception{
        ServerSocket server = new ServerSocket(6013);

        // Now listen for connections
        while (true) {
            Socket client = saerver.accept();
            PrintWriter pout = new PrintWriter(client.getOutputStream(), true);

            // write the Date to the socket
            pout.println(new java.util.Date().toString());

            // close the socket and resume listening for connections
            client.close();
        }
    }
}