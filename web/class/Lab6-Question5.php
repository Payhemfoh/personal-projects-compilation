<?php
	$title=$_POST['title'];
	$paragraph=$_POST['paragraph'];
	if(!empty($paragraph)){
		$num = str_word_count($paragraph);
		if(count_chars($paragraph)>50){
			$display = substr($paragraph,0,50);
			$display=$display."...";
		}else{
			$display=$paragraph;
		}
	}else{
		$num=0;
		$display="";
	}
	printf("Preview your comments,<b>'%s (%d words)'</b>",$display,$num);
?>