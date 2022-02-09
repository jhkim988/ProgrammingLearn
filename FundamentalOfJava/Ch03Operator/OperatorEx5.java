public class OperatorEx5 {
  public static void main(String[] args) {
    int a = 10;
    int b = 4;

    System.out.printf("%d + %d = %d\n", a, b, a + b);
    System.out.printf("%d - %d = %d\n", a, b, a - b);
    System.out.printf("%d * %d = %d\n", a, b, a * b);
    System.out.printf("%d / %d = %d\n", a, b, a / b); // 정수 나누기, 반올림 안 한다.
    System.out.printf("%d / %f = %f\n", a, (float) b, a / (float) b); // 자동 형변환

    // System.out.println(3/0); // ArithmeticException
    // System.out.println(3/0.0); // Infinity
    System.out.println(3%0.0); // NaN
    System.out.println(3%Double.POSITIVE_INFINITY); // 3.0
  }  
}
