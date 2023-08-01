import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
 
public class Permutation {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long n = Long.parseLong(br.readLine());
 
        if (n == 1) {
            System.out.println(1);
        } else if (n < 4) {
            System.out.println("NO SOLUTION");
        } else if (n == 4) {
            System.out.println("2 4 1 3");
        } else {
            StringBuilder sb = new StringBuilder();
            for (int i = 1; i <= n; i += 2) {
                sb.append(i); sb.append(" ");
            }
            for (int i = 2; i <= n; i += 2) {
                sb.append(i); sb.append(" ");
            }
            System.out.println(sb.toString());
        }
    }
