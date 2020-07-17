<?php
    $flower_prices = array(
                "rose"=>5.00,
                "daisy"=>4.00,
                "orchid"=>2.00);
    
    echo "<table border='1'>";
    echo "<tr><th>Flower</th><th>Price</th></tr>";

    foreach($flower_prices as $flower => $price){
        printf("<tr><td>%s</td><td>%.2f</td></tr>",$flower,$price);
    }

    echo "</table>";

?>