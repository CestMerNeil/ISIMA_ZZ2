/**------------------------------------------------------------------------------------------*                                                                                 
 * @brief: Application pendant la troisieme TP de JAVA. 3/7
 * @author: Ao XIE
 * @date:11/10/2022
 * @version: A208_PC-18_1.00                           
 *-------------------------------------------------------------------------------------------*/

public class TP3_JAVA {

    public static void main(String[] argv){
        // Init
        /*
        StringBuffer s1 = new StringBuffer("loic");
        s1 = new StringBuffer("Yon");    
        s1.setCharAt(0, 'b');

        System.out.println(s1);
        String S2 = "Yon";
        System.out.println(S2.replace("y","b"));
        System.out.println(S2);
        */

        
        String s1 = "loic";
        String s2 = "loic";
        String s3 = new String("loic");
        String s4 = new String("loic");
        String s5 = s3;
        String s6 = null;

        System.out.println(s1 == s2);
        System.out.println(s1 == s3);
        System.out.println(s3 == s4);
        System.out.println(s5 == s3);

        System.out.println(s1.equals(s3));
        System.out.println(s1.equals(s6));
        //System.out.println(s6.equals(s1));
        

        //String[] test = new String[100];
        System.out.println("\n" + argv.length + "\n");

    }

}
