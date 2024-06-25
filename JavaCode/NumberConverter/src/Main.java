import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.println("Select language:");
            System.out.println("1. English");
            System.out.println("2. Bahasa Indonesia");
            System.out.println("3. Exit");

            int choice = scanner.nextInt();
            scanner.nextLine(); // Consume newline

            if (choice == 3) {
                System.out.println("Exiting...");
                break;
            }

            System.out.print("Enter number: ");
            String input = scanner.nextLine();

            try {
                String language = choice == 1 ? "en" : "ina";
                System.out.println(convertNumberToWords(input, language));
            } catch (Exception e) {
                System.out.println(e.getMessage());
            }
        }

        scanner.close();
    }

    public static String convertNumberToWords(String number, String language) throws Exception {
        if (!isValidNumber(number)) {
            throw new Exception("Invalid input. Please enter a positive integer between 1 and 66 digits.");
        }

        NumberToWords converter;
        switch (language.toLowerCase()) {
            case "en":
                converter = new EnglishNumberToWords();
                break;
            case "ina":
                converter = new IndonesianNumberToWords();
                break;
            default:
                throw new Exception("Unsupported language. Currently supported: en, ina");
        }

        return converter.convert(number).trim();
    }

    private static boolean isValidNumber(String number) {
        return number.matches("\\d{1,66}");
    }
}
