import java.util.*;

public class StringTokenizerEx5 {
  public static void main(String[] args) {
    String data = "100,,,200,300";

    String[] result = data.split(",");
    StringTokenizer st = new StringTokenizer(data, ",");
    for (int i = 0; i < result.length; i++) {
      System.out.print(result[i] + "|");
    }

    System.out.println("개수: " + result.length);

    int i = 0;
    for (; st.hasMoreTokens(); i++) {
      System.out.print(st.nextToken() + "|");
    }
    System.out.println("개수: " + i);

    // StringTokenizer는 빈문자열을 토큰으로 인식하지 않는다.
    // split()은 배열에 담아 반환하고, StringTokenizer는 토큰으로 바로 잘라서 반환하기 때문에 split이 성능이 더 떨어진다.
  }
}
