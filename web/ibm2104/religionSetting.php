<!DOCTYPE html>
<html lang="en">
    <head>
    <title>Religion Setting</title>
    <link rel="stylesheet" type="text/css" href="script/login-register.css">
    <?php
        include("headInclude.html");
    ?>
    </head>

    <body id="main">
        <center>
        <?php
            include("script/commonFunction.php");

            function settingCookie($str){
                if(!empty($_POST[$str])){
                    setcookie($str,$_POST[$str]);
                }else{
                    setcookie($str,"");
                }
            }
            include("header.php");
        ?>
        
        <div class='sign-register-box fluid-container'>
        <?php
            if(isset($_POST['submitted'])){            
                settingCookie("country");
                settingCookie("language");
                settingCookie("currency");
                settingCookie("background_color");
                echo "Your setting had been saved<br>";
                printFormToHomepage();
            }
            else{
        ?>
    
        <form action="religionSetting.php" method="post">
            <label for="country">Country</label><br>
            <select name="country">
            <?php
                $countries = array("Malaysia","Singapore","Thailand","Taiwan","Hong Kong","China",
                                "Japen","Korea","Russia","India","United State","United Kingdom","French","Italy");
                foreach($countries as $c){
                    echo "<option value=\"$c\">$c</option>";
                }
            ?>
            </select>
            <br><br>

            <label for="language">Language</label><br>
            <select name="language">
            <?php
                $languages = array("English","Chinese","Malay","Hindi","Thai","Japanese","Korean","French","Russian","Italian");
                foreach($languages as $c){
                    echo "<option value=\"$c\">$c</option>";
                }
            ?>
            </select>
            <br><br>

            <label for="currency">Currency</label><br>
            <select name="currency">
            <?php
                $currencies = array("RMY","CNY","USD","EUR","SGD","THB","TWD","KRW","GBP","HKD","JPY");
                foreach($currencies as $c){
                    echo "<option value=\"$c\">$c</option>";
                }
            ?>
            </select>
            <br><br>

            <label for="background_color">Background Color</label><br>
            <select name="background_color">
            <?php
                $colors = array("default","white","black","red","orange","blue","green","yellow","pink","purple","grey");
                foreach($colors as $c){
                    echo "<option value=\"$c\">$c</option>";
                }
            ?>
            </select>
            <br><br>
            <input type="hidden" name="submitted" value="true">
            <input type="submit" value="save setting">
        </form>
        <?php
            }
        ?>
        </div>
        </center>
    </body>
    </html>