<?php
	$price=$_POST['price'];
	$discount=$_POST['discount'];
	$shipping=$_POST['shipping'];
	$gst=$_POST['gst'];
	
	/*
		calculate total price
		1. calculate price after discount
		2. add the shipping fee
		3. calculate the gst
	*/
	$total = (($price * (1-$discount)) + $shipping) * (1+$gst);
	
	echo "The total payment is <b>RM $total</b>";
?>