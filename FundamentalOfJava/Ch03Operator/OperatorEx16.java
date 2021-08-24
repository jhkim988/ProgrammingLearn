public class OperatorEx16 {
  public static void main(String[] args) {
    float pi = 3.141592f;
    float shortPi = (int) (pi * 1000) / 1000f;
    // pi -> 3141.592f -> 3141(int) -> 3.141(float)
    System.out.println(shortPi);
  }  
}
