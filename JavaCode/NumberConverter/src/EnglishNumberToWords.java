import java.util.HashMap;

public class EnglishNumberToWords extends NumberToWords {

    public EnglishNumberToWords() {
        units = new HashMap<>();
        tens = new HashMap<>();
        thousands = new HashMap<>();

        units.put(0, "");
        units.put(1, "one");
        units.put(2, "two");
        units.put(3, "three");
        units.put(4, "four");
        units.put(5, "five");
        units.put(6, "six");
        units.put(7, "seven");
        units.put(8, "eight");
        units.put(9, "nine");
        units.put(10, "ten");
        units.put(11, "eleven");
        units.put(12, "twelve");
        units.put(13, "thirteen");
        units.put(14, "fourteen");
        units.put(15, "fifteen");
        units.put(16, "sixteen");
        units.put(17, "seventeen");
        units.put(18, "eighteen");
        units.put(19, "nineteen");

        tens.put(2, "twenty");
        tens.put(3, "thirty");
        tens.put(4, "forty");
        tens.put(5, "fifty");
        tens.put(6, "sixty");
        tens.put(7, "seventy");
        tens.put(8, "eighty");
        tens.put(9, "ninety");

        thousands.put(1, "thousand");
        thousands.put(2, "million");
        thousands.put(3, "billion");
        thousands.put(4, "trillion");
        thousands.put(5, "quadrillion");
        thousands.put(6, "quintillion");
        thousands.put(7, "sextillion");
        thousands.put(8, "septillion");
        thousands.put(9, "octillion");
        thousands.put(10, "nonillion");
        thousands.put(11, "decillion");
        thousands.put(12, "undecillion");
        thousands.put(13, "duodecillion");
        thousands.put(14, "tredecillion");
        thousands.put(15, "quattuordecillion");
        thousands.put(16, "quindecillion");
        thousands.put(17, "sexdecillion");
        thousands.put(18, "septendecillion");
        thousands.put(19, "octodecillion");
        thousands.put(20, "novemdecillion");
        thousands.put(21, "vigintillion");
    }

    @Override
    public String convert(String number) {
        if (number.equals("0")) return "zero";

        int len = number.length();
        int thousandCounter = 0;

        String result = "";
        while (len > 0) {
            int end = len;
            len = Math.max(len - 3, 0);
            int chunk = Integer.parseInt(number.substring(len, end));
            if (chunk > 0) {
                String chunkInWords = convertLessThanOneThousand(chunk, "hundred");
                if (thousandCounter > 0) {
                    chunkInWords += " " + thousands.get(thousandCounter) + " ";
                }
                result = chunkInWords + " " + result;
            }
            thousandCounter++;
        }
        return result.trim().replaceAll(" +", " ");
    }
}
