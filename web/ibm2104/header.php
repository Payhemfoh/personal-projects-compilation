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
			if(time() - $_SESSION['timestamp'] > 60){
				echo "<script>alert(\"You had been Log out! Please Login again in login page!\")</script>";
				unset($_SESSION);
				session_destroy();
				unset($usr);
			}
			$_SESSION['timestamp'] = time();
		}
	}
?>

<div class='header' id='myHeader'>
	<style>
		<?php
			if($_COOKIE['background_color']=="default")
				unset($_COOKIE['background_color']);
			
			if(!empty($_COOKIE['background_color'])){
				echo "body{background:".$_COOKIE['background_color']." !important;}"; 
			}
		?>
			i{
				color:red;
			}
	</style>

	<header>
		<nav id='navi'>
			<ul id='navigation'>
				<li class='nav-li'><a href='Homepage.php'  class='nav-logo'><img src='pictures/logo.png' alt='Logo' height='40px' width='40px' id='logo'></a></li>
				<li class='nav-li'><a href='Homepage.php'  class='nav-a'>Home</a></li>
				<li class='nav-li'><a href='ProductsListPage.php' class='nav-a'> Product list</a></li>
				<li class='nav-li'><a href='ContactUs.php'  class='nav-a'> Contact Us</a></li>
				<li class='nav-li'><a href='Careers.php' class='nav-a'>Career page</a></li>
				<li class='nav-li'><a href='AboutUs.php'  class='nav-a'>About Us</a></li>
				<?php
					if(empty($usr)){
						echo "<li class='nav-li'><a href='SignIn.php' class='nav-b'>Sign In/Register</a></li>";
					}else{
						echo "<li class='nav-li'><a href='SignIn.php' class='nav-b'>Hi $usr</a></li>";
					}
				?>
				
				<li class='nav-li'><a href='religionSetting.php' class='nav-b'>Change Religion Setting</a></li>
				<?php
					echo "<li class='nav-li'><a href='#' class='nav-b'>Language:<i>$language</i>  Country:<i>$country</i>  Currency:<i>$currency</i></a></li>";
				?>
			</ul>
		</nav>
	</header>
</div>