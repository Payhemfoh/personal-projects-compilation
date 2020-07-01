<?php
	$name = $_POST['name'];
	$food = $_POST['food'];
	$drink = $_POST['drink'];
	$total = $food + $drink;
	
	echo "Thank you, <strong>$name</strong> your payment is <strong>RM$total</strong>";
?>