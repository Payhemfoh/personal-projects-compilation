<!DOCTYPE html>

<html lang="en">
    <head>
        <title>Cookies</title>
        <meta charset="utf-8">
    </head>

    <body>
        <?php
            if(isset($_POST['submitted'])){
                if(!empty($_POST['currency'])){
                    setcookie("currency",$_POST['currency']);
                }else{
                    setcookie("currency","RMY");
                }

                if(!empty($_POST['language'])){
                    setcookie("language",$_POST['language']);
                }else{
                    setcookie("language","English");
                }

                echo "Your setting had been saved!";
            }
            else{
                ?>
                <form action="cookie.php" method="post">
                    <label for="currency">Country</label>
                    <select name="currency">
                        <?php
                            $currencies = array("RMY","EUP","RMB","JPY");
                            foreach($currencies as $select){
                                echo "<option value=\"$select\">$select</option>";
                            }
                        ?>
                    </select>
                    <br><br>

                    <label for="language">Language</label>
                    <select name="language">
                        <?php
                            $languages = array("English","Chinese","Malay","Korean","Japanese");
                            foreach($languages as $select){
                                echo "<option value=\"$select\">$select</option>";
                            }
                        ?>
                    </select>
                    <br><br>

                    <input type="hidden" name="submitted" value="true">
                    <input type="submit">
                </form>
        <?php    
            }
        ?>
    </body>