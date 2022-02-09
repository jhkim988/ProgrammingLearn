import java.util.*;

class NewClass {
  int newField;

  int getNewField() {
    return newField;
  }

  @Deprecated
  int oldField;

  @Deprecated
  int getOldField() {
    return oldField;
  }
}

public class AnnotationEx3 {
  // 여러 개를 추가하는 방법:
  // @SuppressWarnings({"deprecation", "unchecked", "varargs"})
  // @SuppressWarnings("rawtypes") Generics를 사용하지 않을 때
  // @SuppressWarnings("varargs") 가변인자 타입이 Generic 일 때
  @SuppressWarnings("deprecation") // deprecated 대상을 사용할 때
  public static void main(String[] args) {
    NewClass nc = new NewClass();
    nc.oldField = 10;
    System.out.println(nc.getOldField());

    @SuppressWarnings("unchecked") // Generic 타입 지정하지 않았을 때
    ArrayList<NewClass> list = new ArrayList();
    list.add(nc);


  }
}
