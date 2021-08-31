// 배열 리터럴
var evens = [2, 4, 6, 8];

// 배열 요소는 0, 1, 2, ... 번호가 매겨져 있다.(요소번호/인덱스)
// 배열은 객체 타입이므로, 배열을 변수에 대입하면 배열의 참조가 변수에 저장된다.

var empty = []; // 빈 배열
console.log(empty); // []

var a = [2, , 4];
console.log(a); // [2, undefined, 4]

// JS의 배열에는 모든 타입의 값이 올 수 있다.
var various = [3.14, "pi", true, {x : 1, y : 2}, [2, 4, 6, 8]];

// length 프로퍼티
console.log(evens.length); // 최대 인덱스값 + 1, 배열 길이

// JS에서는 배열 요소의 개수와 length가 다른 경우가 있다.
// length 프로퍼티에 현재 배열 요소보다 작고 0보다 큰 정수 값을 대입하면 배열 길이가 줄어든다.
// 배열 길이를 넘는 인덱스 번호에 할당된 배열 요소는 삭제된다.

var b = ["A", "B", "C", "D"];
b.length = 2;
console.log(b); // ["A", "B"]

// Array 생성자로 생성하기
var evens = new Array(2, 4, 6, 8); // [2, 4, 6, 8]
var empty = new Array(); // []

// 주의: 셍성자의 인수가 한 개이고, 그 값이 양의 정수라면, 인수가 배열 길이를 뜻하게 된다.
// 음의 정수라면 오류가 발생한다.
var x = new Array(3);
console.log(x);
console.log(x.length); // 3

// 배열 요소의 참조 - 특정 인덱스 요소는 대괄호[]를 사용해서 읽거나 쓸 수 있다.

// 배열은 객체
// C/Java에서 배열요소는 메모리의 연속된 공간에 차례대로 배치돼 있다.
// 따라서 인덱스를 지정하면 인덱스가 가리키는 요소를 매우 빠르게 읽거나 쓸 수 있다.
// 하지만 JS의 배열은 Array 객체이며, 객체로 배열의 기능을 흉내낸 것이다.
// 배열 객체는 배열의 인덱스를 문자열로 변환하여, 그것을 프로퍼티로 이용한다.

var a = ["A", "B", "C", "D"]
console.log(a["2"]); // "B"
console.log(a[4]); // undefined

// C나 Java같은 프로그래밍 언어의 배열에는 없는 특성이다.
// ECMAScript 6에서는 Typed Array 객체가 추가됐다. TypedArray는 C/Java처럼 메모리의 연속된 공간에 배치한다.

// 배열 요소의 추가와 삭제
// 없는 배열 요소에 값을 대입하면 새로운 요소가 추가된다.
// push 메서드를 이용하면 배열 끝에 추가할 수 있다.
// delete 연산자를 이용하면 특정 배열 요소를 삭제할 수 있다. - length 프로퍼티는 바뀌지 않는다.

var a = ["A", "B", "C"];
a[3] = "D";
console.log(a);

a.push("E");
console.log(a);

delete a[1];
console.log(a);
console.log(a.length);

// 희소 배열
// 인덱스가 0부터 시작되지 않은 배열
// 배열 요소를 추가하거나 삭제했을 때
// length 프로퍼티는 배열 요소의 개수가 아닌, 최대 인덱스 + 1이므로
// 희소배열의 length는 배열 요소 개수보다 커지게 된다.
// 희소배열이 아닌 배열의 length는 배열 요소 개수이다.
// 배열 요소가 있는지 확인 하는 방법
// 1. for in 문으로 모든 요소를 확인한다.
// 2. hasOwnProperty 메서드로 확인한다.