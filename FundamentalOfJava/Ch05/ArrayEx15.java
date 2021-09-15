public class ArrayEx15 {
  // String은 변경할 수 없다. 새로운 문자열이 생성된다.
  // 변경 가능한 문자열을 사용하고 싶다면 StringBuffer를 사용한다.
  public static void main(String[] args) {
    String source = "SOSHELP";
    String[] morse = {".-", "-...", "-.-.", "-..", ".",
    "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---",
    ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--",
    "--.."};

    String result = "";
    for (int i = 0; i < source.length(); i++) {
      result += morse[source.charAt(i) - 'A'];
    }
    System.out.println("source: " + source);
    System.out.println("result: " + result);
  }  
}
