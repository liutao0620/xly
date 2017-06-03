<?php 

require_once(dirname(__file__).'/../include/common.inc.php');
require_once(DEDEINC.'/request.class.php');

$ct = Request('c', 'index');
$ac = Request('a', 'index');

//包含用户类
require_once DEDEINC.'/memberlogin.class.php';
$cfg_ml = new MemberLogin();

// 统一应用程序入口
RunApp($ct, $ac);
?>