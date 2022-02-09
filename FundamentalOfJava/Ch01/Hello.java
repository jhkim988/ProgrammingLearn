class Hello {
    public static void main(String[] args){
        // main 메서드는 JavaApplication의 시작점
        // 모든 클래스에 있을 필요는 없지만, 반드시 하나는 있어야 한다.

        // javac filename.java
        // java classname.class // main 메서드가 포함된 클래스를 작성한다.
        
        // 소스파일 이름과 public class 이름은 같아야 한다.
        // 따라서 하나의 소스 파일에 public class가 두 개 이상 있으면 안된다.
        // public class가 없는 소스 파일의 경우엔 상관 없다.

        // UTF-8로 작성된 소스코드를 컴파일 하는 방법
        // javac -encoding utf-8 Hello.java
        // -encoding 옵션을 준다.
        
        System.out.println("Hello, World.");
    }
}