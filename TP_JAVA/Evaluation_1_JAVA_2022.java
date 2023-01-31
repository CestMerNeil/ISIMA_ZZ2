public class Evaluation_1_JAVA_2022{
    public static void main(String[] args) {
        String s1 = "bleu";
        String s2 = "bleu";

        String s3 = new String("bleu");

        String s7 = "";

        s7.concat(s3);
        System.out.println(s7.equals(s3));
        System.out.println(s7.equals(s2));
    }
}