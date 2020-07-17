<!DOCTYPE html>
<html lang="en">
	<head>
		<title>Form handle</title>
		<meta charset="utf-8">
	</head>
	
	<body>
	<?php
		if(isset($_POST['submitted'])){
			$filled = true;
			if(empty($_POST['email'])){
				$filled = false;
				echo "<p style=\"color:red\">The Email should not be empty!</p>";
			}else{
				$email = $_POST['email'];
			}
			
			if(empty($_POST['phone'])){
				$filled = false;
				echo "<p style=\"color:red\">The Phone No should not be empty!</p>";
			}else{
				$phone = $_POST['phone'];
			}
			
			if($filled){
				echo "<p>Hello, your email is <b>$email</b>.<br>
						Ur phone is <b>$phone</b></p>";
			}else{
				$submitted = false;
			}
		}
		else{
			//print the form
			echo "
				<form method=\"post\" action=\"formHandle.php\">
					<label for=\"email\">Email:</label><br>
					<input type=\"email\" name=\"email\">
					<br><br>
					
					<label for=\"phone\">Phone:</label><br>
					<input type=\"text\" name=\"phone\">
					<br><br>
					
					<input type=\"hidden\" name=\"submitted\" value=\"true\">
					<input type=\"submit\">
					
				</form>";
		}
	?>
	
	</body>
</html>