public class CastingEx3 {
  public static void main(String[] args) {
    float f = 9.1234567f; // 2진수로 무한소수이기 때문에 반올림이 발생한다.
    double d = 9.1234567; // float과 double의 정밀도차이
    double d2 = (double) f; // 이미 반올림이 된 상태로 f가 저장됐기 때문

    System.out.printf("f = %20.18f\n", f);
    System.out.printf("f2 = %20.18f\n", d);
    System.out.printf("d = %20.18f\n", d2);
  }
}
