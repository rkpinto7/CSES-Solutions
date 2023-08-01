import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class IncreasingArray {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in), 1);
        long n = Integer.parseInt(br.readLine());
        long ans = 0,x=0,y;
        if(n == 1)
        {
            System.out.println(ans);
            return;
        }
        StringTokenizer st = new StringTokenizer(br.readLine());
        boolean isFirst = true;
        while(st.hasMoreTokens()) {
            if(isFirst) {
                x =  Long.parseLong(st.nextToken()) ;
                isFirst = false;
            }
            y = Long.parseLong(st.nextToken()) ;
            if(y < x) {
                ans += (x - y);
                y = x;
            } else x = y;



        }
        System.out.println(ans);
    }
}
