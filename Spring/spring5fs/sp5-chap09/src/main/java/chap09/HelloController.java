package chap09;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestParam;

@Controller // 요청을 처리하고 결과를 뷰에 전달하는 빈 객체
public class HelloController {
	
	@GetMapping("/hello")
	public String hello(Model model, @RequestParam(value="name", required=false) String name) {
		model.addAttribute("greeting", "안녕하세요, " + name); // "greeting" 모델 속성에 값(안녕하세요, + name)을 설정한다.
		return "hello"; // view의 이름
	}
}
