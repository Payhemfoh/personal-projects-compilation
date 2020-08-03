<!DOCTYPE html>
<html lang="en">
	<head>
		<title>Shipper Market -Product Detail Page</title>
		<?php
            include("headInclude.html");
        ?>
		<link rel="stylesheet" 
		href="https://use.fontawesome.com/releases/v5.8.1/css/all.css" 
		integrity="sha384-50oBUHEmvpQ+1lW4y57PTFmhCaXp0ML5d60M1M7uH2+nqUivzIebhndOJK28anvf" 
		crossorigin="anonymous">
		<link rel="stylesheet" type="text/css" href="script/list-detail-page.css">
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
		include("header.php");
		
		echo "
			<div class='content fluid-container' id='content-detail'>
				<div class='detail-background'>
					<article class='product-detail'>
						<figure class='img-detail-page'>
							<img src='pictures/item.jpg' class='detail-img'>
						</figure>
							<div class='details'>
								<form method='post' action='/processing/product_detail_page_process.php'>
									<h1 class='detail-name'>Item name</h1>
									<h2 class='detail-price'>RMxxx.xx</h2>
									<br><br>

									<label id='shipping'>Shipping Type:</label>
									<select name='shipping'>
										<option>PosLaju : 7-20days</option>
										<option>J&amp;T Express : 3-12days</option>
										<option>DHL E-commerce : 3-12days</option>
									</select>
									<br><br><br>
									<label id='variation'>Variation:</label>
									<select name='variation'>
										<option>eg1</option>
										<option>eg2</option>
										<option>eg3</option>
									</select>
									<br><br><br>
									
									<label id='qty'>Quantity:</label>
									<button class='qty-btn' onclick='minus()'>-</button>
									<input type='text' size='3px' name='quantity' id='quantity' class='quantity'>
									<button class='qty-btn' onclick='add()'>+</button>
									<input type='digits' size='2px' name='stock' id='stock' class='stock btn' disabled></input>
									pieces left

									<br><br><br>
									<input type='submit' class='btn btn-warning' value=\"<i class='fas fa-cart-plus'></i> Add to Cart\">
									<input type='submit' class='btn btn-warning' value=\"<i class='fas fa-dollar-sign'></i> Buy Now\">
								</form>
							</div>
					</article>
					
					<article class='seller-detail'>
						<figure>
							<img src='pictures/item.jpg' class='seller-icon'>
							<figcaption class='saller-name'>Anonymous</figcaption>
						</figure>
					</article>
					
					<article class='product-info'>
						<div id='specification'>
							<h1 class='info-title'>Product Specification</h1>
							<p class='info-text'>
								Category:<br>
								-<br>
								Brand:<br>
								-<br>
								Type:<br>
								-<br>
								Size/Weight:<br>
								-<br>
								Package Quantity:<br>
								-<br>
								Stock:<br>
								-<br>
								Ships From:<br>
								-<Br>
							</p>
						</div>
						
						<div id='line'></div>
						
						<div id='description'>
							<h1 class='info-title'>Product Description</h1>
							<p class='info-text'>
								The description of the products<br>
								written by the seller:<br>
								Highlights:<br>
								-<br>
								Features:<br>
								-<br>
								Specification:<br>
								-<br>
								Description:<br>
								-<br>
							</p>
						</div>
					</article>
				</div>
			</div>
		";
		
		include("footer.html");
	?>
	<body>
</html>