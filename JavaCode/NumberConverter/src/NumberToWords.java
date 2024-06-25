import java.util.Map;

public abstract class NumberToWords {
    protected Map<Integer, String> units;
    protected Map<Integer, String> tens;
    protected Map<Integer, String> thousands;

    public abstract String convert(String number);

    protected String convertLessThanOneThousand(int number, String hundred) {
        String current;

        if (number % 100 < 20) {
            current = units.get(number % 100);
            number /= 100;
        } else {
            current = units.get(number % 10);
            number /= 10;

            current = tens.get(number % 10) + " " + current;
            number /= 10;
        }
        if (number == 0) return current;
        return units.get(number) + " " + hundred + " " + current;
    }
}
