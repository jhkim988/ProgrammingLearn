package Lecture07;

import java.util.*;

public class BankerAlgorithm {
  public static  void main(String[] args) {
    int numT = 5;
    int numR = 3;
    int[] r = {10, 5, 7};
    int[][] alloc = {{0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2}};
    int[][] max = {{7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3}};
    int[] available = new int[numR];
    for (int i = 0; i < numR; i++) {
      int sumAlloc = 0;
      for (int j = 0; j < numT; j++) {
        sumAlloc += alloc[j][i];
      }
      available[i] = r[i] - sumAlloc;
    }
    int[][] need = new int[numT][numR];
    for (int i = 0; i < numT; i++) {
      for (int j = 0; j < numR; j++) {
        need[i][j] = max[i][j] - alloc[i][j];
      }
    }
    boolean[] finish = new boolean[numT];
    int[] work = new int[numR];
    Arrays.fill(finish, false);
    System.arraycopy(available, 0, work, 0, numR);
    int numTrue = 0;
    while (true) {
      nextT: for (int i = 0; i < numT; i++) {
        if (finish[i]) continue;
        for (int j = 0; j < numR; j++) {
          if (need[i][j] > work[j]) continue nextT;
        }
        for (int j = 0; j < numR; j++) {
          work[j] += alloc[i][j];
        }
        finish[i] = true;
        numTrue++;
        System.out.println("Safe seq: " + i);
      }
      if (numTrue >= numT) break;
    }
  }
}