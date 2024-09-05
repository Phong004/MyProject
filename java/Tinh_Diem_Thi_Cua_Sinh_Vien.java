import java.util.*;

class Tind_Diem_Thi_Cua_Sinh_Vien {
    double getAverageScore(int[] a) {
        double result=0;
        for (int i=0; i<a.length; i++) {
            result += a[i]/a.length;
        }
        return result;
    }
    char computeGrade(double x) {
        char result;
        if (x >= 80) result = 'A';
        else if (x >= 60) result = 'B';
        else if (x >= 50) result = 'C';
        else result= 'F';
        return result;
    }

    public static void main(String[] args) {
        Tind_Diem_Thi_Cua_Sinh_Vien obj = new Tind_Diem_Thi_Cua_Sinh_Vien();

        Scanner sc = new Scanner(System.in);
        int scores[] = new int[5];
        for (int i=0; i<5; i++) {
            scores[i] = sc.nextInt();
        }
        sc.close();
        double avgScore = obj.getAverageScore(scores);
        char grade = obj.computeGrade(avgScore);
        System.out.println(avgScore);
        System.out.println(grade);
    }
}
