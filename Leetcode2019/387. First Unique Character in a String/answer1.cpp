int firstUniqChar(string s)
{
	for (int i = 0; i != s.size(); i++)
	{
		//在字符串里面查找
		if(s.find(s[i],s.find(s[i])+1)==string::npos)
			return i;
	}
	return -1;
}

//Runtime: 52 ms, faster than 60.74% of C++ online submissions for First Unique Character in a String.
//Memory Usage: 13 MB, less than 98.32% of C++ online submissions for First Unique Character in a String.
//Next challenges:Sort Characters By Frequency
