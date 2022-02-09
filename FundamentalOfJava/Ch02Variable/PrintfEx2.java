import java.io.IOException;

public class PrintfEx2 {
 public static void maion(String[] args) {
  // C에서는 char를 %d로 출력할 수 있지만, Java에서는 형변환을 해줘야한다.

  String url = "www.codechobo.com";
  float f1 = .10f;
  float f2 = 1e1f;
  float f3 = 3.14e3f;
  double d = 1.23456789;

  System.out.printf("f1=%f, %e, %g %n", f1, f1, f1);
  System.out.printf("f2=%f, %e, %g %n", f2, f2, f2);
  System.out.printf("f3=%f, %e, %g %n", f3, f3, f3);

  System.out.printf("d=%f%n", d); // 기본 6자리, 7자리에서 반올림한다
  System.out.printf("d=%14.10f%n", d); // 전체 14자리 중 소수점 10자리

  System.out.printf("[12345678901234567890]%n");
  System.out.printf("[%s]", url); // 문자열 길이만큼 출력공간 확보
  System.out.printf("[%20s]", url); // 최소 20글자 출력공간 확보
  System.out.printf("[%-20s]", url); // 왼쪽 정렬
  System.out.printf("[%.8s]", url); // 왼쪽에서 8글자

 } 
}
