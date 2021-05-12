


int prefix(string pattern) ///longest prefix that matches with suffix
{
    vector<int> lps(pattern.size(),0);

    int index=0;
    for(int i=1;i<pattern.size();)
    {
        if(pattern[index]==pattern[i])
        {
        lps[i]=index+1;
        index++;i++;
        }
        else
        {
            if(index!=0) index=lps[index-1];
            else { lps[i]=index;i++; }
        }
    }

    return lps[pattern.size()-1];

}

int largest_pre_pal(string s)
{
    string t=s+"?";
    reverse(s.begin(),s.end());
    t+=s;
    return prefix(t);
}
