class NewClass {
  int newField;
  
  int getNewField() { return newField; }
  
  @Deprecated
  int oldField;
  
  @Deprecated
  int getOldField() { return oldField; }
}

public class AnnotationEx2 {
  public static void main(String[] args) {
    NewClass nc = new NewClass();
    nc.oldField = 10;
    System.out.println(nc.getOldField());
    // 컴파일 시 -Xlint:deprecation 옵션을 주면 자세한 내용을 알 수 있다.
  }
}
