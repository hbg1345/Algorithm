import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import static java.lang.Math.abs;

public class Main {
    private void sol() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n, s;
        n = Integer.parseInt(br.readLine());
        s = Integer.parseInt(br.readLine());
        int sum = n*(n-1)/2;
        int as = abs(s);
        if (sum < as) {
            System.out.println("NIE");
            return;
        }
        int d = sum - as;
        if (d % 2 == 1) {
            System.out.println("NIE");
            return;
        }
        d >>= 1;
        int[] ans = new int[n];
        for(int i=1; i<n; i++) {
            if (d >= n-i) {
                ans[i] = -1; d -= n-i;
            } else ans[i] = 1;
            ans[i] += ans[i-1];
        }
        for(int i:ans) {
            System.out.println(( s > 0 ? i:-i));
        }
    }

    public static void main(String[] args) throws IOException{
        new Main().sol();
    }
}
