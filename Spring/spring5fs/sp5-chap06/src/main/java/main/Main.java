package main;

import java.io.*;

import org.springframework.context.annotation.*;
import org.springframework.context.support.*;

import config.AppCtx;
import spring.Client;

public class Main {
	public static void main(String[] args) throws IOException {
		AbstractApplicationContext ctx = new AnnotationConfigApplicationContext(AppCtx.class);
		Client client = ctx.getBean(Client.class);
		client.send();
		ctx.close();
	}
}
