package spring;

import org.springframework.beans.factory.annotation.*;
import org.springframework.stereotype.*;

@Component
public class ChangePasswordService {
	@Autowired
	private MemberDao memberDao;
	public void changePassword(String email, String oldPwd, String newPwd) {
		Member member = memberDao.selectByEmail(email);
		if (member == null) throw new MemberNotFoundException();
		if (!member.getPassword().equals(oldPwd)) throw new WrongIdPasswordException();
		member.changePassword(oldPwd, newPwd);
		memberDao.update(member);
	}
	public void setMemberDao(MemberDao memberdao) {
		this.memberDao = memberdao;
	}
}
