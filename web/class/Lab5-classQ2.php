<?php
	//get variables from previous webpage
	$email = $_POST['email'];
	$hp = $_POST['hp'];
	
	echo "<center>";
	
	
	//check for each conditions
	//either of the input is invalid
	if(empty($email) || empty($hp) || !is_numeric($hp)){
		
		echo "Sorry, the form has not submitted successfully:<br>";
		
		//password is filled but name is empty
		if(empty($email)){
			echo "email field is empty.<br>";
		}
		
		
		//name is filled but password is empty
		if(empty($hp)){
			echo "handphone field is empty.<br>";
		}
		else if(!is_numeric($hp)){
			echo "handphone field can only contain digits value.<br>";
		}
	}
	//all fields are filled and valid
	else{
		
		echo "Congratulation <b>$email</b>, you had successfully submitted the form.";
	}
	
	echo "</center>";
?>