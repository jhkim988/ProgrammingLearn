public class OperatorEx17 {
  public static void main(String[] args) {
    double pi = 3.141592;
    double shortPi = (int) (pi * 1000 + 0.5) / 1000.0;
    // pi -> 3141.592 -> 3142.092 -> 3142(int) -> 3.142(double)
    System.out.println(shortPi);
  }
}
