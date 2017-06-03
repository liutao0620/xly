<?php
if(!isset($GLOBALS['_vars'])) $GLOBALS['_vars'] = array(); 
$fields = array();
?><!DOCTYPE html>
<html>
<head>
	<title></title>
</head>
<body>
  <h3>用户：</h3>
  <ul>
  	<?php foreach($users as $v):?>
        <ul><?php echo $v['userid']; ?></ul>
    <?php endforeach;?>
  </ul>
</body>
</html>