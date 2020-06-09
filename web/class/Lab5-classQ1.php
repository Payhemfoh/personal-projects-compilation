<?php
	//get variables from previous webpage
	$name = $_POST['name'];
	$password = $_POST['password'];
	
	echo "<center>";
	
	//check for each conditions
	//name and password are empty
	if(empty($name)&&empty($password)){
		echo "Sorry, the form has not submitted successfully:
				<br>name field is empty.
				<br>password field is empty.";
	}
	//password is filled but name is empty
	else if(empty($name)){
		echo "Sorry, the form has not submitted successfully:<br>name field is empty.";
	}
	//name is filled but password is empty
	else if(empty($password)){
		echo "Sorry, the form has not submitted successfully:<br>password field is empty.";
	}
	//all fields are filled
	else{
		echo "Congratulation <b>$name</b>, you had successfully submitted the form.";
	}
	
	echo "</center>";
?>