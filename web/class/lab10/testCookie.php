<?php
    if(!empty($_COOKIE['currency']))
        $currency = $_COOKIE['currency'];
    
    if(!empty($_COOKIE['language']))
        $language = $_COOKIE['language'];

    echo "Hi, your currency is <b>$currency</b><br>your language is <b>$language</b>";

?>