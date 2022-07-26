package controller;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;

import spring.DuplicateMemberException;
import spring.MemberRegisterService;
import spring.RegisterRequest;

@Controller
public class RegisterController {
	private MemberRegisterService memberRegisterService;
	
	@RequestMapping("/register/step1")
	public String handleStep1() {
		return "register/step1";
	}
	
	// 1. HttpServletRequest 를 직접 이용하는 방법
//	@PostMapping("/register/step2")
//	public String handleStep2(HttpServletRequest request) {
//		String agreeParam = request.getParameter("agree");
//		if (agreeParam == null || !request.getParameter("value").equals("true")) {
//			return "register/step1";
//		}
//		return "register/step2";
//	}
	
	// 2. @RequestParam 을 이용하는 방법
	@PostMapping("/register/step2")
	public String handleStep2(@RequestParam(value="agree", defaultValue="false") Boolean agree) {
		if (!agree) {
			return "redirect:/register/step1";
		}
		return "register/step2";
	}
	
	@GetMapping("/register/step2")
	public String handle2Get() {
		return "redirect:/register/step1";
	}
	
	public void setMemberRegisterService(MemberRegisterService memberRegisterService) {
		this.memberRegisterService = memberRegisterService;
	}
	
	@PostMapping("/register/step3")
	public String handleStep3(RegisterRequest regReq) {
		try {
			memberRegisterService.regist(regReq);
			return "register/step3";
		} catch (DuplicateMemberException ex) {
			return "register/step2";
		}
	}
}
