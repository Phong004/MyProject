public class Test {
    public static void main(String[] args) {
        int[] numbers = { 55, 64, 75, 80, 65 };
        int[] newNumbers = numbers;
        for (int a: newNumbers) {
            System.out.println(a);
        }
    }
}
