package spring;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Timestamp;
import java.time.LocalDateTime;
import java.util.Collection;
import java.util.List;

import javax.sql.DataSource;

import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.jdbc.core.PreparedStatementCreator;
import org.springframework.jdbc.core.RowMapper;
import org.springframework.jdbc.support.GeneratedKeyHolder;
import org.springframework.jdbc.support.KeyHolder;


public class MemberDao {
	private JdbcTemplate jdbcTemplate;
	private RowMapper<Member> memRowMapper = new RowMapper<Member>() {
		@Override
		public Member mapRow(ResultSet rs, int rowNum) throws SQLException {
			Member member = new Member(
					rs.getString("EMAIL"),
					rs.getString("PASSWORD"),
					rs.getString("NAME"),
					rs.getTimestamp("REGDATE").toLocalDateTime());
			member.setId(rs.getLong("ID"));
			return member;
		}
	};
	
	public MemberDao(DataSource dataSource) {
		this.jdbcTemplate = new JdbcTemplate(dataSource);
	}
	
	public Member selectByEmail(String email) {
		List<Member> results = jdbcTemplate.query("select * from MEMBER where EMAIL = ?",	memRowMapper, email);
		return results.isEmpty() ? null : results.get(0);
	}
	public void insert(Member member) {
		KeyHolder keyHolder = new GeneratedKeyHolder(); // 자동으로 생성된 키값을 구해준다.
		jdbcTemplate.update(new PreparedStatementCreator() {
			@Override
			public PreparedStatement createPreparedStatement(Connection conn) throws SQLException {
				PreparedStatement pstmt = conn.prepareStatement(
						"insert into MEMBER (EMAIL, PASSWORD, NAME, REGDATE) values(?, ?, ?, ?)",
						new String[] {"ID"});
				pstmt.setString(1,  member.getEmail());
				pstmt.setString(2,  member.getPassword());
				pstmt.setString(3,  member.getName());
				pstmt.setTimestamp(4, Timestamp.valueOf(member.getRegisterDateTime()));
				return pstmt;
			}
		}, keyHolder);
		Number keyValue = keyHolder.getKey();
		member.setId(keyValue.longValue());
	}
	public void update(Member member) {
		jdbcTemplate.update("update Member set NAME = ?, PASSWORD = ? WHERE EMAIL = ?",
				member.getName(), member.getPassword(), member.getEmail());

		// 직접 파라미터값을 변경하고 싶다면
//		jdbcTemplate.update(new PreparedStatementCreator() {
//			@Override
//			public PreparedStatement createPreparedStatement(Connection con) throws SQLException {
//				PreparedStatement pstmt = con.prepareStatement("insert info MEMBER (EMAIL, PASSWORD, NAME, REGDATE) value(?, ?, ?, ?)");
//				pstmt.setString(1, member.getEmail());
//				pstmt.setString(2, member.getPassword());
//				pstmt.setString(3, member.getName());
//				pstmt.setString(4, Timestamp.valueOf(member.getRegisterDateTime()));
//				return pstmt;
//			}
//		});
	}
	public Collection<Member> selectAll() {
		return jdbcTemplate.query("select * from MEMBER", memRowMapper);
	}
	public int count() {
		// queryForObject 는 결과가 1행인 경우에 사용할 수 있다. 0개나 2개 이상이면 Exception 발생한다.
		int count = jdbcTemplate.queryForObject("select count(*) from MEMBER", Integer.class);
		return count;
	}
	
	public List<Member> selectByRegdate(LocalDateTime from, LocalDateTime to) {
		List<Member> results = jdbcTemplate.query(
			"select * from MEMBER where REGDATE between ? and ? order by REGDATE desc",
			memRowMapper, from, to);
		return results;
	}
	
	public Member selectById(Long memId) {
		List<Member> result = jdbcTemplate.query("select * from MEMBER where ID = ?", memRowMapper, memId);
		return result.isEmpty() ? null : result.get(0);
	}
}
