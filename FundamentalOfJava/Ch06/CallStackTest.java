public class CallStackTest {
  // CallStack: main - firstMethod - secondMethod - println
  public static void main(String[] args) {
    firstMethod();
  }
  static void firstMethod() {
    secondMethod();
  }
  static void secondMethod() {
    System.out.println("secondMethod()");
  }
}