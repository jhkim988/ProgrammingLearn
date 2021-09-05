// 표현식: 어떤 값으로 평가되는 것
// 숫자, 문자열, 논리값 등 원시값
// 변수, 프로퍼티, 배열 요소, 함수 호출, 메서드 호출
// 연산자를 사용하면 표현식을 조합하여 더 복잡한 표현식을 만들어낼 수 있다.

// 연산자의 우선순위
// 그룹연산자 (...)을 이용하여 계산 순서를 명시적으로 지정할 수 있다.

// 연산자의 결합법칙
// 우선순위가 같은 연산자가 나열돼 있으면 왼쪽부터 오른쪽으로 연산한다.

// 부수효과가 있는 표현식
// : 대입연산자, 증가연산자, 감소연산자, delete

// 산술 연산자: 피연산자가 숫자인 연산자
// 피연산자가 숫자가 아닐 때는 연산자가 피연산자 타입을 숫자 타입으로 바꾼다.
// 피연산자가 숫자로 바꿀 수 없는 값이거나, 계산할 수 없을 때는 NaN을 반환한다.
// 모든 산술연산은 64비트 부동소수점 연산으로 이루어진다.

// 일부 언어와 차이점:
// 정수끼리 나누어도 결과가 부동소수점이 된다.
// %의 피연산자는 부동소수점이다. a % b = sign(a) * abs(a - kb)
// + 연산자는 피연산자 중 하나가 문자열이면 나머지 피연산자를 문자열로 만들어 연결한다.
// 계산할 수 없으면 NaN, true -> 1, false -> 0, null -> 0, undefined -> NaN

// 증감 연산자를 연속으로 사용하면 참조 오류 발생
// (a++)++

// 뺄셈을 하면 정밀도 손실이 발생한다.
// 10진법으로 딱 떨어지는 값도 오차가 발생한다.(내부적으로는 2진법 연산을 하기 때문)
// (0.16 / 0.2 == 0.8) // false
// Math.abs(0.16 / 0.2 - 0.8) < 1e-10 // use this

// 문자열 연결
// 1. 피연산자가 모두 문자열이라면 문자열 연결을 한다.
// 2. 피연산자 중 하나가 문자열 혹은 문자열로 변환할 수 있는 객체라면 다른 피연산자의 타입을 문자열로 바꾼 다음 연결한다.
// 3. 그렇지 않으면 피연산자 두 개를 숫자 또는 NaN으로 타입을 바꿔 더한다.(JS 실행 환경에 따라 다르다.)

// 문자열을 String 객체로
var msgObj = new String("Everything is practice."); // 래핑: 원시값을 객체로 변환하는 행위
console.log(msgObj.length);
console.log(msgObj.charAt(3));

// 원시값인 문자열에서 프로퍼티를 사용하려고 하면 자동으로 String 객체로 바뀐다.
var msg = "Everything is practice.";
console.log(msg.length);
console.log(msg.charAt(3));
// JS에서는 원시값을 처리할 때 래퍼 객체로 자동 변환한다.(String/Number/Boolean)
// null 과 undefined는 래퍼 객체가 없다.
console.log(msgObj); // String 객체가 출력된다.
console.log(msgObj.valueOf()); // valueOf 메서드를 사용해야 문자열이 출력된다.

msg.substring(7, 10);
msg.slice(7, 10);
msg.slice(-3);
msg.slice(-9, -6);
msg.indexOf("t"); // first index
msg.indexOf("i", 10);// after 10'th char
msg.lastIndexOf("t"); // last index
msg.split(" ");
msg.replace("p", "P");
msg.toUpperCase();
msg.endsWith("."); // boolean whether last char is "." or not.
msg.includes("thing");
msg.charCodeAt(0);
msg.codePointAt(0);
// JS의 문자열은 불변이다. replace, toUpperCase 등은 기존 문자열을 수정하지 않고 새로운 문자열을 반환한다.
// codePointAt()은 써로게이트 페어를 지원한다.

// String 생성자의 프로퍼티
String.length; // 1
String.fromCharCode(65, 66, 67); // ABC, UTF-16 인코딩 값 -> 문자열
String.fromCharCode(0xd83d, 0xdcd6); // 써로게이트 페어, 5자릿수 코드 포인트 표현은 지원하지 않는다.
String.fromCodePoint(0x1f4d6); // UTF-16, 유니코드 코드포인트 스칼라값 모두 지원
"\u{1f4d6}"; // 유니코드 리터럴 사용

// 문자열을 배열로 읽고 쓰기
// charAt() 메서드 대신 대괄호
msg[3];
// 배열처럼 값을 수정할 수는 없다. 수정하려해도 무시된다.
msg[3] = "R";
console.log(msg);
// 써로게이트 페어로 표현하는 문자는 두 개의 배열요소로 분리된다.
// s[0]: 상위 써로게이트, s[1]: 하위 써로게이트

// 써로게이트 페어:
// 유니코드는 문자집합과 문자인코딩 방식을 정한 표준 문자코드이고, 전 세계에서 사용하는 문자가 포함돼 있다.
// 유니코드 문자집합에서 각 문자의 위치를 코드 포인트라고 부르고, 코드 포인트에는 스칼라 값이라는 숫자가 할당돼 있다.
// 스칼라 값은 코드 포인트 값이라고도 부르며, U+8A9E처럼 U+를 붙인 16진수로 표현한다.
// 유니코드 인코딩 방식에는 UTR-8, UTF-16, UTF-32 등이 있다.
// JS에서 사용되는 UTF-16에서 U+10000 미만의 코드포인트 값은 UTF-16인코딩 값과 같다.
// 하지만 U+10000 이상의 코드 포인트 값은 UTF-16의 인코딩 값(2바이트) 두 개를 합쳐서 정의한다.
// 앞 부분 값 a는 0xD800 ~ 0xDBFF(총 1024개), 뒷 부분 값 b는 0xDC00~0xDFFF(총 1024개) 사이의 값이다.
// 이들 모두는 U+10000까지의 코드 포인트 값으로, 아직 문자에 할당되지 않은 미사용 값이다.
// (a, b)를 한 쌍으로 묶은 것을 가리켜 써로게이트 페어라고 부른다.(상위 써로게이트, 하위 써로게이트)
// 써로게이트 페어 (a, b)가 주어졌을 때 유니코드의 코드 포인트 값 u를 구하는 공식:
// u = (a - 0xD800) * 0x400 + (b - 0xDC00) + 0x10000
// u의 범위는 0x10000 ~ 0x10FFFF 사이의 값이다.
// u로부터 써로게이트 페어를 구하는 공식:
// a = (u - 0x10000) / 0x400 + 0xD800;
// b = (u - 0x10000) % 0x400 + 0xDC00;

// 정규 표현식을 이용하여 써로게이트 페어가 포함된 문자열을 문자배열로 만드는 함수
function stringToArray(s) {
  return s.match(/[\uD800-\uDBFF][\uDC00-\uDFFF]|[^\uD800-\uDFFF]/g) || [];
}

// 논리연산자와 관계연산자
// ==: 좌우 피연산자의 타입을 변환한 다음에 같은지 느슨하게 비교한다.
// 1. 좌우 피연산자의 타입이 같을 때, 값이 같으면 true, 다르면 false
// 객체 타입 변수의 값이 같은지를 판별하는 행위는, 같은 객체를 가리키는지 판별하는 것과 같다.
var a = [1, 2, 3];
var b = [1, 2, 3];
var c = a;
console.log(a == b); // false
console.log(a == c); // true
// 2. 좌우 피연산자의 값이 다를 때, 같은 타입이 되도록 타입을 변환한 다음에 판별한다.
// undefined와 null은 같은 것으로 친다.
// 한쪽이 숫자고, 다른 한쪽이 문자열이면 문자열을 숫자로 변환해서 비교한다.
// 한쪽이 논리값이면 true는 1로, false는 0으로 변환하여 비교한다.
// 한쪽이 객체이고, 다른 한쪽이 숫자/문자열이면, 객체를 toString이나 valueOf 메서드를 사용하여 원시타입으로 변환한 다음 비교한다.
// 위의 규칙에 벗어나면 모두 false
console.log(null == undefined); // true
console.log(1 == "1"); // true
console.log("0xff" == 255); // true
console.log(true == 1); // true
console.log(true == "1"); // true
console.log((new String("a")) == "a"); // true, toString, valueOf
console.log((new Number(2)) == 2); // true, valueOf
console.log([2] == 2); // true, valueOf

// ===: 타입을 변환하지 않은 상태의 두 값을 엄격하게 비교한다.
// NaN은 모든 값과 같지 않다. (NaN === NaN: false)
// 값이 NaN인지 판별하는 방법은 isNaN 메서드를 사용하면 된다.

// 논리 연산자
// &&, ||, !
// 피연산자가 논리값이 아니라면 필요에 따라 타입을 변환한다.
// 0, -0, 빈문자열(""), NaN, null, undefined: false
// 0을 제외한 숫자, 빈 문자열을 제외한 문자열, 모든 객체, 심벌: true
// short-circuit evalutaion: &&, ||의 경우 앞의 피연산자만으로 값이 결정되면 뒤의 피연산자를 계산하지 않는다.
// &&와 || 연산자는 ""마지막으로 평가한 피연산자 값을 반환한다"" (C/Java처럼 true false 반환이 아니다.)

// &&를 이용하면 객체가 null인지 아닌지 확인하고자 할 때 유용하다.
var p = null;
p && p.name // null, p가 false로 평가되므로 p를 반환한다. 우변은 평가하지 않음
p = {name : "Tom", age: 18};
p && p.name; // Tom, p가 true로 평가되므로 p.name을 반환한다.

// ||을 이용하면 null/undefined가 아닌 값을 선택하고자 할 때 유용하다.
var time = time_interval || animationSettings.time || 33;

function f(x) { // 함수의 초깃값을 설정할 때 유용하게 사용할 수 있다.
  x = x || 100;
}

f(); // x가 undefined이므로 x에 100이 할당된다.
f(2); // x가 2이다.
// 주의해야할 점: 0이나 ""등을 넘기면 100이 그대로 사용된다. 

// bit 연산
// 비트논리연산 / 비트 시프트 연산
// &, |, ^, ~
// <<, >>

// 기타 연산자
// typeof: 데이터 타입을 조사한다.
// ? : : 조건 연산자
// void: 정의되지 않은 값을 반환한다.
// , : 왼쪽에서 오른쪽 순서대로 피연산자를 연속해서 실행한다.
// delete: 객체의 프로퍼티나 배열 요소를 제거한다.
// new : 객체를 생성한다.
// in : 객체 프로퍼티의 포함 여부를 확인한다.
// instanceof: 객체의 종류를 확인한다.
// eval(): 인수로 받은 문자열을 자바스크립트 코드로 실행한다.

var s = "ABC";
console.log(typeof s); // string
// typeof는 함수 이외의 객체에 대해 object를 반환하므로, 객체 유형은 파악할 수 없다.
// 객체 유형을 조사할 때는 instanceof 연산자와 객체의 constructor 프로퍼티를 사용한다.

// 조건 연산자
var parity = (a % 2 == 0) ? "짝수" : "홀수";

// eval()
// 함수를 호출한 유표 범위 안에 있는 변수를 사용한다. (일반 함수처럼 함수 유효범위를 만들지 않는다.)
// 보안 문제가 있다, 속도가 느리다.

// 명시적 타입 변환
// 숫자를 문자열로
// 1. 숫자 + 문자열: 문자열로 바뀐다.
10 + "cookies"; // "10cookies"
100 + ""; "100"
("0000" + 12).slice(-4); // 0012

// 2. Number 객체의 메서드를 활용하는 방법
var n = 26;
n.toString(); // "26", 10진수 문자열
n.toString(2); // "11010" 2진수 문자열
n.toString(16); // "1a" 16진수 문자열
(26).toString(16); // "1a"

var x = 1234.567;
x.toString(); // "1234.567"
x.toString(16); // "4d2.9126e978d5"
x.toFixed(0); // 1235
x.toFixed(2); // 1234.57
x.toFixed(4); // 1234.5670
x.toExponential(3); // 1.235e+3
x.toPrecision(3); // 1.23e+3
x.toPrecision(5); // 1234.57

// 3. String 함수를 활용하는 방법
// new 연산자를 붙이지 않으면 일반적인 함수로 활용할 수 있다. 반환값은 String 객체가 아닌 문자열이다.
// String 함수는 모든 데이터 타입을 문자열 타입으로 바꾼다.

// 문자열을 숫자로 변환하기
var s = "2";
s - 0; // 2
+s; // 2

// parseInt, parseFlot 메서드
// 숫자 이후의 문자는 무시한다. 해석할 숫자가 앞에 없으면 NaN
// 두 번째 인자로 기수를 설정할 수 있다.(2~36진법)
// Number 함수 활용, 10진수만 처리 가능

// 논리값으로 변환
!!x;
Boolean(x);