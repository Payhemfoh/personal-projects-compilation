<?php
	if(empty($_COOKIE['currency'])){
		$currency = "RMY";
	}else{
		$currency = $_COOKIE['currency'];
	}

	if(empty($_COOKIE['country'])){
		$country = "Malaysia";
	}else{
		$country = $_COOKIE['country'];
	}

	if(empty($_COOKIE['language'])){
		$language = "English";
	}else{
		$language = $_COOKIE['language'];
	}

	session_start();
	if(!empty($_SESSION['username'])){
		$usr = $_SESSION['username'];
		
		$date = $_SESSION['date'];
		
		if(!empty($_SESSION['timestamp'])){
			//user login will stand 2 hour long
			if(time() - $_SESSION['timestamp'] > 7200){
				echo "<script>alert(\"You had been Log out! Please Login again in login page!\")</script>";
				unset($_SESSION);
				session_destroy();
				unset($usr);
			}
			$_SESSION['timestamp'] = time();
		}
	}
?>

<!DOCTYPE html>
<html lang='en'>
	<head>
		<title>Shipper Market-Sign in</title>
		<link rel="stylesheet" type="text/css" href="script/login-register.css">
		<?php
            include("headInclude.html");
        ?>
		<style>
		<?php
			if(!empty($_COOKIE['background_color']) && $_COOKIE['background_color']!="default"){
				echo "body{background-color:".$_COOKIE['background_color'].";}"; 
			}
			else{
				echo "body{background-image:url(\"../pictures/background.jpeg\");}";
			}
		?>
			i{
				color:red;
			}
		</style>
	</head>
	
	<body id="main">
		<div class='header' id='myHeader'>
			<header>
				<nav id='navi'>
					<ul id='navigation'>
						<li class='nav-li'><a href='Homepage.php'  class='nav-logo'><img src='pictures/logo.png' alt='Logo' height='40px' width='40px' id='logo'></a></li>
						<li class='nav-li'><a href='Homepage.php'  class='nav-a'>Home</a></li>
						<li class='nav-li'><a href='ProductsListPage.php' class='nav-a'> Product list</a></li>
						<li class='nav-li'><a href='ContactUs.php'  class='nav-a'> Contact Us</a></li>
						<li class='nav-li'><a href='Careers.php' class='nav-a'>Career page</a></li>
						<li class='nav-li'><a href='AboutUs.php'  class='nav-a'>About Us</a></li>
						<li class='nav-li'><a href='Register.php' class='nav-b'>Register</a></li>
						<li class='nav-li'><a href='religionSetting.php' class='nav-b'>Change Religion Setting</a></li>
						<?php
							echo "<li class='nav-li'><a href='#' class='nav-b'>Language:<i>$language</i>  Country:<i>$country</i>  Currency:<i>$currency</i></a></li>";
						?>
					</ul>
				</nav>
			</header>
		</div>

		<?php
			include("./script/commonFunction.php");
			echo "<div class='sign-register-box fluid-container'>";

			if(empty($usr)){
				if(isset($_POST['submitted'])){	
					//get variables from sign-in page
					$username = $_POST['username'];
					$password = $_POST['password'];
				
					//check conditions
					$submit=true;
					
					if($username == "Superman" && $password == "Wonderwomen"){
						echo "<p>Hard coded username and password detected!</p>";
						$submit = true;
					}else{
						//username
						if(!validateUsername($username))
						$submit = false;


						//password
						if(!validatePassword($password))
							$submit = false;
					}
				
					
					if($submit){
						date_default_timezone_set("Asia/Kuala_Lumpur");
						echo "Your had loged in successfully since ".date("d-m-Y: h:m:sA")."<br>
								Hello, <b>$username</b><br>";
						$_SESSION['username'] = $username;
						$_SESSION['date'] = date("d-m-Y: h:m:sA");
						$_SESSION['timestamp'] = time();

						printFormToHomepage();
					}
					else{
						echo "Sorry, the form has not submitted successfully. Please try again!<br>";
						printFormToLoginpage();
					}
				}
				else{
				echo "<h2 class='title'>Sign In</h2>
						<form method='post' action='SignIn.php'>
							<label for='username' class='label-text'>Username</label><br>
							<input type='text' name='username' placeholder='Username' class='sign-input' tabindex='1' required><br>
							<label for='password' class='label-text'>Password</label><br>
							<input type='password' name='password' placeholder='Password' class='sign-input' tabindex='2' required><br>
							<input type='submit' value='Sign In' class='sign-input btn btn-warning text-center' tabindex'3'>";

				echo "<input type=\"hidden\" name=\"submitted\" value=\"true\">";
				
				echo "</form>
						<h6 class='link'>Didn\'t have an account? <a href='Register.php'>Click here to register a new account.</a></h6>";
				}
			}else{
				if(isset($_POST['submitted'])){
					echo "You had been Log out.";
					unset($_SESSION);
					session_destroy();
					printFormToHomepage();
				}
				else{
					echo "Hi, $usr.<br>You are already Signed In since $date.<br> Do you want to log out?";
					echo "<form action=\"SignIn.php\" method=\"post\">";
						echo "<input type=\"submit\" value=\"Log Out\">";
						echo "<input type=\"hidden\" name=\"submitted\" value=\"true\">";
					echo "</form>";
				}
			}
			echo	"</div>";
		?>
	</body>
</html>