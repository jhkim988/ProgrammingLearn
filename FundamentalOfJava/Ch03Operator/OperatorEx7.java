public class OperatorEx7 {
  public static void main(String[] args) {
    byte a = 10;
    byte b = 20;
    byte c = (byte) (a * b); // 300은 byte의 범위를 넘는다.
    System.out.println(c);
  }
}
