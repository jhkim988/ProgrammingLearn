package spring;

import org.springframework.transaction.annotation.Transactional;

public class ChangePasswordService {
	private MemberDao memberDao;
	@Transactional
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
