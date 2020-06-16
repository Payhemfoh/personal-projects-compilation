<?php
	$title=$_POST['title'];
	$paragraph=$_POST['paragraph'];
	if(!empty($paragraph)){
		$num = str_word_count($paragraph);
		//replace badword with I LOVE YOU
		$display = str_ireplace("badword","I LOVE YOU",$paragraph);
	}else{
		$num=0;
		$display="";
	}
	printf("Preview your comments,<b>'%s (%d words)'</b>",$display,$num);
?>