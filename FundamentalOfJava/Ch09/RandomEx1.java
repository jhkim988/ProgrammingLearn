import java.util.*;

public class RandomEx1 {
  public static void main(String[] args) {
    Random rand = new Random(1);
    Random rand2 = new Random(1);
    // same seed
    System.out.println("= rand =");
    for (int i = 0; i < 5; i++) 
      System.out.println(i + ":" + rand.nextInt());
    System.out.println();
    for (int i = 0; i < 5; i++)
      System.out.println(i + ":" + rand2.nextInt());
}
}
