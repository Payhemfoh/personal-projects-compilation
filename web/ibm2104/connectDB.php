<?php
    
        //check if the database is exist, select if exist, create if not exist
        while(!mysqli_select_db($db,"grocerywebsite")){
            $query = "CREATE DATABASE grocerywebsite";
            mysqli_query($db,$query);
        }

        //check if the table is exist, create if not exist
        $numTable = mysqli_num_rows(mysqli_query($db,"SHOW TABLES LIKE 'productList'"));
        //create new table if the table is not exists
        while(!$numTable){
            $query = "CREATE TABLE productList(
                        productID INT UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY,
                        productName Varchar(100) NOT NULL,
                        productDescription Varchar(300) NOT NULL,
                        productQuantity INT UNSIGNED NOT NULL,
                        productPrice FLOAT UNSIGNED NOT NULL,
                        productShippingFee FLOAT UNSIGNED NOT NULL,
                        productImg VARCHAR(200)
                        )";
            mysqli_query($db,$query);
            $numTable = mysqli_num_rows(mysqli_query($db,"SHOW TABLES LIKE 'productList'"));
        }
?>