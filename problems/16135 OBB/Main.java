import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.function.BooleanSupplier;
import java.util.function.Predicate;
import java.util.function.Supplier;

public class Main {
    public class Point {
        int x, y;
        Point(int _x, int _y){
            x = _x;
            y = _y;
        }
        Point subtract(Point p) {
            return new Point(this.x-p.x, this.y-p.y);
        }
        Point add(Point p) {
            return new Point(this.x+p.x, this.y+p.y);
        }
        int dot(Point p) {
            int a = this.x*p.x;
            int b = this.y*p.y;
            return Math.abs(a+b);
        }
    }

    public void sol() throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] arr1 = Arrays.stream(br.readLine().split(" ")) // 문자열 배열 스트림 생성
                .mapToInt(Integer::parseInt)     // 각 요소를 정수로 매핑
                .toArray();                       // 배열로 변환
        int[] arr2 = Arrays.stream(br.readLine().split(" ")) // 문자열 배열 스트림 생성
                .mapToInt(Integer::parseInt)     // 각 요소를 정수로 매핑
                .toArray();                       // 배열로 변환
        Point[] p1 = new Point[4];
        Point[] p2 = new Point[4];
        for(int i=0; i<arr1.length; i+=2) {
            p1[i/2] = new Point(arr1[i], arr1[i+1]);
        }
        for(int i=0; i<arr1.length; i+=2) {
            p2[i/2] = new Point(arr2[i], arr2[i+1]);
        }
        Point a1 = p1[0].subtract(p1[1]);
        Point a2 = p1[1].subtract(p1[2]);
        Point c1 = p1[0].add(p1[2]);
        Point b1 = p2[0].subtract(p2[1]);
        Point b2 = p2[1].subtract(p2[2]);
        Point c2 = p2[0].add(p2[2]);

        Point d = c1.subtract(c2);
        Predicate<Point> chek = (u) -> d.dot(u) >= a1.dot(u) + a2.dot(u) + b1.dot(u) + b2.dot(u);
        Point u = p1[0].subtract(p1[1]);
        boolean ret = chek.test(u);
        u = p1[1].subtract(p1[2]);
        ret |= chek.test(u);
        u = p2[1].subtract(p2[2]);
        ret |= chek.test(u);
        u = p2[0].subtract(p2[1]);
        ret |= chek.test(u);
        System.out.println(!ret ? 1 : 0);
    }
    public static void main(String[] args) throws IOException{
        new Main().sol();
    }
}

// 	19004KB	200ms