<?php
	$qty = $_POST['qty'];
	$size = $_POST['size'];
	$topping = $_POST['topping'];
	$total = $qty * ($size + $topping);
	
	echo "Hi, thank you for your order. Your payment is <b>RM $total</b>.";
?>