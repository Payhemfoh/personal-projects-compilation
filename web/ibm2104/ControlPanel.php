<!DOCTYPE html>
<html lang="en">
	<head>
        <title>Shipper Market-Product List Page</title>
        <link rel="stylesheet" type="text/css" href="script/login-register.css">
        <?php
            include("headInclude.html");
        ?>
	</head>
	
	<body id="main">
        <?php
            include("header.php");
        ?>
            <?php
                
                //check if the form is submitted
                if(isset($_POST['submitted'])){
                    //check if data is filled
                    $name = $_POST['name'];
                    $description = $_POST['description'];
                    $quantity = $_POST['quantity'];
                    $price = $_POST['price'];
                    $shippingFee = $_POST['shipping_fee'];  
                    $isValid = true;

                      
                    if(empty($name)){
                        echo "<p style='color:red'>The product name should not be empty!</p>";
                        $isValid = false;
                    }
                    else if(strlen($name)>100){
                        echo "<p style='color:red'>The size of product name should below 100 characters!</p>";
                        $isValid = false;
                    }

                    if(empty($description)){
                        echo "<p style='color:red'>The product description should not be empty!</p>";
                        $isValid = false;
                    }

                    if(empty($quantity)){
                        echo "<p style='color:red'>The product quantity should not be empty!</p>";
                        $isValid = false;
                    }
                    else if(!is_numeric($quantity)){
                        echo "<p style='color:red'>The size of product quantity should only contain numeric characters</p>";
                        $isValid = false;
                    }

                    if(empty($price)){
                        echo "<p style='color:red'>The product price should not be empty!</p>";
                        $isValid = false;
                    }
                    else if(!is_numeric($price)){
                        echo "<p style='color:red'>The size of product price should only contain numeric characters!</p>";
                        $isValid = false;
                    }

                    if(empty($shippingFee)){
                        echo "<p style='color:red'>The product shipping fee should not be empty!</p>";
                        $isValid = false;
                    }
                    else if(!is_numeric($shippingFee)){
                        echo "<p style='color:red'>The size of product shipping fee should only contain numeric characters!</p>";
                        $isValid = false;
                    }

                    $imgLink = "";
                    $upload_ok = false;
                    if(is_uploaded_file($_FILES['imgLink']['tmp_name'])){
                        $target_dir = "./uploads/";
                        $target_file = $target_dir . basename($_FILES["imgLink"]["name"]);
                        $target_file_temp = $target_file;
                        while(file_exists($target_file_temp)){
                            $count = 0;
                            $target_file_temp = $target_file + $count;
                        }
                        $fileType = strtolower(pathinfo($target_file,PATHINFO_EXTENSION));

                        //check if image file is actual image or fake image
                        $check = getimagesize($_FILES["imgLink"]["tmp_name"]);
                        if($check !== false){
                            if($_FILES['imgLink']['size']<1000000){
                                $imgLink = $target_file;
                                $upload_ok = true;
                            }else{
                                echo "<p style='color:red'>Image size should not exceed 1MB!</p>";
                                $isValid = false;
                            }
                        }else{
                            echo "<p style='color:red'>File is not an image!</p>";
                            $isValid = false;
                        }
                    }

                    //if all the data is valid, try insert into database
                    if($isValid){
                        if($upload_ok){
                            //upload file to server
                            if(move_uploaded_file($_FILES['imgLink']['tmp_name'],$imgLink)){
                                echo "The file has been uploaded!<br>";
                            }else{
                                echo "No2";
                            }
                        }
                        //check if the connection to database is successful
                        if($db = mysqli_connect("localhost","root","")){
                            include("connectDB.php");
                            
                            
                            //insert data into table
                            $query = "INSERT INTO productlist 
                                        (productID, productName, productDescription, productQuantity, productPrice, productShippingFee, productImg) 
                                        VALUES(
                                        0, \"$name\", \"$description\", $quantity, $price, $shippingFee,\"$imgLink\"
                                        )";
                            if(mysqli_query($db,$query)){
                                echo "The data has been added into the database!</p>";
                                echo "<p>Please click the button below to return to control panel</p>";
                                echo "<form action=\"ControlPanel2.php\">";
                                echo "<input type=\"submit\" value=\"Ok\">";
                                echo "</form>";
                            }else{
                                echo "<p style'color:red;'>An error has occur when insert data into database. Please try again later!</p>"
                                .mysqli_error($db)."<br>";
                            }//end if failed to insert data into table
                            

                            //close the database connection
                            mysqli_close($db);
                        }
                        else{
                            //if not print out the table
                                echo "<p style='color:red;'>Unable to connect to database! Please try again later!</p>".mysqli_error($db)."<br>";
                        }//end if connect to database
                    
                    }
                    else{
                        echo "<p style='color:red'>Failed to insert data into database! Please check if the data is filled!</p>";
                        $_POST['submitted'] = false;
                    }//end if data is valid
                    
                }
                else{
            ?>
                <div class='content fluid-container' id='content-detail'>
                    <div class='sign-register-box'>
                        <form method="post" action="ControlPanel.php" enctype="multipart/form-data">
                            
                            <label for="name" class='label-text'>Product Name:</label><br>
                            <input type="text" name="name" class='sign-input' placeholder='Product Name:'>
                            <br><br>

                            <label for="description" class='label-text'>Product Description:</label><br>
                            <textarea name="description" class='sign-input' placeholder='Product Description:'></textarea>
                            <br><br>

                            <label for="quantity" class='label-text'>Product Quantity:</label><br>
                            <input type="number" name="quantity" class='sign-input' placeholder='Product Quantity:'>
                            <br><br>

                            <label for="price" class='label-text'>Product Price:</label><br>
                            <input type="number" name="price" class='sign-input' placeholder='<?php echo "Product Price:($currency)"?>' step="0.01">
                            <br><br>

                            <label for="shipping_fee" class='label-text'>Product Shipping Fee:</label><br>
                            <input type="number" name="shipping_fee" class='sign-input' placeholder='<?php echo "Product Shipping Fee:($currency)"?>' step="0.01">
                            <br><br>

                            <label for="imgLink" class='label-text'>Image File:</label><br>
                            <input type="file" accept="image/*" name="imgLink" class='sign-input' placeholder='Image File:'>
                            <br><br>

                            <input type="submit" class='sign-input btn btn-warning text-center'>
                            <input type="hidden" name="submitted" value="true">
                        </form>
                    </div>
                </div>
            <?php
                };
            
                include("footer.html");
            ?>
    </body>
</html>