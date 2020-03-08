

int main()
{
    int p;
    High_Precision n;
    cin>>p>>n;
    vector<int> coefficient;
    
    while(n.equal_to_zero()==false)
    {
        int i=n.mod(p);//i=n%(-p);n/=-p;
        if(i<0)
        {
            i+=p;
            n.plus_1();//n++;
        }
        coefficient.push_back(i);
    }
    
    cout<<coefficient.size()-1<<endl;
    for(int i=0;i<coefficient.size();i++)
    {
        cout<<coefficient[i];
        if(i<coefficient.size()-1)cout<<' ';
    }
    
    while(1);
}

