import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class WeirdAlgorithm {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long n = Integer.parseInt(br.readLine());
        StringBuilder ans = new StringBuilder();
        while(n != 1) {
            System.out.print(n + " ");
            if(n%2 == 0)
                n = n/2;
            else n = 3*n + 1;
        }
        System.out.print(1);

    }
}

