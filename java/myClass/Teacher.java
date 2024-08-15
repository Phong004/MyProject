package myClass;

public class Teacher extends Person {
    private String subject;
    private double salary;

    public Teacher(){}
    public Teacher(String id, String name, int age, double height, double weight, String gender, String subject, double salary) {
        super(id, name, age, height, weight, gender);
        this.subject = subject;
        this.salary = salary;
    }

    public void setSubject(String subject) {
        this.subject = subject;
    }
    public void setSalary(double salary) {
        this.salary = salary;
    }

    public String getSubject() {
        return subject;
    }
    public double getSalary() {
        return salary;
    }

    public void display() {
        super.display();
        System.out.println("Subject: " + getSubject());
        System.out.println("Salary: " + getSalary());
        System.out.println();
    }
}
