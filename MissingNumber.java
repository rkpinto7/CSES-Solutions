import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class MissingNumber {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long n = Long.parseLong(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        long sumToN = n*(n+1)/2, sumOfInput = 0;
        while (st.hasMoreTokens()) {
            sumOfInput += Long.parseLong(st.nextToken());
        }
        System.out.println(sumToN - sumOfInput);

    }
}
