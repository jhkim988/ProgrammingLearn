public class OperatorEx6 {
  public static void main(String[] args) {
    byte a = 10;
    byte b = 20;
    byte c = (byte) (a + b); // 자동으로 int로 산술 형변환 했기 때문에 명시적 변환을 해주지 않으면 에러가 발생한다.
    System.out.println(c);
  }  
}
