import java.io.*;
import java.net.*;

public class clienttcp {
    private static int port;

    public static void main(String[] args) throws Exception{
        String adresse, line, lineReversed;
        Reader randSoc;
        PrintStream a_envoye = null;

        if(args.length != 2){
            System.out.println("usage: java client nom_serveur port");
            System.exit(0);
        }
        adresse = args[0];
        port = Integer.parseInt(args[1]);
        
        Socket socket = new Socket(adresse, port);

        Reader reader = new InputStreamReader(System.in);
        BufferedReader keyboard = new BufferedReader(reader);
    }
}
