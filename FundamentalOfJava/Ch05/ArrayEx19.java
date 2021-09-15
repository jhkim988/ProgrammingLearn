public class ArrayEx19 {
  public static void main(String[] args) {
    int[][] score = {
      {100, 100, 100},
      {20, 20, 20},
      {30, 30, 30},
      {40, 40, 40},
      {50, 50, 50}
    };

    int korTotal = 0, engTotal = 0, mathTotal = 0;
    System.out.println("번호\t국어\t영어\t수학\t총점\t평균\t");
    System.out.println("===========================================================");
    for (int i = 0; i < score.length; i++) {
      int sum = 0;
      float avg = 0.0f;
      korTotal += score[i][0];
      engTotal += score[i][1];
      mathTotal += score[i][2];
      System.out.printf("%d\t", i + 1);
      for (int j = 0; j < score[i].length; j++) {
        sum += score[i][j];
        System.out.printf("%d\t", score[i][j]);
      }
      avg = sum / (float) score[i].length;
      System.out.printf("%d\t%.1f\t\n", sum, avg);

    }
    System.out.println("===========================================================");
    System.out.printf("총점:\t%d\t%d\t%d\n", korTotal, engTotal,mathTotal);
  }  
}
