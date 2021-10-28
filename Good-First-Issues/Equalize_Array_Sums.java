import java.util.Arrays;

public class Solution {
    public static int calc(int[] a, int[] b) {
        int sumA = Arrays.stream(a).sum();
        Arrays.sort(a);

        int sumB = Arrays.stream(b).sum();
        Arrays.sort(b);

        if(Math.min(a.length, b.length)*6 < Math.max(a.length, b.length)) return -1;
        if (sumA > sumB) {return calc(b, a);}
        if (sumA == sumB) return 0;

        int totalSum = 0, x = 0, y = b.length-1;

        while (sumA != sumB && y >= 0 && x <= a.length) {
            int diff = sumB - sumA;
            int dA = 6 - a[x];
            int dB = b[y] - 1;

            if(dA >= dB) {
                sumA += Math.min(diff, dA);
                x++;
            } else {
                sumB -= Math.min(diff, dB);
                y--;
            }
            totalSum++;
        }
        System.out.println(totalSum);
        return totalSum;
    }
}
                                                                                                           