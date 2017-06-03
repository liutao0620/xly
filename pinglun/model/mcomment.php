<?php
/**
 * Created by liutao.
 * User: comment.php
 * Date: 2017/5/13
 * Time: 15:29
 */
class mcomment extends Model
{
    public function addModel($title,$content,$userid,$movieid)
    {
        $sql = "INSERT INTO dede_comment(title,content,addtime,userid,movieid) VALUES('$title','$content',UNIX_TIMESTAMP(),'$userid','$movieid')";
        if($this->dsql->ExecuteNoneQuery($sql))
            return true;
        else
            return false;

    }

}


?>