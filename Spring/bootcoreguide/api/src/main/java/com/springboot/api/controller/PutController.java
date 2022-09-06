package com.springboot.api.controller;

import com.springboot.api.dto.MemberDto;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.Map;

@RestController
@RequestMapping(value="/api/v1/put-api")
public class PutController {
    // http://localhost:8080/v1/put-api/member
    @PutMapping(value="/member")
    public String postMember(@RequestBody Map<String, Object> putData) {
        StringBuilder sb = new StringBuilder();
        putData.entrySet().forEach(map -> {
            sb.append(map.getKey() + ": " + map.getValue());
        });
        return sb.toString();
    }

    // http://localhost:8080/v1/put-api/member1
    @PutMapping(value="/member1")
    public String postMember1(@RequestBody MemberDto memberDto) {
        return memberDto.toString(); // content-type: text/plain
    }

    // http://localhost:8080/put-api/member2
    @PutMapping(value="/member2")
    public MemberDto postMember2(@RequestBody MemberDto memberDto) {
        return memberDto; // content-type: application/json
    }

    // http://localhost:8080/put-api/member3
    @PutMapping(value="/member3")
    public ResponseEntity<MemberDto> postMember3(@RequestBody MemberDto memberDto) {
        return ResponseEntity
                .status(HttpStatus.ACCEPTED)
                .body(memberDto);
    }
}
