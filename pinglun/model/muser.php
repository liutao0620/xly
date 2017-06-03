<?php 
class muser extends Model
{
	public function getUsers()
	{
		$sql="select * from dede_member";
		$this->dsql->SetQuery($sql);
		$this->dsql->Execute('me',$sql);
		$arr = array();
		while($row = $this->dsql->GetArray()){
			$arr[] = $row;
		}
		return $arr;
	}

}


 ?>