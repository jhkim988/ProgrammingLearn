<%@ page contentType = "text/html; charset=utf-8" %>
<!DOCTYPE>
<html>
	<head>
		<title>회원가입</title>
	</head>
	<body>
		<h2>회원 정보 입력</h2>
		<form action="step3" method="post">
		<p>
			<label>이메일:
			<input type="text" name="email" id="email">
			</label>
		</p>
		<p>
			<label>이름:
			<input type="text" name="name" id="name">
			</label>
		</p>
		<p>
			<label>비밀번호:
			<input type="text" name="password" id="password">
			</label>
		</p>
		<p>
			<label>비밀번호 확인:
			<input type="text" name="confirmPassword" id="confirmPassword">
			</label>
		</p>
		<input type="submit" value="가입완료">
		</form>
	</body>
</html>