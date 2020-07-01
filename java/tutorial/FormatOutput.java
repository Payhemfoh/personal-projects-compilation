public class FormatOutput {
    public static void main(String[] args) {//String name,String mark){
        /*let say name and mark saved separate like:
        String name = "name1,name2,name3,name4";
        String mark = "mark,mark2,mark3,mark4";
        */
        String name = "Jesus,Oh,God,kjdsjladjlkajdklasjdsks";
        String mark = "3,5,2,4";
        String output="";

        //find the longest name in the string
        String findLongest = "";
        int longestLength = 0;
        for (int i = 0; i < name.length(); i++) {
            if (name.charAt(i) == ',' || i==name.length()-1){
                if (longestLength < findLongest.length()) {
                    longestLength = findLongest.length();
                }
                findLongest = "";
            }else{
                findLongest += name.charAt(i);
            }
        }

        //format output
        String nameSubstring = "";
        String markSubstring = "";
        int nameStartIndex = 0;
        int nameEndIndex = 0;
        int markStartIndex = 0;
        int markEndIndex = 0;
        //loop until the string is finish read
        while (nameStartIndex < name.length()) {
            //find , as break point
            for (; nameEndIndex < name.length(); nameEndIndex++) {
                if (name.charAt(nameEndIndex) == ',') {
                    break;
                }
            }

            //get substring and set new start index
            nameSubstring = name.substring(nameStartIndex, nameEndIndex);
            nameStartIndex = nameEndIndex + 1;
            nameEndIndex++;

            //same as name
            for (; markEndIndex < mark.length(); markEndIndex++) {
                if (mark.charAt(markEndIndex) == ',') {
                    break;
                }
            }

            markSubstring = mark.substring(markStartIndex, markEndIndex);
            markStartIndex=markEndIndex+1;
            markEndIndex++;

            //print histogram
            System.out.printf("%-"+longestLength+"s",nameSubstring);
            for (int i = 0; i < Integer.parseInt(markSubstring); i++) {
                System.out.print(" *");
            }
            System.out.println();
        }
    }
}
