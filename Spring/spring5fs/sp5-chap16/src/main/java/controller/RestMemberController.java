package controller;

import java.io.IOException;
import java.util.List;

import javax.servlet.http.HttpServletResponse;
import javax.validation.Valid;

import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.ExceptionHandler;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RestController;

import spring.DuplicateMemberException;
import spring.Member;
import spring.MemberDao;
import spring.MemberNotFoundException;
import spring.MemberRegisterService;
import spring.RegisterRequest;

@RestController
public class RestMemberController {
	private MemberDao memberDao;
	private MemberRegisterService registerService;
	
	public void setMemberDao(MemberDao memberDao) {
		this.memberDao = memberDao;
	}
	public void setRegisterService(MemberRegisterService registerService) {
		this.registerService = registerService;
	}
	
	@GetMapping("/api/members")
	public List<Member> members() {
		return (List<Member>) memberDao.selectAll();
	}
	
	@GetMapping("/api/members/{id}")
	public Member member(@PathVariable Long id, HttpServletResponse response) throws IOException {
		Member member = memberDao.selectById(id);
		if (member == null) {
			response.sendError(HttpServletResponse.SC_NOT_FOUND);
			return null;
		}
		return member;
	}
	// Use ResponseEntity
//	@GetMapping("/api/members/{id}")
//	public ResponseEntity<Object> member(@PathVariable Long id) {
//		Member member = memberDao.selectById(id);
//		if (member == null) {
//			return ResponseEntity.status(HttpStatus.NOT_FOUND).body(new ErrorResponse("no member"));
//		}
//		return ResponseEntity.status(HttpStatus.OK).body(member);
//	}
	
	@PostMapping("/api/members")
	public void newMember(@RequestBody @Valid RegisterRequest regReq, HttpServletResponse response) throws IOException {
		try {
			Long newMemberId = registerService.regist(regReq);
			response.setHeader("Location", "/api/members/" + newMemberId);
			response.setStatus(HttpServletResponse.SC_CREATED);
		} catch (DuplicateMemberException dupEx) {
			response.sendError(HttpServletResponse.SC_CONFLICT);
		}
	}
	// Use ResponseEntity
//	@PostMapping("/api/members")
//	public ResponseEntity<Object> newMember(@RequestBody @Valid RegisterRequest regReq) {
//		try {
//			Long newMemberId = registerService.regist(regReq);
//			URI uri = URI.create("/api/members/" + newMemberId);
//			return ResponseEntity.created(uri).build();
//		} catch (DuplicateMemberException ex) {
//			return ResponseEntity.status(HttpStatus.CONFLICT).build();
//		}
//	}
	
	// @Valid 에서 Exception 발생하는 경우.
	// (1) Errors 타입 파라미터를 추가해서 hasErrors()를 이용해 예외처리한다.
	// (2) MethodArgumentNotValidException이 발생하므로, ExceptionHandler 메서드를 만들어서 처리한다.

	// 회원이 존재하지 않을 때의 에러응답을 따로 만들어서 코드 중복을 줄인다.
	// 존재하지 않을 때 MemberNotFoundException을 throw 하도록 하면 아래 메서드가 실행된다.
	@ExceptionHandler(MemberNotFoundException.class)
	public ResponseEntity<ErrorResponse> handleNoData() {
		return ResponseEntity.status(HttpStatus.NOT_FOUND).body(new ErrorResponse("no member"));
	}
}
