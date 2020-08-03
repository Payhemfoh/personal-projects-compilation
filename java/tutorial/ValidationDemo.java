import java.util.InputMismatchException;

public class ValidationDemo {
    //first character A / B
    //follow by 5 digit
    public static void main(String[] args){

    }

    public static boolean validateCharacter(){
        String id = "A00000";
        String school = "";

        boolean isValid = false;

        if(id==null || id.length()!=6){
            return false;
        }

        String substr = id.substring(1,5);
        for(int i=0;i<substr.length();++i){
            if(!java.lang.Character.isDigit(substr.charAt(i)))
                isValid = false;
        }

        if(isValid) {
            switch (id.charAt(0)) {
                case 'A':
                    school = "FSBA";
                    break;
                case 'B':
                    school = "FASC";
                    break;
                default:
                    isValid = false;
            }
        }

        return isValid;
    }


    public static boolean validateWithException(){
        String id="A00000";
        String school ="";
        boolean isValid = true;

        try {
            if (id == null || id.length() != 6)
                throw new AssertionError();

            for (int i = 1; i < id.length(); ++i){
                if (!java.lang.Character.isDigit(id.charAt(i))) {
                    throw new AssertionError();
                }
            }

            switch (id.charAt(0)) {
                case 'A':
                    school = "FSBA";
                    break;
                case 'B':
                    school = "FASC";
                    break;
                default:
                    isValid = false;
            }

        }catch(AssertionError e){
            isValid = false;
        }

        return isValid;
    }

    public static void validateWithParse(){
        String id="A00000";
        String school ="";
        boolean isValid = true;

        try {
            if (id == null || id.length() != 6)
                throw new AssertionError();

            int value = Integer.parseInt(id.substring(1,5));


            switch (id.charAt(0)) {
                case 'A':
                    school = "FSBA";
                    break;
                case 'B':
                    school = "FASC";
                    break;
                default:
                    isValid = false;
            }

        }catch(AssertionError e){
            isValid = false;
        }catch(NumberFormatException e){
            isValid = false;
        }
    }
}
