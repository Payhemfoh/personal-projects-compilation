<!DOCTYPE html>
<html lang="en">
    <head>
        <title>Control Panel</title>
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
                //check if the connection to database is successful
                if($db = mysqli_connect("localhost","root","")){
                    include("connectDB.php");

                    //extract data from database and show in table format
                    $query = "SELECT * FROM productList";
                    $data = mysqli_query($db,$query);
                    $field = array("productID","productName","productDescription","productQuantity","productPrice","productShippingFee","productImg");

                    //print out data in table form
                    $numRow = mysqli_num_rows($data);
                    if($numRow){
                    echo "<table spacing=\"3\" border=\"1\">";
                    echo "<tr>";
                    foreach($field as $col){
                        echo "<th>$col</th>";
                    }
                    echo "<th>Edit</th><th>Delete</th>";
                    echo "</tr>";
                        while($row = mysqli_fetch_array($data)){
                            echo "<tr>";
                                foreach($field as $col){
                                    echo "<td>$row[$col]</td>";
                                };
                                echo "<td><a href=\"edit_delete.php?id=".((int)($row['productID'])+1)."&&mode=edit\">Edit</td>";
                                echo "<td><a href=\"edit_delete.php?id=".((int)($row['productID'])+1)."&&mode=delete\">Delete</td>";
                            echo "</tr>";
                        }
                    echo "</table>";
                    }
                    //close the database connection
                    mysqli_close($db);
                }else{
                    echo "Failed to connect to database:".mysqli_error($db)."<br>";
                }//end if connection failed
            ?>
        </center>
        </div>

        <?php
            include("footer.html");
        ?>
    </body>
</html>