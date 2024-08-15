package myClass;

public class Student extends Person {
    private String major;
    private double gpa;
    
    public Student() {}
    public Student (String id, String name, int age, double height, double weight, String gender, String major, double gpa) {
        super(id, name, age, height, weight, gender);
        this.major = major;
        this.gpa = gpa;
    }

    public void setMajor(String major) {
        this.major = major;
    }
    public void setGpa(double gpa) {
        this.gpa = gpa;
    }

    public String getMajor() {
        return major;
    }
    public double getGpa() {
        return gpa;
    }

    @Override
    public void display() {
        super.display();
        System.out.println("Major: " + major + ";");
        System.out.println("GPA: " + (double)Math.round(gpa*100)/100);
        System.out.println();
    }
}
