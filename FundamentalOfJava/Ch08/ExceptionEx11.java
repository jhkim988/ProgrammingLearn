public class ExceptionEx11 {
  public static void main(String[] args) {
    throw new RuntimeException(); // 컴파일은 된다. "런타임"에러가 난다.
  } 
  // RuntimeException클래스와 그 자손에 해당하는 예외는 예외처리를 강제하지 않는다.
}
