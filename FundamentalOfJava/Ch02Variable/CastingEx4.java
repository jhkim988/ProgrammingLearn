public class CastingEx4 {
  public static void main(String[] args) {
    int i = 91234567; // 8자리 수
    float f = (float) i; // float의 정밀도는 7자리이므로 오차가 발생한다.
    int i2 = (int) f;

    double d = (double) i; // double의 정밀도는 15자리이므로 오차가 발생하지 않는다.
    int i3 = (int) d;

    float f2 = 1.666f;
    int i4 = (int) f2; // 반올림 하지 않는다.

    System.out.printf("i=%d%n", i);
    System.out.printf("f=%f i2=%d\n", f, i2);
    System.out.printf("d=%f i3=%d\n", d, i3);
    System.out.printf("(int) %f=%d\n", f2, i4);

    // 자동 형변환, 컴파일러가 생략된 형변환을 수행해준다.
    float ff = 1234; // (float) 1234;
    // byte b = 1000; // byte의 범위 초과, 에러
    char ch = (char) 1000; // 명시적 형변환, 에러 나지 않음
    int ii = 3;
    double dd = 1.0 + ii; // 1.0 + (double) ii; 산술변환
    // 컴파일러는 기존의 값을 최대한 보존할 수 있는 타입으로 자동 형변환 한다.
  }  
}
