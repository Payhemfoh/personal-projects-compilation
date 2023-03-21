<!DOCTYPE html>
<html lang="en">
    <head>
        <title>Sessions</title>
        <meta charset='utf-8'>
    </head>

    <body>
        <?php
            if(isset($_POST['submitted'])){
                session_start();
                if(!empty($_POST['id'])){
                    $_SESSION['id'] = $_POST['id'];
                }

                if(!empty($_POST['phone'])){
                    $_SESSION['phone'] = $_POST['phone'];
                }

                date_default_timezone_set("Asia/Kuala_Lumpur");
                $_SESSION['time'] = date("d-m-y: h:i:sA");

                echo "You had submitted the form successfully!";
            }
            else{
        ?>
        <form action="session.php" method="post">
            <label for="id">User ID</label>
            <input type="text" name="id">
            <br><br>

            <label for="phone">Phone No</label>
            <input type="text" name="phone">
            <br><br>

            <input type="hidden" name="submitted" value="true">
            <input type="submit">
        </form>
        <?php
            }
        ?>
    </body>
</html>