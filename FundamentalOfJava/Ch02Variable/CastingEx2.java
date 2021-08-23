public class CastingEx2 {
  public static void main(String[] args) {
    int i = 10;
    byte b = (byte) i;
    System.out.printf("[int -> byte] i = %d -> b = %d%n", i, b);

    i = 300;
    b = (byte) i;
    System.out.printf("[int -> byte] i = %d -> b = %d%n", i, b);

    // 작은 타입 -> 큰타입, 양수일 땐 0을 채워넣고 음수일 땐 1을 채워넣는다.
    b = 10;
    i = (int) b;
    System.out.printf("[byte -> int] b = %d -> i = %d%n", b, i);

    b = -2;
    i = (int) b;
    System.out.printf("[byte -> int] b = %d -> i = %d%n", b, i);
    System.out.println("i=" + Integer.toBinaryString(i));
  }  
}
