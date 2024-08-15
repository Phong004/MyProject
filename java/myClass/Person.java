package myClass;

public abstract class Person {
    private String id;
    private String name;
    private int age;
    private double height;
    private double weight;
    private boolean isMale;
    private static int total = 0;
    private int No;
    
    public Person() {}
    public Person(String id, String name, int age, double height, double weight, String gender) {
        this.id = id;
        this.name = name;
        this.age = age;
        this.height = height;
        this.weight = weight;
        if (gender == "male" || gender == "Male" || gender == "m" || gender == "M") {
            isMale = true;
        }
        else if (gender == "female" || gender == "Female" || gender == "f" || gender == "F") {
            isMale = false;
        }
    }
    public void setId(String id) {
        this.id = id;
    }
    public void setName(String name) {
        this.name = name;
    }
    public void setAge(int age) {
        this.age = age;
    }
    public void setAge(double age) {
        this.age = (int)Math.round(age);
    }
    public void setHeight(double height) {
        this.height = height;
    }
    public void setWeight(double weight) {
        this.weight = weight;
    }
    public void setGender(String gender) {
        if (gender == "male" || gender == "Male" || gender == "m" || gender == "M") {
            isMale = true;
        }
        else if (gender == "female" || gender == "Female" || gender == "f" || gender == "F") {
            isMale = false;
        }
    }
    
    public String getId() {
        return id;
    }
    public String getName() {
        return name;
    }
    public int getAge() {
        return age;
    }
    public double getHeight() {
        return height;
    }
    public double getWeight() {
        return weight;
    }
    public String getGender() {
        if (isMale) {
            return "male";
        }
        else {
            return "female";
        }
    }

    public int getNumberof() {
        return No;
    }

    public static int getTotal() {
        return total;
    }

    public void display() {
        total += 1;
        No = total;
        System.out.println("No: " + getNumberof() + ";");
        System.out.println("Id: " + id + "; Name: " + name + "; age: " + age + ";");
        System.out.println("Height: " + (double) Math.round(height*100)/100 + "; Weight: " + (double)Math.round(weight*100)/100 + ";");
        System.out.println("Gender: " + getGender() + ";");
    }
}
