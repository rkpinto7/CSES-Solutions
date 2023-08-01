import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class LongestRepeatingSubstring {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = br.readLine();
        int longestSize = 1, currentSize = 1;
        for (int i = 1; i < input.length(); i++) {
            if (input.charAt(i) == input.charAt(i - 1)) {
                currentSize++;
                longestSize = Math.max(longestSize, currentSize);
            } else {
                currentSize = 1;
            }
        }
        System.out.println(longestSize);
    }
}
