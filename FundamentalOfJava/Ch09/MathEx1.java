import static java.lang.Math.*;
import static java.lang.System.*;

public class MathEx1 {
  public static void main(String[] args) {
    double val = 90.7552;
    out.println("round(" + val + ")=" + round(val));
    val *= 100;
    out.println("round(" + val + ")/100=" + round(val) / 100);
    out.println("round(" + val + ")/100.0=" + round(val) / 100.0);
    out.println();

    out.printf("ceil (%3.1f)=%3.1f\n", 1.1, ceil(1.1));
    out.printf("floor (%3.1f)=%3.1f\n", 1.5, floor(1.5));
    out.printf("round (%3.1f)=%d\n", 1.1, round(1.1));
    out.printf("round (%3.1f)=%d\n", 1.5, round(1.5));
    out.printf("rint (%3.1f)=%f\n", 1.1, rint(1.1));
    out.printf("round (%3.1f)=%d\n", -1.5, round(-1.5));
    out.printf("rint (%3.1f)=%f\n", -135, rint(-1.5));
    out.printf("ceil (%3.1f)=%3.1f\n", -1.5, ceil(-1.5));
    out.printf("floor (%3.1f)=%3.1f\n", -1.5, floor(-1.5));
  
    // round: 반환값이 int, 첫째 자리가 5일 때 더 큰 값으로 반올림한다.
    // rint: 반환값이 double, 정가운데 있는 값은 가장 가까이 있는 "짝수" 정수를 double 타입으로 반환한다.
  }
}
