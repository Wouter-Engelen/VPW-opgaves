# Java-Specific Advice

* You can only submit a single file.
* This file must contain a class named `Main`.
* Given the restrictions that Java imposes, you might want to rely on [nested classes](https://docs.oracle.com/javase/tutorial/java/javaOO/nested.html) in case you want to work with multiple classes.

```java
public class Main
{
    public static void main(String[] args)
    {
        OtherClass oc = new OtherClass();
    }

    // Don't forget static!
    public static class OtherClass
    {

    }
}
```




## Reading From STDIN

```java
import java.util.Scanner;

public class Main
{
    public static void main(String[] args)
    {
        // Create scanner object
        Scanner scanner = new Scanner(System.in);

        // Read an integer
        int i = scanner.nextInt();

        // Read an entire line
        String line = scanner.nextLine();
    }
}
```

## Flushing
Use [`System.out.flush()`](https://docs.oracle.com/javase/7/docs/api/java/io/OutputStream.html#flush()) to force output to be written. We advice you to call it each time you solved one of the cases in the input file.

```java
System.out.flush();
```

## Command Line

Compiling:

```bash
# Compilatie
$ javac Main.java

# Uitvoer solver laten afprinten
$ cat voorbeeld.invoer | java Main

# Uitvoer solver vergelijken met verwachte uitvoer
$ cat voorbeeld.invoer | java Main | diff -w - voorbeeld.uitvoer
```