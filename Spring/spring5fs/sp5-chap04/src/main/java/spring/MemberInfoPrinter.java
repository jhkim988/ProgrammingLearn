package spring;

import org.springframework.beans.factory.annotation.*;

public class MemberInfoPrinter {
	private MemberDao memDao;
	private MemberPrinter printer;
	
	public void printMemberInfo(String email) {
		Member member = memDao.selectByEmail(email);
		if (member == null) {
			System.out.println("데이터 없음\n");
			return;
		}
		printer.print(member);
		System.out.println();
	}
	// 메서드에 @Autowired를 붙이면, 스프링은 해당 메서드를 호출한다.
	// 이 때 파라미터 타입에 해당하는 빈 객체를 찾아 인자로 주입한다.
	@Autowired
	public void setMemberDao(MemberDao memDao) {
		this.memDao = memDao;
	}
	@Autowired
	@Qualifier("printer")
	public void setPrinter(MemberPrinter printer) {
		this.printer = printer;
	}
}
