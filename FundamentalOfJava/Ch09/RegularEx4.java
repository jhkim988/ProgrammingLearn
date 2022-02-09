import java.util.regex.*;

public class RegularEx4 {
  public static void main(String[] args) {
    String source = "A broken hand works, but not a broken heart.";
    String pattern = "broken";
    StringBuffer sb = new StringBuffer();

    Pattern p = Pattern.compile(pattern);
    Matcher m = p.matcher(source);
    System.out.println("source: " + source);

    int i = 0;
    while (m.find()) {
      // find()로 찾으면 start(), end()로 위치를 알 수 있다.
      System.out.println(++i + "번 째 매칭: " + m.start() + "~" + m.end());
      m.appendReplacement(sb, "drunken");
    }
  }
}
