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

        // 상수: final 키워드를 사용한다. 변경할 수 없기 때문에 선언할 때 초기화를 해준다.
        final int MAX_SPEED = 10;

        // 리터럴의 타입과 접미사
        // byte와 short 타입의 리터럴은 별도로 존재하지 않는다.
        // long 타입의 경우에 접미사 l 또는 L을 붙여준다.
        // 0b 2진수, 0 8진수, 0x 16진수
        // float는 f, double은 d를 붙이다. d는 생략 가능하다.
        // 기호 p를 이용하여 실수 리터럴을 16진 지수형태로 표현할 수 있다. p는 2의 제곱을 의미한다.

        // 넓은 타입에 좁은 타입의 값을 저장하는 것은 가능하다.
    }
}
