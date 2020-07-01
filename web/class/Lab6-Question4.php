<?php
	$title=$_POST['title'];
	$paragraph=$_POST['paragraph'];
	if(!empty($paragraph)){
		$num = str_word_count($paragraph);
	}else{
		$num=0;
	}
	printf("Thank you for your comments,<b>'%s (%d words)'</b>",$paragraph,$num);
?>