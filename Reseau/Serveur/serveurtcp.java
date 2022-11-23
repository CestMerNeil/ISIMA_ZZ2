import java.io.*;
import java.net.*;
import java.nio.BufferOverflowException;

import javax.crypto.SecretKey;
import javax.print.attribute.IntegerSyntax;

public class serveurtcp {
    private static int port;
    public static void main(String[] args) throws Exception{
        boolean boucle = true;
        Reader readersoc;
        PrintStream a_envoye = null;
        Socket soc;
        String line;

        if(args.length !=1){
            System.out.println("usage: java serveurtcp port");
            System.exit(0);
        }

        port = Integer.parseInt(args[0]);

        ServerSocket s = new ServerSocket(port);
        System.out.println("La socket serveur est cree!");

        while(true){
            boucle = true;
            soc = s.accept();
            System.out.println("Connexion realise a "+ soc.toString());

            readersoc = new InputStreamReader(soc.getInputStream());
            a_envoye = new PrintStream(soc.getOutputStream());
            BufferedReader datarecu = new BufferedReader(readersoc);

            while(boucle){
                line = datarecu.readLine();
                System.out.println("Vous avez saisi : "+ line);

                if(line.equals("FIN")){
                    boucle = false;
                    line = null;
                    soc.close();
                }
                else{
                    StringBuffer lineReversed = (new StringBuffer(line).reverse());
                    a_envoye.println(lineReversed);
                }
            }
        }
    }
    
}
