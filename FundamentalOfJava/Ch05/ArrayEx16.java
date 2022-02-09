public class ArrayEx16 {
  public static void main(String[] args) {
    // JVM이 입력된 args가 없을 때 null 대신 크기 0인 배열을 생성하여 전달해준다.
    // 따라서 매개변수를 전달하지 않아도 args.length 등에 접근할 수 있다.
    System.out.println("매개변수의 개수: " + args.length);
    for (int i = 0; i < args.length; i++) {
      System.out.println("args[" + i + "] = \"" + args[i] + "\"");
    }
  }  
}
