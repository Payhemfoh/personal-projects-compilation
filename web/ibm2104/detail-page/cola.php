<!DOCTYPE html>
<html lang="en">
	<head>
		<title>Shipper Market -Product Detail Page</title>
		<meta charset="utf-8">
		<link rel="icon" href="../pictures/logo.png">
		<link rel="stylesheet" 
		href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css" 
		integrity="sha384-BVYiiSIFeK1dGmJRAkycuHAHRg32OmUcww7on3RYdg4Va+PmSTsz/K68vbdEjh4u" 
		crossorigin="anonymous">
		<link rel="stylesheet" 
		href="https://use.fontawesome.com/releases/v5.8.1/css/all.css" 
		integrity="sha384-50oBUHEmvpQ+1lW4y57PTFmhCaXp0ML5d60M1M7uH2+nqUivzIebhndOJK28anvf" 
		crossorigin="anonymous">
		<link rel="stylesheet" type="text/css" href="../script/website.css">
		<link rel="stylesheet" type="text/css" href="../script/list-detail-page.css">
		<script src="../script/script.js"></script>
		<script>
			window.onload = function(){
				initialize();
			};
			
			function initialize(){
				let element = document.getElementById("quantity");
				stock = parseInt(document.getElementById("stock").value);
				stock=3;
				if(stock<=0){
					element.value=0;
					element.setAttribute('disabled','true');
				}
				else{
					element.value=1;
					element.addEventListener("keyup",check);
				}
			};
			
			function add(){
				let buy = document.getElementById("quantity");
				if(buy.value < stock)
					buy.value++;
				else
					alert("The value had reached maximum!");
			};
			
			function minus(){
				let buy = document.getElementById("quantity");
				if(buy.value>1)
					buy.value--;
				else{
					alert("The value had reached minimum!");
				}
			};
			
			function check(){
				let buy = this.value;
				let stock = document.getElementById("stock");
				if(characterCode == 13){
					if(buy<0 || buy>stock){
						window.alert("Invalid value!")
						this.value=0;
					}
				}
			}
		</script>
	</head>
	
	<body id="main">
		<?php
			echo '
				<div class="header" id="myHeader">
					<header>
						<nav id="navi">
							<ul id="navigation">
								<li class="nav-li"><a href="../Homepage.php"  class="nav-logo"><img src="../pictures/logo.png" alt="Logo" height="40px" width="40px" id="logo"></a></li>
								<li class="nav-li"><a href="../Homepage.php"  class="nav-a">Home</a></li>
								<li class="nav-li"><a href="../ProductsListPage.php" class="nav-a"> Product list</a></li>
								<li class="nav-li"><a href="../ContactUs.php"  class="nav-a"> Contact Us</a></li>
								<li class="nav-li"><a href="../Careers.php" class="nav-a">Career page</a></li>
								<li class="nav-li"><a href="../AboutUs.php"  class="nav-a">About Us</a></li>
								<li class="nav-li"><a href="../SignIn.php" class="nav-b">Sign In/Register</a></li>
							</ul>
						</nav>
					</header>
				</div>
			';
		
			echo '
				<div class="content fluid-container" id="content-detail">
					<div class="detail-background">
						<article class="product-detail">
							<figure class="img-detail-page">
								<img src="../pictures/cola.jpg" class="detail-img">
							</figure>
								<div class="details">
									<h1 class="detail-name">Coca Cola</h1>
									<h2 class="detail-price">RM4.00/pic</h2>
									<br><br>

									<label id="shipping">Shipping Type:</label>
									<select name="shipping">
										<option>PosLaju : 7-20days</option>
										<option>J&amp;T Express : 3-12days</option>
										<option>DHL E-commerce : 3-12days</option>
									</select>
									<br><br><br>
									<label id="variation">Variation:</label>
									<select name="variation">
										<option>Original</option>
										<option>Vanilla</option>
										<option>Strawberry</option>
									</select>
									<br><br><br>
									
									<label id="qty">Quantity:</label>
									<button class="qty-btn" onclick="minus()">-</button>
									<input type="text" size="3px" name="quantity" id="quantity" class="quantity">
									<button class="qty-btn" onclick="add()">+</button>
									<input type="digits" size="2px" name="stock" id="stock" class="stock btn" disabled>3</input>
									pieces left

									<br><br><br>
									<button class="btn btn-warning"><i class="fas fa-cart-plus"></i> Add to Cart</button>
									<button class="btn btn-warning"><i class="fas fa-dollar-sign"></i> Buy Now</button>

								</div>
						</article>
						
						<article class="seller-detail">
							<figure>
								<img src="../pictures/item.jpg" class="seller-icon">
								<figcaption class="saller-name">Anonymous</figcaption>
							</figure>
						</article>
						
						<article class="product-info">
							<div id="specification">
								<h1 class="info-title">Product Specification</h1>
								<p class="info-text">
									Category:<br>
									-Breverage<br>
									Brand:<br>
									-Coca Cola<br>
									Type:<br>
									-Food &amp; breverage<br>
									Size/Weight:<br>
									-1L/pic<br>
									Package Quantity:<br>
									-none<br>
									Stock:<br>
									-3<br>
									Ships From:<br>
									-Penang<Br>
								</p>
							</div>
							
							<div id="line"></div>
							
							<div id="description">
								<h1 class="info-title">Product Description</h1>
								<p class="info-text">
									The description of the products<br>
									written by the seller:<br>
									Highlights:<br>
									-none<br>
									Features:<br>
									-none<br>
									Specification:<br>
									-none<br>
									Description:<br>
									-none<br>
								</p>
							</div>
						</article>
					</div>
				</div>
			';

			echo '
				<footer>
					<div class="footer-sign-up"> 
						Want to shopping in Shipper Market? Click here to <a href="Register.php" class="footer-link">register your free account</a>
						or you already <a href="SignIn.php" class="footer-link">have an account?</a>
						<br>
						Interesting in joining us? Please refer to our <a href="Career.php" class="footer-link">career page</a> for more information!
						<br>
						More information about Shipper Market? Please refer to our <a href="AboutUs.php" class="footer-link">about page</a>.
					</div>
					
					<div class="footer-line">
					</div>
					
					<div class="footer-contact">
						<p>E-mail:<a href="mailto:#">#@mail.com</a>
						<p>More contact method please refer to the our <a href="ContactUs.php" class="footer-link">contact page</a>.
					</div>
					<p class="copyright" style="font-size:10px;">The website is owned by Shipper Market &copy;2020</p>
				</footer>
			';
		?>
	<body>
</html>