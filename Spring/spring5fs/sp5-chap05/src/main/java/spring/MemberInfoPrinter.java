package spring;

import org.springframework.beans.factory.annotation.*;
import org.springframework.stereotype.*;

@Component("infoPrinter") // 빈 이름 설정
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
