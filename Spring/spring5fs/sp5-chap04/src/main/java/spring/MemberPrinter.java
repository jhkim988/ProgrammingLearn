package spring;

import java.util.*;
import java.time.format.DateTimeFormatter;
import org.springframework.beans.factory.annotation.*;

public class MemberPrinter {
	private DateTimeFormatter dateTimeFormatter;
	
	// 기본 생성자에서 초기화한다면, dateTimeFormatter 값이 null이 아니게 된다.
	// Autowired(required=false)는 일치하는 빈이 존재하지 않으면 실행하지 않는 것을 확인할 수 있다.
	public MemberPrinter() {
		dateTimeFormatter = DateTimeFormatter.ofPattern("yyyy년 MM월 dd일");
	}
	
	public void print(Member member) {
		if (dateTimeFormatter == null) {
			System.out.printf("회원 정보: 아이디=%d, 이메일=%s, 이름=%s, 등록일=%tF\n",
					member.getId(), member.getEmail(), member.getName(), member.getRegisterDateTime());	
		} else {
			System.out.printf("회원 정보: 아이디=%d, 이메일=%s, 이름=%s, 등록일=%s\n",
					member.getId(), member.getEmail(), member.getName(), dateTimeFormatter.format(member.getRegisterDateTime()));
		}
	}
	@Autowired(required=false) // 자둥주입이 필수가 아닐 때, 매칭되는 빈이 없어도 익셉션이 발생하지 않고, 자동주입을 수행하지 않는다.
	public void setDateFormatter(DateTimeFormatter dateTimeFormatter) {		
		// @Autowired(required=false)와 @Nullable의 차이:
		// 전자는 대상 빈이 존재하지 않으면 메서드를 실행하지 않는다. 후자는 메서드를 실행한다.
		this.dateTimeFormatter = dateTimeFormatter;
	}
	
	// Optional 사용:
	// 일치하는 빈이 없으면, 값이 없는 Optional을 할당한다.
//	private Optional<DateTimeFormatter> formatterOpt;
//	@Autowired
//	public void setDateFormatter(Optional<DateTimeFormatter> formatterOpt) {
//		if (formatterOpt.isPresent()) {
//			this.dateTimeFormatter = formatterOpt.get();
//		} else {
//			this.dateTimeFormatter = null;
//		}
//	}
//	public void print(Member member) {
//		DateTimeFormatter dateTimeFormatter = formatterOpt.orElse(null);
//		if (dateTimeFormatter == null) {
//			// ...
//		} else {
//			// ...
//		}
//	}

	// Nullable 사용:
	// @Nullable을 사용할 경우, 자동으로 주입할 빈이 존재하지 않으면 null을 인자로 전달한다ㅏ.
//	@Autowired
//	public void setDateFormatter(@Nullable DateTimeFormatter dateTimeformatter) {
//		this.dateTimeFormatter = dateTimeFormatter;
//	}
}
