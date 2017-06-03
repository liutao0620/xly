<li class="nav-line">	</li>
		 		<li id='nav_1' style='width:133px;' >
			 		<a href='{dede:field name='typeurl'/}'  title='{dede:field name='typename'/}' class='hover-none nav'>
			 		    <span>{dede:field name='typename'/}</span>
			 		</a>
			 		<dl>
                        {dede:channel  type='son' noself='yes'}
				 		<dd>
				 		<a href='[field:typelink/]' title='[field:typename/]' >[field:typename/]</a>
				 		</dd>
                        {/dede:channel}
			 		</dl>
		 		</li>