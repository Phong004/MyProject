import myClass.Student;
import myClass.Teacher;

public class MainClass {
    public static void main(String[] args) {
        Student sdt = new Student("HE172034", "John", 22, 1.7f, 62.7f, "Male", "Business", 3.7f);
        Student sdt2 = new Student("SE184915", "Phong", 20, 1.7f, 63f, "m", "Information Assurance", 4.0f);
        Teacher t1 = new Teacher("ABC1234", "Mary", 32, 1.75f, 70.3f, "f", "Mathematic", 10000);
        t1.display();
        sdt2.display();
        sdt.display();
    }
}