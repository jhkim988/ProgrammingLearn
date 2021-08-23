import java.io.IOException;

public class FloatToBinEx {
  public static void main(String[] args) throws IOException {
    float f = 9.1234567f;
    int i = Float.floatToIntBits(f); // 실수가 저장된 bit를 정수로 해석한다.

    System.out.printf("%f%n", f);
    System.out.printf("%X%n", i);
  }  
}
