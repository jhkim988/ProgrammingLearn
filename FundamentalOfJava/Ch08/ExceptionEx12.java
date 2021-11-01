public class ExceptionEx12 {
  // 메소드에 throws를 명시하는 것은 예외처리를 하는 것이 아니라, 호출한 곳에 예외처리를 떠넘기는 것이다.
  public static void main(String[] args) {
    method1(); // method1을 호출했지만, 예외처리를 하지 않아 프로그램이 종료된다.
  } 
  static void method1() throws Exception { // method1을 호출한 곳에서 예외처리를 해야한다.
    method2();
  }
  static void method2() throws Exception { // method2를 호출한 곳에서 예외처리를 해야한다.
    throw new Exception();
  }
}
