package spring;

import java.time.format.DateTimeFormatter;
import org.springframework.beans.factory.annotation.*;

public class MemberPrinter {
	private DateTimeFormatter dateTimeFormatter;
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
		// Optional<DateTimeFormatter>를 이용해도 된다. Optioinal#isPresent() 메서드를 이용한다.
		// @Nullable 을 이용해도 된다.
		
		// @Autowired(required=false)와 @Nullable의 차이:
		// 전자는 대상 빈이 존재하지 않으면 메서드를 실행하지 않는다. 후자는 메서드를 실행한다.
		this.dateTimeFormatter = dateTimeFormatter;
	}
}
