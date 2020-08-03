<?php
    $shipping = $_POST['shipping'];
    $variation = $_POST['variation'];
    $quantity = $_POST['quantity'];
    $submit = true;

    echo "<center>";

    if(empty($shipping)){
        echo "Shipping type should not be empty!<br>";
        $submit = false;
    }
    else if(!is_numeric($shipping)){
        echo "Shipping price should only contain digit!<br>";
        $submit = false;
    }

    if(empty($variation)){
        echo "Varaition should not be empty!<br>";
        $submit = false;
    }else if(!is_numeric($variation)){
        echo "Variation price should only contain digit!<br>";
        $submit = false;
    }

    if(empty($quantity)){
        echo "Quantity should not be empty!<br>";
        $submit = false;
    }else if(!is_numeric($quantity)){
        echo "Quantity should only contain numbers!<br>";
        $submit = false;
    }

    if($submit)
        echo "Your form is submitted successfully.<br>
                Hello, <b>$username</b>"; 
    else{
        echo "Sorry, the form has not submitted successfully:<br>";
    }

    echo "</center>";
?>