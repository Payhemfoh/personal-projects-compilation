<?php
	$first = $_POST['first'];
	$last = $_POST['last'];
	$sum = $first + $last;
	$dif = $first - $last;
	$product = $first * $last;
	$div = (float)$first / $last;
	
	echo "The sum of $first and $last is $sum.<br>";
	echo "The difference of $first and $last is $dif.<br>";
	echo "The product of $first and $last is $product.<br>";
	echo "The division of $first and $last is $div.<br>";
?>