// 객체지향 프로그래밍(OOP)
// OOP에서 Object는 JS의 object와 다르다. (개념적 접근)
// 행위(Behavior)와 속성(Attribute)으로 객체의 특성을 표현한다.
// 객체 - Class, 행위 - method, 속성 - property
{
  class Point { // class 선언, 엔진이 class 키워드를 만나면 클래스 오브젝트를 생성한다.
    constructor(point) { // 생성자
      this.point = point;
    }
    getPoint() { // method
      return this.point;
    }
  }

  const obj = new Point(100); // constructor 호출, parameter 값을 넘겨준다. 인스턴스를 반환하여 obj에 할당한다.
  console.log(obj.getPoint()); // method 호출
  console.log(obj.point); // property 호출
}
// JS의 OOP 구현
// 다른 언어와 OOP 개념은 같지만, 클래스 구조와 구현 방법은 다르다.
// prototype에 메서드를 연결하는 구조
// 연결된 메서드로 인스턴스 생성

// 1. class Point 선언
// Point에는 property, prototype, __proto__가 있다.
// prototype을 펼치면 constructor와 getPoint()가 있다.
// 클래스에 메서드를 작성하면 prototype에 연결된다.
// Point.prototype.getPoint = function() {}; 으로 작성한 것과 똑같다.
// __proto__에서 built-in Function object의 prototype에 연결된 메서드를 참조한다.

// 2. Instance 생성
// Point class의 constructor를 호출한다.(작성하지 않으면 default 호출)
// obj에는 __proto__가 있다. Point class의 prototype에 있는 constructor, getPoint를 첨부시킨다.


// class는 strict 모드에서 실행된다.
// console.log(typeof Point); // function. Class 타입이 별도로 존재하지 않는다.

// Computed name
// 메서드 이름을 조합하여 사용한다.
// 대괄호 [] 안에 조합할 이름을 작성한다.
// 조합한 결과가 메서드 이름이 된다.
{
  const name = "Point";
  class Point {
    // class를 오브젝트로 만드는 시점에 method 이름이 결정된다.
    // 따라서, 이후에 name 변수를 바꾸거나, name 변수를 나중에 선언/할당한다면 제대로 동작하지 않을 수 있다.

    // static - 정적 메서드
    static["get" + name](add) { // method 이름을 변수로 처리할 수 있다.
      return add ? 100 : 50
    }
  }
  console.log(Point["get" + name](true)); // 정적메서드를 호출하는 방법 - className[methodName] / className.methodName
}

{
  class Point {
    setPoint(point) {
      this.point = point;
    }
  }
  console.log(Point.prototype.setPoint);
}

{
  class Point {};
  const obj = new Point();
  Point.prototype.getPoint = function () { // prototype에 추가한다.
    return 100;
  }
  console.log(obj.getPoint()); // 생성된 모든 인스턴스에서 사용할 수 있다. 이를 prototype sharing이라고 한다.
}


// ES5 - constructor 작성 불가
// ES6 - constructor 작성 가능
{
  class Point {
    constructor(point) {
      this.point = point;
    }
  }

  const obj = new Point(100); // constructor 호출, parameter 넘겨준다.
  // 엔진은 빈 오브젝트 { }를 만든다.(인스턴스)
  // 인스턴스에 프로퍼티 이름과 값을 설정하여 인스턴스 구조를 만든다.
  // __proto__, __proto__.constructor 등...
  // constructor 블럭 실행 (this.point = point)
  // this는 위에서 새로 만든 빈 오브젝트를 참조한다.
  // this.point는 인스턴스의 프로퍼티가 된다. { point : 100 }
  // 생성한 인스턴스를 반환한다.
  console.log(obj.point);
}

// constructor를 작성하지 않으면 prototype에 연결된 constructor가 호출된다.
// 엔진이 class 키워드를 만나 Point 클래스 오브젝트를 생성할 때
// constructor에서 클래스 전체를 참조하도록 환경을 만든다.
// constructor를 작성하지 않으면, prototype.constructor를 사용하므로, 인스턴스를 생성해도 초깃값을 설정할 수 없다.
// constructor를 작성하면 prototype.constructor를 override하게 된다.

// constructor에서 return을 작성하지 않으면 생성한 인스턴스를 반환한다.
// constructor에서 Number, String을 반환하면 이를 무시하고 인스턴스를 반환한다.
// constructor에서 Object를 반환하면, 인스턴스를 반환하지 않고 Object를 반환한다.


// getter - method를 호출하여 값을 구한다.
