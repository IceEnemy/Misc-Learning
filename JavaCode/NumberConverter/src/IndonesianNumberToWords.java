import java.util.HashMap;

public class IndonesianNumberToWords extends NumberToWords {

    public IndonesianNumberToWords() {
        units = new HashMap<>();
        tens = new HashMap<>();
        thousands = new HashMap<>();

        units.put(0, "");
        units.put(1, "satu");
        units.put(2, "dua");
        units.put(3, "tiga");
        units.put(4, "empat");
        units.put(5, "lima");
        units.put(6, "enam");
        units.put(7, "tujuh");
        units.put(8, "delapan");
        units.put(9, "sembilan");
        units.put(10, "sepuluh");
        units.put(11, "sebelas");
        units.put(12, "dua belas");
        units.put(13, "tiga belas");
        units.put(14, "empat belas");
        units.put(15, "lima belas");
        units.put(16, "enam belas");
        units.put(17, "tujuh belas");
        units.put(18, "delapan belas");
        units.put(19, "sembilan belas");

        tens.put(2, "dua puluh");
        tens.put(3, "tiga puluh");
        tens.put(4, "empat puluh");
        tens.put(5, "lima puluh");
        tens.put(6, "enam puluh");
        tens.put(7, "tujuh puluh");
        tens.put(8, "delapan puluh");
        tens.put(9, "sembilan puluh");

        thousands.put(1, "ribu");
        thousands.put(2, "juta");
        thousands.put(3, "milyar");
        thousands.put(4, "triliun");
        thousands.put(5, "kuadriliun");
        thousands.put(6, "kuintiliun");
        thousands.put(7, "sextiliun");
        thousands.put(8, "septiliun");
        thousands.put(9, "oktiliun");
        thousands.put(10, "noniliun");
        thousands.put(11, "desiliun");
        thousands.put(12, "undesiliun");
        thousands.put(13, "duodesiliun");
        thousands.put(14, "tredesiliun");
        thousands.put(15, "kuatuordesiliun");
        thousands.put(16, "kuindesiliun");
        thousands.put(17, "seksdesiliun");
        thousands.put(18, "septendesiliun");
        thousands.put(19, "oktodesiliun");
        thousands.put(20, "novemdesiliun");
        thousands.put(21, "vijintiliun");
    }

    @Override
    public String convert(String number) {
        if (number.equals("0")) return "nol";

        int len = number.length();
        int thousandCounter = 0;

        String result = "";
        while (len > 0) {
            int end = len;
            len = Math.max(len - 3, 0);
            int chunk = Integer.parseInt(number.substring(len, end));
            if (chunk > 0) {
                String chunkInWords = convertLessThanOneThousand(chunk, "ratus");
                if (thousandCounter > 0) {
                    chunkInWords += " " + thousands.get(thousandCounter) + " ";
                }
                result = chunkInWords + " " + result;
            }
            thousandCounter++;
        }
        return adjustSpecialCases(result.trim().replaceAll(" +", " "));
    }

    private String adjustSpecialCases(String result) {
        if (result.startsWith("satu ribu")) {
            result = result.replaceFirst("satu ribu", "seribu");
        }
        if (result.contains("satu ratus")) {
            result = result.replace("satu ratus", "seratus");
        }
        return result;
    }
}
