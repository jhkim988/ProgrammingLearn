public class StringEx {
    public static void main(String[] args) {
        // 자료형 - 기본형, 참조형
        // 기본형 변수는 실제 값을 저장
        // 참조형 변수는 어떤 값이 저장되어 있는 주소를 값으로 갖는다.
        // C언어와 덜리 참조형 변수 간의 연산을 할 수 없다.
    
        // 기본형
        // boolean, char, byte, short, int, long, float, double
        // 참조형
        // 기본형 8개를 제외한 나머지
        
        // 참조변수는 null 또는 객체의 주소를 값으로 갖는다.
        // 참조변수의 초기화
        // Date today = new Date(); // 객체를 생성하는 연산자 new의 결과는 객체의 주소이다.
        // JVM이 32bit가 아니라 64bit라면 참조형 변수의 크기는 8byte가 된다.

        // char는 내부적으로 정수로 저장하기 때문에 정수형과 다르지 않으며, 정수형 실수형과 연산도 가능하다.
        // boolean을 제외한 나머지 7개의 기본형은 서로 연산과 변환이 가능하다.
        // int는 CPU가 가장 효율적으로 처리할 수 있는 타입이다.

        // boolean: 1byte
        // char : 2byte
        // byte: 1byte
        // short: 2byte
        // int: 4byte
        // long: 4byte
        // float: 4byte
        // double: 4byte

        // 상수와 리터럴
        // 상수는 final 키워드를 붙인다. 상수는 값을 한 번 저장하면 변경할 수 없다.
        // 때문에 상수는 선언과 동시에 초기화를 해야하고, 이전 버전에서는 초기화 하지 않으면 에러가 났다.
        // JDK1.6부터는, 사용하기 전에만 초기화하면 되도록 바뀌었다.
        // 상수 변수의 이름은 모두 대문자로 하는 것이 암묵적 관례이다.

        // 리터럴
        // 123, 12, 3.14, 'A'와 같은 값
        // 정수형 리터럴은 기본적으로 int, 실수형 리터럴은 기본적으로 double 타입이다.
        // long 타입 리터럴을 사용하기 위해서는 접미사로 L을 붙인다.
        // float 타입/double 타입 리터럴을 사용하기 위해서는 접미사로 f/d를 붙인다.
        // 리터럴 사이에 구분자 _를 넣을 수 있게 되어서, 큰 숫자를 쉽게 읽을 수 있게 됐다.
        // 16진법을 사용하기 위해선 접두사로 0x를 붙이고, 8진법을 사용하기 위해선 0를 붙인다.
        // 10의 제곱을 나타내는 기호 E/e, 접미사로 f F d D를 포함하면 실수형 리터럴로 간주된다.
        // 접미사 p를 붙여 16진 지수 형태의 리터럴을 사용할 수 있다.

        // 타입 불일치
        // int i = 'A'; // 'A'의 유니코드인 65가 변수 i에 저장된다.
        // long l = 123; // int 타입보다 long 타입의 범위가 더 넓다.
        // double d = 3.14f; // float 타입보다 double 타입의 범위가 더 넓다.
        // int i = 0x123456789; // 에러, int 타입의 범위를 넘는 값
        // float f = 3.14; // 에러, float 타입보다 double 타입의 범위가 넓다.
        // byte나 short는 접미사가 따로 존재하지 않기 때문에 int 타입의 리터럴을 사용한다.
        // 단 변수를 저장할 수 있는 범위에 속해야한다.
    
        // 홀따옴표는 char 타입 문자 리터럴을 표기할 때 사용한다. 반드시 하나의 문자가 있어야 한다.
        // 겹따옴표는 String 타입 문자열 리터럴을 표기할 때 사용한다. 빈 문자열을 허용한다.
        // String은 클래스이므로 new String("Java"); 처럼 new 연산자를 사용해야 하지만, 사용하지 않아도 생성되도록 특별히 허용한다.
        // 문자열은 덧셈 연산자를 이용하여 결헙할 수 있다.

        String name = "Ja" + "va";
        String str = name + 8.0;

        System.out.println(name);
        System.out.println(str);
        System.out.println(7 + " ");
        System.out.println(" " + 7);
        System.out.println(7 + "");
        System.out.println("" + 7);
        System.out.println("" + "");
        System.out.println(7 + 7 + "");
        System.out.println("" + 7 + 7);
    }
}
