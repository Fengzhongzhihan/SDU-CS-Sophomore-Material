    //找到了空行
	if(beset!=-1)
	{
		//更新LRU
		for (m = 0; m < 4; m++)    
		{
			if(m==beset)
				continue;
			else 
				if(iCache.sets[sets_index].lines[m].LRU<3)
				iCache.sets[sets_index].lines[m].LRU++;
		}
			return iCache.sets[sets_index].lines[j].data
		[(address & 0x0000001f) >> 2];
	}

    	for (m = 0; m < 4; m++)    //寻找LRU最大的行
    {
	    if(m==max_LRU_line)
		    continue;
		else 
			if(iCache.sets[sets_index].lines[m].LRU<3)
	        iCache.sets[sets_index].lines[m].LRU++;
    }

        	for (m = 0; m < 8; m++)    //寻找LRU最大的行
    {
	    if(m==max_LRU_line)
		    continue;
		else 
			if(iCache.sets[sets_index].lines[m].LRU<7)
	        iCache.sets[sets_index].lines[m].LRU++;
    }

        if(beset!=-1)
    {
		//更新LRU
		for (m = 0; m < 8; m++)    
		{
			if(m==beset)
				continue;
			else 
				if(iCache.sets[sets_index].lines[m].LRU<7)
				iCache.sets[sets_index].lines[m].LRU++;
		}
			return iCache.sets[sets_index].lines[j].data
		[(address & 0x0000001f) >> 2];
	  return dCache.sets[sets_index].lines[k].data[(address & 0x0000001f) >> 2];
    }

    