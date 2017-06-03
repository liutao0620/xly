<?php
if(!isset($GLOBALS['_vars'])) $GLOBALS['_vars'] = array(); 
$fields = array();
?><!DOCTYPE HTML>
<html>
<head>
<meta charset="utf-8" />
<title><?php echo $cfg_webname; ?> - 留言本</title>

<link rel="stylesheet" type="text/css" href="<?php echo $cfg_templeturl; ?>/moban/style/metinfo_ui.css" id="metuimodule" data-module ="7" />
<link rel="stylesheet" type="text/css" href="<?php echo $cfg_templeturl; ?>/moban/style/metinfo.css" />
<script src="<?php echo $cfg_templeturl; ?>/moban/style/jQuery1.7.2.js" type="text/javascript"></script>
<script src="<?php echo $cfg_templeturl; ?>/moban/style/metinfo_ui.js" type="text/javascript"></script>
<!--[if IE]>
<script src="../public/js/html5.js" type="text/javascript"></script>
<![endif]-->
</head>

<?php
  pasterTempletDiy("moban/head.htm");
?>

<div class="sidebar width center">
    <?php
        pasterTempletDiy("moban/left.htm");
    ?>
	
    <div class="sb_box fr">
	    <div class="sb_box-box position">
	    <h3 class="sb_box-title">
			<div class="sb_box-wz fr position">当前位置：<a href="<?php echo $cfg_basehost;?>" title="网站首页" target='_self'>网站首页</a> &gt; 家长信箱&nbsp;</div>
			<span>家长信箱</span>
		</h3>
		</div>
		<div class="clear"></div>


        <div class="active" id="messagelist">
        	<?php
$atts = array();
$atts['tagname'] = 'datalist';
$blockValue = $this->refObj->GetArcList($atts,$this->refObj,$fields); 
if(is_array($blockValue)){
foreach( $blockValue as $key=>$fields )
{
?>
            <dl class='list-none metlist'>
				<dt class='title'>
					<span class='tt'><?php echo $fields['id']; ?><sup>#</sup></span>
					<span class='name'><?php echo $fields['uname']; ?></span>
					<span class='time'> <?php echo MyDate('m-d H:i',$fields['dtime']); ?></span>
				</dt>
				<dd class='info'>
					<span class='tt'>留言内容</span>
					<span class='text'><?php echo $fields['msg']; ?>					
						 <br />
						 <?php if($g_isadmin) { ?>    
						 [邮件]：<?php echo $fields['email']; ?>&nbsp;
                         [电话号码]：<?php echo $fields['homepage']; ?>  &nbsp;               
                         <a href='guestbook.php?action=admin&id=<?php echo $fields['id']; ?>'><img src='guestbook/images/quote.gif' border=0 width='16' height='16'/>[回复/编辑]</a>&nbsp;
                         <a href='guestbook.php?action=admin&id=<?php echo $fields['id']; ?>&job=del'><img src='guestbook/images/del.gif' border=0 width='16' height='16'/>[删除]</a>
                         <?php }  ?>
			</dl>
			<?php
}
}?>

	        <div id="flip">
		        <div class='digg4 metpager_8'>
		        <span class='disabled disabledfy'>
		        <?php
$atts = array();
$atts['tagname'] = 'pagelist';
$atts['listsize'] = '5';
 echo $this->refObj->GetPageList($atts,$this->refObj,$fields); 
?>

		        </span>
		        </div>
	        </div>
        
			<h3 class="ctitle" align='left'>提交留言</h3>
			<form method='POST' name='myform' onSubmit='return metmessagesubmit("姓名不能为空","留言信息不能为空");' action='guestbook.php' target='_self'>
			<input type='hidden' name='action' value='save' />
				<table class='message_table'>
					<tr>
						<td class='text'>姓名</td>
						<td class='input'><input name='uname' type='text' class='input-text' /><span class='info'>*</span></td>
					</tr>
					<tr>
						<td class='text'>电话</td>
						<td class='input'><input name='homepage' type='text' class='input-text' /></td>
					</tr>
					<tr>
						<td class='text'>Email</td>
						<td class='input'><input name='email' type='text' class='input-text' /></td>
					</tr>
					<tr>
						<td class='text'>其他联系方式</td>
						<td class='input'><input name='qq' type='text' class='input-text' />如QQ、MSN等</td>
					</tr>
					<tr>
						<td class='text'>留言内容</td>
						<td class='input'><textarea name='msg' cols='50' rows='6' class='textarea-text'></textarea><span class='info'>*</span></td>
					</tr>
					<tr>
						<td class='text'>验证码</td>
						<td class='input'><input name="validate" type="text" id="vdcode2" class="ipt-txt" style="width:60px;text-transform: uppercase;" />
						<img src='../include/vdimgck.php'/></td>
					</tr>
					<tr>
						<td class='text'></td><td class='submint'>
						<input type='hidden' name='ip' value='118.250.117.67' />
						<input type='hidden' name='lang' value='cn' />
						<input type='submit' name='Submit' value='提交留言' class='submit button orange'></td>
					</tr>
				</table>
	        </form>

        </div>

    </div>
    <div class="clear"></div>
</div>

<?php
  pasterTempletDiy("moban/footer.htm");
?>