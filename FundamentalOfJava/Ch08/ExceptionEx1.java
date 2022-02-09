public class ExceptionEx1 {
  public static void main(String[] args) {
    try {
      try { } catch (Exception e) { }
    } catch(Exception e) {
      // try { } catch (Exception e) { } // 변수 e가 중복선언 되었다.
    }
    
    try {

    } catch (Exception e) {
      
    }
  } 
}
