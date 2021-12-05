import java.util.*;

public class ScannerEx1 {
  public static void main(String[] args) {
    // // JDK 1.5 이전
    // try {
    //   BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    //   String input1 = br.readLine();
    // } catch (IOException e) { }

    // // JDK 1.5 이후
    // Scanner s = new Scanner(System.in);
    // String input2 = s.nextLine();

    // // JDK 1.6 이후
    // Console console = System.console();
    // String input3 = console.readLine();
  
      Scanner s = new Scanner(System.in);
      String[] argArr = null;

      while (true) {
        String prompt = ">>";
        System.out.print(prompt);

        String input = s.nextLine();
        input = input.trim();
        argArr = input.split(" +"); // regex

        String command = argArr[0].trim();
        if ("".equals(command)) continue;

        if (command.equals("q")) {
          System.exit(0);
        } else {
          for (int i = 0; i < argArr.length; i++) 
            System.out.println(argArr[i]);
        }
      }
  }
}