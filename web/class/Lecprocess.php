<?php
	$punctuality = $_POST['punctuality'];
	$preparation=$_POST['preparation'];
	$sum = $punctuality + $preparation;

	if($sum>15){
		echo "Add Salary";
	}
	else if($sum>=5){
		echo "Give Salary";
	}
	else{
		echo "Cut Salary";
	}
?>