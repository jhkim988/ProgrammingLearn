package spring;

import org.springframework.beans.factory.annotation.*;
import java.util.*;
import org.springframework.stereotype.*;

@Component("listPrinter")
public class MemberListPrinter {
	private MemberDao memberDao;
	private MemberPrinter printer;
	public MemberListPrinter() {}
	public MemberListPrinter(MemberDao memberDao, MemberPrinter printer) {
		this.memberDao = memberDao;
		this.printer = printer;
	}
	public void printAll() {
		Collection<Member> members = memberDao.selectAll();
		members.forEach(m -> printer.print(m));
	}
	@Autowired
	public void setMemberDao(MemberDao memberDao) {
		this.memberDao = memberDao;
	}
	@Autowired
	@Qualifier("summaryPrinter") // 혹은 입력받는 파라미터 타입을 MemberSummaryPrinter로 바꿔준다.
	public void setMemberPrinter(MemberPrinter printer) {
		this.printer = printer;
	}
}
