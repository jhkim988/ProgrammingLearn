<%@ page contentType="text/html; charset=utf-8"%>
<!DOCTYPE>
<html>
<head><title>설문조사</title></head>
<body>
<h2>설문조사</h2>
<form method="post">
	<p>1. 당신의 역할은?
	<label><input type="radio" name="responses[0]" value="서버">서버개발자</label>
	<label><input type="radio" name="responses[0]" value="프론트">프론트개발자</label>
	<label><input type="radio" name="responses[0]" value="풀스택">풀스택개발자</label>
	</p>
	<p>2. 가장 많이 사용하는 개발도구는?
	<label><input type="radio" name="responses[1]" value="Eclipse">이클립스</label>
	<label><input type="radio" name="responses[1]" value="Intellij">인텔리제이</label>
	<label><input type="radio" name="responses[1]" value="Sublime">서브라임</label>
	</p>
	<p>3. 하고싶은 말
	<input type="text" name="responses[2]">
	</p>
	<p>
	<label>응답자 위치:</label>
	<input type="text" name="res.location">
	</p>
	<p>
	<label>응답자 나이:</label>
	<input type="text" name="res.age">
	</p>
	<input type="submit" value="전송">
</form>
</body>
</html>