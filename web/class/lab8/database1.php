<!DOCTYPE html>
<html lang="en">
	<head>
		<title>Form</title>
		<meta charset="utf-8">
	</head>
	
	<body>
		<form method="post" action="database1.php">
			<label for="title">Entry title:</label><br>
			<input type="text" name="title">
			<br><br>
			
			<label for="text">Entry text:</label><br>
			<textarea name="text"></textarea>
			<br><br>
			
			<input type="submit">
		</form>
		
		<?php
			//mysqli need to include $dbc as first param
			
			if(!empty($_POST['title']) && 	!empty($_POST['text'])){
				$title = $_POST['title'];
				$text=$_POST['text'];
				
				//connect database
				if($dbc = mysqli_connect("localhost","root","")){
					echo "<p>Successfully connected to MySQL!</p>";
					
					//create database
					
					if(mysqli_query($dbc,"CREATE DATABASE myblog")){
						echo "<p>Database is created!</p>";
					}else{
						echo "<p style=\"color:red\">Could not create database:<br>";
						echo mysqli_error($dbc);
					}
					
					
					
					//select the database created
					if(mysqli_select_db($dbc,"myblog")){
						echo "<p>The database is selected</p>";
					}else{
						echo "<p style=\"color:red\">Could not select database<br>";
					}
					
					//create table
					/*
					if(mysqli_query($dbc,"")){
						echo "<p>The table is created</p>";
					}else{
						echo "<p style=\"color:red\">Could not create database:<br>";
						echo mysqli_error($dbc);
					}
					*/
					
					//check if connection is work
					if($dbc){
						//command to create table
						$query ="CREATE TABLE entries(
						entry_id INT UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY,
						title VARCHAR(100) NOT NULL,
						entry TEXT NOT NULL,
						data_entered DATETIME NOT NULL)";
						
						//execute the command to create table
						if(mysqli_query($dbc,$query)){
							echo "<p>The table is created!</p>";
						}
						else{
							echo "<p style=\"color:red\">Could not create database:<br>";
							echo mysqli_error($dbc);
						}
						
						//insert data into table
						$insert_command = "INSERT INTO entries(entry_id,title,entry,data_entered)
											VALUES (0,\"$title\",\"$text\",NOW( ))";
						
						if(mysqli_query($dbc,$insert_command)){
							echo "<p>The entry is added into table</p>";
						}else{
							echo "<p style=\"color:red\">Could not insert table:<br>";
							echo mysqli_error($dbc);
						}
					}
					
					/*
					//temporary code to delete the created database for show result
					mysqli_query($dbc,"DROP DATABASE myblog");
					*/
					
					//close the connection
					mysqli_close($dbc);
				}
				else{
					echo "<P style=\"color:red\">Could not connect to MySQL</p>";
				}
			
			}
			else{
				echo "<p>Please enter both fields!</p>";
			}
			
		?>
	</body>
</html>