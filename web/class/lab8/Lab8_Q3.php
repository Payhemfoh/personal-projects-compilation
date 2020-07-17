<?php
    $num = array(2,4,8,16,32);
    $total = 1;

    foreach($num as $key => $value){
        $total*=$value;
    }

    echo "The total value is $total<br>";
?>