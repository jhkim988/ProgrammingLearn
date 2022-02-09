package hello.hellospring.controller;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;

@Controller
public class HelloController {
    // 1. 웹브라우저에서 localhost:8080/hello 로 접속한다.
    // 2. 톰캣 서버가 GetMapping("hello")를 찾아 메서드를 실행한다.
    @GetMapping("hello")
    public String hello(Model model) {
        // 3. "data"라는 속성에 "hello!!"라는 값을 넣어준다.
        model.addAttribute("data", "hello!!");

        // 4. 렌더링할 파일의 이름을 리턴한다.(hello.html)
        return "hello";
        // 5. resources/templates/hello 를 찾아 렌더링한다.

        // 컨트롤러에서 리턴 값으로 문자열을 반환하면 뷰 리졸버가 화면을 찾아 처리한다.
        // spring-boot-devtools 라이브러리를 이용하면 html 파일을 컴파일만 해주면 서버 재시작 없이 view 파일 변경이 가능하다.

        // 빌드/실행 방법:
        // 1. ./gradlew.bat build 실행
        // 2. cd ./build/libs/
        // 3. java -jar hello-spring-0.0.1-SNAPSHOT.jar
        // 서버에서 .jar 파일을 옮겨서 실행만 하면 된다.

        // ./gradlew.bat clean: 빌드된 폴더를 삭제한다.
    }

    // 1. 브라우저에서 /hello-mvc 접속
    // 2. 톰캣 서버가 스프링 컨테이너로 넘겨준다.
    // 3. helloController 에서 발견, 메서드 호출
    // 4. return html 파일 이름, name 값을 뷰 리졸버로 넘겨준다.
    // 5. 뷰 리졸버가 리턴값과 이름이 같은 html 파일을 찾고 템플릿 엔진에 넘겨준다.
    // 6. 템플릿 엔진이 변환을 한 후 보내준다.
    @GetMapping("hello-mvc")
    public String helloMvc(@RequestParam(name = "name", required = false) String name, Model model) {
        model.addAttribute("name", name);
        return "hello-template";
    }

    // ResponseBody:
    // http 통신의 헤더와 바디에서, 바디에 데이터를 직접 추가한다.
    @GetMapping("hello-string")
    @ResponseBody
    public String helloString(@RequestParam("name") String name) {
        return "hello " + name; // hello string
    } // 반환값이 문자인 경우에는 문자를 http 응답에 바로 넣는다.

    @GetMapping("hello-api")
    @ResponseBody
    public Hello helloApi(@RequestParam("name") String name) {
        Hello hello = new Hello();
        hello.setName(name);
        return hello; // json
    } // 반환값이 객체인 경우에는 JSON 방식으로 응답에 반환한다.
    static class Hello {
        private String name;
        
        // java bean 규약
        public String getName() {
            return name;
        }

        public void setName(String name) {
            this.name = name;
        }
    }
    // @ResponseBody 가 있으면 viewResolver 대신 httpMessageConverter 가 동작한다.
    // 반환값이 문자열인 경우: StringConverter
    // 반환값이 객체인 경우: JsonConverter(객체를 JSON 으로 바꿔주는 라이브러리... Jackson2)
    // 클라이언트의 HTTP Accept 헤더에서 받을 데이터의 포맷을 정할 수 있다.(XML 등)
}
