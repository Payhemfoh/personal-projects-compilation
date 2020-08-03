<!DOCTYPE html>
<html lang="en">
    <head>
        <title>Edit &amp; Delete</title>
        <?php
            include("headInclude.html");
        ?>
        <style>
            #content{
                background-color:white;
                width:80%;
                margin-left:10%;
                border-radius:20px;
            }

        </style>
    </head>

    <body id="main">
    <?php
        include("header.php");
    ?>
    <div class='content fluid-container' id='content'>
        <center>
        <?php
            if(isset($_POST['confirmSubmitted'])){
                if(!empty($_POST['id']) && !empty($_POST['mode'])){
                    $id = $_POST['id'];
                    $mode = $_POST['mode'];

                    //check if the connection to database is successful
                    if($db = mysqli_connect("localhost","root","")){
                        include("connectDB.php");

                        if($mode == "edit"){
                            $name = $_POST['productName'];
                            $description = $_POST['productDescription'];
                            $quantity = $_POST['productQuantity'];
                            $price = $_POST['productPrice'];
                            $shippingFee = $_POST['productShippingFee'];

                            $query = "UPDATE productList SET 
                                        productName = \"$name\",
                                        productDescription = \"$description\",
                                        productQuantity = \"$quantity\",
                                        productPrice = \"$price\",
                                        productShippingFee = \"$shippingFee\"
                                        WHERE productID = \"".($id-1)."\";
                                        ";
                            
                            if(mysqli_query($db,$query)){
                                echo "<p>The data had been updated successfully from the Database</p>";
                            }else{
                                echo "<p style=\"color:red\">Failed to update the data from Database :<br>".mysqli_error($db)."</p>";
                            }
                        }//end if mode == edit
                        else if($mode == "delete"){
                            $query = "DELETE FROM productList WHERE productID = \"".($id-1)."\"";

                            if(mysqli_query($db,$query)){
                                echo "<p>The data had been removed successfully from the Database</p>";
                            }else{
                                echo "<p style=\"color:red\">Failed to remove the data from Database :<br>".mysqli_error($db)."</p>";
                            }
                        }//end if mode == delete

                        //create button to return to controlPanel
                        echo "<form action=\"ControlPanel2.php\">";
                        echo "<input type=\"submit\" value=\"Ok\">";

                    }
                    //if failed to connect to server
                    else{
                        echo "<p style=\"color:red;\" Failed to connect to database!".mysqli_error($db)."</p>";
                    }
                }
                //if id or mode is empty, return to control panel
                else{
                    header("ControlPanel2.php");
                }
            }
            //if the form is not submitted
            else{
                //check if id and mode is set
                if(!empty($_GET['id']) && !empty($_GET['mode'])){
                    $id = $_GET['id'];
                    $mode = $_GET['mode'];

                    if($db = mysqli_connect("localhost","root","")){
                        include("connectDB.php");

                        //create query to select the row and display
                        $query = "SELECT * FROM productList WHERE productId = ".($id-1);
                        $data = mysqli_query($db,$query);
    
                        $field = array("productID","productName","productDescription","productQuantity","productPrice","productShippingFee");
                        
                        if($mode=="edit"){
                            while($row = mysqli_fetch_array($data)){
                                echo "<form action=\"edit_delete.php\" method=\"post\">";
                                foreach ($field as $col) {
                                    echo "<label for\"$col\">$col</label><br>";
                                    if($col=="productID")
                                        echo "<input type=\"text\" name=\"$col\" value=\"".$row[$col]."\" disabled>";
                                    else
                                        echo "<input type=\"text\" name=\"$col\" value=\"".$row[$col]."\">";
                                    echo "<br><br>";
                                }
                                echo "<input type=\"hidden\" name=\"id\" value=\"$id\">";
                                echo "<input type=\"hidden\" name=\"mode\" value=\"edit\">";
                                echo "<input type=\"hidden\" name=\"confirmSubmitted\" value=\"true\">";
                                echo "<input type=\"submit\" value=\"update\">";
                            }
                        }
                        else if($mode=="delete"){
                            echo "<table border=\"1\">";
                            echo "<th>Fields</th><th>Data</th>";
                            while($row = mysqli_fetch_array($data)){
                                foreach($field as $col){
                                echo "<tr>";
                                echo "<td>$col</td><td>$row[$col]</td>";
                                echo "</tr>";
                                }
                            }
                            echo "</table>";

                            echo "<form action=\"edit_delete.php\" method=\"post\">";
                            echo "<input type=\"hidden\" name=\"id\" value=\"$id\">";
                            echo "<input type=\"hidden\" name=\"mode\" value=\"delete\">";
                            echo "<input type=\"hidden\" name=\"confirmSubmitted\" value=\"true\">";
                            echo "<input type=\"submit\" value=\"delete\">";
                        }

                    }
                    //if failed to connect to the server
                    else{
                        echo "<p style=\"color:red;\" Failed to connect to database!".mysqli_error($db)."</p>";
                    }
                }
                //if id or mode is empty
                else{
                    header("ControlPanel2.php");
                }
            }
        ?>
        </center>
        </div>
        <?php
            include("footer.html");
        ?>
    </body>
</html>