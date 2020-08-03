public class MonthConverter {
    public static final String MONTH[] = {"JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC"};
    public static final int DAYSPERMONTH[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    /**
     * This method will convert the integer month value into the English month value
     * @param month the integer month value
     * @return the English month value
     */
    public static String convertMonth(int month){
        return MONTH[month-1];
    }

    /**
     * This method is used to validate the day based on the English month value
     * @param day the day
     * @param month the English month value
     * @return validation result of the day
     */
    public static boolean checkDay(int day,String month){
        int monthIndex = 0;
        boolean isValid = false;

        //get the index of month to match the day
        for(int i=0;i<MONTH.length;++i){
            if(month.equals(MONTH[i]))
                monthIndex = i;
        }

        if(day>0 && day<=DAYSPERMONTH[monthIndex]){
            isValid = true;
        }

        return isValid;
    }//end method

    /**
     * This method is used to validate the day based on the digit month value
     * @param day the day
     * @param month the digit month value
     * @return validation result of the day
     */
    public static boolean checkDay(int day,int month){
        boolean isValid = false;

        if(day>0 && day<=DAYSPERMONTH[month-1]){
            isValid = true;
        }

        return isValid;
    }//end method
}//end class
